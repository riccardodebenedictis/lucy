// Generated from PDDL.g4 by ANTLR 4.7
package it.cnr.istc.translators.pddl2ratio.parser;

import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link PDDLParser}.
 */
public interface PDDLListener extends ParseTreeListener {

    /**
     * Enter a parse tree produced by {@link PDDLParser#domain}.
     *
     * @param ctx the parse tree
     */
    void enterDomain(PDDLParser.DomainContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#domain}.
     *
     * @param ctx the parse tree
     */
    void exitDomain(PDDLParser.DomainContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#require_def}.
     *
     * @param ctx the parse tree
     */
    void enterRequire_def(PDDLParser.Require_defContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#require_def}.
     *
     * @param ctx the parse tree
     */
    void exitRequire_def(PDDLParser.Require_defContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#types_def}.
     *
     * @param ctx the parse tree
     */
    void enterTypes_def(PDDLParser.Types_defContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#types_def}.
     *
     * @param ctx the parse tree
     */
    void exitTypes_def(PDDLParser.Types_defContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#constants_def}.
     *
     * @param ctx the parse tree
     */
    void enterConstants_def(PDDLParser.Constants_defContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#constants_def}.
     *
     * @param ctx the parse tree
     */
    void exitConstants_def(PDDLParser.Constants_defContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#predicates_def}.
     *
     * @param ctx the parse tree
     */
    void enterPredicates_def(PDDLParser.Predicates_defContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#predicates_def}.
     *
     * @param ctx the parse tree
     */
    void exitPredicates_def(PDDLParser.Predicates_defContext ctx);

    /**
     * Enter a parse tree produced by
     * {@link PDDLParser#atomic_formula_skeleton}.
     *
     * @param ctx the parse tree
     */
    void enterAtomic_formula_skeleton(PDDLParser.Atomic_formula_skeletonContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#atomic_formula_skeleton}.
     *
     * @param ctx the parse tree
     */
    void exitAtomic_formula_skeleton(PDDLParser.Atomic_formula_skeletonContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#predicate}.
     *
     * @param ctx the parse tree
     */
    void enterPredicate(PDDLParser.PredicateContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#predicate}.
     *
     * @param ctx the parse tree
     */
    void exitPredicate(PDDLParser.PredicateContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#variable}.
     *
     * @param ctx the parse tree
     */
    void enterVariable(PDDLParser.VariableContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#variable}.
     *
     * @param ctx the parse tree
     */
    void exitVariable(PDDLParser.VariableContext ctx);

    /**
     * Enter a parse tree produced by
     * {@link PDDLParser#atomic_function_skeleton}.
     *
     * @param ctx the parse tree
     */
    void enterAtomic_function_skeleton(PDDLParser.Atomic_function_skeletonContext ctx);

    /**
     * Exit a parse tree produced by
     * {@link PDDLParser#atomic_function_skeleton}.
     *
     * @param ctx the parse tree
     */
    void exitAtomic_function_skeleton(PDDLParser.Atomic_function_skeletonContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#function_symbol}.
     *
     * @param ctx the parse tree
     */
    void enterFunction_symbol(PDDLParser.Function_symbolContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#function_symbol}.
     *
     * @param ctx the parse tree
     */
    void exitFunction_symbol(PDDLParser.Function_symbolContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#functions_def}.
     *
     * @param ctx the parse tree
     */
    void enterFunctions_def(PDDLParser.Functions_defContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#functions_def}.
     *
     * @param ctx the parse tree
     */
    void exitFunctions_def(PDDLParser.Functions_defContext ctx);

    /**
     * Enter a parse tree produced by
     * {@link PDDLParser#function_typed_list_atomic_function_skeleton}.
     *
     * @param ctx the parse tree
     */
    void enterFunction_typed_list_atomic_function_skeleton(PDDLParser.Function_typed_list_atomic_function_skeletonContext ctx);

    /**
     * Exit a parse tree produced by
     * {@link PDDLParser#function_typed_list_atomic_function_skeleton}.
     *
     * @param ctx the parse tree
     */
    void exitFunction_typed_list_atomic_function_skeleton(PDDLParser.Function_typed_list_atomic_function_skeletonContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#function_type}.
     *
     * @param ctx the parse tree
     */
    void enterFunction_type(PDDLParser.Function_typeContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#function_type}.
     *
     * @param ctx the parse tree
     */
    void exitFunction_type(PDDLParser.Function_typeContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#constraints}.
     *
     * @param ctx the parse tree
     */
    void enterConstraints(PDDLParser.ConstraintsContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#constraints}.
     *
     * @param ctx the parse tree
     */
    void exitConstraints(PDDLParser.ConstraintsContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#structure_def}.
     *
     * @param ctx the parse tree
     */
    void enterStructure_def(PDDLParser.Structure_defContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#structure_def}.
     *
     * @param ctx the parse tree
     */
    void exitStructure_def(PDDLParser.Structure_defContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#typed_list_name}.
     *
     * @param ctx the parse tree
     */
    void enterTyped_list_name(PDDLParser.Typed_list_nameContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#typed_list_name}.
     *
     * @param ctx the parse tree
     */
    void exitTyped_list_name(PDDLParser.Typed_list_nameContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#typed_list_variable}.
     *
     * @param ctx the parse tree
     */
    void enterTyped_list_variable(PDDLParser.Typed_list_variableContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#typed_list_variable}.
     *
     * @param ctx the parse tree
     */
    void exitTyped_list_variable(PDDLParser.Typed_list_variableContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#primitive_type}.
     *
     * @param ctx the parse tree
     */
    void enterPrimitive_type(PDDLParser.Primitive_typeContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#primitive_type}.
     *
     * @param ctx the parse tree
     */
    void exitPrimitive_type(PDDLParser.Primitive_typeContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#type}.
     *
     * @param ctx the parse tree
     */
    void enterType(PDDLParser.TypeContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#type}.
     *
     * @param ctx the parse tree
     */
    void exitType(PDDLParser.TypeContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#emptyOr_pre_GD}.
     *
     * @param ctx the parse tree
     */
    void enterEmptyOr_pre_GD(PDDLParser.EmptyOr_pre_GDContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#emptyOr_pre_GD}.
     *
     * @param ctx the parse tree
     */
    void exitEmptyOr_pre_GD(PDDLParser.EmptyOr_pre_GDContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#emptyOr_effect}.
     *
     * @param ctx the parse tree
     */
    void enterEmptyOr_effect(PDDLParser.EmptyOr_effectContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#emptyOr_effect}.
     *
     * @param ctx the parse tree
     */
    void exitEmptyOr_effect(PDDLParser.EmptyOr_effectContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#emptyOr_da_GD}.
     *
     * @param ctx the parse tree
     */
    void enterEmptyOr_da_GD(PDDLParser.EmptyOr_da_GDContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#emptyOr_da_GD}.
     *
     * @param ctx the parse tree
     */
    void exitEmptyOr_da_GD(PDDLParser.EmptyOr_da_GDContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#emptyOr_da_effect}.
     *
     * @param ctx the parse tree
     */
    void enterEmptyOr_da_effect(PDDLParser.EmptyOr_da_effectContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#emptyOr_da_effect}.
     *
     * @param ctx the parse tree
     */
    void exitEmptyOr_da_effect(PDDLParser.EmptyOr_da_effectContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#action_def}.
     *
     * @param ctx the parse tree
     */
    void enterAction_def(PDDLParser.Action_defContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#action_def}.
     *
     * @param ctx the parse tree
     */
    void exitAction_def(PDDLParser.Action_defContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#action_symbol}.
     *
     * @param ctx the parse tree
     */
    void enterAction_symbol(PDDLParser.Action_symbolContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#action_symbol}.
     *
     * @param ctx the parse tree
     */
    void exitAction_symbol(PDDLParser.Action_symbolContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#action_def_body}.
     *
     * @param ctx the parse tree
     */
    void enterAction_def_body(PDDLParser.Action_def_bodyContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#action_def_body}.
     *
     * @param ctx the parse tree
     */
    void exitAction_def_body(PDDLParser.Action_def_bodyContext ctx);

    /**
     * Enter a parse tree produced by the {@code pre_GD_pref_GD} labeled
     * alternative in {@link PDDLParser#pre_GD}.
     *
     * @param ctx the parse tree
     */
    void enterPre_GD_pref_GD(PDDLParser.Pre_GD_pref_GDContext ctx);

    /**
     * Exit a parse tree produced by the {@code pre_GD_pref_GD} labeled
     * alternative in {@link PDDLParser#pre_GD}.
     *
     * @param ctx the parse tree
     */
    void exitPre_GD_pref_GD(PDDLParser.Pre_GD_pref_GDContext ctx);

    /**
     * Enter a parse tree produced by the {@code pre_GD_and} labeled alternative
     * in {@link PDDLParser#pre_GD}.
     *
     * @param ctx the parse tree
     */
    void enterPre_GD_and(PDDLParser.Pre_GD_andContext ctx);

    /**
     * Exit a parse tree produced by the {@code pre_GD_and} labeled alternative
     * in {@link PDDLParser#pre_GD}.
     *
     * @param ctx the parse tree
     */
    void exitPre_GD_and(PDDLParser.Pre_GD_andContext ctx);

    /**
     * Enter a parse tree produced by the {@code pre_GD_forall} labeled
     * alternative in {@link PDDLParser#pre_GD}.
     *
     * @param ctx the parse tree
     */
    void enterPre_GD_forall(PDDLParser.Pre_GD_forallContext ctx);

    /**
     * Exit a parse tree produced by the {@code pre_GD_forall} labeled
     * alternative in {@link PDDLParser#pre_GD}.
     *
     * @param ctx the parse tree
     */
    void exitPre_GD_forall(PDDLParser.Pre_GD_forallContext ctx);

    /**
     * Enter a parse tree produced by the {@code pref_GD_preference_gD} labeled
     * alternative in {@link PDDLParser#pref_GD}.
     *
     * @param ctx the parse tree
     */
    void enterPref_GD_preference_gD(PDDLParser.Pref_GD_preference_gDContext ctx);

    /**
     * Exit a parse tree produced by the {@code pref_GD_preference_gD} labeled
     * alternative in {@link PDDLParser#pref_GD}.
     *
     * @param ctx the parse tree
     */
    void exitPref_GD_preference_gD(PDDLParser.Pref_GD_preference_gDContext ctx);

    /**
     * Enter a parse tree produced by the {@code pref_GD_gD} labeled alternative
     * in {@link PDDLParser#pref_GD}.
     *
     * @param ctx the parse tree
     */
    void enterPref_GD_gD(PDDLParser.Pref_GD_gDContext ctx);

    /**
     * Exit a parse tree produced by the {@code pref_GD_gD} labeled alternative
     * in {@link PDDLParser#pref_GD}.
     *
     * @param ctx the parse tree
     */
    void exitPref_GD_gD(PDDLParser.Pref_GD_gDContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#pref_name}.
     *
     * @param ctx the parse tree
     */
    void enterPref_name(PDDLParser.Pref_nameContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#pref_name}.
     *
     * @param ctx the parse tree
     */
    void exitPref_name(PDDLParser.Pref_nameContext ctx);

    /**
     * Enter a parse tree produced by the {@code gd_atomic_formula_term} labeled
     * alternative in {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     */
    void enterGd_atomic_formula_term(PDDLParser.Gd_atomic_formula_termContext ctx);

    /**
     * Exit a parse tree produced by the {@code gd_atomic_formula_term} labeled
     * alternative in {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     */
    void exitGd_atomic_formula_term(PDDLParser.Gd_atomic_formula_termContext ctx);

    /**
     * Enter a parse tree produced by the {@code gd_literal_term} labeled
     * alternative in {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     */
    void enterGd_literal_term(PDDLParser.Gd_literal_termContext ctx);

    /**
     * Exit a parse tree produced by the {@code gd_literal_term} labeled
     * alternative in {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     */
    void exitGd_literal_term(PDDLParser.Gd_literal_termContext ctx);

    /**
     * Enter a parse tree produced by the {@code gd_and} labeled alternative in
     * {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     */
    void enterGd_and(PDDLParser.Gd_andContext ctx);

    /**
     * Exit a parse tree produced by the {@code gd_and} labeled alternative in
     * {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     */
    void exitGd_and(PDDLParser.Gd_andContext ctx);

    /**
     * Enter a parse tree produced by the {@code gd_or} labeled alternative in
     * {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     */
    void enterGd_or(PDDLParser.Gd_orContext ctx);

    /**
     * Exit a parse tree produced by the {@code gd_or} labeled alternative in
     * {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     */
    void exitGd_or(PDDLParser.Gd_orContext ctx);

    /**
     * Enter a parse tree produced by the {@code gd_not} labeled alternative in
     * {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     */
    void enterGd_not(PDDLParser.Gd_notContext ctx);

    /**
     * Exit a parse tree produced by the {@code gd_not} labeled alternative in
     * {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     */
    void exitGd_not(PDDLParser.Gd_notContext ctx);

    /**
     * Enter a parse tree produced by the {@code gd_imply} labeled alternative
     * in {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     */
    void enterGd_imply(PDDLParser.Gd_implyContext ctx);

    /**
     * Exit a parse tree produced by the {@code gd_imply} labeled alternative in
     * {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     */
    void exitGd_imply(PDDLParser.Gd_implyContext ctx);

    /**
     * Enter a parse tree produced by the {@code gd_exists} labeled alternative
     * in {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     */
    void enterGd_exists(PDDLParser.Gd_existsContext ctx);

    /**
     * Exit a parse tree produced by the {@code gd_exists} labeled alternative
     * in {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     */
    void exitGd_exists(PDDLParser.Gd_existsContext ctx);

    /**
     * Enter a parse tree produced by the {@code gd_forall} labeled alternative
     * in {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     */
    void enterGd_forall(PDDLParser.Gd_forallContext ctx);

    /**
     * Exit a parse tree produced by the {@code gd_forall} labeled alternative
     * in {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     */
    void exitGd_forall(PDDLParser.Gd_forallContext ctx);

    /**
     * Enter a parse tree produced by the {@code gd_f_comp} labeled alternative
     * in {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     */
    void enterGd_f_comp(PDDLParser.Gd_f_compContext ctx);

    /**
     * Exit a parse tree produced by the {@code gd_f_comp} labeled alternative
     * in {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     */
    void exitGd_f_comp(PDDLParser.Gd_f_compContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#f_comp}.
     *
     * @param ctx the parse tree
     */
    void enterF_comp(PDDLParser.F_compContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#f_comp}.
     *
     * @param ctx the parse tree
     */
    void exitF_comp(PDDLParser.F_compContext ctx);

    /**
     * Enter a parse tree produced by the
     * {@code literal_term_atomic_formula_term} labeled alternative in
     * {@link PDDLParser#literal_term}.
     *
     * @param ctx the parse tree
     */
    void enterLiteral_term_atomic_formula_term(PDDLParser.Literal_term_atomic_formula_termContext ctx);

    /**
     * Exit a parse tree produced by the
     * {@code literal_term_atomic_formula_term} labeled alternative in
     * {@link PDDLParser#literal_term}.
     *
     * @param ctx the parse tree
     */
    void exitLiteral_term_atomic_formula_term(PDDLParser.Literal_term_atomic_formula_termContext ctx);

    /**
     * Enter a parse tree produced by the
     * {@code literal_term_not_atomic_formula_term} labeled alternative in
     * {@link PDDLParser#literal_term}.
     *
     * @param ctx the parse tree
     */
    void enterLiteral_term_not_atomic_formula_term(PDDLParser.Literal_term_not_atomic_formula_termContext ctx);

    /**
     * Exit a parse tree produced by the
     * {@code literal_term_not_atomic_formula_term} labeled alternative in
     * {@link PDDLParser#literal_term}.
     *
     * @param ctx the parse tree
     */
    void exitLiteral_term_not_atomic_formula_term(PDDLParser.Literal_term_not_atomic_formula_termContext ctx);

    /**
     * Enter a parse tree produced by the
     * {@code literal_name_atomic_formula_name} labeled alternative in
     * {@link PDDLParser#literal_name}.
     *
     * @param ctx the parse tree
     */
    void enterLiteral_name_atomic_formula_name(PDDLParser.Literal_name_atomic_formula_nameContext ctx);

    /**
     * Exit a parse tree produced by the
     * {@code literal_name_atomic_formula_name} labeled alternative in
     * {@link PDDLParser#literal_name}.
     *
     * @param ctx the parse tree
     */
    void exitLiteral_name_atomic_formula_name(PDDLParser.Literal_name_atomic_formula_nameContext ctx);

    /**
     * Enter a parse tree produced by the
     * {@code literal_name_not_atomic_formula_name} labeled alternative in
     * {@link PDDLParser#literal_name}.
     *
     * @param ctx the parse tree
     */
    void enterLiteral_name_not_atomic_formula_name(PDDLParser.Literal_name_not_atomic_formula_nameContext ctx);

    /**
     * Exit a parse tree produced by the
     * {@code literal_name_not_atomic_formula_name} labeled alternative in
     * {@link PDDLParser#literal_name}.
     *
     * @param ctx the parse tree
     */
    void exitLiteral_name_not_atomic_formula_name(PDDLParser.Literal_name_not_atomic_formula_nameContext ctx);

    /**
     * Enter a parse tree produced by the {@code atomic_formula_term_predicate}
     * labeled alternative in {@link PDDLParser#atomic_formula_term}.
     *
     * @param ctx the parse tree
     */
    void enterAtomic_formula_term_predicate(PDDLParser.Atomic_formula_term_predicateContext ctx);

    /**
     * Exit a parse tree produced by the {@code atomic_formula_term_predicate}
     * labeled alternative in {@link PDDLParser#atomic_formula_term}.
     *
     * @param ctx the parse tree
     */
    void exitAtomic_formula_term_predicate(PDDLParser.Atomic_formula_term_predicateContext ctx);

    /**
     * Enter a parse tree produced by the {@code atomic_formula_term_eq} labeled
     * alternative in {@link PDDLParser#atomic_formula_term}.
     *
     * @param ctx the parse tree
     */
    void enterAtomic_formula_term_eq(PDDLParser.Atomic_formula_term_eqContext ctx);

    /**
     * Exit a parse tree produced by the {@code atomic_formula_term_eq} labeled
     * alternative in {@link PDDLParser#atomic_formula_term}.
     *
     * @param ctx the parse tree
     */
    void exitAtomic_formula_term_eq(PDDLParser.Atomic_formula_term_eqContext ctx);

    /**
     * Enter a parse tree produced by the {@code atomic_formula_name_predicate}
     * labeled alternative in {@link PDDLParser#atomic_formula_name}.
     *
     * @param ctx the parse tree
     */
    void enterAtomic_formula_name_predicate(PDDLParser.Atomic_formula_name_predicateContext ctx);

    /**
     * Exit a parse tree produced by the {@code atomic_formula_name_predicate}
     * labeled alternative in {@link PDDLParser#atomic_formula_name}.
     *
     * @param ctx the parse tree
     */
    void exitAtomic_formula_name_predicate(PDDLParser.Atomic_formula_name_predicateContext ctx);

    /**
     * Enter a parse tree produced by the {@code atomic_formula_name_eq} labeled
     * alternative in {@link PDDLParser#atomic_formula_name}.
     *
     * @param ctx the parse tree
     */
    void enterAtomic_formula_name_eq(PDDLParser.Atomic_formula_name_eqContext ctx);

    /**
     * Exit a parse tree produced by the {@code atomic_formula_name_eq} labeled
     * alternative in {@link PDDLParser#atomic_formula_name}.
     *
     * @param ctx the parse tree
     */
    void exitAtomic_formula_name_eq(PDDLParser.Atomic_formula_name_eqContext ctx);

    /**
     * Enter a parse tree produced by the {@code term_name} labeled alternative
     * in {@link PDDLParser#term}.
     *
     * @param ctx the parse tree
     */
    void enterTerm_name(PDDLParser.Term_nameContext ctx);

    /**
     * Exit a parse tree produced by the {@code term_name} labeled alternative
     * in {@link PDDLParser#term}.
     *
     * @param ctx the parse tree
     */
    void exitTerm_name(PDDLParser.Term_nameContext ctx);

    /**
     * Enter a parse tree produced by the {@code term_variable} labeled
     * alternative in {@link PDDLParser#term}.
     *
     * @param ctx the parse tree
     */
    void enterTerm_variable(PDDLParser.Term_variableContext ctx);

    /**
     * Exit a parse tree produced by the {@code term_variable} labeled
     * alternative in {@link PDDLParser#term}.
     *
     * @param ctx the parse tree
     */
    void exitTerm_variable(PDDLParser.Term_variableContext ctx);

    /**
     * Enter a parse tree produced by the {@code term_function} labeled
     * alternative in {@link PDDLParser#term}.
     *
     * @param ctx the parse tree
     */
    void enterTerm_function(PDDLParser.Term_functionContext ctx);

    /**
     * Exit a parse tree produced by the {@code term_function} labeled
     * alternative in {@link PDDLParser#term}.
     *
     * @param ctx the parse tree
     */
    void exitTerm_function(PDDLParser.Term_functionContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#function_term}.
     *
     * @param ctx the parse tree
     */
    void enterFunction_term(PDDLParser.Function_termContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#function_term}.
     *
     * @param ctx the parse tree
     */
    void exitFunction_term(PDDLParser.Function_termContext ctx);

    /**
     * Enter a parse tree produced by the {@code f_exp_number} labeled
     * alternative in {@link PDDLParser#f_exp}.
     *
     * @param ctx the parse tree
     */
    void enterF_exp_number(PDDLParser.F_exp_numberContext ctx);

    /**
     * Exit a parse tree produced by the {@code f_exp_number} labeled
     * alternative in {@link PDDLParser#f_exp}.
     *
     * @param ctx the parse tree
     */
    void exitF_exp_number(PDDLParser.F_exp_numberContext ctx);

    /**
     * Enter a parse tree produced by the {@code f_exp_binary_op} labeled
     * alternative in {@link PDDLParser#f_exp}.
     *
     * @param ctx the parse tree
     */
    void enterF_exp_binary_op(PDDLParser.F_exp_binary_opContext ctx);

    /**
     * Exit a parse tree produced by the {@code f_exp_binary_op} labeled
     * alternative in {@link PDDLParser#f_exp}.
     *
     * @param ctx the parse tree
     */
    void exitF_exp_binary_op(PDDLParser.F_exp_binary_opContext ctx);

    /**
     * Enter a parse tree produced by the {@code f_exp_multi_op} labeled
     * alternative in {@link PDDLParser#f_exp}.
     *
     * @param ctx the parse tree
     */
    void enterF_exp_multi_op(PDDLParser.F_exp_multi_opContext ctx);

    /**
     * Exit a parse tree produced by the {@code f_exp_multi_op} labeled
     * alternative in {@link PDDLParser#f_exp}.
     *
     * @param ctx the parse tree
     */
    void exitF_exp_multi_op(PDDLParser.F_exp_multi_opContext ctx);

    /**
     * Enter a parse tree produced by the {@code f_exp_minus} labeled
     * alternative in {@link PDDLParser#f_exp}.
     *
     * @param ctx the parse tree
     */
    void enterF_exp_minus(PDDLParser.F_exp_minusContext ctx);

    /**
     * Exit a parse tree produced by the {@code f_exp_minus} labeled alternative
     * in {@link PDDLParser#f_exp}.
     *
     * @param ctx the parse tree
     */
    void exitF_exp_minus(PDDLParser.F_exp_minusContext ctx);

    /**
     * Enter a parse tree produced by the {@code f_exp_f_head} labeled
     * alternative in {@link PDDLParser#f_exp}.
     *
     * @param ctx the parse tree
     */
    void enterF_exp_f_head(PDDLParser.F_exp_f_headContext ctx);

    /**
     * Exit a parse tree produced by the {@code f_exp_f_head} labeled
     * alternative in {@link PDDLParser#f_exp}.
     *
     * @param ctx the parse tree
     */
    void exitF_exp_f_head(PDDLParser.F_exp_f_headContext ctx);

    /**
     * Enter a parse tree produced by the {@code f_head_function_symbol_terms}
     * labeled alternative in {@link PDDLParser#f_head}.
     *
     * @param ctx the parse tree
     */
    void enterF_head_function_symbol_terms(PDDLParser.F_head_function_symbol_termsContext ctx);

    /**
     * Exit a parse tree produced by the {@code f_head_function_symbol_terms}
     * labeled alternative in {@link PDDLParser#f_head}.
     *
     * @param ctx the parse tree
     */
    void exitF_head_function_symbol_terms(PDDLParser.F_head_function_symbol_termsContext ctx);

    /**
     * Enter a parse tree produced by the {@code f_head_function_symbol} labeled
     * alternative in {@link PDDLParser#f_head}.
     *
     * @param ctx the parse tree
     */
    void enterF_head_function_symbol(PDDLParser.F_head_function_symbolContext ctx);

    /**
     * Exit a parse tree produced by the {@code f_head_function_symbol} labeled
     * alternative in {@link PDDLParser#f_head}.
     *
     * @param ctx the parse tree
     */
    void exitF_head_function_symbol(PDDLParser.F_head_function_symbolContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#binary_op}.
     *
     * @param ctx the parse tree
     */
    void enterBinary_op(PDDLParser.Binary_opContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#binary_op}.
     *
     * @param ctx the parse tree
     */
    void exitBinary_op(PDDLParser.Binary_opContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#multi_op}.
     *
     * @param ctx the parse tree
     */
    void enterMulti_op(PDDLParser.Multi_opContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#multi_op}.
     *
     * @param ctx the parse tree
     */
    void exitMulti_op(PDDLParser.Multi_opContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#binary_comp}.
     *
     * @param ctx the parse tree
     */
    void enterBinary_comp(PDDLParser.Binary_compContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#binary_comp}.
     *
     * @param ctx the parse tree
     */
    void exitBinary_comp(PDDLParser.Binary_compContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#name}.
     *
     * @param ctx the parse tree
     */
    void enterName(PDDLParser.NameContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#name}.
     *
     * @param ctx the parse tree
     */
    void exitName(PDDLParser.NameContext ctx);

    /**
     * Enter a parse tree produced by the {@code effect_and_c_effect} labeled
     * alternative in {@link PDDLParser#effect}.
     *
     * @param ctx the parse tree
     */
    void enterEffect_and_c_effect(PDDLParser.Effect_and_c_effectContext ctx);

    /**
     * Exit a parse tree produced by the {@code effect_and_c_effect} labeled
     * alternative in {@link PDDLParser#effect}.
     *
     * @param ctx the parse tree
     */
    void exitEffect_and_c_effect(PDDLParser.Effect_and_c_effectContext ctx);

    /**
     * Enter a parse tree produced by the {@code effect_c_effect} labeled
     * alternative in {@link PDDLParser#effect}.
     *
     * @param ctx the parse tree
     */
    void enterEffect_c_effect(PDDLParser.Effect_c_effectContext ctx);

    /**
     * Exit a parse tree produced by the {@code effect_c_effect} labeled
     * alternative in {@link PDDLParser#effect}.
     *
     * @param ctx the parse tree
     */
    void exitEffect_c_effect(PDDLParser.Effect_c_effectContext ctx);

    /**
     * Enter a parse tree produced by the {@code c_effect_forall} labeled
     * alternative in {@link PDDLParser#c_effect}.
     *
     * @param ctx the parse tree
     */
    void enterC_effect_forall(PDDLParser.C_effect_forallContext ctx);

    /**
     * Exit a parse tree produced by the {@code c_effect_forall} labeled
     * alternative in {@link PDDLParser#c_effect}.
     *
     * @param ctx the parse tree
     */
    void exitC_effect_forall(PDDLParser.C_effect_forallContext ctx);

    /**
     * Enter a parse tree produced by the {@code c_effect_when} labeled
     * alternative in {@link PDDLParser#c_effect}.
     *
     * @param ctx the parse tree
     */
    void enterC_effect_when(PDDLParser.C_effect_whenContext ctx);

    /**
     * Exit a parse tree produced by the {@code c_effect_when} labeled
     * alternative in {@link PDDLParser#c_effect}.
     *
     * @param ctx the parse tree
     */
    void exitC_effect_when(PDDLParser.C_effect_whenContext ctx);

    /**
     * Enter a parse tree produced by the {@code c_effect_p_effect} labeled
     * alternative in {@link PDDLParser#c_effect}.
     *
     * @param ctx the parse tree
     */
    void enterC_effect_p_effect(PDDLParser.C_effect_p_effectContext ctx);

    /**
     * Exit a parse tree produced by the {@code c_effect_p_effect} labeled
     * alternative in {@link PDDLParser#c_effect}.
     *
     * @param ctx the parse tree
     */
    void exitC_effect_p_effect(PDDLParser.C_effect_p_effectContext ctx);

    /**
     * Enter a parse tree produced by the
     * {@code p_effect_negated_atomic_formula_term} labeled alternative in
     * {@link PDDLParser#p_effect}.
     *
     * @param ctx the parse tree
     */
    void enterP_effect_negated_atomic_formula_term(PDDLParser.P_effect_negated_atomic_formula_termContext ctx);

    /**
     * Exit a parse tree produced by the
     * {@code p_effect_negated_atomic_formula_term} labeled alternative in
     * {@link PDDLParser#p_effect}.
     *
     * @param ctx the parse tree
     */
    void exitP_effect_negated_atomic_formula_term(PDDLParser.P_effect_negated_atomic_formula_termContext ctx);

    /**
     * Enter a parse tree produced by the
     * {@code p_effect_directed_atomic_formula_term} labeled alternative in
     * {@link PDDLParser#p_effect}.
     *
     * @param ctx the parse tree
     */
    void enterP_effect_directed_atomic_formula_term(PDDLParser.P_effect_directed_atomic_formula_termContext ctx);

    /**
     * Exit a parse tree produced by the
     * {@code p_effect_directed_atomic_formula_term} labeled alternative in
     * {@link PDDLParser#p_effect}.
     *
     * @param ctx the parse tree
     */
    void exitP_effect_directed_atomic_formula_term(PDDLParser.P_effect_directed_atomic_formula_termContext ctx);

    /**
     * Enter a parse tree produced by the
     * {@code p_effect_assign_op_f_head_f_exp} labeled alternative in
     * {@link PDDLParser#p_effect}.
     *
     * @param ctx the parse tree
     */
    void enterP_effect_assign_op_f_head_f_exp(PDDLParser.P_effect_assign_op_f_head_f_expContext ctx);

    /**
     * Exit a parse tree produced by the {@code p_effect_assign_op_f_head_f_exp}
     * labeled alternative in {@link PDDLParser#p_effect}.
     *
     * @param ctx the parse tree
     */
    void exitP_effect_assign_op_f_head_f_exp(PDDLParser.P_effect_assign_op_f_head_f_expContext ctx);

    /**
     * Enter a parse tree produced by the {@code p_effect_assign_term} labeled
     * alternative in {@link PDDLParser#p_effect}.
     *
     * @param ctx the parse tree
     */
    void enterP_effect_assign_term(PDDLParser.P_effect_assign_termContext ctx);

    /**
     * Exit a parse tree produced by the {@code p_effect_assign_term} labeled
     * alternative in {@link PDDLParser#p_effect}.
     *
     * @param ctx the parse tree
     */
    void exitP_effect_assign_term(PDDLParser.P_effect_assign_termContext ctx);

    /**
     * Enter a parse tree produced by the {@code p_effect_assign_undefined}
     * labeled alternative in {@link PDDLParser#p_effect}.
     *
     * @param ctx the parse tree
     */
    void enterP_effect_assign_undefined(PDDLParser.P_effect_assign_undefinedContext ctx);

    /**
     * Exit a parse tree produced by the {@code p_effect_assign_undefined}
     * labeled alternative in {@link PDDLParser#p_effect}.
     *
     * @param ctx the parse tree
     */
    void exitP_effect_assign_undefined(PDDLParser.P_effect_assign_undefinedContext ctx);

    /**
     * Enter a parse tree produced by the {@code cond_effect_and_p_effect}
     * labeled alternative in {@link PDDLParser#cond_effect}.
     *
     * @param ctx the parse tree
     */
    void enterCond_effect_and_p_effect(PDDLParser.Cond_effect_and_p_effectContext ctx);

    /**
     * Exit a parse tree produced by the {@code cond_effect_and_p_effect}
     * labeled alternative in {@link PDDLParser#cond_effect}.
     *
     * @param ctx the parse tree
     */
    void exitCond_effect_and_p_effect(PDDLParser.Cond_effect_and_p_effectContext ctx);

    /**
     * Enter a parse tree produced by the {@code cond_effect_p_effect} labeled
     * alternative in {@link PDDLParser#cond_effect}.
     *
     * @param ctx the parse tree
     */
    void enterCond_effect_p_effect(PDDLParser.Cond_effect_p_effectContext ctx);

    /**
     * Exit a parse tree produced by the {@code cond_effect_p_effect} labeled
     * alternative in {@link PDDLParser#cond_effect}.
     *
     * @param ctx the parse tree
     */
    void exitCond_effect_p_effect(PDDLParser.Cond_effect_p_effectContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#assign_op}.
     *
     * @param ctx the parse tree
     */
    void enterAssign_op(PDDLParser.Assign_opContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#assign_op}.
     *
     * @param ctx the parse tree
     */
    void exitAssign_op(PDDLParser.Assign_opContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#durative_action_def}.
     *
     * @param ctx the parse tree
     */
    void enterDurative_action_def(PDDLParser.Durative_action_defContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#durative_action_def}.
     *
     * @param ctx the parse tree
     */
    void exitDurative_action_def(PDDLParser.Durative_action_defContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#da_symbol}.
     *
     * @param ctx the parse tree
     */
    void enterDa_symbol(PDDLParser.Da_symbolContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#da_symbol}.
     *
     * @param ctx the parse tree
     */
    void exitDa_symbol(PDDLParser.Da_symbolContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#da_def_body}.
     *
     * @param ctx the parse tree
     */
    void enterDa_def_body(PDDLParser.Da_def_bodyContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#da_def_body}.
     *
     * @param ctx the parse tree
     */
    void exitDa_def_body(PDDLParser.Da_def_bodyContext ctx);

    /**
     * Enter a parse tree produced by the {@code da_GD_pref_timed_GD} labeled
     * alternative in {@link PDDLParser#da_GD}.
     *
     * @param ctx the parse tree
     */
    void enterDa_GD_pref_timed_GD(PDDLParser.Da_GD_pref_timed_GDContext ctx);

    /**
     * Exit a parse tree produced by the {@code da_GD_pref_timed_GD} labeled
     * alternative in {@link PDDLParser#da_GD}.
     *
     * @param ctx the parse tree
     */
    void exitDa_GD_pref_timed_GD(PDDLParser.Da_GD_pref_timed_GDContext ctx);

    /**
     * Enter a parse tree produced by the {@code da_GD_and} labeled alternative
     * in {@link PDDLParser#da_GD}.
     *
     * @param ctx the parse tree
     */
    void enterDa_GD_and(PDDLParser.Da_GD_andContext ctx);

    /**
     * Exit a parse tree produced by the {@code da_GD_and} labeled alternative
     * in {@link PDDLParser#da_GD}.
     *
     * @param ctx the parse tree
     */
    void exitDa_GD_and(PDDLParser.Da_GD_andContext ctx);

    /**
     * Enter a parse tree produced by the {@code da_GD_forall} labeled
     * alternative in {@link PDDLParser#da_GD}.
     *
     * @param ctx the parse tree
     */
    void enterDa_GD_forall(PDDLParser.Da_GD_forallContext ctx);

    /**
     * Exit a parse tree produced by the {@code da_GD_forall} labeled
     * alternative in {@link PDDLParser#da_GD}.
     *
     * @param ctx the parse tree
     */
    void exitDa_GD_forall(PDDLParser.Da_GD_forallContext ctx);

    /**
     * Enter a parse tree produced by the {@code pref_timed_GD_timed_GD} labeled
     * alternative in {@link PDDLParser#pref_timed_GD}.
     *
     * @param ctx the parse tree
     */
    void enterPref_timed_GD_timed_GD(PDDLParser.Pref_timed_GD_timed_GDContext ctx);

    /**
     * Exit a parse tree produced by the {@code pref_timed_GD_timed_GD} labeled
     * alternative in {@link PDDLParser#pref_timed_GD}.
     *
     * @param ctx the parse tree
     */
    void exitPref_timed_GD_timed_GD(PDDLParser.Pref_timed_GD_timed_GDContext ctx);

    /**
     * Enter a parse tree produced by the
     * {@code pref_timed_GD_preference_timed_GD} labeled alternative in
     * {@link PDDLParser#pref_timed_GD}.
     *
     * @param ctx the parse tree
     */
    void enterPref_timed_GD_preference_timed_GD(PDDLParser.Pref_timed_GD_preference_timed_GDContext ctx);

    /**
     * Exit a parse tree produced by the
     * {@code pref_timed_GD_preference_timed_GD} labeled alternative in
     * {@link PDDLParser#pref_timed_GD}.
     *
     * @param ctx the parse tree
     */
    void exitPref_timed_GD_preference_timed_GD(PDDLParser.Pref_timed_GD_preference_timed_GDContext ctx);

    /**
     * Enter a parse tree produced by the {@code timed_GD_at_GD} labeled
     * alternative in {@link PDDLParser#timed_GD}.
     *
     * @param ctx the parse tree
     */
    void enterTimed_GD_at_GD(PDDLParser.Timed_GD_at_GDContext ctx);

    /**
     * Exit a parse tree produced by the {@code timed_GD_at_GD} labeled
     * alternative in {@link PDDLParser#timed_GD}.
     *
     * @param ctx the parse tree
     */
    void exitTimed_GD_at_GD(PDDLParser.Timed_GD_at_GDContext ctx);

    /**
     * Enter a parse tree produced by the {@code timed_GD_over_GD} labeled
     * alternative in {@link PDDLParser#timed_GD}.
     *
     * @param ctx the parse tree
     */
    void enterTimed_GD_over_GD(PDDLParser.Timed_GD_over_GDContext ctx);

    /**
     * Exit a parse tree produced by the {@code timed_GD_over_GD} labeled
     * alternative in {@link PDDLParser#timed_GD}.
     *
     * @param ctx the parse tree
     */
    void exitTimed_GD_over_GD(PDDLParser.Timed_GD_over_GDContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#time_specifier}.
     *
     * @param ctx the parse tree
     */
    void enterTime_specifier(PDDLParser.Time_specifierContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#time_specifier}.
     *
     * @param ctx the parse tree
     */
    void exitTime_specifier(PDDLParser.Time_specifierContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#interval}.
     *
     * @param ctx the parse tree
     */
    void enterInterval(PDDLParser.IntervalContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#interval}.
     *
     * @param ctx the parse tree
     */
    void exitInterval(PDDLParser.IntervalContext ctx);

    /**
     * Enter a parse tree produced by the {@code duration_constraint_and}
     * labeled alternative in {@link PDDLParser#duration_constraint}.
     *
     * @param ctx the parse tree
     */
    void enterDuration_constraint_and(PDDLParser.Duration_constraint_andContext ctx);

    /**
     * Exit a parse tree produced by the {@code duration_constraint_and} labeled
     * alternative in {@link PDDLParser#duration_constraint}.
     *
     * @param ctx the parse tree
     */
    void exitDuration_constraint_and(PDDLParser.Duration_constraint_andContext ctx);

    /**
     * Enter a parse tree produced by the {@code duration_constraint_empty}
     * labeled alternative in {@link PDDLParser#duration_constraint}.
     *
     * @param ctx the parse tree
     */
    void enterDuration_constraint_empty(PDDLParser.Duration_constraint_emptyContext ctx);

    /**
     * Exit a parse tree produced by the {@code duration_constraint_empty}
     * labeled alternative in {@link PDDLParser#duration_constraint}.
     *
     * @param ctx the parse tree
     */
    void exitDuration_constraint_empty(PDDLParser.Duration_constraint_emptyContext ctx);

    /**
     * Enter a parse tree produced by the
     * {@code duration_constraint_duration_constraint} labeled alternative in
     * {@link PDDLParser#duration_constraint}.
     *
     * @param ctx the parse tree
     */
    void enterDuration_constraint_duration_constraint(PDDLParser.Duration_constraint_duration_constraintContext ctx);

    /**
     * Exit a parse tree produced by the
     * {@code duration_constraint_duration_constraint} labeled alternative in
     * {@link PDDLParser#duration_constraint}.
     *
     * @param ctx the parse tree
     */
    void exitDuration_constraint_duration_constraint(PDDLParser.Duration_constraint_duration_constraintContext ctx);

    /**
     * Enter a parse tree produced by the
     * {@code simple_duration_constraint_d_op} labeled alternative in
     * {@link PDDLParser#simple_duration_constraint}.
     *
     * @param ctx the parse tree
     */
    void enterSimple_duration_constraint_d_op(PDDLParser.Simple_duration_constraint_d_opContext ctx);

    /**
     * Exit a parse tree produced by the {@code simple_duration_constraint_d_op}
     * labeled alternative in {@link PDDLParser#simple_duration_constraint}.
     *
     * @param ctx the parse tree
     */
    void exitSimple_duration_constraint_d_op(PDDLParser.Simple_duration_constraint_d_opContext ctx);

    /**
     * Enter a parse tree produced by the {@code simple_duration_constraint_at}
     * labeled alternative in {@link PDDLParser#simple_duration_constraint}.
     *
     * @param ctx the parse tree
     */
    void enterSimple_duration_constraint_at(PDDLParser.Simple_duration_constraint_atContext ctx);

    /**
     * Exit a parse tree produced by the {@code simple_duration_constraint_at}
     * labeled alternative in {@link PDDLParser#simple_duration_constraint}.
     *
     * @param ctx the parse tree
     */
    void exitSimple_duration_constraint_at(PDDLParser.Simple_duration_constraint_atContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#d_op}.
     *
     * @param ctx the parse tree
     */
    void enterD_op(PDDLParser.D_opContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#d_op}.
     *
     * @param ctx the parse tree
     */
    void exitD_op(PDDLParser.D_opContext ctx);

    /**
     * Enter a parse tree produced by the {@code d_value_number} labeled
     * alternative in {@link PDDLParser#d_value}.
     *
     * @param ctx the parse tree
     */
    void enterD_value_number(PDDLParser.D_value_numberContext ctx);

    /**
     * Exit a parse tree produced by the {@code d_value_number} labeled
     * alternative in {@link PDDLParser#d_value}.
     *
     * @param ctx the parse tree
     */
    void exitD_value_number(PDDLParser.D_value_numberContext ctx);

    /**
     * Enter a parse tree produced by the {@code d_value_f_exp} labeled
     * alternative in {@link PDDLParser#d_value}.
     *
     * @param ctx the parse tree
     */
    void enterD_value_f_exp(PDDLParser.D_value_f_expContext ctx);

    /**
     * Exit a parse tree produced by the {@code d_value_f_exp} labeled
     * alternative in {@link PDDLParser#d_value}.
     *
     * @param ctx the parse tree
     */
    void exitD_value_f_exp(PDDLParser.D_value_f_expContext ctx);

    /**
     * Enter a parse tree produced by the {@code da_effect_and} labeled
     * alternative in {@link PDDLParser#da_effect}.
     *
     * @param ctx the parse tree
     */
    void enterDa_effect_and(PDDLParser.Da_effect_andContext ctx);

    /**
     * Exit a parse tree produced by the {@code da_effect_and} labeled
     * alternative in {@link PDDLParser#da_effect}.
     *
     * @param ctx the parse tree
     */
    void exitDa_effect_and(PDDLParser.Da_effect_andContext ctx);

    /**
     * Enter a parse tree produced by the {@code da_effect_timed_effect} labeled
     * alternative in {@link PDDLParser#da_effect}.
     *
     * @param ctx the parse tree
     */
    void enterDa_effect_timed_effect(PDDLParser.Da_effect_timed_effectContext ctx);

    /**
     * Exit a parse tree produced by the {@code da_effect_timed_effect} labeled
     * alternative in {@link PDDLParser#da_effect}.
     *
     * @param ctx the parse tree
     */
    void exitDa_effect_timed_effect(PDDLParser.Da_effect_timed_effectContext ctx);

    /**
     * Enter a parse tree produced by the {@code da_effect_forall} labeled
     * alternative in {@link PDDLParser#da_effect}.
     *
     * @param ctx the parse tree
     */
    void enterDa_effect_forall(PDDLParser.Da_effect_forallContext ctx);

    /**
     * Exit a parse tree produced by the {@code da_effect_forall} labeled
     * alternative in {@link PDDLParser#da_effect}.
     *
     * @param ctx the parse tree
     */
    void exitDa_effect_forall(PDDLParser.Da_effect_forallContext ctx);

    /**
     * Enter a parse tree produced by the {@code da_effect_when} labeled
     * alternative in {@link PDDLParser#da_effect}.
     *
     * @param ctx the parse tree
     */
    void enterDa_effect_when(PDDLParser.Da_effect_whenContext ctx);

    /**
     * Exit a parse tree produced by the {@code da_effect_when} labeled
     * alternative in {@link PDDLParser#da_effect}.
     *
     * @param ctx the parse tree
     */
    void exitDa_effect_when(PDDLParser.Da_effect_whenContext ctx);

    /**
     * Enter a parse tree produced by the {@code timed_effect_cond_effect}
     * labeled alternative in {@link PDDLParser#timed_effect}.
     *
     * @param ctx the parse tree
     */
    void enterTimed_effect_cond_effect(PDDLParser.Timed_effect_cond_effectContext ctx);

    /**
     * Exit a parse tree produced by the {@code timed_effect_cond_effect}
     * labeled alternative in {@link PDDLParser#timed_effect}.
     *
     * @param ctx the parse tree
     */
    void exitTimed_effect_cond_effect(PDDLParser.Timed_effect_cond_effectContext ctx);

    /**
     * Enter a parse tree produced by the {@code timed_effect_f_assign_da}
     * labeled alternative in {@link PDDLParser#timed_effect}.
     *
     * @param ctx the parse tree
     */
    void enterTimed_effect_f_assign_da(PDDLParser.Timed_effect_f_assign_daContext ctx);

    /**
     * Exit a parse tree produced by the {@code timed_effect_f_assign_da}
     * labeled alternative in {@link PDDLParser#timed_effect}.
     *
     * @param ctx the parse tree
     */
    void exitTimed_effect_f_assign_da(PDDLParser.Timed_effect_f_assign_daContext ctx);

    /**
     * Enter a parse tree produced by the {@code timed_effect_assign_op} labeled
     * alternative in {@link PDDLParser#timed_effect}.
     *
     * @param ctx the parse tree
     */
    void enterTimed_effect_assign_op(PDDLParser.Timed_effect_assign_opContext ctx);

    /**
     * Exit a parse tree produced by the {@code timed_effect_assign_op} labeled
     * alternative in {@link PDDLParser#timed_effect}.
     *
     * @param ctx the parse tree
     */
    void exitTimed_effect_assign_op(PDDLParser.Timed_effect_assign_opContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#f_assign_da}.
     *
     * @param ctx the parse tree
     */
    void enterF_assign_da(PDDLParser.F_assign_daContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#f_assign_da}.
     *
     * @param ctx the parse tree
     */
    void exitF_assign_da(PDDLParser.F_assign_daContext ctx);

    /**
     * Enter a parse tree produced by the {@code f_exp_da_binary} labeled
     * alternative in {@link PDDLParser#f_exp_da}.
     *
     * @param ctx the parse tree
     */
    void enterF_exp_da_binary(PDDLParser.F_exp_da_binaryContext ctx);

    /**
     * Exit a parse tree produced by the {@code f_exp_da_binary} labeled
     * alternative in {@link PDDLParser#f_exp_da}.
     *
     * @param ctx the parse tree
     */
    void exitF_exp_da_binary(PDDLParser.F_exp_da_binaryContext ctx);

    /**
     * Enter a parse tree produced by the {@code f_exp_da_multi} labeled
     * alternative in {@link PDDLParser#f_exp_da}.
     *
     * @param ctx the parse tree
     */
    void enterF_exp_da_multi(PDDLParser.F_exp_da_multiContext ctx);

    /**
     * Exit a parse tree produced by the {@code f_exp_da_multi} labeled
     * alternative in {@link PDDLParser#f_exp_da}.
     *
     * @param ctx the parse tree
     */
    void exitF_exp_da_multi(PDDLParser.F_exp_da_multiContext ctx);

    /**
     * Enter a parse tree produced by the {@code f_exp_da_minus} labeled
     * alternative in {@link PDDLParser#f_exp_da}.
     *
     * @param ctx the parse tree
     */
    void enterF_exp_da_minus(PDDLParser.F_exp_da_minusContext ctx);

    /**
     * Exit a parse tree produced by the {@code f_exp_da_minus} labeled
     * alternative in {@link PDDLParser#f_exp_da}.
     *
     * @param ctx the parse tree
     */
    void exitF_exp_da_minus(PDDLParser.F_exp_da_minusContext ctx);

    /**
     * Enter a parse tree produced by the {@code f_exp_da_duration} labeled
     * alternative in {@link PDDLParser#f_exp_da}.
     *
     * @param ctx the parse tree
     */
    void enterF_exp_da_duration(PDDLParser.F_exp_da_durationContext ctx);

    /**
     * Exit a parse tree produced by the {@code f_exp_da_duration} labeled
     * alternative in {@link PDDLParser#f_exp_da}.
     *
     * @param ctx the parse tree
     */
    void exitF_exp_da_duration(PDDLParser.F_exp_da_durationContext ctx);

    /**
     * Enter a parse tree produced by the {@code f_exp_da_f_exp} labeled
     * alternative in {@link PDDLParser#f_exp_da}.
     *
     * @param ctx the parse tree
     */
    void enterF_exp_da_f_exp(PDDLParser.F_exp_da_f_expContext ctx);

    /**
     * Exit a parse tree produced by the {@code f_exp_da_f_exp} labeled
     * alternative in {@link PDDLParser#f_exp_da}.
     *
     * @param ctx the parse tree
     */
    void exitF_exp_da_f_exp(PDDLParser.F_exp_da_f_expContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#assign_op_t}.
     *
     * @param ctx the parse tree
     */
    void enterAssign_op_t(PDDLParser.Assign_op_tContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#assign_op_t}.
     *
     * @param ctx the parse tree
     */
    void exitAssign_op_t(PDDLParser.Assign_op_tContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#f_exp_t}.
     *
     * @param ctx the parse tree
     */
    void enterF_exp_t(PDDLParser.F_exp_tContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#f_exp_t}.
     *
     * @param ctx the parse tree
     */
    void exitF_exp_t(PDDLParser.F_exp_tContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#derived_def}.
     *
     * @param ctx the parse tree
     */
    void enterDerived_def(PDDLParser.Derived_defContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#derived_def}.
     *
     * @param ctx the parse tree
     */
    void exitDerived_def(PDDLParser.Derived_defContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#problem}.
     *
     * @param ctx the parse tree
     */
    void enterProblem(PDDLParser.ProblemContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#problem}.
     *
     * @param ctx the parse tree
     */
    void exitProblem(PDDLParser.ProblemContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#object_declaration}.
     *
     * @param ctx the parse tree
     */
    void enterObject_declaration(PDDLParser.Object_declarationContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#object_declaration}.
     *
     * @param ctx the parse tree
     */
    void exitObject_declaration(PDDLParser.Object_declarationContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#init}.
     *
     * @param ctx the parse tree
     */
    void enterInit(PDDLParser.InitContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#init}.
     *
     * @param ctx the parse tree
     */
    void exitInit(PDDLParser.InitContext ctx);

    /**
     * Enter a parse tree produced by the {@code init_el_literal_name} labeled
     * alternative in {@link PDDLParser#init_el}.
     *
     * @param ctx the parse tree
     */
    void enterInit_el_literal_name(PDDLParser.Init_el_literal_nameContext ctx);

    /**
     * Exit a parse tree produced by the {@code init_el_literal_name} labeled
     * alternative in {@link PDDLParser#init_el}.
     *
     * @param ctx the parse tree
     */
    void exitInit_el_literal_name(PDDLParser.Init_el_literal_nameContext ctx);

    /**
     * Enter a parse tree produced by the {@code init_el_at} labeled alternative
     * in {@link PDDLParser#init_el}.
     *
     * @param ctx the parse tree
     */
    void enterInit_el_at(PDDLParser.Init_el_atContext ctx);

    /**
     * Exit a parse tree produced by the {@code init_el_at} labeled alternative
     * in {@link PDDLParser#init_el}.
     *
     * @param ctx the parse tree
     */
    void exitInit_el_at(PDDLParser.Init_el_atContext ctx);

    /**
     * Enter a parse tree produced by the {@code init_el_eq_number} labeled
     * alternative in {@link PDDLParser#init_el}.
     *
     * @param ctx the parse tree
     */
    void enterInit_el_eq_number(PDDLParser.Init_el_eq_numberContext ctx);

    /**
     * Exit a parse tree produced by the {@code init_el_eq_number} labeled
     * alternative in {@link PDDLParser#init_el}.
     *
     * @param ctx the parse tree
     */
    void exitInit_el_eq_number(PDDLParser.Init_el_eq_numberContext ctx);

    /**
     * Enter a parse tree produced by the {@code init_el_eq_name} labeled
     * alternative in {@link PDDLParser#init_el}.
     *
     * @param ctx the parse tree
     */
    void enterInit_el_eq_name(PDDLParser.Init_el_eq_nameContext ctx);

    /**
     * Exit a parse tree produced by the {@code init_el_eq_name} labeled
     * alternative in {@link PDDLParser#init_el}.
     *
     * @param ctx the parse tree
     */
    void exitInit_el_eq_name(PDDLParser.Init_el_eq_nameContext ctx);

    /**
     * Enter a parse tree produced by the
     * {@code basic_function_term_function_symbol} labeled alternative in
     * {@link PDDLParser#basic_function_term}.
     *
     * @param ctx the parse tree
     */
    void enterBasic_function_term_function_symbol(PDDLParser.Basic_function_term_function_symbolContext ctx);

    /**
     * Exit a parse tree produced by the
     * {@code basic_function_term_function_symbol} labeled alternative in
     * {@link PDDLParser#basic_function_term}.
     *
     * @param ctx the parse tree
     */
    void exitBasic_function_term_function_symbol(PDDLParser.Basic_function_term_function_symbolContext ctx);

    /**
     * Enter a parse tree produced by the
     * {@code basic_function_term_function_symbol_names} labeled alternative in
     * {@link PDDLParser#basic_function_term}.
     *
     * @param ctx the parse tree
     */
    void enterBasic_function_term_function_symbol_names(PDDLParser.Basic_function_term_function_symbol_namesContext ctx);

    /**
     * Exit a parse tree produced by the
     * {@code basic_function_term_function_symbol_names} labeled alternative in
     * {@link PDDLParser#basic_function_term}.
     *
     * @param ctx the parse tree
     */
    void exitBasic_function_term_function_symbol_names(PDDLParser.Basic_function_term_function_symbol_namesContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#goal}.
     *
     * @param ctx the parse tree
     */
    void enterGoal(PDDLParser.GoalContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#goal}.
     *
     * @param ctx the parse tree
     */
    void exitGoal(PDDLParser.GoalContext ctx);

    /**
     * Enter a parse tree produced by the {@code pref_con_GD_and} labeled
     * alternative in {@link PDDLParser#pref_con_GD}.
     *
     * @param ctx the parse tree
     */
    void enterPref_con_GD_and(PDDLParser.Pref_con_GD_andContext ctx);

    /**
     * Exit a parse tree produced by the {@code pref_con_GD_and} labeled
     * alternative in {@link PDDLParser#pref_con_GD}.
     *
     * @param ctx the parse tree
     */
    void exitPref_con_GD_and(PDDLParser.Pref_con_GD_andContext ctx);

    /**
     * Enter a parse tree produced by the {@code pref_con_GD_forall} labeled
     * alternative in {@link PDDLParser#pref_con_GD}.
     *
     * @param ctx the parse tree
     */
    void enterPref_con_GD_forall(PDDLParser.Pref_con_GD_forallContext ctx);

    /**
     * Exit a parse tree produced by the {@code pref_con_GD_forall} labeled
     * alternative in {@link PDDLParser#pref_con_GD}.
     *
     * @param ctx the parse tree
     */
    void exitPref_con_GD_forall(PDDLParser.Pref_con_GD_forallContext ctx);

    /**
     * Enter a parse tree produced by the {@code pref_con_GD_preference} labeled
     * alternative in {@link PDDLParser#pref_con_GD}.
     *
     * @param ctx the parse tree
     */
    void enterPref_con_GD_preference(PDDLParser.Pref_con_GD_preferenceContext ctx);

    /**
     * Exit a parse tree produced by the {@code pref_con_GD_preference} labeled
     * alternative in {@link PDDLParser#pref_con_GD}.
     *
     * @param ctx the parse tree
     */
    void exitPref_con_GD_preference(PDDLParser.Pref_con_GD_preferenceContext ctx);

    /**
     * Enter a parse tree produced by the {@code pref_con_GD_con_GD} labeled
     * alternative in {@link PDDLParser#pref_con_GD}.
     *
     * @param ctx the parse tree
     */
    void enterPref_con_GD_con_GD(PDDLParser.Pref_con_GD_con_GDContext ctx);

    /**
     * Exit a parse tree produced by the {@code pref_con_GD_con_GD} labeled
     * alternative in {@link PDDLParser#pref_con_GD}.
     *
     * @param ctx the parse tree
     */
    void exitPref_con_GD_con_GD(PDDLParser.Pref_con_GD_con_GDContext ctx);

    /**
     * Enter a parse tree produced by the {@code con_GD_and} labeled alternative
     * in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void enterCon_GD_and(PDDLParser.Con_GD_andContext ctx);

    /**
     * Exit a parse tree produced by the {@code con_GD_and} labeled alternative
     * in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void exitCon_GD_and(PDDLParser.Con_GD_andContext ctx);

    /**
     * Enter a parse tree produced by the {@code con_GD_forall} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void enterCon_GD_forall(PDDLParser.Con_GD_forallContext ctx);

    /**
     * Exit a parse tree produced by the {@code con_GD_forall} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void exitCon_GD_forall(PDDLParser.Con_GD_forallContext ctx);

    /**
     * Enter a parse tree produced by the {@code con_GD_at_end} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void enterCon_GD_at_end(PDDLParser.Con_GD_at_endContext ctx);

    /**
     * Exit a parse tree produced by the {@code con_GD_at_end} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void exitCon_GD_at_end(PDDLParser.Con_GD_at_endContext ctx);

    /**
     * Enter a parse tree produced by the {@code con_GD_always} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void enterCon_GD_always(PDDLParser.Con_GD_alwaysContext ctx);

    /**
     * Exit a parse tree produced by the {@code con_GD_always} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void exitCon_GD_always(PDDLParser.Con_GD_alwaysContext ctx);

    /**
     * Enter a parse tree produced by the {@code con_GD_sometime} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void enterCon_GD_sometime(PDDLParser.Con_GD_sometimeContext ctx);

    /**
     * Exit a parse tree produced by the {@code con_GD_sometime} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void exitCon_GD_sometime(PDDLParser.Con_GD_sometimeContext ctx);

    /**
     * Enter a parse tree produced by the {@code con_GD_within} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void enterCon_GD_within(PDDLParser.Con_GD_withinContext ctx);

    /**
     * Exit a parse tree produced by the {@code con_GD_within} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void exitCon_GD_within(PDDLParser.Con_GD_withinContext ctx);

    /**
     * Enter a parse tree produced by the {@code con_GD_at_most_once} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void enterCon_GD_at_most_once(PDDLParser.Con_GD_at_most_onceContext ctx);

    /**
     * Exit a parse tree produced by the {@code con_GD_at_most_once} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void exitCon_GD_at_most_once(PDDLParser.Con_GD_at_most_onceContext ctx);

    /**
     * Enter a parse tree produced by the {@code con_GD_sometime_after} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void enterCon_GD_sometime_after(PDDLParser.Con_GD_sometime_afterContext ctx);

    /**
     * Exit a parse tree produced by the {@code con_GD_sometime_after} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void exitCon_GD_sometime_after(PDDLParser.Con_GD_sometime_afterContext ctx);

    /**
     * Enter a parse tree produced by the {@code con_GD_sometime_before} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void enterCon_GD_sometime_before(PDDLParser.Con_GD_sometime_beforeContext ctx);

    /**
     * Exit a parse tree produced by the {@code con_GD_sometime_before} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void exitCon_GD_sometime_before(PDDLParser.Con_GD_sometime_beforeContext ctx);

    /**
     * Enter a parse tree produced by the {@code con_GD_always_within} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void enterCon_GD_always_within(PDDLParser.Con_GD_always_withinContext ctx);

    /**
     * Exit a parse tree produced by the {@code con_GD_always_within} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void exitCon_GD_always_within(PDDLParser.Con_GD_always_withinContext ctx);

    /**
     * Enter a parse tree produced by the {@code con_GD_hold_during} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void enterCon_GD_hold_during(PDDLParser.Con_GD_hold_duringContext ctx);

    /**
     * Exit a parse tree produced by the {@code con_GD_hold_during} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void exitCon_GD_hold_during(PDDLParser.Con_GD_hold_duringContext ctx);

    /**
     * Enter a parse tree produced by the {@code con_GD_hold_after} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void enterCon_GD_hold_after(PDDLParser.Con_GD_hold_afterContext ctx);

    /**
     * Exit a parse tree produced by the {@code con_GD_hold_after} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     */
    void exitCon_GD_hold_after(PDDLParser.Con_GD_hold_afterContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#metric_spec}.
     *
     * @param ctx the parse tree
     */
    void enterMetric_spec(PDDLParser.Metric_specContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#metric_spec}.
     *
     * @param ctx the parse tree
     */
    void exitMetric_spec(PDDLParser.Metric_specContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#optimization}.
     *
     * @param ctx the parse tree
     */
    void enterOptimization(PDDLParser.OptimizationContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#optimization}.
     *
     * @param ctx the parse tree
     */
    void exitOptimization(PDDLParser.OptimizationContext ctx);

    /**
     * Enter a parse tree produced by the {@code metric_f_exp_binary} labeled
     * alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     */
    void enterMetric_f_exp_binary(PDDLParser.Metric_f_exp_binaryContext ctx);

    /**
     * Exit a parse tree produced by the {@code metric_f_exp_binary} labeled
     * alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     */
    void exitMetric_f_exp_binary(PDDLParser.Metric_f_exp_binaryContext ctx);

    /**
     * Enter a parse tree produced by the {@code metric_f_exp_multi} labeled
     * alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     */
    void enterMetric_f_exp_multi(PDDLParser.Metric_f_exp_multiContext ctx);

    /**
     * Exit a parse tree produced by the {@code metric_f_exp_multi} labeled
     * alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     */
    void exitMetric_f_exp_multi(PDDLParser.Metric_f_exp_multiContext ctx);

    /**
     * Enter a parse tree produced by the {@code metric_f_exp_minus} labeled
     * alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     */
    void enterMetric_f_exp_minus(PDDLParser.Metric_f_exp_minusContext ctx);

    /**
     * Exit a parse tree produced by the {@code metric_f_exp_minus} labeled
     * alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     */
    void exitMetric_f_exp_minus(PDDLParser.Metric_f_exp_minusContext ctx);

    /**
     * Enter a parse tree produced by the {@code metric_f_exp_number} labeled
     * alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     */
    void enterMetric_f_exp_number(PDDLParser.Metric_f_exp_numberContext ctx);

    /**
     * Exit a parse tree produced by the {@code metric_f_exp_number} labeled
     * alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     */
    void exitMetric_f_exp_number(PDDLParser.Metric_f_exp_numberContext ctx);

    /**
     * Enter a parse tree produced by the
     * {@code metric_f_exp_function_symbol_name} labeled alternative in
     * {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     */
    void enterMetric_f_exp_function_symbol_name(PDDLParser.Metric_f_exp_function_symbol_nameContext ctx);

    /**
     * Exit a parse tree produced by the
     * {@code metric_f_exp_function_symbol_name} labeled alternative in
     * {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     */
    void exitMetric_f_exp_function_symbol_name(PDDLParser.Metric_f_exp_function_symbol_nameContext ctx);

    /**
     * Enter a parse tree produced by the {@code metric_f_exp_function_symbol}
     * labeled alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     */
    void enterMetric_f_exp_function_symbol(PDDLParser.Metric_f_exp_function_symbolContext ctx);

    /**
     * Exit a parse tree produced by the {@code metric_f_exp_function_symbol}
     * labeled alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     */
    void exitMetric_f_exp_function_symbol(PDDLParser.Metric_f_exp_function_symbolContext ctx);

    /**
     * Enter a parse tree produced by the {@code metric_f_exp_total_time}
     * labeled alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     */
    void enterMetric_f_exp_total_time(PDDLParser.Metric_f_exp_total_timeContext ctx);

    /**
     * Exit a parse tree produced by the {@code metric_f_exp_total_time} labeled
     * alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     */
    void exitMetric_f_exp_total_time(PDDLParser.Metric_f_exp_total_timeContext ctx);

    /**
     * Enter a parse tree produced by the {@code metric_f_exp_is_violated}
     * labeled alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     */
    void enterMetric_f_exp_is_violated(PDDLParser.Metric_f_exp_is_violatedContext ctx);

    /**
     * Exit a parse tree produced by the {@code metric_f_exp_is_violated}
     * labeled alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     */
    void exitMetric_f_exp_is_violated(PDDLParser.Metric_f_exp_is_violatedContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#length_spec}.
     *
     * @param ctx the parse tree
     */
    void enterLength_spec(PDDLParser.Length_specContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#length_spec}.
     *
     * @param ctx the parse tree
     */
    void exitLength_spec(PDDLParser.Length_specContext ctx);

    /**
     * Enter a parse tree produced by {@link PDDLParser#require_key}.
     *
     * @param ctx the parse tree
     */
    void enterRequire_key(PDDLParser.Require_keyContext ctx);

    /**
     * Exit a parse tree produced by {@link PDDLParser#require_key}.
     *
     * @param ctx the parse tree
     */
    void exitRequire_key(PDDLParser.Require_keyContext ctx);
}
