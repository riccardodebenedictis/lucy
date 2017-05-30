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

import it.cnr.istc.translators.pddl2ratio.language.AndTerm;
import it.cnr.istc.translators.pddl2ratio.language.AtEndTerm;
import it.cnr.istc.translators.pddl2ratio.language.AtStartTerm;
import it.cnr.istc.translators.pddl2ratio.language.ConstantTerm;
import it.cnr.istc.translators.pddl2ratio.language.Domain;
import it.cnr.istc.translators.pddl2ratio.language.Predicate;
import it.cnr.istc.translators.pddl2ratio.language.PredicateTerm;
import it.cnr.istc.translators.pddl2ratio.language.Term;
import it.cnr.istc.translators.pddl2ratio.language.VariableTerm;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.stream.Collectors;
import org.stringtemplate.v4.AttributeRenderer;
import org.stringtemplate.v4.STGroupFile;

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
class PredicateRenderer implements AttributeRenderer {

    private final STGroupFile file;
    private final Domain domain;

    PredicateRenderer(STGroupFile file, Domain domain) {
        this.file = file;
        this.domain = domain;
    }

    @Override
    public String toString(Object o, String formatString, Locale locale) {
        Predicate predicate = (Predicate) o;
        Collection<String> conjunctions = new ArrayList<>();

        domain.getActions().values().stream().filter(action -> action.getEffect() != null && action.getEffect().updatesPredicate(predicate)).forEach(action -> {
            String formula_name = Utils.lowercase(action.getName());
            String predicate_name = Utils.capitalize(action.getName());
            conjunctions.addAll(getActions(predicate, formula_name, predicate_name, "at", action.getEffect()));
        });
        domain.getDurativeActions().values().stream().filter(action -> action.getEffect() != null && action.getEffect().updatesPredicate(predicate)).forEach(action -> {
            String formula_name = Utils.lowercase(action.getName());
            String predicate_name = Utils.capitalize(action.getName());
            conjunctions.addAll(getActions(predicate, formula_name, predicate_name, null, action.getEffect()));
        });

        StringBuilder sb = new StringBuilder();
        if (conjunctions.size() > 1) {
            sb.append("{\n").append(conjunctions.stream()
                    .map(c -> "   " + c)
                    .collect(Collectors.joining("\n} or {\n"))).append("\n}");
        } else {
            sb.append(conjunctions.stream()
                    .collect(Collectors.joining()));
        }
        return sb.toString();
    }

    private Collection<String> getActions(Predicate predicate, String formula_name, String predicate_name, String time_specifier, Term term) {
        if (term instanceof PredicateTerm) {
            PredicateTerm pt = (PredicateTerm) term;
            if (pt.getPredicate() == predicate && (pt.isDirected() || domain.getRequirements().contains(":negative-preconditions"))) {
                // We map from the action schema to the predicate schema..
                Map<String, String> args = new HashMap<>();
                for (int i = 0; i < pt.getArguments().size(); i++) {
                    if (pt.getArguments().get(i) instanceof VariableTerm) {
                        args.put(pt.getPredicate().getVariables().get(i).getName(), ((VariableTerm) pt.getArguments().get(i)).getVariable().getName());
                    } else if (pt.getArguments().get(i) instanceof ConstantTerm) {
                        args.put(pt.getPredicate().getVariables().get(i).getName(), ((ConstantTerm) pt.getArguments().get(i)).getConstant().getName());
                    } else {
                        throw new AssertionError(pt.getArguments().get(i).getClass().getSimpleName());
                    }
                }

                StringBuilder sb = new StringBuilder();
                List<String> assignments = new ArrayList<>(pt.getArguments().size() + 1);
                assignments.add(time_specifier + ":start");
                predicate.getVariables().forEach(v -> {
                    assignments.add(args.get(v.getName()) + ":" + v.getName());
                });
                sb.append("goal ").append(formula_name).append(" = new agent.").append(predicate_name).append("(").append(assignments.stream().collect(Collectors.joining(", "))).append(");");
                if (domain.getRequirements().contains(":negative-preconditions")) {
                    sb.append("  ").append("polarity").append(" == ").append(pt.isDirected()).append(";");
                }
                return Arrays.asList(sb.toString());
            }
        } else if (term instanceof AtStartTerm) {
            return getActions(predicate, formula_name, predicate_name, "start", ((AtStartTerm) term).getTerm());
        } else if (term instanceof AtEndTerm) {
            return getActions(predicate, formula_name, predicate_name, "end", ((AtEndTerm) term).getTerm());
        } else if (term instanceof AndTerm) {
            return ((AndTerm) term).getTerms().stream().flatMap(t -> getActions(predicate, formula_name, predicate_name, time_specifier, t).stream()).collect(Collectors.toList());
        }
        return Collections.emptyList();
    }
}
