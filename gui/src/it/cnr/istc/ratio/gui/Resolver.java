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

import java.util.Collection;
import java.util.Collections;

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
public class Resolver {

    public final String label;
    public final String chosen_var;
    double cost = Double.POSITIVE_INFINITY;
    LBool chosen = LBool.Undefined;
    final Flaw solves;
    final Collection<Flaw> preconditions;

    Resolver(String label, String chosen_var, Flaw solves, Collection<Flaw> preconditions) {
        this.label = label;
        this.chosen_var = chosen_var;
        this.solves = solves;
        this.preconditions = preconditions;
    }

    public double getCost() {
        return cost;
    }

    public LBool getChosen() {
        return chosen;
    }

    public Flaw getSolves() {
        return solves;
    }

    public Collection<Flaw> getPreconditions() {
        return Collections.unmodifiableCollection(preconditions);
    }
}
