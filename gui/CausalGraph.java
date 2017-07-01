import java.awt.Dimension;

import javax.swing.JFrame;
import javax.swing.SwingUtilities;

import prefuse.Display;
import prefuse.Visualization;

/**
 * CausalGraph
 */
public class CausalGraph extends Display {

    CausalGraph() {
        // initialize display and data
        super(new Visualization());
        try {
            SwingUtilities.invokeLater(new Runnable() {
                @Override
                public void run() {
                    JFrame frame = new JFrame("Causal graph");
                    frame.setSize(new Dimension(600, 400));
                    frame.pack();
                    frame.setVisible(true);
                    frame.add(CausalGraph.this);
                }
            });
        } catch (Exception e) {
        }
    }

    public void flaw_created(final long f_id, final long[] cause, final String label, final double cost,
            final int state) {
        System.out.println("a new flaw has been created..");
    }

    public void flaw_state_changed(final long f_id, final int state) {
        System.out.println("a flaw state has changed..");
    }

    public void flaw_cost_changed(final long f_id, final double cost) {
        System.out.println("a flaw cost has changed..");
    }

    public void current_flaw(final long f_id) {
        System.out.println("a flaw cost has changed..");
    }

    public void resolver_created(final long r_id, final long f_id, final String label, final int state) {
        System.out.println("a new resolver has been created..");
    }

    public void resolver_state_changed(final long r_id, final int state) {
        System.out.println("a resolver state has changed..");
    }

    public void current_resolver(final long r_id) {
        System.out.println("a resolver cost has changed..");
    }

    public void causal_link_added(final long f_id, final long r_id) {
        System.out.println("a new causal link has been created..");
    }
}