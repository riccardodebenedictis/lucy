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
package it.cnr.istc.translators.pddl2ratio.parser;

import it.cnr.istc.translators.pddl2ratio.language.Domain;
import it.cnr.istc.translators.pddl2ratio.language.EitherType;
import it.cnr.istc.translators.pddl2ratio.language.Type;
import it.cnr.istc.translators.pddl2ratio.language.Variable;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
class TypedListVariableListener extends PDDLBaseListener {

    private final Domain domain;
    final List<Variable> variables = new ArrayList<>();

    TypedListVariableListener(Domain domain) {
        this.domain = domain;
    }

    @Override
    public void enterTyped_list_variable(PDDLParser.Typed_list_variableContext ctx) {
        Type type = null;
        if (ctx.type() == null) {
            type = Type.OBJECT;
        } else if (ctx.type().primitive_type().size() == 1) {
            type = ctx.type().primitive_type(0).name() == null ? Type.OBJECT : domain.getType(Utils.capitalize(ctx.type().primitive_type(0).name().getText()));
        } else {
            type = new EitherType(ctx.type().primitive_type().stream().map(primitive_type -> primitive_type.name() == null ? Type.OBJECT : domain.getType(Utils.capitalize(primitive_type.name().getText()))).collect(Collectors.toList()));
            if (!domain.getTypes().containsKey(type.getName())) {
                domain.addType(type);
            }
        }

        assert type != null : "Cannot find type " + ctx.type().primitive_type(0).name().getText();
        Type c_type = type;
        ctx.variable().stream().forEach(variable -> {
            variables.add(new Variable("?" + Utils.lowercase(variable.name().getText()), c_type));
        });
    }
}
