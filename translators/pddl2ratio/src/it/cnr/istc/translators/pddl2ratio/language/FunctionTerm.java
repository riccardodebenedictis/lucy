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
public class FunctionTerm implements Term {

    private final Function function;
    private final List<Term> arguments;

    public FunctionTerm(Function function, Term... arguments) {
        assert function != null;
        assert Stream.of(arguments).noneMatch(Objects::isNull);
        this.function = function;
        this.arguments = Arrays.asList(arguments);
    }

    public Function getFunction() {
        return function;
    }

    public List<Term> getArguments() {
        return Collections.unmodifiableList(arguments);
    }

    @Override
    public Term negate() {
        throw new AssertionError("It is not possible to call negate on a function..");
    }

    @Override
    public boolean updatesPredicate(Predicate predicate) {
        return false;
    }

    @Override
    public boolean updatesFunction(Function function) {
        return this.function == function;
    }

    @Override
    public String toString() {
        return "(" + function.getName() + " " + arguments.stream().map(argument -> argument.toString()).collect(Collectors.joining(" ")) + ")";
    }
}
