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
import it.cnr.istc.translators.pddl2ratio.language.OrTerm;
import it.cnr.istc.translators.pddl2ratio.language.OverAllTerm;
import it.cnr.istc.translators.pddl2ratio.language.PredicateTerm;
import it.cnr.istc.translators.pddl2ratio.language.Term;
import it.cnr.istc.translators.pddl2ratio.language.VariableTerm;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.stream.Collectors;
import org.stringtemplate.v4.AttributeRenderer;
import org.stringtemplate.v4.STGroupFile;

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
class TermRenderer implements AttributeRenderer {

    private final STGroupFile file;
    private final Domain domain;

    TermRenderer(STGroupFile file, Domain domain) {
        this.file = file;
        this.domain = domain;
    }

    @Override
    public String toString(Object o, String formatString, Locale locale) {
        Term term = (Term) o;
        StringBuilder sb = new StringBuilder();
        if (term instanceof AndTerm) {
            AndTerm and = (AndTerm) term;
            sb.append(and.getTerms().stream()
                    .map(t -> toString(t, formatString, locale))
                    .collect(Collectors.joining("\n")));
        } else if (term instanceof OrTerm) {
            OrTerm or = (OrTerm) term;
            if (or.getTerms().size() > 1) {
                sb.append("{\n").append(or.getTerms().stream()
                        .map(t -> "   " + toString(t, formatString, locale))
                        .collect(Collectors.joining("\n} or {\n"))).append("\n}");
            } else {
                sb.append(or.getTerms().stream()
                        .map(t -> toString(t, formatString, locale))
                        .collect(Collectors.joining()));
            }
        } else if (term instanceof AtStartTerm) {
            switch (formatString) {
                case "condition":
                    sb.append(toString(((AtStartTerm) term).getTerm(), "at-start-condition", locale));
                    break;
                case "effect":
                    sb.append(toString(((AtStartTerm) term).getTerm(), "at-start-effect", locale));
                    break;
                default:
                    throw new AssertionError(formatString);
            }
        } else if (term instanceof AtEndTerm) {
            switch (formatString) {
                case "condition":
                    sb.append(toString(((AtStartTerm) term).getTerm(), "at-end-condition", locale));
                    break;
                case "effect":
                    sb.append(toString(((AtStartTerm) term).getTerm(), "at-end-effect", locale));
                    break;
                default:
                    throw new AssertionError(formatString);
            }
        } else if (term instanceof OverAllTerm) {
            sb.append(toString(((AtStartTerm) term).getTerm(), "over-all-condition", locale));
        } else if (term instanceof PredicateTerm) {
            PredicateTerm predicate = (PredicateTerm) term;
            String formula_name = (predicate.isDirected() ? "" : "not_") + Utils.lowercase(predicate.getPredicate().getName());
            String predicate_name = Utils.capitalize(predicate.getPredicate().getName());
            List<String> assignments = new ArrayList<>(predicate.getArguments().size());
            assignments.add("polarity" + ":" + predicate.isDirected());
            for (int i = 0; i < predicate.getArguments().size(); i++) {
                if (predicate.getArguments().get(i) instanceof VariableTerm) {
                    assignments.add(predicate.getPredicate().getVariables().get(i).getName() + ":" + ((VariableTerm) predicate.getArguments().get(i)).getVariable().getName());
                    formula_name += "_" + ((VariableTerm) predicate.getArguments().get(i)).getVariable().getName();
                } else if (predicate.getArguments().get(i) instanceof ConstantTerm) {
                    assignments.add(predicate.getPredicate().getVariables().get(i).getName() + ":" + ((ConstantTerm) predicate.getArguments().get(i)).getConstant().getName());
                    formula_name += "_" + ((ConstantTerm) predicate.getArguments().get(i)).getConstant().getName();
                } else {
                    throw new UnsupportedOperationException(predicate.getArguments().get(i).getClass().getSimpleName());
                }
            }
            switch (formatString) {
                case "precondition":
                    sb.append("goal ").append(formula_name).append(" = new propositional_state.").append(predicate_name).append("(").append(assignments.stream().collect(Collectors.joining(", "))).append(");");
                    sb.append("  ").append(formula_name).append(".start <= at - 1.0;");
                    sb.append("  ").append(formula_name).append(".end >= at;");
                    break;
                case "effect":
                    assignments.add("start:at");
                    sb.append("fact ").append(formula_name).append(" = new propositional_state.").append(predicate_name).append("(").append(assignments.stream().collect(Collectors.joining(", "))).append(");");
                    sb.append("  ").append(formula_name).append(".duration >= 1.0;");
                    break;
                case "at-start-condition":
                    sb.append("goal ").append(formula_name).append(" = new propositional_state.").append(predicate_name).append("(").append(assignments.stream().collect(Collectors.joining(", "))).append(");");
                    sb.append("  ").append(formula_name).append(".start <= start - 1.0;");
                    sb.append("  ").append(formula_name).append(".end >= start;");
                    break;
                case "over-all-condition":
                    sb.append("goal ").append(formula_name).append(" = new propositional_state.").append(predicate_name).append("(").append(assignments.stream().collect(Collectors.joining(", "))).append(");");
                    sb.append("  ").append(formula_name).append(".start <= start;");
                    sb.append("  ").append(formula_name).append(".end >= end;");
                    break;
                case "at-end-condition":
                    sb.append("goal ").append(formula_name).append(" = new propositional_state.").append(predicate_name).append("(").append(assignments.stream().collect(Collectors.joining(", "))).append(");");
                    sb.append("  ").append(formula_name).append(".start <= end - 1.0;");
                    sb.append("  ").append(formula_name).append(".end >= end;");
                    break;
                case "at-start-effect":
                    assignments.add("start:start");
                    sb.append("fact ").append(formula_name).append(" = new propositional_state.").append(predicate_name).append("(").append(assignments.stream().collect(Collectors.joining(", "))).append(");");
                    sb.append("  ").append(formula_name).append(".duration >= 1.0;");
                    break;
                case "at-end-effect":
                    assignments.add("start:end");
                    sb.append("fact ").append(formula_name).append(" = new propositional_state.").append(predicate_name).append("(").append(assignments.stream().collect(Collectors.joining(", "))).append(");");
                    sb.append("  ").append(formula_name).append(".duration >= 1.0;");
                    break;
                case "init":
                    assignments.add("start:origin");
                    sb.append("fact ").append(formula_name).append(" = new agent.propositional_state.").append(predicate_name).append("(").append(assignments.stream().collect(Collectors.joining(", "))).append(");");
                    sb.append("  ").append(formula_name).append(".duration >= 1.0;");
                    break;
                case "goal":
                    assignments.add("end:horizon");
                    sb.append("goal ").append(formula_name).append(" = new agent.propositional_state.").append(predicate_name).append("(").append(assignments.stream().collect(Collectors.joining(", "))).append(");");
                    break;
                default:
                    throw new UnsupportedOperationException(formatString);
            }
        } else {
            sb.append("// ").append(formatString).append(" ").append(term.getClass().getSimpleName()).append(" ").append(term.toString()).append("\n");
        }
        return sb.toString();
    }
}
