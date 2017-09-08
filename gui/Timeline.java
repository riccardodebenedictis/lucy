import java.awt.Graphics2D;

/**
 * Timeline
 */
public abstract class Timeline {

    protected int x_offset = 0;
    protected int y_offset = 0;
    protected int width = 0;
    protected int height = 0;

    public abstract void paint(Graphics2D g);
}