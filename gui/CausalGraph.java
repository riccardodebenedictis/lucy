import java.awt.Dimension;
import java.awt.geom.Rectangle2D;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import javax.swing.JFrame;
import javax.swing.SwingUtilities;

import prefuse.Constants;
import prefuse.Display;
import prefuse.Visualization;
import prefuse.action.ActionList;
import prefuse.action.RepaintAction;
import prefuse.action.assignment.ColorAction;
import prefuse.action.assignment.DataColorAction;
import prefuse.action.assignment.StrokeAction;
import prefuse.action.layout.Layout;
import prefuse.action.layout.graph.ForceDirectedLayout;
import prefuse.activity.Activity;
import prefuse.controls.ControlAdapter;
import prefuse.controls.DragControl;
import prefuse.controls.PanControl;
import prefuse.controls.WheelZoomControl;
import prefuse.controls.ZoomToFitControl;
import prefuse.data.Graph;
import prefuse.data.Node;
import prefuse.data.Schema;
import prefuse.render.DefaultRendererFactory;
import prefuse.render.EdgeRenderer;
import prefuse.render.LabelRenderer;
import prefuse.util.ColorLib;
import prefuse.util.FontLib;
import prefuse.util.PrefuseLib;
import prefuse.util.StrokeLib;
import prefuse.visual.DecoratorItem;
import prefuse.visual.VisualGraph;
import prefuse.visual.VisualItem;

/**
 * CausalGraph
 */
public class CausalGraph extends Display {

    private static final String GRAPH = "graph";
    private static final String NODES = "graph.nodes";
    private static final String EDGES = "graph.edges";
    private static final String NODE_TYPE = "node_type";
    private static final String NODE_COST = "node_cost";
    private static final String NODE_STATE = "node_state";
    private static final String EDGE_DECORATORS = "edgeDeco";
    private static final String NODE_DECORATORS = "nodeDeco";
    private static final Schema DECORATOR_SCHEMA = PrefuseLib.getVisualItemSchema();

    static {
        DECORATOR_SCHEMA.setDefault(VisualItem.INTERACTIVE, false);
        DECORATOR_SCHEMA.setDefault(VisualItem.TEXTCOLOR, ColorLib.gray(128));
        DECORATOR_SCHEMA.setDefault(VisualItem.FONT, FontLib.getFont("Tahoma", 7));
    }
    private final Graph g = new Graph(true);
    private final VisualGraph vg;
    private final Map<Long, Node> flaws = new HashMap<>();
    private final Map<Long, Node> resolvers = new HashMap<>();

    CausalGraph() {
        // initialize display and data
        super(new Visualization());

        g.getNodeTable().addColumn(VisualItem.LABEL, String.class);
        g.getNodeTable().addColumn(NODE_TYPE, String.class);
        g.getNodeTable().addColumn(NODE_COST, Double.class);
        g.getNodeTable().addColumn(NODE_STATE, Integer.class);
        g.getEdgeTable().addColumn(VisualItem.LABEL, String.class);

        // add visual data groups
        vg = m_vis.addGraph(GRAPH, g);

        m_vis.setInteractive(EDGES, null, false);
        m_vis.setValue(NODES, null, VisualItem.SHAPE, Constants.SHAPE_ELLIPSE);

        // set up the renderers
        // draw the nodes as basic shapes
        LabelRenderer flaw_renderer = new LabelRenderer(VisualItem.LABEL);
        flaw_renderer.setRoundedCorner(8, 8);
        LabelRenderer resolver_renderer = new LabelRenderer(VisualItem.LABEL);

        DefaultRendererFactory drf = new DefaultRendererFactory();
        drf.setDefaultRenderer(flaw_renderer);
        drf.add("ingroup('" + NODES + "')&&" + NODE_TYPE + "==\"resolver\"", resolver_renderer);
        drf.setDefaultEdgeRenderer(new EdgeRenderer(Constants.EDGE_TYPE_CURVE));
        m_vis.setRendererFactory(drf);

        // adding decorators, one group for the nodes, one for the edges
        DECORATOR_SCHEMA.setDefault(VisualItem.TEXTCOLOR, ColorLib.gray(50));
        m_vis.addDecorators(EDGE_DECORATORS, EDGES, DECORATOR_SCHEMA);

        DECORATOR_SCHEMA.setDefault(VisualItem.TEXTCOLOR, ColorLib.gray(128));
        m_vis.addDecorators(NODE_DECORATORS, NODES, DECORATOR_SCHEMA);

        // set up the visual operators
        // first set up all the color actions
        ColorAction nFill = new DataColorAction(NODES, NODE_COST, Constants.ORDINAL, VisualItem.FILLCOLOR,
                ColorLib.getHotPalette());
        nFill.add(VisualItem.HOVER, ColorLib.gray(200));
        nFill.add(VisualItem.HIGHLIGHT, ColorLib.rgb(255, 230, 230));
        nFill.add(NODE_STATE + " == " + 0, ColorLib.gray(235));

        ColorAction nStrokeColor = new ColorAction(NODES, VisualItem.STROKECOLOR);
        nStrokeColor.setDefaultColor(ColorLib.gray(100));
        nStrokeColor.add(VisualItem.HOVER, ColorLib.gray(200));

        StrokeAction nStroke = new StrokeAction(NODES, StrokeLib.getStroke(5));
        nStroke.add(NODE_STATE + " == " + 0, StrokeLib.getStroke(0.1f, StrokeLib.DOTS));
        nStroke.add(NODE_STATE + " == " + 1, StrokeLib.getStroke(0.5f));
        nStroke.add(NODE_STATE + " == " + 2, StrokeLib.getStroke(1, StrokeLib.DASHES));

        ColorAction eStroke = new ColorAction(EDGES, VisualItem.STROKECOLOR);
        eStroke.setDefaultColor(ColorLib.gray(100));

        ColorAction eFill = new ColorAction(EDGES, VisualItem.FILLCOLOR);
        eFill.setDefaultColor(ColorLib.gray(100));

        // bundle the color actions
        ActionList colors = new ActionList();
        colors.add(nFill);
        colors.add(nStrokeColor);
        colors.add(eStroke);
        colors.add(eFill);
        colors.add(nStroke);

        // now create the main layout routine
        ActionList layout = new ActionList(Activity.INFINITY);
        layout.add(colors);
        layout.add(new LabelLayout2(EDGE_DECORATORS));
        layout.add(new LabelLayout2(NODE_DECORATORS));
        layout.add(new ForceDirectedLayout(GRAPH, true));
        layout.add(new RepaintAction());
        m_vis.putAction("layout", layout);

        // set up the display
        setHighQuality(true);
        addControlListener(new PanControl());
        addControlListener(new DragControl());
        addControlListener(new ZoomToFitControl());
        addControlListener(new WheelZoomControl());

        // set things running
        m_vis.run("layout");

        try {
            SwingUtilities.invokeLater(new Runnable() {
                @Override
                public void run() {
                    JFrame frame = new JFrame("Causal graph");
                    frame.setSize(new Dimension(640, 480));
                    frame.setLocationRelativeTo(null);
                    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                    frame.add(CausalGraph.this);
                    frame.setVisible(true);
                }
            });
        } catch (Exception e) {
        }
    }

    public void flaw_created(final long f_id, final long[] cause, final String label, final double cost,
            final int state) {
        assert !flaws.containsKey(f_id);
        synchronized (m_vis) {
            Node flaw_node = g.addNode();
            flaw_node.set(VisualItem.LABEL, label);
            flaw_node.set(NODE_TYPE, "flaw");
            flaw_node.set(NODE_COST, -cost);
            flaw_node.set(NODE_STATE, state);
            flaws.put(f_id, flaw_node);
            for (long c : cause) {
                assert resolvers.containsKey(c);
                g.addEdge(flaw_node, resolvers.get(c));
            }
        }
    }

    public void flaw_state_changed(final long f_id, final int state) {
        assert flaws.containsKey(f_id);
        synchronized (m_vis) {
            Node flaw_node = flaws.get(f_id);
            flaw_node.set(NODE_STATE, state);
        }
    }

    public void flaw_cost_changed(final long f_id, final double cost) {
        assert flaws.containsKey(f_id);
        synchronized (m_vis) {
            Node flaw_node = flaws.get(f_id);
            flaw_node.set(NODE_COST, -cost);
        }
    }

    public void current_flaw(final long f_id) {
        System.out.println("a flaw cost has changed..");
    }

    public void resolver_created(final long r_id, final long f_id, final String label, final int state) {
        assert !resolvers.containsKey(r_id);
        assert flaws.containsKey(f_id);
        synchronized (m_vis) {
            Node resolver_node = g.addNode();
            resolver_node.set(VisualItem.LABEL, label);
            resolver_node.set(NODE_TYPE, "resolver");
            resolver_node.set(NODE_COST, Double.NEGATIVE_INFINITY);
            resolver_node.set(NODE_STATE, state);
            resolvers.put(r_id, resolver_node);
            g.addEdge(resolver_node, flaws.get(f_id));
        }
    }

    public void resolver_state_changed(final long r_id, final int state) {
        assert resolvers.containsKey(r_id);
        synchronized (m_vis) {
            Node resolver_node = resolvers.get(r_id);
            resolver_node.set(NODE_STATE, state);
        }
    }

    public void current_resolver(final long r_id) {
        System.out.println("a resolver cost has changed..");
    }

    public void causal_link_added(final long f_id, final long r_id) {
        System.out.println("a new causal link has been created..");
    }

    /**
     * Set label positions. Labels are assumed to be DecoratorItem instances,
     * decorating their respective nodes. The layout simply gets the bounds of
     * the decorated node and assigns the label coordinates to the center of
     * those bounds.
     */
    private static class LabelLayout2 extends Layout {

        LabelLayout2(String group) {
            super(group);
        }

        @Override
        public void run(double frac) {
            Iterator<?> iter = m_vis.items(m_group);
            while (iter.hasNext()) {
                DecoratorItem decorator = (DecoratorItem) iter.next();
                VisualItem decoratedItem = decorator.getDecoratedItem();
                Rectangle2D bounds = decoratedItem.getBounds();

                double x = bounds.getCenterX();
                double y = bounds.getCenterY();

                setX(decorator, null, x);
                setY(decorator, null, y);
            }
        }
    }
}