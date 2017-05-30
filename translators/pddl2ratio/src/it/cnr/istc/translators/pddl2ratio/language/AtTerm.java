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

import java.math.BigDecimal;

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
public class AtTerm implements Term {

    private final BigDecimal at;
    private final PredicateTerm predicateTerm;

    public AtTerm(BigDecimal at, PredicateTerm predicateTerm) {
        assert at != null;
        assert predicateTerm != null;
        this.at = at;
        this.predicateTerm = predicateTerm;
    }

    @Override
    public Term negate() {
        throw new AssertionError("It is not possible to call negate on an at term..");
    }

    @Override
    public boolean updatesPredicate(Predicate predicate) {
        return predicateTerm.updatesPredicate(predicate);
    }

    @Override
    public boolean updatesFunction(Function function) {
        return false;
    }

    @Override
    public String toString() {
        return "(at " + at + " " + predicateTerm + ")";
    }
}
