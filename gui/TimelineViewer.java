import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JComponent;

/**
 * TimelineViewer
 */
public class TimelineViewer extends JComponent {

    private final TimelineMouseAdapter mouse = new TimelineMouseAdapter();

    public TimelineViewer() {
        addMouseListener(mouse);
        addMouseMotionListener(mouse);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D) g;

        g2.setColor(Color.WHITE);
        g2.fillRect(0, 0, getWidth(), getHeight());

        if (mouse.draw_line) {
            g2.setColor(Color.GRAY);
            g2.drawLine(mouse.mouse_x, 0, mouse.mouse_x, getHeight());
        }
    }

    private class TimelineMouseAdapter extends MouseAdapter {

        private boolean draw_line = false;
        private int mouse_x;
        private int mouse_y;

        @Override
        public void mouseEntered(MouseEvent e) {
            draw_line = true;
            repaint();
        }

        @Override
        public void mouseExited(MouseEvent e) {
            draw_line = false;
            repaint();
        }

        @Override
        public void mouseMoved(MouseEvent e) {
            mouse_x = e.getX();
            mouse_y = e.getY();
            repaint();
        }
    }
}