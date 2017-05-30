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

import java.util.Collection;
import java.util.List;
import java.util.stream.Collectors;

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
public class EitherType extends Type {

    private final List<Type> types;

    public EitherType(List<Type> types) {
        super("Either" + types.stream().map(type -> type.getName()).collect(Collectors.joining()));
        this.types = types;
    }

    @Override
    public Collection<Constant> getInstances() {
        return types.stream().flatMap(type -> type.getInstances().stream()).distinct().collect(Collectors.toList());
    }

    @Override
    public String toString() {
        return "(either " + types.stream().map(type -> type.getName()).collect(Collectors.joining(" ")) + ")";
    }
}
