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
import java.util.Collections;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
public class OrTerm implements Term {

    private final List<Term> terms;

    public OrTerm(Term... terms) {
        assert Stream.of(terms).noneMatch(Objects::isNull);
        this.terms = Arrays.asList(terms);
    }

    public List<Term> getTerms() {
        return Collections.unmodifiableList(terms);
    }

    @Override
    public Term negate() {
        return new AndTerm(terms.stream().map(term -> term.negate()).toArray(Term[]::new));
    }

    @Override
    public boolean updatesPredicate(Predicate predicate) {
        return terms.stream().anyMatch(term -> term.updatesPredicate(predicate));
    }

    @Override
    public boolean updatesFunction(Function function) {
        return terms.stream().anyMatch(term -> term.updatesFunction(function));
    }

    @Override
    public String toString() {
        return "(or " + terms.stream().map(term -> term.toString()).collect(Collectors.joining(" ")) + ")";
    }
}
