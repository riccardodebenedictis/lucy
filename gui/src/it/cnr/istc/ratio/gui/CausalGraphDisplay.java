/*
 * Copyright (C) 2017 Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package it.cnr.istc.ratio.gui;

import java.awt.event.MouseEvent;
import java.awt.geom.Rectangle2D;
import java.beans.Beans;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;
import java.util.logging.Level;
import java.util.logging.Logger;
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
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
public class CausalGraphDisplay extends Display {

    private static final String GRAPH = "graph";
    private static final String NODES = "graph.nodes";
    private static final String EDGES = "graph.edges";
    private static final String NODE_TYPE = "node_type";
    private static final String NODE_COST = "node_cost";
    private static final String NODE_STATE = "node_state";
    private static final String NODE_CONTENT = "node_content";
    private static final String EDGE_DECORATORS = "edgeDeco";
    private static final String NODE_DECORATORS = "nodeDeco";
    private static final Schema DECORATOR_SCHEMA = PrefuseLib.getVisualItemSchema();
    private static final Executor EXECUTOR = Executors.newCachedThreadPool();

    static {
        DECORATOR_SCHEMA.setDefault(VisualItem.INTERACTIVE, false);
        DECORATOR_SCHEMA.setDefault(VisualItem.TEXTCOLOR, ColorLib.gray(128));
        DECORATOR_SCHEMA.setDefault(VisualItem.FONT, FontLib.getFont("Tahoma", 7));
    }
    private final Graph g = new Graph(true);
    private final VisualGraph vg;
    private final Map<Flaw, Node> flaws = new HashMap<>();
    private final Map<Resolver, Node> resolvers = new HashMap<>();

    public CausalGraphDisplay() {
        // initialize display and data
        super(new Visualization());

        Logger.getLogger("prefuse").setLevel(Level.OFF);

        g.getNodeTable().addColumn(VisualItem.LABEL, String.class);
        g.getNodeTable().addColumn(NODE_TYPE, String.class);
        g.getNodeTable().addColumn(NODE_COST, Double.class);
        g.getNodeTable().addColumn(NODE_STATE, String.class);
        g.getNodeTable().addColumn(NODE_CONTENT, Object.class);
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
        ColorAction nFill = new DataColorAction(NODES, NODE_COST, Constants.ORDINAL, VisualItem.FILLCOLOR, ColorLib.getHotPalette());
        nFill.add(VisualItem.HOVER, ColorLib.gray(200));
        nFill.add(VisualItem.HIGHLIGHT, ColorLib.rgb(255, 230, 230));
        nFill.add(NODE_STATE + " == \"" + LBool.False + "\"", ColorLib.gray(235));

        ColorAction nStrokeColor = new ColorAction(NODES, VisualItem.STROKECOLOR);
        nStrokeColor.setDefaultColor(ColorLib.gray(100));
        nStrokeColor.add(VisualItem.HOVER, ColorLib.gray(200));

        StrokeAction nStroke = new StrokeAction(NODES, StrokeLib.getStroke(5));
        nStroke.add(NODE_STATE + " == \"" + LBool.True + "\"", StrokeLib.getStroke(0.5f));
        nStroke.add(NODE_STATE + " == \"" + LBool.False + "\"", StrokeLib.getStroke(0.1f, StrokeLib.DOTS));
        nStroke.add(NODE_STATE + " == \"" + LBool.Undefined + "\"", StrokeLib.getStroke(1, StrokeLib.DASHES));

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
        addControlListener(new ControlAdapter() {
            @Override
            public void itemEntered(VisualItem vi, MouseEvent me) {
                Display d = (Display) me.getSource();
                if (vi.getSourceTuple() instanceof Node) {
                    Node nodeData = (Node) vi.getSourceTuple();
                    Object content = nodeData.get(NODE_CONTENT);
                    switch ((String) nodeData.get(NODE_TYPE)) {
                        case "flaw":
                            d.setToolTipText("in-plan: (" + ((Flaw) content).in_plan_var + ") " + ((Flaw) content).getInPlan() + ", cost: " + ((Flaw) content).getCost());
                            break;
                        case "resolver":
                            d.setToolTipText("chosen: (" + ((Resolver) content).chosen_var + ") " + ((Resolver) content).getChosen() + ", cost: " + ((Resolver) content).getCost());
                            break;
                    }
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
                    Object content = nodeData.get(NODE_CONTENT);
                    switch ((String) nodeData.get(NODE_TYPE)) {
                        case "flaw":
                            break;
                        case "resolver":
                            break;
                    }
                }
            }
        });

        if (!Beans.isDesignTime()) {
            // set things running
            m_vis.run("layout");
        }
    }

    void clear() {
        flaws.clear();
        resolvers.clear();
        synchronized (m_vis) {
            g.clear();
        }
    }

    public void new_flaw(Flaw f) {
        assert !flaws.containsKey(f);
        synchronized (m_vis) {
            Node flaw_node = g.addNode();
            flaw_node.set(VisualItem.LABEL, f.label);
            flaw_node.set(NODE_TYPE, "flaw");
            flaw_node.set(NODE_COST, -f.cost);
            flaw_node.set(NODE_STATE, f.in_plan_val.toString());
            flaw_node.set(NODE_CONTENT, f);
            flaws.put(f, flaw_node);
        }
    }

    public void flaw_changed(Flaw f) {
        assert flaws.containsKey(f);
        synchronized (m_vis) {
            Node flaw_node = flaws.get(f);
            flaw_node.set(NODE_COST, -f.cost);
            flaw_node.set(NODE_STATE, f.in_plan_val.toString());
        }
    }

    public void new_resolver(Resolver r) {
        assert !resolvers.containsKey(r);
        assert flaws.containsKey(r.solves);
        assert r.preconditions.stream().allMatch(pre -> flaws.containsKey(pre));
        synchronized (m_vis) {
            Node resolver_node = g.addNode();
            resolver_node.set(VisualItem.LABEL, r.label);
            resolver_node.set(NODE_TYPE, "resolver");
            resolver_node.set(NODE_COST, -r.cost);
            resolver_node.set(NODE_STATE, r.chosen.toString());
            resolver_node.set(NODE_CONTENT, r);
            resolvers.put(r, resolver_node);
            g.addEdge(resolver_node, flaws.get(r.solves));
            for (Flaw pre : r.preconditions) {
                g.addEdge(flaws.get(pre), resolver_node);
            }
        }
    }

    public void resolver_changed(Resolver r) {
        assert resolvers.containsKey(r);
        synchronized (m_vis) {
            Node resolver_node = resolvers.get(r);
            resolver_node.set(NODE_COST, -r.cost);
            resolver_node.set(NODE_STATE, r.chosen.toString());
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
