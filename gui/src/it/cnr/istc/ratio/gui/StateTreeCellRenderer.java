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

import java.awt.Component;
import java.text.DecimalFormat;
import javax.swing.ImageIcon;
import javax.swing.JTree;
import javax.swing.tree.DefaultTreeCellRenderer;

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
public class StateTreeCellRenderer extends DefaultTreeCellRenderer {

    private static final ImageIcon OBJECT_ICON = new ImageIcon(StateTreeCellRenderer.class.getResource("resources/object.png"));
    private static final ImageIcon ACTIVE_FORMULA_ICON = new ImageIcon(StateTreeCellRenderer.class.getResource("resources/active_formula.png"));
    private static final ImageIcon INACTIVE_FORMULA_ICON = new ImageIcon(StateTreeCellRenderer.class.getResource("resources/inactive_formula.png"));
    private static final ImageIcon UNIFIED_FORMULA_ICON = new ImageIcon(StateTreeCellRenderer.class.getResource("resources/unified_formula.png"));
    private static final ImageIcon ENUM_ICON = new ImageIcon(StateTreeCellRenderer.class.getResource("resources/enum.png"));
    private static final ImageIcon BOOL_ICON = new ImageIcon(StateTreeCellRenderer.class.getResource("resources/bool.png"));
    private static final ImageIcon NUMBER_ICON = new ImageIcon(StateTreeCellRenderer.class.getResource("resources/number.png"));
    private static final ImageIcon STRING_ICON = new ImageIcon(StateTreeCellRenderer.class.getResource("resources/enum.png"));

    @Override
    public Component getTreeCellRendererComponent(JTree tree, Object value, boolean sel, boolean expanded, boolean leaf, int row, boolean hasFocus) {
        super.getTreeCellRendererComponent(tree, value, sel, expanded, leaf, row, hasFocus);
        if (value instanceof StateTreeModel.ItemNode) {
            Item item = (Item) ((StateTreeModel.ItemNode) value).getUserObject();
            if (item instanceof BoolItem) {
                setIcon(BOOL_ICON);
                setText(((StateTreeModel.ItemNode) value).name + " = " + ((BoolItem) item).val);
                setToolTipText(((BoolItem) item).lit + " = " + ((BoolItem) item).val);
            } else if (item instanceof ArithItem) {
                setIcon(NUMBER_ICON);
                setText(((StateTreeModel.ItemNode) value).name + " = " + new DecimalFormat("#0.##").format(((ArithItem) item).val));
                setToolTipText(((ArithItem) item).lin + " = " + ((ArithItem) item).val + " [" + ((ArithItem) item).lb + ", " + ((ArithItem) item).ub + "]");
            } else if (item instanceof EnumItem) {
                setIcon(ENUM_ICON);
                setText(((StateTreeModel.ItemNode) value).name);
                setToolTipText(((EnumItem) item).type);
            } else {
                setIcon(OBJECT_ICON);
                setText(((StateTreeModel.ItemNode) value).name);
                setToolTipText(item.type);
            }
        } else if (value instanceof StateTreeModel.AtomNode) {
            Atom atom = (Atom) ((StateTreeModel.AtomNode) value).getUserObject();
            if (atom.state.size() == 1) {
                switch (atom.state.iterator().next()) {
                    case Active:
                        setIcon(ACTIVE_FORMULA_ICON);
                        break;
                    case Inactive:
                        setIcon(INACTIVE_FORMULA_ICON);
                        break;
                    case Unified:
                        setIcon(UNIFIED_FORMULA_ICON);
                        break;
                    default:
                        throw new AssertionError(atom.state.iterator().next().name());
                }
            } else {
                setIcon(INACTIVE_FORMULA_ICON);
            }
            setText(atom.type);
            setToolTipText(atom.type);
        }
        return this;
    }
}
