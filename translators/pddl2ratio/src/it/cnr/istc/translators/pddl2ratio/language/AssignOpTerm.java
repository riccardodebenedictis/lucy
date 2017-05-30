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
package it.cnr.istc.translators.pddl2ratio.language;

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
public class AssignOpTerm implements Term {

    private final AssignOp assignOp;
    private final FunctionTerm functionTerm;
    private final Term value;

    public AssignOpTerm(AssignOp assignOp, FunctionTerm functionTerm, Term value) {
        this.assignOp = assignOp;
        this.functionTerm = functionTerm;
        this.value = value;
    }

    public AssignOp getAssignOp() {
        return assignOp;
    }

    public FunctionTerm getFunctionTerm() {
        return functionTerm;
    }

    public Term getValue() {
        return value;
    }

    @Override
    public Term negate() {
        throw new AssertionError("It is not possible to call negate on an assignment term..");
    }

    @Override
    public boolean updatesPredicate(Predicate predicate) {
        return false;
    }

    @Override
    public boolean updatesFunction(Function function) {
        return functionTerm.updatesFunction(function) || value.updatesFunction(function);
    }

    @Override
    public String toString() {
        switch (assignOp) {
            case Assign:
                return "(assign " + functionTerm + " " + value + ")";
            case ScaleUp:
                return "(scale-up " + functionTerm + " " + value + ")";
            case ScaleDown:
                return "(scale-down " + functionTerm + " " + value + ")";
            case Increase:
                return "(increase " + functionTerm + " " + value + ")";
            case Decrease:
                return "(decrease " + functionTerm + " " + value + ")";
            default:
                throw new AssertionError(assignOp.name());
        }
    }

    public enum AssignOp {
        Assign, ScaleUp, ScaleDown, Increase, Decrease
    }
}
