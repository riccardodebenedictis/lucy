import java.awt.Color;
import java.awt.GradientPaint;
import java.awt.Graphics2D;
import java.awt.geom.Point2D;
import java.awt.geom.RoundRectangle2D;
import java.util.ArrayList;
import java.util.Collection;

/**
 * StateVariable
 */
public class StateVariable extends Timeline {

    private final Collection<Value> vs = new ArrayList<>();

    public StateVariable() {
        height = 20;
    }

    public void addValue(int start, int end, String label, Color color) {
        width = Math.max(width, end);
        vs.add(new Value(start, end, label, color));
    }

    @Override
    public boolean contains(Point2D p) {
        for (Value v : vs)
            if (v.shape.contains(p))
                return true;
        return false;
    }

    @Override
    public String getToolTipText(Point2D p) {
        for (Value v : vs)
            if (v.shape.contains(p))
                return v.label;
        return null;
    }

    @Override
    public void paint(Graphics2D g) {
        g.setColor(Color.WHITE);
        g.fillRect(x_offset, y_offset, width, height);
        for (Value v : vs)
            v.paint(g);
    }

    /**
     * Value
     */
    private class Value {

        private final String label;
        private final Color color;
        private final RoundRectangle2D shape;

        private Value(int start, int end, String label, Color color) {
            this.label = label;
            this.color = color;
            this.shape = new RoundRectangle2D.Double(start + x_offset, y_offset, end - start, height, 5, 5);
        }

        private void paint(Graphics2D g) {
            g.setPaint(new GradientPaint(0, y_offset + height / 4, Color.WHITE, 0, y_offset + height, color, true));
            shape.setRoundRect(shape.getMinX() + x_offset, y_offset, shape.getWidth(), height, 5, 5);
            g.fill(shape);
            g.setColor(Color.BLACK);
            g.draw(shape);
        }
    }
}