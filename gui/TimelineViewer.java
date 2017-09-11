import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.SwingUtilities;
import javax.swing.ToolTipManager;

/**
 * TimelineViewer
 */
public class TimelineViewer extends JComponent {

    private int x_offset = 5;
    private int y_offset = 5;
    private int gap = 5;
    private final List<Timeline> timelines = new ArrayList<>();
    private final TimelineMouseAdapter mouse = new TimelineMouseAdapter();

    public TimelineViewer() {
        addMouseListener(mouse);
        addMouseMotionListener(mouse);

        try {
            SwingUtilities.invokeLater(new Runnable() {
                @Override
                public void run() {
                    JFrame frame = new JFrame("Timelines");
                    frame.setSize(new Dimension(640, 480));
                    frame.setLocationRelativeTo(null);
                    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                    frame.add(TimelineViewer.this);
                    frame.setVisible(true);
                }
            });
        } catch (Exception e) {
        }
    }

    public void addTimelines(Timeline... ts) {
        for (Timeline t : ts) {
            t.x_offset = x_offset;
            if (timelines.isEmpty()) {
                t.y_offset = y_offset;
            } else {
                t.y_offset = y_offset + gap + timelines.get(timelines.size() - 1).y_offset
                        + timelines.get(timelines.size() - 1).height;
            }
            timelines.add(t);
        }
        repaint();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D) g;

        g2.setColor(Color.WHITE);
        g2.fillRect(0, 0, getWidth(), getHeight());

        for (Timeline timeline : timelines) {
            timeline.paint(g2);
        }

        if (mouse.inside) {
            g2.setColor(Color.GRAY);
            g2.drawLine(mouse.mouse_x, 0, mouse.mouse_x, getHeight());
        }
    }

    private class TimelineMouseAdapter extends MouseAdapter {

        private boolean inside = false;
        private int mouse_x;

        @Override
        public void mouseEntered(MouseEvent e) {
            inside = true;
            repaint();
        }

        @Override
        public void mouseExited(MouseEvent e) {
            inside = false;
            repaint();
        }

        @Override
        public void mouseMoved(MouseEvent e) {
            if (inside) {
                mouse_x = e.getX();
                boolean show_tooltip = false;
                for (Timeline t : timelines) {
                    if (t.contains(e.getPoint())) {
                        show_tooltip = true;
                        setToolTipText(t.getToolTipText());
                        break;
                    }
                }
                if (!show_tooltip) {
                    setToolTipText(null);
                }
                repaint();
            }
            ToolTipManager.sharedInstance().mouseMoved(e);
        }
    }
}