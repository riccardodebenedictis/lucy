import javax.swing.JFrame;
import prefuse.Display;
import prefuse.Visualization;

/**
 * CausalGraph
 */
public class CausalGraph extends Display {

    CausalGraph() {
        // initialize display and data
        super(new Visualization());
        JFrame frame = new JFrame();
        frame.setVisible(true);
        frame.add(this);
    }

    public void flaw_created(double f_id) {
        System.out.println("a new flaw has been created..");
    }

    public void flaw_state_changed(double f_id) {
        System.out.println("a new flaw has been created..");
    }

    public void flaw_cost_changed(double f_id) {
        System.out.println("a new flaw has been created..");
    }
}