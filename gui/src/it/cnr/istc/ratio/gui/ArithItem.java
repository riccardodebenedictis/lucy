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

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
public class ArithItem extends Item {

    public final String lin;
    public final double val, lb, ub;

    ArithItem(String type, String lin, double val, double lb, double ub) {
        super(type);
        this.lin = lin;
        this.val = val;
        this.lb = lb;
        this.ub = ub;
    }

    @Override
    public String toString() {
        return "ArithItem{" + "lin=" + lin + ", val=" + val + ", lb=" + lb + ", ub=" + ub + '}';
    }
}
