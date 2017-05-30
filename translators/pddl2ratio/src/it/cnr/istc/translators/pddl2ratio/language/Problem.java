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

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
public class Problem {

    private final Domain domain;
    private final String name;
    private final Set<String> requirements;
    private final Map<String, Constant> objects = new LinkedHashMap<>();
    private final List<Term> init_els = new ArrayList<>();
    private Term goal;

    public Problem(Domain domain, String name, Set<String> requirements) {
        this.domain = domain;
        this.name = name;
        this.requirements = requirements;
    }

    public Domain getDomain() {
        return domain;
    }

    public String getName() {
        return name;
    }

    public Set<String> getRequirements() {
        return Collections.unmodifiableSet(requirements);
    }

    public Constant getObject(String name) {
        return objects.get(name);
    }

    public Map<String, Constant> getObjects() {
        return Collections.unmodifiableMap(objects);
    }

    public void addObject(Constant object) {
        objects.put(object.getName(), object);
    }

    public List<Term> getInitEls() {
        return Collections.unmodifiableList(init_els);
    }

    public void addInitEl(Term init_el) {
        init_els.add(init_el);
    }

    public Term getGoal() {
        return goal;
    }

    public void setGoal(Term goal) {
        this.goal = goal;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("(define (problem ").append(name).append(")\n");

        sb.append("(:domain ").append(domain.getName()).append(")\n");

        sb.append("(:objects ").append(objects.values().stream().map(object -> object.getName() + " - " + object.getType().getName()).collect(Collectors.joining(" "))).append(")\n");

        sb.append("(:init ").append(init_els.stream().map(init_el -> init_el.toString()).collect(Collectors.joining(" "))).append(")\n");

        sb.append("(:goal ").append(goal).append(")\n");

        sb.append(")\n");
        return sb.toString();
    }
}
