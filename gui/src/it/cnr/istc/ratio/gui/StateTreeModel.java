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

import java.util.Map;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
public class StateTreeModel extends DefaultTreeModel {

    public StateTreeModel() {
        super(new DefaultMutableTreeNode());
    }

    void setRoot(State state) {
        StateNode state_node = new StateNode(state);
        setRoot(state_node);
        createChilds(state_node);
        fireTreeNodesChanged(this, null, null, null);
    }

    void createChilds(DefaultMutableTreeNode tree_node) {
        tree_node.removeAllChildren();
        if (tree_node instanceof StateNode) {
            State state = (State) ((StateNode) tree_node).getUserObject();
            for (Map.Entry<String, Item> entry : state.items.entrySet()) {
                tree_node.add(new ItemNode(entry.getKey(), entry.getValue()));
            }
            for (Atom atom : state.atoms) {
                tree_node.add(new AtomNode(atom));
            }
        } else if (tree_node instanceof ItemNode) {
            Item item = (Item) ((ItemNode) tree_node).getUserObject();
            if (item instanceof EnumItem) {
                for (Item value : ((EnumItem) item).values) {
                    tree_node.add(new ItemNode("", value));
                }
            } else {
                for (Map.Entry<String, Item> entry : item.items.entrySet()) {
                    tree_node.add(new ItemNode(entry.getKey(), entry.getValue()));
                }
            }
        } else if (tree_node instanceof AtomNode) {
            Atom atom = (Atom) ((AtomNode) tree_node).getUserObject();
            for (Map.Entry<String, Item> entry : atom.items.entrySet()) {
                tree_node.add(new ItemNode(entry.getKey(), entry.getValue()));
            }
        }
        int[] child_indices = new int[tree_node.getChildCount()];
        Object[] children = new Object[tree_node.getChildCount()];
        for (int i = 0; i < child_indices.length; i++) {
            child_indices[i] = i;
            children[i] = tree_node.getChildAt(i);
        }
        fireTreeStructureChanged(this, tree_node.getPath(), child_indices, children);
    }

    static class StateNode extends DefaultMutableTreeNode {

        public StateNode(State state) {
            super(state, !state.items.isEmpty() || !state.atoms.isEmpty());
        }

        @Override
        public boolean isLeaf() {
            return !getAllowsChildren();
        }
    }

    static class ItemNode extends DefaultMutableTreeNode {

        final String name;

        public ItemNode(String name, Item item) {
            super(item, !item.items.isEmpty() || (item instanceof EnumItem));
            this.name = name;
        }

        @Override
        public boolean isLeaf() {
            return !getAllowsChildren();
        }
    }

    static class AtomNode extends DefaultMutableTreeNode {

        public AtomNode(Atom atom) {
            super(atom, !atom.items.isEmpty());
        }

        @Override
        public boolean isLeaf() {
            return !getAllowsChildren();
        }
    }
}
