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

import it.cnr.istc.translators.pddl2ratio.language.Action;
import it.cnr.istc.translators.pddl2ratio.language.Domain;
import it.cnr.istc.translators.pddl2ratio.language.DurativeAction;
import it.cnr.istc.translators.pddl2ratio.language.EitherType;
import it.cnr.istc.translators.pddl2ratio.language.Function;
import it.cnr.istc.translators.pddl2ratio.language.Predicate;
import it.cnr.istc.translators.pddl2ratio.language.Problem;
import it.cnr.istc.translators.pddl2ratio.language.Term;
import it.cnr.istc.translators.pddl2ratio.language.Type;
import it.cnr.istc.translators.pddl2ratio.language.Variable;
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.util.BitSet;
import java.util.Collections;
import java.util.Set;
import java.util.logging.Logger;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import org.antlr.v4.runtime.ANTLRErrorListener;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.Parser;
import org.antlr.v4.runtime.RecognitionException;
import org.antlr.v4.runtime.Recognizer;
import org.antlr.v4.runtime.atn.ATNConfigSet;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.tree.ParseTreeWalker;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroupFile;

/**
 *
 * @author Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 */
public class Translator {

    private static final Logger LOG = Logger.getLogger(Translator.class.getName());
    private static final ParseTreeWalker WALKER = new ParseTreeWalker();

    public static PDDLInstance parse(File pddl_domain, File pddl_problem) throws IOException {
        // We get the requirements
        Set<String> domain_requirements = PDDLRequirements.getRequirements(pddl_domain);
        Set<String> problem_requirements = PDDLRequirements.getRequirements(pddl_problem);
        problem_requirements.addAll(domain_requirements);

        // we create the domain parser..
        PDDLLexer domain_lexer = new PDDLLexer(CharStreams.fromString(new String(Files.readAllBytes(pddl_domain.toPath())).toLowerCase()));
        domain_lexer.requirements.addAll(domain_requirements);
        PDDLParser domain_parser = new PDDLParser(new CommonTokenStream(domain_lexer));
        domain_parser.requirements.addAll(domain_requirements);
        domain_parser.addErrorListener(new ANTLRErrorListener() {
            @Override
            public void syntaxError(Recognizer<?, ?> recognizer, Object offendingSymbol, int line, int charPositionInLine, String msg, RecognitionException e) {
                LOG.severe(msg);
            }

            @Override
            public void reportAmbiguity(Parser recognizer, DFA dfa, int startIndex, int stopIndex, boolean exact, BitSet ambigAlts, ATNConfigSet configs) {
            }

            @Override
            public void reportAttemptingFullContext(Parser recognizer, DFA dfa, int startIndex, int stopIndex, BitSet conflictingAlts, ATNConfigSet configs) {
            }

            @Override
            public void reportContextSensitivity(Parser recognizer, DFA dfa, int startIndex, int stopIndex, int prediction, ATNConfigSet configs) {
            }
        });

        // we create the problem parser..
        PDDLLexer problem_lexer = new PDDLLexer(CharStreams.fromString(new String(Files.readAllBytes(pddl_problem.toPath())).toLowerCase()));
        problem_lexer.requirements.addAll(problem_requirements);
        PDDLParser problem_parser = new PDDLParser(new CommonTokenStream(problem_lexer));
        problem_parser.requirements.addAll(problem_requirements);
        problem_parser.addErrorListener(new ANTLRErrorListener() {
            @Override
            public void syntaxError(Recognizer<?, ?> recognizer, Object offendingSymbol, int line, int charPositionInLine, String msg, RecognitionException e) {
                LOG.severe(msg);
            }

            @Override
            public void reportAmbiguity(Parser recognizer, DFA dfa, int startIndex, int stopIndex, boolean exact, BitSet ambigAlts, ATNConfigSet configs) {
            }

            @Override
            public void reportAttemptingFullContext(Parser recognizer, DFA dfa, int startIndex, int stopIndex, BitSet conflictingAlts, ATNConfigSet configs) {
            }

            @Override
            public void reportContextSensitivity(Parser recognizer, DFA dfa, int startIndex, int stopIndex, int prediction, ATNConfigSet configs) {
            }
        });

        // We parse the domain..
        PDDLParser.DomainContext domain_context = domain_parser.domain();

        // We parse the problem..
        PDDLParser.ProblemContext problem_context = problem_parser.problem();

        Domain domain = new Domain(Utils.capitalize(domain_context.name().NAME().getSymbol().getText()), domain_requirements);
        Problem problem = new Problem(domain, Utils.capitalize(problem_context.name(1).NAME().getSymbol().getText()), problem_requirements);

        if (domain_context.types_def() != null) {
            /**
             * We define all the types of the domain..
             */
            ParseTreeWalker.DEFAULT.walk(new PDDLBaseListener() {
                @Override
                public void enterTyped_list_name(PDDLParser.Typed_list_nameContext ctx) {
                    Type c_superclass = null;
                    if (ctx.type() == null) {
                        c_superclass = Type.OBJECT;
                    } else if (ctx.type().primitive_type().size() == 1) {
                        c_superclass = ctx.type().primitive_type(0).name() == null ? Type.OBJECT : domain.getType(Utils.capitalize(ctx.type().primitive_type(0).name().getText()));
                        if (c_superclass == null) {
                            c_superclass = new Type(Utils.capitalize(ctx.type().primitive_type(0).name().getText()));
                            domain.addType(c_superclass);
                        }
                    } else {
                        c_superclass = new EitherType(ctx.type().primitive_type().stream().map(primitive_type -> primitive_type.name() == null ? Type.OBJECT : domain.getType(Utils.capitalize(primitive_type.name().getText()))).collect(Collectors.toList()));
                        domain.addType(c_superclass);
                    }
                    final Type superclass = c_superclass;
                    ctx.name().forEach(type_name -> {
                        Type type = new Type(Utils.capitalize(type_name.getText()));
                        type.setSuperclass(superclass);
                        domain.addType(type);
                    });
                }
            }, domain_context.types_def());
        }

        if (domain_context.constants_def() != null) {
            /**
             * We define the constants.
             */
            ParseTreeWalker.DEFAULT.walk(new PDDLBaseListener() {
                @Override
                public void enterTyped_list_name(PDDLParser.Typed_list_nameContext ctx) {
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
                    ctx.name().stream().forEach(name -> {
                        domain.addConstant(c_type.newInstance(Utils.lowercase(name.getText())));
                    });
                }
            }, domain_context.constants_def());
        }

        if (domain_context.predicates_def() != null) {
            /**
             * We define the predicates.
             */
            ParseTreeWalker.DEFAULT.walk(new PDDLBaseListener() {
                @Override
                public void enterAtomic_formula_skeleton(PDDLParser.Atomic_formula_skeletonContext ctx) {
                    Variable[] variables = new Variable[0];
                    if (ctx.typed_list_variable() != null) {
                        // The predicate formula has parameters
                        TypedListVariableListener typedListVariable = new TypedListVariableListener(domain);
                        ParseTreeWalker.DEFAULT.walk(typedListVariable, ctx.typed_list_variable());
                        variables = typedListVariable.variables.toArray(new Variable[typedListVariable.variables.size()]);
                    }
                    domain.addPredicate(new Predicate(Utils.capitalize(ctx.predicate().name().getText()), variables));
                }
            }, domain_context.predicates_def());
        }

        if (domain_context.functions_def() != null) {
            /**
             * We define the functions.
             */
            ParseTreeWalker.DEFAULT.walk(new PDDLBaseListener() {
                private Type function_type = null;

                @Override
                public void enterFunction_typed_list_atomic_function_skeleton(PDDLParser.Function_typed_list_atomic_function_skeletonContext ctx) {
                    if (ctx.function_type() == null) {
                        function_type = Type.OBJECT;
                    } else if (ctx.function_type().type() == null) {
                        function_type = Type.NUMBER;
                    } else if (ctx.function_type().type().primitive_type().size() == 1) {
                        function_type = ctx.function_type().type().primitive_type(0).name() == null ? Type.OBJECT : domain.getType(Utils.capitalize(ctx.function_type().type().primitive_type(0).name().getText()));
                    } else {
                        function_type = new EitherType(ctx.function_type().type().primitive_type().stream().map(primitive_type -> primitive_type.name() == null ? Type.OBJECT : domain.getType(Utils.capitalize(primitive_type.name().getText()))).collect(Collectors.toList()));
                        domain.addType(function_type);
                    }
                }

                @Override
                public void enterAtomic_function_skeleton(PDDLParser.Atomic_function_skeletonContext ctx) {
                    Variable[] variables = new Variable[0];
                    if (ctx.typed_list_variable() != null) {
                        // The predicate formula has parameters
                        TypedListVariableListener typedListVariable = new TypedListVariableListener(domain);
                        ParseTreeWalker.DEFAULT.walk(typedListVariable, ctx.typed_list_variable());
                        variables = typedListVariable.variables.toArray(new Variable[typedListVariable.variables.size()]);
                    }
                    domain.addFunction(new Function(Utils.capitalize(ctx.function_symbol().name().getText()), function_type, variables));
                }
            }, domain_context.functions_def());
        }

        /**
         * We define the structures.
         */
        domain_context.structure_def().stream().forEach(structure_def -> {
            if (structure_def.action_def() != null) {
                ParseTreeWalker.DEFAULT.walk(new PDDLBaseListener() {
                    @Override
                    public void enterAction_def(PDDLParser.Action_defContext ctx) {
                        Variable[] variables = new Variable[0];
                        if (ctx.typed_list_variable() != null) {
                            // The action has parameters
                            TypedListVariableListener typedListVariable = new TypedListVariableListener(domain);
                            ParseTreeWalker.DEFAULT.walk(typedListVariable, ctx.typed_list_variable());
                            variables = typedListVariable.variables.toArray(new Variable[typedListVariable.variables.size()]);
                        }
                        Action action = new Action(Utils.capitalize(ctx.action_symbol().name().getText()), variables);

                        TermVisitor term_visitor = new TermVisitor(domain_parser, domain, problem, Stream.of(variables).collect(Collectors.toMap(Variable::getName, variable -> variable)));
                        if (ctx.action_def_body().emptyOr_pre_GD() != null) {
                            action.setPrecondition(term_visitor.visit(ctx.action_def_body().emptyOr_pre_GD()));
                        }
                        if (ctx.action_def_body().emptyOr_effect() != null) {
                            action.setEffect(term_visitor.visit(ctx.action_def_body().emptyOr_effect()));
                        }
                        domain.addAction(action);
                    }
                }, structure_def.action_def());
            } else if (structure_def.durative_action_def() != null) {
                ParseTreeWalker.DEFAULT.walk(new PDDLBaseListener() {
                    @Override
                    public void enterDurative_action_def(PDDLParser.Durative_action_defContext ctx) {
                        Variable[] variables = new Variable[0];
                        if (ctx.typed_list_variable() != null) {
                            // The durative action has parameters
                            TypedListVariableListener typedListVariable = new TypedListVariableListener(domain);
                            ParseTreeWalker.DEFAULT.walk(typedListVariable, ctx.typed_list_variable());
                            variables = typedListVariable.variables.toArray(new Variable[typedListVariable.variables.size()]);
                        }
                        DurativeAction action = new DurativeAction(Utils.capitalize(ctx.da_symbol().name().getText()), variables);
                        TermVisitor term_visitor = new TermVisitor(domain_parser, domain, problem, Stream.of(variables).collect(Collectors.toMap(Variable::getName, variable -> variable)));
                        if (ctx.da_def_body().duration_constraint() != null) {
                            action.setDuration(term_visitor.visit(ctx.da_def_body().duration_constraint()));
                        }
                        if (ctx.da_def_body().emptyOr_da_GD() != null) {
                            action.setEffect(term_visitor.visit(ctx.da_def_body().emptyOr_da_GD()));
                        }
                        if (ctx.da_def_body().emptyOr_da_effect() != null) {
                            action.setEffect(term_visitor.visit(ctx.da_def_body().emptyOr_da_effect()));
                        }
                        domain.addDurativeAction(action);
                    }
                }, structure_def.durative_action_def());
            }
        });

        /**
         * We define the objects.
         */
        if (problem_context.object_declaration() != null) {
            ParseTreeWalker.DEFAULT.walk(new PDDLBaseListener() {
                @Override
                public void enterTyped_list_name(PDDLParser.Typed_list_nameContext ctx) {
                    Type type = null;
                    if (ctx.type() == null) {
                        type = Type.OBJECT;
                    } else if (ctx.type().primitive_type().size() == 1) {
                        type = ctx.type().primitive_type(0).name() == null ? Type.OBJECT : domain.getType(Utils.capitalize(ctx.type().primitive_type(0).name().getText()));
                    }
                    final Type c_type = type;
                    ctx.name().stream().forEach(object -> {
                        problem.addObject(c_type.newInstance(Utils.lowercase(object.getText())));
                    });
                }
            }, problem_context.object_declaration());
        }

        TermVisitor term_visitor = new TermVisitor(domain_parser, domain, problem, Collections.emptyMap());
        /**
         * We define the initial state
         */
        problem_context.init().init_el().stream().forEach(init_el -> {
            problem.addInitEl(term_visitor.visit(init_el));
        });

        /**
         * We define the goal
         */
        problem.setGoal(term_visitor.visit(problem_context.goal().pre_GD()));

        return new PDDLInstance(domain, problem);
    }

    public static String translate(File pddl_domain, File pddl_problem) throws IOException {
        PDDLInstance instance = parse(pddl_domain, pddl_problem);

        STGroupFile file = new STGroupFile(Translator.class.getResource("pddl2ratioTemplate.stg").getPath());
        file.registerRenderer(Predicate.class, new PredicateRenderer(file, instance.getDomain()));
        file.registerRenderer(Function.class, new FunctionRenderer(file, instance.getDomain()));
        file.registerRenderer(Action.class, new ActionRenderer(file));
        file.registerRenderer(DurativeAction.class, new DurativeActionRenderer(file));
        file.registerRenderer(Term.class, new TermRenderer(file, instance.getDomain()));

        ST translation = file.getInstanceOf("PDDL");
        translation.add("domain", instance.getDomain());
        translation.add("problem", instance.getProblem());

        return translation.render().replace("?", "");
    }

    private Translator() {
    }
}
