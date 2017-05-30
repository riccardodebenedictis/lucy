/*
 * Copyright (C) 2017 Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package it.cnr.istc.ratio.gui;

import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.Path;
import static java.nio.file.StandardWatchEventKinds.ENTRY_CREATE;
import static java.nio.file.StandardWatchEventKinds.ENTRY_DELETE;
import static java.nio.file.StandardWatchEventKinds.ENTRY_MODIFY;
import static java.nio.file.StandardWatchEventKinds.OVERFLOW;
import java.nio.file.WatchEvent;
import java.nio.file.WatchKey;
import java.nio.file.WatchService;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.ImageIcon;
import javax.swing.SwingUtilities;
import javax.swing.ToolTipManager;
import javax.swing.event.TreeExpansionEvent;
import javax.swing.event.TreeWillExpandListener;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.ExpandVetoException;

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
public class MainJFrame extends javax.swing.JFrame {

    private final Path path;
    private final State state = new State();
    private final Map<String, Item> items = new HashMap<>();
    private final Map<String, Flaw> flaws = new HashMap<>();
    private final Map<String, Resolver> resolvers = new HashMap<>();

    /**
     * Creates new form MainJFrame
     */
    public MainJFrame(String first) {
        initComponents();

        setIconImages(Arrays.asList(
                new ImageIcon(getClass().getResource("resources/ratio16.png")).getImage(),
                new ImageIcon(getClass().getResource("resources/ratio32.png")).getImage())
        );

        path = FileSystems.getDefault().getPath(first);

        load_state();
        load_graph();

        new Thread(() -> {
            WatchService watcher;
            try {
                watcher = FileSystems.getDefault().newWatchService();
            } catch (IOException ex) {
                return;
            }
            try {
                path.register(watcher, ENTRY_CREATE, ENTRY_DELETE, ENTRY_MODIFY);
            } catch (IOException ex) {
                Logger.getLogger(MainJFrame.class.getName()).log(Level.SEVERE, null, ex);
            }
            for (;;) {
                try {
                    boolean overflow = false;
                    WatchKey key = watcher.take();
                    for (WatchEvent<?> event : key.pollEvents()) {
                        WatchEvent.Kind<?> kind = event.kind();
                        if (kind == OVERFLOW) {
                            overflow = true;
                            continue;
                        }
                        @SuppressWarnings("unchecked")
                        WatchEvent<Path> ev = (WatchEvent<Path>) event;
                        Path filename = ev.context();
                        if (kind == ENTRY_DELETE) {
                            switch (filename.getFileName().toString()) {
                                case "state.json":
                                    clear_state();
                                    break;
                                case "graph.json":
                                    clear_graph();
                                    break;
                            }
                            continue;
                        }
                        switch (filename.getFileName().toString()) {
                            case "state.json":
                                try {
                                    JsonElement s_element = new JsonParser().parse(new FileReader(path.resolve(filename).toFile()));
                                    if (s_element.isJsonNull()) {
                                        clear_state();
                                    } else {
                                        update_state(s_element.getAsJsonObject());
                                    }
                                } catch (Exception ex) {
                                    clear_state();
                                }
                                break;
                            case "graph.json":
                                try {
                                    JsonElement g_element = new JsonParser().parse(new FileReader(path.resolve(filename).toFile()));
                                    if (g_element.isJsonNull()) {
                                        clear_graph();
                                    } else {
                                        update_graph(g_element.getAsJsonObject());
                                    }
                                } catch (Exception e) {
                                    clear_graph();
                                }
                                break;
                        }
                    }

                    if (!key.reset()) {
                        break;
                    }

                    if (overflow) {
                        clear_state();
                        load_state();
                        clear_graph();
                        load_graph();
                    }
                } catch (InterruptedException ex) {
                    Logger.getLogger(MainJFrame.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        }).start();

        stateJTree.addTreeWillExpandListener(new TreeWillExpandListener() {
            @Override
            public void treeWillExpand(TreeExpansionEvent event) throws ExpandVetoException {
                stateTreeModel.createChilds((DefaultMutableTreeNode) event.getPath().getLastPathComponent());
            }

            @Override
            public void treeWillCollapse(TreeExpansionEvent event) throws ExpandVetoException {
            }
        });

        ToolTipManager.sharedInstance().registerComponent(stateJTree);
    }

    private void load_state() {
        File file = path.resolve("state.json").toFile();
        if (file.exists()) {
            try {
                FileReader reader = new FileReader(file);
                JsonElement element = new JsonParser().parse(reader);
                reader.close();
                if (!element.isJsonNull()) {
                    update_state(element.getAsJsonObject());
                }
            } catch (Exception ex) {
                clear_state();
            }
        }
    }

    private void load_graph() {
        File file = path.resolve("graph.json").toFile();
        if (file.exists()) {
            try {
                FileReader reader = new FileReader(file);
                JsonElement element = new JsonParser().parse(reader);
                reader.close();
                if (!element.isJsonNull()) {
                    update_graph(element.getAsJsonObject());
                }
            } catch (Exception ex) {
                clear_graph();
            }
        }
    }

    private void clear_state() {
        items.clear();
        state.items.clear();
        state.atoms.clear();
        SwingUtilities.invokeLater(() -> stateTreeModel.setRoot(state));
    }

    private void clear_graph() {
        flaws.clear();
        resolvers.clear();
        causalGraphDisplay.clear();
    }

    private void update_state(JsonObject j_state) {
        // we create items (if needed)..
        if (j_state.has("items")) {
            JsonArray items_array = j_state.get("items").getAsJsonArray();
            for (int i = 0; i < items_array.size(); i++) {
                JsonObject j_item = items_array.get(i).getAsJsonObject();
                String id = j_item.get("id").getAsString();
                if (!items.containsKey(id)) {
                    // we have a new item..
                    Item item = new Item(j_item.get("type").getAsString());
                    items.put(id, item);
                }
            }
        }
        // we create atoms (if needed)..
        if (j_state.has("atoms")) {
            JsonArray atoms_array = j_state.get("atoms").getAsJsonArray();
            for (int i = 0; i < atoms_array.size(); i++) {
                JsonObject j_atom = atoms_array.get(i).getAsJsonObject();
                String id = j_atom.get("id").getAsString();
                Atom atom;
                if (items.containsKey(id)) {
                    atom = (Atom) items.get(id);
                } else {
                    // we have a new atom..
                    atom = new Atom(j_atom.get("predicate").getAsString());
                    state.atoms.add(atom);
                    items.put(id, atom);
                }
                // we update the atom's state..
                JsonArray j_atom_state = j_atom.get("state").getAsJsonArray();
                for (int j = 0; j < j_atom_state.size(); j++) {
                    atom.state.add(AtomState.valueOf(j_atom_state.get(j).getAsString()));
                }
            }
        }

        if (j_state.has("items")) {
            JsonArray items_array = j_state.get("items").getAsJsonArray();
            for (int i = 0; i < items_array.size(); i++) {
                JsonObject j_item = items_array.get(i).getAsJsonObject();
                Item item = items.get(j_item.get("id").getAsString());
                if (j_item.has("items")) {
                    JsonArray j_item_refs = j_item.get("items").getAsJsonArray();
                    for (int j = 0; j < j_item_refs.size(); j++) {
                        JsonObject j_item_ref = j_item_refs.get(j).getAsJsonObject();
                        String name = j_item_ref.get("name").getAsString();
                        item.items.put(name, getItem(j_item_ref));
                    }
                }
            }
        }
        if (j_state.has("atoms")) {
            JsonArray atoms_array = j_state.get("atoms").getAsJsonArray();
            for (int i = 0; i < atoms_array.size(); i++) {
                JsonObject j_atom = atoms_array.get(i).getAsJsonObject();
                Atom atom = (Atom) items.get(j_atom.get("id").getAsString());
                if (j_atom.has("pars")) {
                    JsonArray j_atom_refs = j_atom.get("pars").getAsJsonArray();
                    for (int j = 0; j < j_atom_refs.size(); j++) {
                        JsonObject j_item_ref = j_atom_refs.get(j).getAsJsonObject();
                        String name = j_item_ref.get("name").getAsString();
                        atom.items.put(name, getItem(j_item_ref));
                    }
                }
            }
        }

        JsonArray refs_array = j_state.get("refs").getAsJsonArray();
        for (int i = 0; i < refs_array.size(); i++) {
            JsonObject j_ref = refs_array.get(i).getAsJsonObject();
            String name = j_ref.get("name").getAsString();
            state.items.put(name, getItem(j_ref));
        }

        SwingUtilities.invokeLater(() -> stateTreeModel.setRoot(state));
    }

    private void update_graph(JsonObject j_graph) {
        // we create flaws (if needed)..
        if (j_graph.has("flaws")) {
            JsonArray flaws_array = j_graph.get("flaws").getAsJsonArray();
            for (int i = 0; i < flaws_array.size(); i++) {
                JsonObject j_flaw = flaws_array.get(i).getAsJsonObject();
                String id = j_flaw.get("id").getAsString();
                Flaw f;
                if (!flaws.containsKey(id)) {
                    // we have a new flaw..
                    f = new Flaw(j_flaw.get("label").getAsString(), j_flaw.get("in_plan_var").getAsString());
                    flaws.put(id, f);
                    causalGraphDisplay.new_flaw(f);
                }
            }
        }

        // we create resolvers (if needed)..
        if (j_graph.has("resolvers")) {
            JsonArray resolvers_array = j_graph.get("resolvers").getAsJsonArray();
            for (int i = 0; i < resolvers_array.size(); i++) {
                JsonObject j_resolver = resolvers_array.get(i).getAsJsonObject();
                String id = j_resolver.get("id").getAsString();
                Resolver r;
                if (!resolvers.containsKey(id)) {
                    // we have a new resolver..
                    Flaw sol = flaws.get(j_resolver.get("solves").getAsString());
                    Collection<Flaw> pres = new ArrayList<>();
                    if (j_resolver.has("preconditions")) {
                        JsonArray preconditions_array = j_resolver.get("preconditions").getAsJsonArray();
                        for (int j = 0; j < preconditions_array.size(); j++) {
                            pres.add(flaws.get(preconditions_array.get(j).getAsString()));
                        }
                    }
                    r = new Resolver(j_resolver.get("label").getAsString(), j_resolver.get("chosen_var").getAsString(), sol, pres);
                    resolvers.put(id, r);
                    causalGraphDisplay.new_resolver(r);
                }
            }
        }

        if (j_graph.has("flaws")) {
            JsonArray flaws_array = j_graph.get("flaws").getAsJsonArray();
            for (int i = 0; i < flaws_array.size(); i++) {
                JsonObject j_flaw = flaws_array.get(i).getAsJsonObject();
                String id = j_flaw.get("id").getAsString();
                Flaw f = flaws.get(id);
                f.in_plan_val = LBool.valueOf(j_flaw.get("in_plan_val").getAsString());
                if (j_flaw.has("cost")) {
                    f.cost = j_flaw.get("cost").getAsDouble();
                }
                causalGraphDisplay.flaw_changed(f);
            }
        }
        if (j_graph.has("resolvers")) {
            JsonArray resolvers_array = j_graph.get("resolvers").getAsJsonArray();
            for (int i = 0; i < resolvers_array.size(); i++) {
                JsonObject j_resolver = resolvers_array.get(i).getAsJsonObject();
                String id = j_resolver.get("id").getAsString();
                Resolver r = resolvers.get(id);
                r.chosen = LBool.valueOf(j_resolver.get("chosen_val").getAsString());
                if (j_resolver.has("cost")) {
                    r.cost = j_resolver.get("cost").getAsDouble();
                }
                causalGraphDisplay.resolver_changed(r);
            }
        }
    }

    private Item getItem(JsonObject ref) {
        if (ref.get("value").isJsonPrimitive()) {
            return items.get(ref.get("value").getAsString());
        }
        JsonObject val = ref.get("value").getAsJsonObject();
        if (val.has("lit")) {
            return new BoolItem(val.get("lit").getAsString(), LBool.valueOf(val.get("val").getAsString()));
        } else if (val.has("lin")) {
            return new ArithItem(ref.get("type").getAsString(), val.get("lin").getAsString(), val.get("val").getAsDouble(), val.has("lb") ? val.get("lb").getAsDouble() : Double.NEGATIVE_INFINITY, val.has("ub") ? val.get("ub").getAsDouble() : Double.POSITIVE_INFINITY);
        } else if (val.has("var")) {
            EnumItem ei = new EnumItem(ref.get("type").getAsString(), val.get("var").getAsString());
            JsonArray vals_array = val.get("vals").getAsJsonArray();
            for (int i = 0; i < vals_array.size(); i++) {
                ei.values.add(items.get(vals_array.get(i).getAsString()));
            }
            return ei;
        } else {
            throw new AssertionError(val);
        }
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        stateTreeModel = new it.cnr.istc.ratio.gui.StateTreeModel();
        stateTreeCellRenderer = new it.cnr.istc.ratio.gui.StateTreeCellRenderer();
        jDesktopPane = new javax.swing.JDesktopPane();
        causalGraphJInternalFrame = new javax.swing.JInternalFrame();
        causalGraphDisplay = new it.cnr.istc.ratio.gui.CausalGraphDisplay();
        stateJInternalFrame = new javax.swing.JInternalFrame();
        stateJScrollPane = new javax.swing.JScrollPane();
        stateJTree = new javax.swing.JTree();
        mainJToolBar = new javax.swing.JToolBar();
        reloadJButton = new javax.swing.JButton();

        stateTreeCellRenderer.setText("stateTreeCellRenderer1");

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("o-ratio");

        causalGraphJInternalFrame.setIconifiable(true);
        causalGraphJInternalFrame.setMaximizable(true);
        causalGraphJInternalFrame.setResizable(true);
        causalGraphJInternalFrame.setTitle("Causal graph");
        causalGraphJInternalFrame.setVisible(true);

        javax.swing.GroupLayout causalGraphJInternalFrameLayout = new javax.swing.GroupLayout(causalGraphJInternalFrame.getContentPane());
        causalGraphJInternalFrame.getContentPane().setLayout(causalGraphJInternalFrameLayout);
        causalGraphJInternalFrameLayout.setHorizontalGroup(
            causalGraphJInternalFrameLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(causalGraphDisplay, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, 363, Short.MAX_VALUE)
        );
        causalGraphJInternalFrameLayout.setVerticalGroup(
            causalGraphJInternalFrameLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(causalGraphDisplay, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)
        );

        stateJInternalFrame.setIconifiable(true);
        stateJInternalFrame.setMaximizable(true);
        stateJInternalFrame.setResizable(true);
        stateJInternalFrame.setTitle("State");
        stateJInternalFrame.setVisible(true);

        stateJTree.setModel(stateTreeModel);
        stateJTree.setCellRenderer(stateTreeCellRenderer);
        stateJTree.setRootVisible(false);
        stateJScrollPane.setViewportView(stateJTree);

        javax.swing.GroupLayout stateJInternalFrameLayout = new javax.swing.GroupLayout(stateJInternalFrame.getContentPane());
        stateJInternalFrame.getContentPane().setLayout(stateJInternalFrameLayout);
        stateJInternalFrameLayout.setHorizontalGroup(
            stateJInternalFrameLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(stateJInternalFrameLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(stateJScrollPane, javax.swing.GroupLayout.DEFAULT_SIZE, 159, Short.MAX_VALUE)
                .addContainerGap())
        );
        stateJInternalFrameLayout.setVerticalGroup(
            stateJInternalFrameLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(stateJInternalFrameLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(stateJScrollPane, javax.swing.GroupLayout.DEFAULT_SIZE, 343, Short.MAX_VALUE)
                .addContainerGap())
        );

        jDesktopPane.setLayer(causalGraphJInternalFrame, javax.swing.JLayeredPane.DEFAULT_LAYER);
        jDesktopPane.setLayer(stateJInternalFrame, javax.swing.JLayeredPane.DEFAULT_LAYER);

        javax.swing.GroupLayout jDesktopPaneLayout = new javax.swing.GroupLayout(jDesktopPane);
        jDesktopPane.setLayout(jDesktopPaneLayout);
        jDesktopPaneLayout.setHorizontalGroup(
            jDesktopPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jDesktopPaneLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(stateJInternalFrame)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(causalGraphJInternalFrame)
                .addContainerGap())
        );
        jDesktopPaneLayout.setVerticalGroup(
            jDesktopPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jDesktopPaneLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jDesktopPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(stateJInternalFrame)
                    .addComponent(causalGraphJInternalFrame))
                .addContainerGap())
        );

        mainJToolBar.setFloatable(false);
        mainJToolBar.setRollover(true);

        reloadJButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/it/cnr/istc/ratio/gui/resources/reload.png"))); // NOI18N
        reloadJButton.setFocusable(false);
        reloadJButton.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        reloadJButton.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        reloadJButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                reloadJButtonActionPerformed(evt);
            }
        });
        mainJToolBar.add(reloadJButton);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jDesktopPane)
            .addComponent(mainJToolBar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addComponent(mainJToolBar, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jDesktopPane))
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void reloadJButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_reloadJButtonActionPerformed
        clear_state();
        load_state();
        clear_graph();
        load_graph();
    }//GEN-LAST:event_reloadJButtonActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException | InstantiationException | IllegalAccessException | javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(MainJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(() -> {
            if (args.length == 0) {
                new MainJFrame(".").setVisible(true);
            } else {
                new MainJFrame(args[0]).setVisible(true);
            }
        });
    }
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private it.cnr.istc.ratio.gui.CausalGraphDisplay causalGraphDisplay;
    private javax.swing.JInternalFrame causalGraphJInternalFrame;
    private javax.swing.JDesktopPane jDesktopPane;
    private javax.swing.JToolBar mainJToolBar;
    private javax.swing.JButton reloadJButton;
    private javax.swing.JInternalFrame stateJInternalFrame;
    private javax.swing.JScrollPane stateJScrollPane;
    private javax.swing.JTree stateJTree;
    private it.cnr.istc.ratio.gui.StateTreeCellRenderer stateTreeCellRenderer;
    private it.cnr.istc.ratio.gui.StateTreeModel stateTreeModel;
    // End of variables declaration//GEN-END:variables
}
