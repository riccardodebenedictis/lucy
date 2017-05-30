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
public class ComparisonTerm implements Term {

    private final Comp comp;
    private final Term firstTerm, secondTerm;

    public ComparisonTerm(Comp comp, Term firstTerm, Term secondTerm) {
        assert comp != null;
        assert firstTerm != null;
        assert secondTerm != null;
        this.comp = comp;
        this.firstTerm = firstTerm;
        this.secondTerm = secondTerm;
    }

    @Override
    public Term negate() {
        switch (comp) {
            case Gt:
                return new ComparisonTerm(Comp.LEq, firstTerm, secondTerm);
            case Lt:
                return new ComparisonTerm(Comp.GEq, firstTerm, secondTerm);
            case Eq:
                return new OrTerm(firstTerm.negate(), secondTerm);
            case GEq:
                return new ComparisonTerm(Comp.Lt, firstTerm, secondTerm);
            case LEq:
                return new ComparisonTerm(Comp.Gt, firstTerm, secondTerm);
            default:
                throw new AssertionError(comp.name());
        }
    }

    @Override
    public boolean updatesPredicate(Predicate predicate) {
        return firstTerm.updatesPredicate(predicate) || secondTerm.updatesPredicate(predicate);
    }

    @Override
    public boolean updatesFunction(Function function) {
        return firstTerm.updatesFunction(function) || secondTerm.updatesFunction(function);
    }

    @Override
    public String toString() {
        switch (comp) {
            case Gt:
                return "(> " + firstTerm + " " + secondTerm + ")";
            case Lt:
                return "(< " + firstTerm + " " + secondTerm + ")";
            case Eq:
                return "(= " + firstTerm + " " + secondTerm + ")";
            case GEq:
                return "(>= " + firstTerm + " " + secondTerm + ")";
            case LEq:
                return "(<= " + firstTerm + " " + secondTerm + ")";
            default:
                throw new AssertionError(comp.name());
        }
    }

    public enum Comp {
        Gt, Lt, Eq, GEq, LEq;
    }
}
