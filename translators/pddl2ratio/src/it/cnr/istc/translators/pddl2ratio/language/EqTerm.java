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
public class EqTerm implements Term {

    private final boolean directed;
    private final Term firstTerm, secondTerm;

    public EqTerm(boolean directed, Term firstTerm, Term secondTerm) {
        assert firstTerm != null;
        assert secondTerm != null;
        this.directed = directed;
        this.firstTerm = firstTerm;
        this.secondTerm = secondTerm;
    }

    public boolean isDirected() {
        return directed;
    }

    public Term getFirstTerm() {
        return firstTerm;
    }

    public Term getSecondTerm() {
        return secondTerm;
    }

    @Override
    public Term negate() {
        return new EqTerm(!directed, firstTerm, secondTerm);
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
        if (directed) {
            return "(= " + firstTerm + " " + secondTerm + ")";
        } else {
            return "(not (= " + firstTerm + " " + secondTerm + "))";
        }
    }
}
