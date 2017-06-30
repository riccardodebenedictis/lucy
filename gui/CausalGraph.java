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
                    JFrame frame = new JFrame();
                    frame.setVisible(true);
                    frame.add(CausalGraph.this);
                }
            });
        } catch (Exception e) {
        }
    }

    public void flaw_created(final long f_id) {
        System.out.println("a new flaw has been created..");
    }

    public void flaw_state_changed(final long f_id) {
        System.out.println("a flaw state has changed..");
    }

    public void flaw_cost_changed(final long f_id) {
        System.out.println("a flaw cost has changed..");
    }
}