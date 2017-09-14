import java.awt.Component;
import java.awt.Dimension;
import java.awt.Font;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import javax.swing.AbstractListModel;
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

    private final VarListModel var_list_model = new VarListModel();
    private final ClauseListModel clause_list_model = new ClauseListModel();

    public SATCore() {
        setLayout(new BoxLayout(this, BoxLayout.LINE_AXIS));

        JList var_list = new JList<>(var_list_model);
        var_list.setCellRenderer(new DefaultListCellRenderer() {

            @Override
            public Component getListCellRendererComponent(JList<?> list, Object value, int index, boolean isSelected,
                    boolean cellHasFocus) {
                Component c = super.getListCellRendererComponent(list, value, index, isSelected, cellHasFocus);
                if (var_list_model.current_var != null && index == var_list_model.current_var) {
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
        clause_list.setCellRenderer(new DefaultListCellRenderer() {

            @Override
            public Component getListCellRendererComponent(JList<?> list, Object value, int index, boolean isSelected,
                    boolean cellHasFocus) {
                Component c = super.getListCellRendererComponent(list, value, index, isSelected, cellHasFocus);
                c.setFont(c.getFont().deriveFont(Font.PLAIN));
                return c;
            }
        });
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
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                var_list_model.addVar(id);
            }
        });
    }

    public void new_value(final long id, final LBool val) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                var_list_model.setValue(id, val);
            }
        });
    }

    public void new_clause(final long id, final Lit[] clause) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                clause_list_model.addClause(clause);
            }
        });
    }

    private class VarListModel extends AbstractListModel<String> {

        private final List<LBool> vals = new ArrayList<>();
        private Integer current_var;

        public void addVar(final long id) {
            assert vals.size() == id;
            int index = vals.size();
            vals.add(LBool.Undefined);
            fireIntervalAdded(this, index, index);
        }

        public void setValue(final long id, final LBool val) {
            vals.set((int) id, val);
            if (current_var != null) {
                int c_var = current_var;
                current_var = (int) id;
                fireContentsChanged(this, c_var, c_var);
                fireContentsChanged(this, current_var, current_var);
            } else {
                current_var = (int) id;
                fireContentsChanged(this, current_var, current_var);
            }
        }

        @Override
        public int getSize() {
            return vals.size();
        }

        @Override
        public String getElementAt(int index) {
            return vals.get(index) == LBool.Undefined ? "b" + index : "b" + index + ": " + vals.get(index);
        }
    }

    private class ClauseListModel extends AbstractListModel<String> {

        private final List<Lit[]> clauses = new ArrayList<>();

        public void addClause(Lit[] lits) {
            int index = clauses.size();
            clauses.add(lits);
            fireIntervalAdded(this, index, index);
        }

        @Override
        public int getSize() {
            return clauses.size();
        }

        @Override
        public String getElementAt(int index) {
            return "(" + Stream.of(clauses.get(index)).map(l -> (l.sign ? "" : "-") + "b" + l.var).collect(Collectors.joining(", "))
                    + ")";
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