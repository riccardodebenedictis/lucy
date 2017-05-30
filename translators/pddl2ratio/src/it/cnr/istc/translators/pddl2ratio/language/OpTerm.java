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

import java.util.Arrays;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
public class OpTerm implements Term {

    private final Op op;
    private final List<Term> terms;

    public OpTerm(Op op, Term... terms) {
        assert op != null;
        assert Stream.of(terms).noneMatch(Objects::isNull);
        this.op = op;
        this.terms = Arrays.asList(terms);
    }

    @Override
    public Term negate() {
        return new MinusTerm(new OpTerm(op, terms.stream().toArray(Term[]::new)));
    }

    @Override
    public boolean updatesPredicate(Predicate predicate) {
        return false;
    }

    @Override
    public boolean updatesFunction(Function function) {
        return terms.stream().anyMatch(term -> term.updatesFunction(function));
    }

    @Override
    public String toString() {
        switch (op) {
            case Add:
                return "(+ " + terms.stream().map(term -> term.toString()).collect(Collectors.joining(" ")) + ")";
            case Sub:
                return "(- " + terms.stream().map(term -> term.toString()).collect(Collectors.joining(" ")) + ")";
            case Mul:
                return "(* " + terms.stream().map(term -> term.toString()).collect(Collectors.joining(" ")) + ")";
            case Div:
                return "(/ " + terms.stream().map(term -> term.toString()).collect(Collectors.joining(" ")) + ")";
            default:
                throw new AssertionError(op.name());
        }
    }

    public enum Op {
        Add, Sub, Mul, Div
    }
}
