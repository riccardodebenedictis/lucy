import java.awt.Graphics2D;
import java.awt.geom.Point2D;

/**
 * Timeline
 */
public abstract class Timeline {

    protected int x_offset = 0;
    protected int y_offset = 0;
    protected int width = 0;
    protected int height = 0;

    public abstract void paint(Graphics2D g);

    public abstract boolean contains(Point2D p);

    public abstract String getToolTipText(Point2D p);
}