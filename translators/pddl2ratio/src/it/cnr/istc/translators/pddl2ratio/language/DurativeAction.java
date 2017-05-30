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
public class DurativeAction {

    private final String name;
    private final List<Variable> variables;
    private Term duration;
    private Term condition;
    private Term effect;

    public DurativeAction(String name, Variable... variables) {
        assert Stream.of(variables).noneMatch(Objects::isNull);
        this.name = name;
        this.variables = Arrays.asList(variables);
    }

    public String getName() {
        return name;
    }

    public List<Variable> getVariables() {
        return Collections.unmodifiableList(variables);
    }

    public Term getDuration() {
        return duration;
    }

    public void setDuration(Term duration) {
        assert duration != null;
        this.duration = duration;
    }

    public Term getCondition() {
        return condition;
    }

    public void setCondition(Term condition) {
        assert condition != null;
        this.condition = condition;
    }

    public Term getEffect() {
        return effect;
    }

    public void setEffect(Term effect) {
        assert effect != null;
        this.effect = effect;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("(durative-action ").append(name).append("( ").append(variables.stream().map(variable -> variable.getName() + " - " + variable.getType().getName()).collect(Collectors.joining(" "))).append(")\n");
        if (duration != null) {
            sb.append("(:duration ").append(duration.toString()).append(")\n");
        }
        if (condition != null) {
            sb.append("(:condition ").append(condition.toString()).append(")\n");
        }
        if (effect != null) {
            sb.append("(:effect ").append(effect.toString()).append(")\n");
        }
        sb.append(")");
        return sb.toString();
    }
}
