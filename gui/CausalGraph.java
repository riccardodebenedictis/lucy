import java.awt.Dimension;
import java.awt.event.MouseEvent;
import java.awt.geom.Rectangle2D;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

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
import prefuse.data.Edge;
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
    private static final String EDGE_STATE = "edge_state";
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
    private final Map<Long, Collection<Long>> causes = new HashMap<>();
    private final Map<Long, Collection<Long>> preconditions = new HashMap<>();
    private static final Executor EXECUTOR = Executors.newCachedThreadPool();

    CausalGraph() {
        // initialize display and data
        super(new Visualization());

        g.getNodeTable().addColumn(VisualItem.LABEL, String.class);
        g.getNodeTable().addColumn(NODE_TYPE, String.class);
        g.getNodeTable().addColumn(NODE_COST, Double.class);
        g.getNodeTable().addColumn(NODE_STATE, Integer.class);
        g.getEdgeTable().addColumn(VisualItem.LABEL, String.class);
        g.getEdgeTable().addColumn(EDGE_STATE, Integer.class);

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

        ColorAction eStrokeColor = new ColorAction(EDGES, VisualItem.STROKECOLOR);
        eStrokeColor.setDefaultColor(ColorLib.gray(100));

        StrokeAction eStroke = new StrokeAction(EDGES, StrokeLib.getStroke(5));
        eStroke.add(EDGE_STATE + " == " + 0, StrokeLib.getStroke(0.1f, StrokeLib.DOTS));
        eStroke.add(EDGE_STATE + " == " + 1, StrokeLib.getStroke(0.5f));
        eStroke.add(EDGE_STATE + " == " + 2, StrokeLib.getStroke(1, StrokeLib.DASHES));

        ColorAction eFill = new ColorAction(EDGES, VisualItem.FILLCOLOR);
        eFill.setDefaultColor(ColorLib.gray(100));

        // bundle the color actions
        ActionList colors = new ActionList();
        colors.add(nFill);
        colors.add(nStrokeColor);
        colors.add(nStroke);
        colors.add(eStrokeColor);
        colors.add(eStroke);
        colors.add(eFill);

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
        addControlListener(new ControlAdapter() {
            @Override
            public void itemEntered(VisualItem vi, MouseEvent me) {
                Display d = (Display) me.getSource();
                if (vi.getSourceTuple() instanceof Node) {
                    Node nodeData = (Node) vi.getSourceTuple();
                    String t_text = "";
                    switch ((String) nodeData.get(NODE_TYPE)) {
                    case "flaw":
                        t_text += "in-plan";
                        break;
                    case "resolver":
                        t_text += "chosen";
                        break;
                    }
                    t_text += ": ";
                    switch ((int) nodeData.get(NODE_STATE)) {
                    case 0:
                        t_text += "False";
                        break;
                    case 1:
                        t_text += "True";
                        break;
                    case 2:
                        t_text += "Undefined";
                        break;
                    default:
                        break;
                    }
                    t_text += ", cost: " + (-(Double) nodeData.get(NODE_COST));
                    d.setToolTipText(t_text);
                }
            }

            @Override
            public void itemExited(VisualItem vi, MouseEvent me) {
                Display d = (Display) me.getSource();
                d.setToolTipText(null);
            }

            @Override
            public void itemClicked(VisualItem vi, MouseEvent me) {
                if (vi.getSourceTuple() instanceof Node) {
                    Node nodeData = (Node) vi.getSourceTuple();
                    switch ((String) nodeData.get(NODE_TYPE)) {
                    case "flaw":
                        break;
                    case "resolver":
                        break;
                    }
                }
            }
        });

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
        synchronized (m_vis) {
            assert !flaws.containsKey(f_id) : "the flaw already exists..";
            assert Arrays.stream(cause).allMatch(c -> resolvers.containsKey(c)) : "the flaw's cause does not exist: "
                    + Arrays.toString(cause) + resolvers;
            causes.put(f_id, new ArrayList<>());
            Node flaw_node = g.addNode();
            flaw_node.set(VisualItem.LABEL, label);
            flaw_node.set(NODE_TYPE, "flaw");
            flaw_node.set(NODE_COST, -cost);
            flaw_node.set(NODE_STATE, state);
            flaws.put(f_id, flaw_node);
            for (long c : cause) {
                causes.get(f_id).add(c);
                preconditions.get(c).add(f_id);
                Edge c_edge = g.addEdge(flaw_node, resolvers.get(c));
                c_edge.set(EDGE_STATE, resolvers.get(c).get(NODE_STATE));
                resolvers.get(c).set(NODE_COST, preconditions.get(c).stream()
                        .mapToDouble(pre -> (Double) flaws.get(pre).get(NODE_COST)).min().getAsDouble());
            }
        }
    }

    public void flaw_state_changed(final long f_id, final int state) {
        synchronized (m_vis) {
            assert flaws.containsKey(f_id) : "the flaw does not exist..";
            Node flaw_node = flaws.get(f_id);
            flaw_node.set(NODE_STATE, state);
        }
    }

    public void flaw_cost_changed(final long f_id, final double cost) {
        synchronized (m_vis) {
            assert flaws.containsKey(f_id) : "the flaw does not exist..";
            Node flaw_node = flaws.get(f_id);
            flaw_node.set(NODE_COST, -cost);
            for (long c : causes.get(f_id)) {
                resolvers.get(c).set(NODE_COST, preconditions.get(c).stream()
                        .mapToDouble(pre -> (Double) flaws.get(pre).get(NODE_COST)).min().getAsDouble());
            }
        }
    }

    public void current_flaw(final long f_id) {
        EXECUTOR.execute(new Runnable() {
            @Override
            public void run() {
                synchronized (m_vis) {
                    assert flaws.containsKey(f_id) : "the flaw does not exist..";
                    if (!m_vis.getVisualItem(NODES, flaws.get(f_id)).isHighlighted())
                        m_vis.getVisualItem(NODES, flaws.get(f_id)).setHighlighted(true);
                }
                try {
                    TimeUnit.SECONDS.sleep(5);
                } catch (Exception e) {
                }
                synchronized (m_vis) {
                    m_vis.getVisualItem(NODES, flaws.get(f_id)).setHighlighted(false);
                }
            }
        });
    }

    public void resolver_created(final long r_id, final long f_id, final String label, final int state) {
        synchronized (m_vis) {
            assert !resolvers.containsKey(r_id) : "the resolver already exists..";
            assert flaws.containsKey(f_id) : "the resolver's solved flaw does not exist..";
            preconditions.put(r_id, new ArrayList<>());
            Node resolver_node = g.addNode();
            resolver_node.set(VisualItem.LABEL, label);
            resolver_node.set(NODE_TYPE, "resolver");
            resolver_node.set(NODE_COST, -0d);
            resolver_node.set(NODE_STATE, state);
            resolvers.put(r_id, resolver_node);
            Edge c_edge = g.addEdge(resolver_node, flaws.get(f_id));
            c_edge.set(EDGE_STATE, state);
        }
    }

    public void resolver_state_changed(final long r_id, final int state) {
        synchronized (m_vis) {
            assert resolvers.containsKey(r_id) : "the resolver does not exist..";
            Node resolver_node = resolvers.get(r_id);
            resolver_node.set(NODE_STATE, state);
            Iterator<Edge> c_edges = resolver_node.edges();
            while (c_edges.hasNext()) {
                c_edges.next().set(EDGE_STATE, state);
            }
        }
    }

    public void current_resolver(final long r_id) {
        EXECUTOR.execute(new Runnable() {
            @Override
            public void run() {
                synchronized (m_vis) {
                    assert resolvers.containsKey(r_id) : "the resolver does not exist..";
                    if (!m_vis.getVisualItem(NODES, resolvers.get(r_id)).isHighlighted())
                        m_vis.getVisualItem(NODES, resolvers.get(r_id)).setHighlighted(true);
                }
                try {
                    TimeUnit.SECONDS.sleep(5);
                } catch (Exception e) {
                }
                synchronized (m_vis) {
                    m_vis.getVisualItem(NODES, resolvers.get(r_id)).setHighlighted(false);
                }
            }
        });
    }

    public void causal_link_added(final long f_id, final long r_id) {
        synchronized (m_vis) {
            assert flaws.containsKey(f_id) : "the flaw does not exist..";
            assert resolvers.containsKey(r_id) : "the resolver does not exist..";
            Edge c_edge = g.addEdge(flaws.get(f_id), resolvers.get(r_id));
            c_edge.set(EDGE_STATE, resolvers.get(r_id).get(NODE_STATE));
            causes.get(f_id).add(r_id);
            preconditions.get(r_id).add(f_id);
            resolvers.get(r_id).set(NODE_COST, preconditions.get(r_id).stream()
                    .mapToDouble(pre -> (Double) flaws.get(pre).get(NODE_COST)).min().getAsDouble());
        }
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