// Generated from PDDL.g4 by ANTLR 4.7
package it.cnr.istc.translators.pddl2ratio.parser;

import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link PDDLParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface PDDLVisitor<T> extends ParseTreeVisitor<T> {

    /**
     * Visit a parse tree produced by {@link PDDLParser#domain}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitDomain(PDDLParser.DomainContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#require_def}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitRequire_def(PDDLParser.Require_defContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#types_def}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitTypes_def(PDDLParser.Types_defContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#constants_def}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitConstants_def(PDDLParser.Constants_defContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#predicates_def}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitPredicates_def(PDDLParser.Predicates_defContext ctx);

    /**
     * Visit a parse tree produced by
     * {@link PDDLParser#atomic_formula_skeleton}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitAtomic_formula_skeleton(PDDLParser.Atomic_formula_skeletonContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#predicate}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitPredicate(PDDLParser.PredicateContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#variable}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitVariable(PDDLParser.VariableContext ctx);

    /**
     * Visit a parse tree produced by
     * {@link PDDLParser#atomic_function_skeleton}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitAtomic_function_skeleton(PDDLParser.Atomic_function_skeletonContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#function_symbol}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitFunction_symbol(PDDLParser.Function_symbolContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#functions_def}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitFunctions_def(PDDLParser.Functions_defContext ctx);

    /**
     * Visit a parse tree produced by
     * {@link PDDLParser#function_typed_list_atomic_function_skeleton}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitFunction_typed_list_atomic_function_skeleton(PDDLParser.Function_typed_list_atomic_function_skeletonContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#function_type}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitFunction_type(PDDLParser.Function_typeContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#constraints}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitConstraints(PDDLParser.ConstraintsContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#structure_def}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitStructure_def(PDDLParser.Structure_defContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#typed_list_name}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitTyped_list_name(PDDLParser.Typed_list_nameContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#typed_list_variable}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitTyped_list_variable(PDDLParser.Typed_list_variableContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#primitive_type}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitPrimitive_type(PDDLParser.Primitive_typeContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#type}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitType(PDDLParser.TypeContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#emptyOr_pre_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitEmptyOr_pre_GD(PDDLParser.EmptyOr_pre_GDContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#emptyOr_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitEmptyOr_effect(PDDLParser.EmptyOr_effectContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#emptyOr_da_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitEmptyOr_da_GD(PDDLParser.EmptyOr_da_GDContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#emptyOr_da_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitEmptyOr_da_effect(PDDLParser.EmptyOr_da_effectContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#action_def}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitAction_def(PDDLParser.Action_defContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#action_symbol}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitAction_symbol(PDDLParser.Action_symbolContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#action_def_body}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitAction_def_body(PDDLParser.Action_def_bodyContext ctx);

    /**
     * Visit a parse tree produced by the {@code pre_GD_pref_GD} labeled
     * alternative in {@link PDDLParser#pre_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitPre_GD_pref_GD(PDDLParser.Pre_GD_pref_GDContext ctx);

    /**
     * Visit a parse tree produced by the {@code pre_GD_and} labeled alternative
     * in {@link PDDLParser#pre_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitPre_GD_and(PDDLParser.Pre_GD_andContext ctx);

    /**
     * Visit a parse tree produced by the {@code pre_GD_forall} labeled
     * alternative in {@link PDDLParser#pre_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitPre_GD_forall(PDDLParser.Pre_GD_forallContext ctx);

    /**
     * Visit a parse tree produced by the {@code pref_GD_preference_gD} labeled
     * alternative in {@link PDDLParser#pref_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitPref_GD_preference_gD(PDDLParser.Pref_GD_preference_gDContext ctx);

    /**
     * Visit a parse tree produced by the {@code pref_GD_gD} labeled alternative
     * in {@link PDDLParser#pref_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitPref_GD_gD(PDDLParser.Pref_GD_gDContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#pref_name}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitPref_name(PDDLParser.Pref_nameContext ctx);

    /**
     * Visit a parse tree produced by the {@code gd_atomic_formula_term} labeled
     * alternative in {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitGd_atomic_formula_term(PDDLParser.Gd_atomic_formula_termContext ctx);

    /**
     * Visit a parse tree produced by the {@code gd_literal_term} labeled
     * alternative in {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitGd_literal_term(PDDLParser.Gd_literal_termContext ctx);

    /**
     * Visit a parse tree produced by the {@code gd_and} labeled alternative in
     * {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitGd_and(PDDLParser.Gd_andContext ctx);

    /**
     * Visit a parse tree produced by the {@code gd_or} labeled alternative in
     * {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitGd_or(PDDLParser.Gd_orContext ctx);

    /**
     * Visit a parse tree produced by the {@code gd_not} labeled alternative in
     * {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitGd_not(PDDLParser.Gd_notContext ctx);

    /**
     * Visit a parse tree produced by the {@code gd_imply} labeled alternative
     * in {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitGd_imply(PDDLParser.Gd_implyContext ctx);

    /**
     * Visit a parse tree produced by the {@code gd_exists} labeled alternative
     * in {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitGd_exists(PDDLParser.Gd_existsContext ctx);

    /**
     * Visit a parse tree produced by the {@code gd_forall} labeled alternative
     * in {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitGd_forall(PDDLParser.Gd_forallContext ctx);

    /**
     * Visit a parse tree produced by the {@code gd_f_comp} labeled alternative
     * in {@link PDDLParser#gD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitGd_f_comp(PDDLParser.Gd_f_compContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#f_comp}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitF_comp(PDDLParser.F_compContext ctx);

    /**
     * Visit a parse tree produced by the
     * {@code literal_term_atomic_formula_term} labeled alternative in
     * {@link PDDLParser#literal_term}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitLiteral_term_atomic_formula_term(PDDLParser.Literal_term_atomic_formula_termContext ctx);

    /**
     * Visit a parse tree produced by the
     * {@code literal_term_not_atomic_formula_term} labeled alternative in
     * {@link PDDLParser#literal_term}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitLiteral_term_not_atomic_formula_term(PDDLParser.Literal_term_not_atomic_formula_termContext ctx);

    /**
     * Visit a parse tree produced by the
     * {@code literal_name_atomic_formula_name} labeled alternative in
     * {@link PDDLParser#literal_name}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitLiteral_name_atomic_formula_name(PDDLParser.Literal_name_atomic_formula_nameContext ctx);

    /**
     * Visit a parse tree produced by the
     * {@code literal_name_not_atomic_formula_name} labeled alternative in
     * {@link PDDLParser#literal_name}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitLiteral_name_not_atomic_formula_name(PDDLParser.Literal_name_not_atomic_formula_nameContext ctx);

    /**
     * Visit a parse tree produced by the {@code atomic_formula_term_predicate}
     * labeled alternative in {@link PDDLParser#atomic_formula_term}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitAtomic_formula_term_predicate(PDDLParser.Atomic_formula_term_predicateContext ctx);

    /**
     * Visit a parse tree produced by the {@code atomic_formula_term_eq} labeled
     * alternative in {@link PDDLParser#atomic_formula_term}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitAtomic_formula_term_eq(PDDLParser.Atomic_formula_term_eqContext ctx);

    /**
     * Visit a parse tree produced by the {@code atomic_formula_name_predicate}
     * labeled alternative in {@link PDDLParser#atomic_formula_name}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitAtomic_formula_name_predicate(PDDLParser.Atomic_formula_name_predicateContext ctx);

    /**
     * Visit a parse tree produced by the {@code atomic_formula_name_eq} labeled
     * alternative in {@link PDDLParser#atomic_formula_name}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitAtomic_formula_name_eq(PDDLParser.Atomic_formula_name_eqContext ctx);

    /**
     * Visit a parse tree produced by the {@code term_name} labeled alternative
     * in {@link PDDLParser#term}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitTerm_name(PDDLParser.Term_nameContext ctx);

    /**
     * Visit a parse tree produced by the {@code term_variable} labeled
     * alternative in {@link PDDLParser#term}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitTerm_variable(PDDLParser.Term_variableContext ctx);

    /**
     * Visit a parse tree produced by the {@code term_function} labeled
     * alternative in {@link PDDLParser#term}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitTerm_function(PDDLParser.Term_functionContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#function_term}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitFunction_term(PDDLParser.Function_termContext ctx);

    /**
     * Visit a parse tree produced by the {@code f_exp_number} labeled
     * alternative in {@link PDDLParser#f_exp}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitF_exp_number(PDDLParser.F_exp_numberContext ctx);

    /**
     * Visit a parse tree produced by the {@code f_exp_binary_op} labeled
     * alternative in {@link PDDLParser#f_exp}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitF_exp_binary_op(PDDLParser.F_exp_binary_opContext ctx);

    /**
     * Visit a parse tree produced by the {@code f_exp_multi_op} labeled
     * alternative in {@link PDDLParser#f_exp}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitF_exp_multi_op(PDDLParser.F_exp_multi_opContext ctx);

    /**
     * Visit a parse tree produced by the {@code f_exp_minus} labeled
     * alternative in {@link PDDLParser#f_exp}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitF_exp_minus(PDDLParser.F_exp_minusContext ctx);

    /**
     * Visit a parse tree produced by the {@code f_exp_f_head} labeled
     * alternative in {@link PDDLParser#f_exp}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitF_exp_f_head(PDDLParser.F_exp_f_headContext ctx);

    /**
     * Visit a parse tree produced by the {@code f_head_function_symbol_terms}
     * labeled alternative in {@link PDDLParser#f_head}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitF_head_function_symbol_terms(PDDLParser.F_head_function_symbol_termsContext ctx);

    /**
     * Visit a parse tree produced by the {@code f_head_function_symbol} labeled
     * alternative in {@link PDDLParser#f_head}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitF_head_function_symbol(PDDLParser.F_head_function_symbolContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#binary_op}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitBinary_op(PDDLParser.Binary_opContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#multi_op}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitMulti_op(PDDLParser.Multi_opContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#binary_comp}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitBinary_comp(PDDLParser.Binary_compContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#name}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitName(PDDLParser.NameContext ctx);

    /**
     * Visit a parse tree produced by the {@code effect_and_c_effect} labeled
     * alternative in {@link PDDLParser#effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitEffect_and_c_effect(PDDLParser.Effect_and_c_effectContext ctx);

    /**
     * Visit a parse tree produced by the {@code effect_c_effect} labeled
     * alternative in {@link PDDLParser#effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitEffect_c_effect(PDDLParser.Effect_c_effectContext ctx);

    /**
     * Visit a parse tree produced by the {@code c_effect_forall} labeled
     * alternative in {@link PDDLParser#c_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitC_effect_forall(PDDLParser.C_effect_forallContext ctx);

    /**
     * Visit a parse tree produced by the {@code c_effect_when} labeled
     * alternative in {@link PDDLParser#c_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitC_effect_when(PDDLParser.C_effect_whenContext ctx);

    /**
     * Visit a parse tree produced by the {@code c_effect_p_effect} labeled
     * alternative in {@link PDDLParser#c_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitC_effect_p_effect(PDDLParser.C_effect_p_effectContext ctx);

    /**
     * Visit a parse tree produced by the
     * {@code p_effect_negated_atomic_formula_term} labeled alternative in
     * {@link PDDLParser#p_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitP_effect_negated_atomic_formula_term(PDDLParser.P_effect_negated_atomic_formula_termContext ctx);

    /**
     * Visit a parse tree produced by the
     * {@code p_effect_directed_atomic_formula_term} labeled alternative in
     * {@link PDDLParser#p_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitP_effect_directed_atomic_formula_term(PDDLParser.P_effect_directed_atomic_formula_termContext ctx);

    /**
     * Visit a parse tree produced by the
     * {@code p_effect_assign_op_f_head_f_exp} labeled alternative in
     * {@link PDDLParser#p_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitP_effect_assign_op_f_head_f_exp(PDDLParser.P_effect_assign_op_f_head_f_expContext ctx);

    /**
     * Visit a parse tree produced by the {@code p_effect_assign_term} labeled
     * alternative in {@link PDDLParser#p_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitP_effect_assign_term(PDDLParser.P_effect_assign_termContext ctx);

    /**
     * Visit a parse tree produced by the {@code p_effect_assign_undefined}
     * labeled alternative in {@link PDDLParser#p_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitP_effect_assign_undefined(PDDLParser.P_effect_assign_undefinedContext ctx);

    /**
     * Visit a parse tree produced by the {@code cond_effect_and_p_effect}
     * labeled alternative in {@link PDDLParser#cond_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitCond_effect_and_p_effect(PDDLParser.Cond_effect_and_p_effectContext ctx);

    /**
     * Visit a parse tree produced by the {@code cond_effect_p_effect} labeled
     * alternative in {@link PDDLParser#cond_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitCond_effect_p_effect(PDDLParser.Cond_effect_p_effectContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#assign_op}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitAssign_op(PDDLParser.Assign_opContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#durative_action_def}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitDurative_action_def(PDDLParser.Durative_action_defContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#da_symbol}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitDa_symbol(PDDLParser.Da_symbolContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#da_def_body}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitDa_def_body(PDDLParser.Da_def_bodyContext ctx);

    /**
     * Visit a parse tree produced by the {@code da_GD_pref_timed_GD} labeled
     * alternative in {@link PDDLParser#da_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitDa_GD_pref_timed_GD(PDDLParser.Da_GD_pref_timed_GDContext ctx);

    /**
     * Visit a parse tree produced by the {@code da_GD_and} labeled alternative
     * in {@link PDDLParser#da_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitDa_GD_and(PDDLParser.Da_GD_andContext ctx);

    /**
     * Visit a parse tree produced by the {@code da_GD_forall} labeled
     * alternative in {@link PDDLParser#da_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitDa_GD_forall(PDDLParser.Da_GD_forallContext ctx);

    /**
     * Visit a parse tree produced by the {@code pref_timed_GD_timed_GD} labeled
     * alternative in {@link PDDLParser#pref_timed_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitPref_timed_GD_timed_GD(PDDLParser.Pref_timed_GD_timed_GDContext ctx);

    /**
     * Visit a parse tree produced by the
     * {@code pref_timed_GD_preference_timed_GD} labeled alternative in
     * {@link PDDLParser#pref_timed_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitPref_timed_GD_preference_timed_GD(PDDLParser.Pref_timed_GD_preference_timed_GDContext ctx);

    /**
     * Visit a parse tree produced by the {@code timed_GD_at_GD} labeled
     * alternative in {@link PDDLParser#timed_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitTimed_GD_at_GD(PDDLParser.Timed_GD_at_GDContext ctx);

    /**
     * Visit a parse tree produced by the {@code timed_GD_over_GD} labeled
     * alternative in {@link PDDLParser#timed_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitTimed_GD_over_GD(PDDLParser.Timed_GD_over_GDContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#time_specifier}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitTime_specifier(PDDLParser.Time_specifierContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#interval}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitInterval(PDDLParser.IntervalContext ctx);

    /**
     * Visit a parse tree produced by the {@code duration_constraint_and}
     * labeled alternative in {@link PDDLParser#duration_constraint}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitDuration_constraint_and(PDDLParser.Duration_constraint_andContext ctx);

    /**
     * Visit a parse tree produced by the {@code duration_constraint_empty}
     * labeled alternative in {@link PDDLParser#duration_constraint}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitDuration_constraint_empty(PDDLParser.Duration_constraint_emptyContext ctx);

    /**
     * Visit a parse tree produced by the
     * {@code duration_constraint_duration_constraint} labeled alternative in
     * {@link PDDLParser#duration_constraint}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitDuration_constraint_duration_constraint(PDDLParser.Duration_constraint_duration_constraintContext ctx);

    /**
     * Visit a parse tree produced by the
     * {@code simple_duration_constraint_d_op} labeled alternative in
     * {@link PDDLParser#simple_duration_constraint}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitSimple_duration_constraint_d_op(PDDLParser.Simple_duration_constraint_d_opContext ctx);

    /**
     * Visit a parse tree produced by the {@code simple_duration_constraint_at}
     * labeled alternative in {@link PDDLParser#simple_duration_constraint}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitSimple_duration_constraint_at(PDDLParser.Simple_duration_constraint_atContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#d_op}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitD_op(PDDLParser.D_opContext ctx);

    /**
     * Visit a parse tree produced by the {@code d_value_number} labeled
     * alternative in {@link PDDLParser#d_value}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitD_value_number(PDDLParser.D_value_numberContext ctx);

    /**
     * Visit a parse tree produced by the {@code d_value_f_exp} labeled
     * alternative in {@link PDDLParser#d_value}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitD_value_f_exp(PDDLParser.D_value_f_expContext ctx);

    /**
     * Visit a parse tree produced by the {@code da_effect_and} labeled
     * alternative in {@link PDDLParser#da_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitDa_effect_and(PDDLParser.Da_effect_andContext ctx);

    /**
     * Visit a parse tree produced by the {@code da_effect_timed_effect} labeled
     * alternative in {@link PDDLParser#da_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitDa_effect_timed_effect(PDDLParser.Da_effect_timed_effectContext ctx);

    /**
     * Visit a parse tree produced by the {@code da_effect_forall} labeled
     * alternative in {@link PDDLParser#da_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitDa_effect_forall(PDDLParser.Da_effect_forallContext ctx);

    /**
     * Visit a parse tree produced by the {@code da_effect_when} labeled
     * alternative in {@link PDDLParser#da_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitDa_effect_when(PDDLParser.Da_effect_whenContext ctx);

    /**
     * Visit a parse tree produced by the {@code timed_effect_cond_effect}
     * labeled alternative in {@link PDDLParser#timed_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitTimed_effect_cond_effect(PDDLParser.Timed_effect_cond_effectContext ctx);

    /**
     * Visit a parse tree produced by the {@code timed_effect_f_assign_da}
     * labeled alternative in {@link PDDLParser#timed_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitTimed_effect_f_assign_da(PDDLParser.Timed_effect_f_assign_daContext ctx);

    /**
     * Visit a parse tree produced by the {@code timed_effect_assign_op} labeled
     * alternative in {@link PDDLParser#timed_effect}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitTimed_effect_assign_op(PDDLParser.Timed_effect_assign_opContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#f_assign_da}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitF_assign_da(PDDLParser.F_assign_daContext ctx);

    /**
     * Visit a parse tree produced by the {@code f_exp_da_binary} labeled
     * alternative in {@link PDDLParser#f_exp_da}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitF_exp_da_binary(PDDLParser.F_exp_da_binaryContext ctx);

    /**
     * Visit a parse tree produced by the {@code f_exp_da_multi} labeled
     * alternative in {@link PDDLParser#f_exp_da}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitF_exp_da_multi(PDDLParser.F_exp_da_multiContext ctx);

    /**
     * Visit a parse tree produced by the {@code f_exp_da_minus} labeled
     * alternative in {@link PDDLParser#f_exp_da}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitF_exp_da_minus(PDDLParser.F_exp_da_minusContext ctx);

    /**
     * Visit a parse tree produced by the {@code f_exp_da_duration} labeled
     * alternative in {@link PDDLParser#f_exp_da}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitF_exp_da_duration(PDDLParser.F_exp_da_durationContext ctx);

    /**
     * Visit a parse tree produced by the {@code f_exp_da_f_exp} labeled
     * alternative in {@link PDDLParser#f_exp_da}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitF_exp_da_f_exp(PDDLParser.F_exp_da_f_expContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#assign_op_t}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitAssign_op_t(PDDLParser.Assign_op_tContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#f_exp_t}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitF_exp_t(PDDLParser.F_exp_tContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#derived_def}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitDerived_def(PDDLParser.Derived_defContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#problem}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitProblem(PDDLParser.ProblemContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#object_declaration}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitObject_declaration(PDDLParser.Object_declarationContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#init}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitInit(PDDLParser.InitContext ctx);

    /**
     * Visit a parse tree produced by the {@code init_el_literal_name} labeled
     * alternative in {@link PDDLParser#init_el}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitInit_el_literal_name(PDDLParser.Init_el_literal_nameContext ctx);

    /**
     * Visit a parse tree produced by the {@code init_el_at} labeled alternative
     * in {@link PDDLParser#init_el}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitInit_el_at(PDDLParser.Init_el_atContext ctx);

    /**
     * Visit a parse tree produced by the {@code init_el_eq_number} labeled
     * alternative in {@link PDDLParser#init_el}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitInit_el_eq_number(PDDLParser.Init_el_eq_numberContext ctx);

    /**
     * Visit a parse tree produced by the {@code init_el_eq_name} labeled
     * alternative in {@link PDDLParser#init_el}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitInit_el_eq_name(PDDLParser.Init_el_eq_nameContext ctx);

    /**
     * Visit a parse tree produced by the
     * {@code basic_function_term_function_symbol} labeled alternative in
     * {@link PDDLParser#basic_function_term}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitBasic_function_term_function_symbol(PDDLParser.Basic_function_term_function_symbolContext ctx);

    /**
     * Visit a parse tree produced by the
     * {@code basic_function_term_function_symbol_names} labeled alternative in
     * {@link PDDLParser#basic_function_term}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitBasic_function_term_function_symbol_names(PDDLParser.Basic_function_term_function_symbol_namesContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#goal}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitGoal(PDDLParser.GoalContext ctx);

    /**
     * Visit a parse tree produced by the {@code pref_con_GD_and} labeled
     * alternative in {@link PDDLParser#pref_con_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitPref_con_GD_and(PDDLParser.Pref_con_GD_andContext ctx);

    /**
     * Visit a parse tree produced by the {@code pref_con_GD_forall} labeled
     * alternative in {@link PDDLParser#pref_con_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitPref_con_GD_forall(PDDLParser.Pref_con_GD_forallContext ctx);

    /**
     * Visit a parse tree produced by the {@code pref_con_GD_preference} labeled
     * alternative in {@link PDDLParser#pref_con_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitPref_con_GD_preference(PDDLParser.Pref_con_GD_preferenceContext ctx);

    /**
     * Visit a parse tree produced by the {@code pref_con_GD_con_GD} labeled
     * alternative in {@link PDDLParser#pref_con_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitPref_con_GD_con_GD(PDDLParser.Pref_con_GD_con_GDContext ctx);

    /**
     * Visit a parse tree produced by the {@code con_GD_and} labeled alternative
     * in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitCon_GD_and(PDDLParser.Con_GD_andContext ctx);

    /**
     * Visit a parse tree produced by the {@code con_GD_forall} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitCon_GD_forall(PDDLParser.Con_GD_forallContext ctx);

    /**
     * Visit a parse tree produced by the {@code con_GD_at_end} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitCon_GD_at_end(PDDLParser.Con_GD_at_endContext ctx);

    /**
     * Visit a parse tree produced by the {@code con_GD_always} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitCon_GD_always(PDDLParser.Con_GD_alwaysContext ctx);

    /**
     * Visit a parse tree produced by the {@code con_GD_sometime} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitCon_GD_sometime(PDDLParser.Con_GD_sometimeContext ctx);

    /**
     * Visit a parse tree produced by the {@code con_GD_within} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitCon_GD_within(PDDLParser.Con_GD_withinContext ctx);

    /**
     * Visit a parse tree produced by the {@code con_GD_at_most_once} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitCon_GD_at_most_once(PDDLParser.Con_GD_at_most_onceContext ctx);

    /**
     * Visit a parse tree produced by the {@code con_GD_sometime_after} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitCon_GD_sometime_after(PDDLParser.Con_GD_sometime_afterContext ctx);

    /**
     * Visit a parse tree produced by the {@code con_GD_sometime_before} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitCon_GD_sometime_before(PDDLParser.Con_GD_sometime_beforeContext ctx);

    /**
     * Visit a parse tree produced by the {@code con_GD_always_within} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitCon_GD_always_within(PDDLParser.Con_GD_always_withinContext ctx);

    /**
     * Visit a parse tree produced by the {@code con_GD_hold_during} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitCon_GD_hold_during(PDDLParser.Con_GD_hold_duringContext ctx);

    /**
     * Visit a parse tree produced by the {@code con_GD_hold_after} labeled
     * alternative in {@link PDDLParser#con_GD}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitCon_GD_hold_after(PDDLParser.Con_GD_hold_afterContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#metric_spec}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitMetric_spec(PDDLParser.Metric_specContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#optimization}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitOptimization(PDDLParser.OptimizationContext ctx);

    /**
     * Visit a parse tree produced by the {@code metric_f_exp_binary} labeled
     * alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitMetric_f_exp_binary(PDDLParser.Metric_f_exp_binaryContext ctx);

    /**
     * Visit a parse tree produced by the {@code metric_f_exp_multi} labeled
     * alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitMetric_f_exp_multi(PDDLParser.Metric_f_exp_multiContext ctx);

    /**
     * Visit a parse tree produced by the {@code metric_f_exp_minus} labeled
     * alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitMetric_f_exp_minus(PDDLParser.Metric_f_exp_minusContext ctx);

    /**
     * Visit a parse tree produced by the {@code metric_f_exp_number} labeled
     * alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitMetric_f_exp_number(PDDLParser.Metric_f_exp_numberContext ctx);

    /**
     * Visit a parse tree produced by the
     * {@code metric_f_exp_function_symbol_name} labeled alternative in
     * {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitMetric_f_exp_function_symbol_name(PDDLParser.Metric_f_exp_function_symbol_nameContext ctx);

    /**
     * Visit a parse tree produced by the {@code metric_f_exp_function_symbol}
     * labeled alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitMetric_f_exp_function_symbol(PDDLParser.Metric_f_exp_function_symbolContext ctx);

    /**
     * Visit a parse tree produced by the {@code metric_f_exp_total_time}
     * labeled alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitMetric_f_exp_total_time(PDDLParser.Metric_f_exp_total_timeContext ctx);

    /**
     * Visit a parse tree produced by the {@code metric_f_exp_is_violated}
     * labeled alternative in {@link PDDLParser#metric_f_exp}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitMetric_f_exp_is_violated(PDDLParser.Metric_f_exp_is_violatedContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#length_spec}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitLength_spec(PDDLParser.Length_specContext ctx);

    /**
     * Visit a parse tree produced by {@link PDDLParser#require_key}.
     *
     * @param ctx the parse tree
     * @return the visitor result
     */
    T visitRequire_key(PDDLParser.Require_keyContext ctx);
}
