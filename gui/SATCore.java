import java.awt.Component;
import java.awt.Dimension;
import java.awt.Font;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import javax.swing.BoxLayout;
import javax.swing.DefaultListCellRenderer;
import javax.swing.DefaultListModel;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.SwingUtilities;

/**
 * SATCore
 */
public class SATCore extends JPanel {

    private final Map<Long, Integer> vars = new HashMap<>();
    private final List<LBool> vals = new ArrayList<>();
    private final DefaultListModel<String> var_list_model = new DefaultListModel<>();

    private final Map<Long, Lit[]> clauses = new HashMap<>();
    private final DefaultListModel<String> clause_list_model = new DefaultListModel<>();

    private Integer current_var;

    public SATCore() {
        setLayout(new BoxLayout(this, BoxLayout.LINE_AXIS));

        JList var_list = new JList<>(var_list_model);
        var_list.setCellRenderer(new DefaultListCellRenderer() {

            @Override
            public Component getListCellRendererComponent(JList<?> list, Object value, int index, boolean isSelected,
                    boolean cellHasFocus) {
                Component c = super.getListCellRendererComponent(list, value, index, isSelected, cellHasFocus);
                if (current_var != null && index == current_var) {
                    c.setFont(c.getFont().deriveFont(Font.BOLD));
                } else {
                    c.setFont(c.getFont().deriveFont(Font.PLAIN));
                }
                return c;
            }
        });
        JScrollPane var_pane = new JScrollPane(var_list);
        add(var_pane);

        JList clause_list = new JList<>(clause_list_model);
        JScrollPane clause_pane = new JScrollPane(clause_list);
        add(clause_pane);

        try {
            SwingUtilities.invokeLater(new Runnable() {
                @Override
                public void run() {
                    JFrame frame = new JFrame("SAT-core");
                    frame.setSize(new Dimension(640, 480));
                    frame.setLocationRelativeTo(null);
                    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                    frame.add(SATCore.this);
                    frame.setVisible(true);
                }
            });
        } catch (Exception e) {
        }
    }

    public void new_var(final long id) {
        assert !vars.containsKey(id) : "the variable already exists..";
        synchronized (this) {
            vars.put(id, vars.size());
            vals.add(LBool.Undefined);
            var_list_model.addElement("b" + vars.get(id));
        }
    }

    public void new_value(final long id, final LBool val) {
        assert vars.containsKey(id) : "the variable does not exist..";
        synchronized (this) {
            vals.set(vars.get(id), val);
            if (current_var != null) {
                var_list_model.set(current_var, "b" + current_var + ": " + val);
            }
            var_list_model.set(vars.get(id), "b" + vars.get(id) + ": " + val);
        }
    }

    public void new_clause(final long id, Lit[] clause) {
        assert !clauses.containsKey(id) : "the clause already exists..";
        synchronized (this) {
            clauses.put(id, clause);
            clause_list_model.addElement("("
                    + Stream.of(clause).map(l -> (l.sign ? "" : "-") + "b" + l.var).collect(Collectors.joining(", "))
                    + ")");
        }
    }

    public static class Lit {

        private final long var;
        private final boolean sign;

        public Lit(final long var, final boolean sign) {
            this.var = var;
            this.sign = sign;
        }

        @Override
        public String toString() {
            return (sign ? "" : "-") + var;
        }
    }

    public enum LBool {
        False, True, Undefined
    }
}