
// Generated from ratio.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "ratioParser.h"


namespace lucy {

	/**
	 * This interface defines an abstract listener for a parse tree produced by ratioParser.
	 */
	class  ratioListener : public antlr4::tree::ParseTreeListener {
	public:

		virtual void enterCompilation_unit(ratioParser::Compilation_unitContext *ctx) = 0;
		virtual void exitCompilation_unit(ratioParser::Compilation_unitContext *ctx) = 0;

		virtual void enterType_declaration(ratioParser::Type_declarationContext *ctx) = 0;
		virtual void exitType_declaration(ratioParser::Type_declarationContext *ctx) = 0;

		virtual void enterTypedef_declaration(ratioParser::Typedef_declarationContext *ctx) = 0;
		virtual void exitTypedef_declaration(ratioParser::Typedef_declarationContext *ctx) = 0;

		virtual void enterEnum_declaration(ratioParser::Enum_declarationContext *ctx) = 0;
		virtual void exitEnum_declaration(ratioParser::Enum_declarationContext *ctx) = 0;

		virtual void enterEnum_constants(ratioParser::Enum_constantsContext *ctx) = 0;
		virtual void exitEnum_constants(ratioParser::Enum_constantsContext *ctx) = 0;

		virtual void enterClass_declaration(ratioParser::Class_declarationContext *ctx) = 0;
		virtual void exitClass_declaration(ratioParser::Class_declarationContext *ctx) = 0;

		virtual void enterMember(ratioParser::MemberContext *ctx) = 0;
		virtual void exitMember(ratioParser::MemberContext *ctx) = 0;

		virtual void enterField_declaration(ratioParser::Field_declarationContext *ctx) = 0;
		virtual void exitField_declaration(ratioParser::Field_declarationContext *ctx) = 0;

		virtual void enterVariable_dec(ratioParser::Variable_decContext *ctx) = 0;
		virtual void exitVariable_dec(ratioParser::Variable_decContext *ctx) = 0;

		virtual void enterVoid_method_declaration(ratioParser::Void_method_declarationContext *ctx) = 0;
		virtual void exitVoid_method_declaration(ratioParser::Void_method_declarationContext *ctx) = 0;

		virtual void enterType_method_declaration(ratioParser::Type_method_declarationContext *ctx) = 0;
		virtual void exitType_method_declaration(ratioParser::Type_method_declarationContext *ctx) = 0;

		virtual void enterConstructor_declaration(ratioParser::Constructor_declarationContext *ctx) = 0;
		virtual void exitConstructor_declaration(ratioParser::Constructor_declarationContext *ctx) = 0;

		virtual void enterInitializer_element(ratioParser::Initializer_elementContext *ctx) = 0;
		virtual void exitInitializer_element(ratioParser::Initializer_elementContext *ctx) = 0;

		virtual void enterPredicate_declaration(ratioParser::Predicate_declarationContext *ctx) = 0;
		virtual void exitPredicate_declaration(ratioParser::Predicate_declarationContext *ctx) = 0;

		virtual void enterStatement(ratioParser::StatementContext *ctx) = 0;
		virtual void exitStatement(ratioParser::StatementContext *ctx) = 0;

		virtual void enterBlock(ratioParser::BlockContext *ctx) = 0;
		virtual void exitBlock(ratioParser::BlockContext *ctx) = 0;

		virtual void enterAssignment_statement(ratioParser::Assignment_statementContext *ctx) = 0;
		virtual void exitAssignment_statement(ratioParser::Assignment_statementContext *ctx) = 0;

		virtual void enterLocal_variable_statement(ratioParser::Local_variable_statementContext *ctx) = 0;
		virtual void exitLocal_variable_statement(ratioParser::Local_variable_statementContext *ctx) = 0;

		virtual void enterExpression_statement(ratioParser::Expression_statementContext *ctx) = 0;
		virtual void exitExpression_statement(ratioParser::Expression_statementContext *ctx) = 0;

		virtual void enterDisjunction_statement(ratioParser::Disjunction_statementContext *ctx) = 0;
		virtual void exitDisjunction_statement(ratioParser::Disjunction_statementContext *ctx) = 0;

		virtual void enterConjunction(ratioParser::ConjunctionContext *ctx) = 0;
		virtual void exitConjunction(ratioParser::ConjunctionContext *ctx) = 0;

		virtual void enterFormula_statement(ratioParser::Formula_statementContext *ctx) = 0;
		virtual void exitFormula_statement(ratioParser::Formula_statementContext *ctx) = 0;

		virtual void enterReturn_statement(ratioParser::Return_statementContext *ctx) = 0;
		virtual void exitReturn_statement(ratioParser::Return_statementContext *ctx) = 0;

		virtual void enterAssignment_list(ratioParser::Assignment_listContext *ctx) = 0;
		virtual void exitAssignment_list(ratioParser::Assignment_listContext *ctx) = 0;

		virtual void enterAssignment(ratioParser::AssignmentContext *ctx) = 0;
		virtual void exitAssignment(ratioParser::AssignmentContext *ctx) = 0;

		virtual void enterCast_expression(ratioParser::Cast_expressionContext *ctx) = 0;
		virtual void exitCast_expression(ratioParser::Cast_expressionContext *ctx) = 0;

		virtual void enterQualified_id_expression(ratioParser::Qualified_id_expressionContext *ctx) = 0;
		virtual void exitQualified_id_expression(ratioParser::Qualified_id_expressionContext *ctx) = 0;

		virtual void enterDivision_expression(ratioParser::Division_expressionContext *ctx) = 0;
		virtual void exitDivision_expression(ratioParser::Division_expressionContext *ctx) = 0;

		virtual void enterSubtraction_expression(ratioParser::Subtraction_expressionContext *ctx) = 0;
		virtual void exitSubtraction_expression(ratioParser::Subtraction_expressionContext *ctx) = 0;

		virtual void enterExtc_one_expression(ratioParser::Extc_one_expressionContext *ctx) = 0;
		virtual void exitExtc_one_expression(ratioParser::Extc_one_expressionContext *ctx) = 0;

		virtual void enterPlus_expression(ratioParser::Plus_expressionContext *ctx) = 0;
		virtual void exitPlus_expression(ratioParser::Plus_expressionContext *ctx) = 0;

		virtual void enterFunction_expression(ratioParser::Function_expressionContext *ctx) = 0;
		virtual void exitFunction_expression(ratioParser::Function_expressionContext *ctx) = 0;

		virtual void enterAddition_expression(ratioParser::Addition_expressionContext *ctx) = 0;
		virtual void exitAddition_expression(ratioParser::Addition_expressionContext *ctx) = 0;

		virtual void enterParentheses_expression(ratioParser::Parentheses_expressionContext *ctx) = 0;
		virtual void exitParentheses_expression(ratioParser::Parentheses_expressionContext *ctx) = 0;

		virtual void enterMinus_expression(ratioParser::Minus_expressionContext *ctx) = 0;
		virtual void exitMinus_expression(ratioParser::Minus_expressionContext *ctx) = 0;

		virtual void enterImplication_expression(ratioParser::Implication_expressionContext *ctx) = 0;
		virtual void exitImplication_expression(ratioParser::Implication_expressionContext *ctx) = 0;

		virtual void enterLt_expression(ratioParser::Lt_expressionContext *ctx) = 0;
		virtual void exitLt_expression(ratioParser::Lt_expressionContext *ctx) = 0;

		virtual void enterNot_expression(ratioParser::Not_expressionContext *ctx) = 0;
		virtual void exitNot_expression(ratioParser::Not_expressionContext *ctx) = 0;

		virtual void enterConjunction_expression(ratioParser::Conjunction_expressionContext *ctx) = 0;
		virtual void exitConjunction_expression(ratioParser::Conjunction_expressionContext *ctx) = 0;

		virtual void enterGeq_expression(ratioParser::Geq_expressionContext *ctx) = 0;
		virtual void exitGeq_expression(ratioParser::Geq_expressionContext *ctx) = 0;

		virtual void enterRange_expression(ratioParser::Range_expressionContext *ctx) = 0;
		virtual void exitRange_expression(ratioParser::Range_expressionContext *ctx) = 0;

		virtual void enterMultiplication_expression(ratioParser::Multiplication_expressionContext *ctx) = 0;
		virtual void exitMultiplication_expression(ratioParser::Multiplication_expressionContext *ctx) = 0;

		virtual void enterLeq_expression(ratioParser::Leq_expressionContext *ctx) = 0;
		virtual void exitLeq_expression(ratioParser::Leq_expressionContext *ctx) = 0;

		virtual void enterGt_expression(ratioParser::Gt_expressionContext *ctx) = 0;
		virtual void exitGt_expression(ratioParser::Gt_expressionContext *ctx) = 0;

		virtual void enterConstructor_expression(ratioParser::Constructor_expressionContext *ctx) = 0;
		virtual void exitConstructor_expression(ratioParser::Constructor_expressionContext *ctx) = 0;

		virtual void enterDisjunction_expression(ratioParser::Disjunction_expressionContext *ctx) = 0;
		virtual void exitDisjunction_expression(ratioParser::Disjunction_expressionContext *ctx) = 0;

		virtual void enterLiteral_expression(ratioParser::Literal_expressionContext *ctx) = 0;
		virtual void exitLiteral_expression(ratioParser::Literal_expressionContext *ctx) = 0;

		virtual void enterEq_expression(ratioParser::Eq_expressionContext *ctx) = 0;
		virtual void exitEq_expression(ratioParser::Eq_expressionContext *ctx) = 0;

		virtual void enterNeq_expression(ratioParser::Neq_expressionContext *ctx) = 0;
		virtual void exitNeq_expression(ratioParser::Neq_expressionContext *ctx) = 0;

		virtual void enterExpr_list(ratioParser::Expr_listContext *ctx) = 0;
		virtual void exitExpr_list(ratioParser::Expr_listContext *ctx) = 0;

		virtual void enterLiteral(ratioParser::LiteralContext *ctx) = 0;
		virtual void exitLiteral(ratioParser::LiteralContext *ctx) = 0;

		virtual void enterQualified_id(ratioParser::Qualified_idContext *ctx) = 0;
		virtual void exitQualified_id(ratioParser::Qualified_idContext *ctx) = 0;

		virtual void enterType(ratioParser::TypeContext *ctx) = 0;
		virtual void exitType(ratioParser::TypeContext *ctx) = 0;

		virtual void enterClass_type(ratioParser::Class_typeContext *ctx) = 0;
		virtual void exitClass_type(ratioParser::Class_typeContext *ctx) = 0;

		virtual void enterPrimitive_type(ratioParser::Primitive_typeContext *ctx) = 0;
		virtual void exitPrimitive_type(ratioParser::Primitive_typeContext *ctx) = 0;

		virtual void enterType_list(ratioParser::Type_listContext *ctx) = 0;
		virtual void exitType_list(ratioParser::Type_listContext *ctx) = 0;

		virtual void enterTyped_list(ratioParser::Typed_listContext *ctx) = 0;
		virtual void exitTyped_list(ratioParser::Typed_listContext *ctx) = 0;

		virtual void enterQualified_predicate(ratioParser::Qualified_predicateContext *ctx) = 0;
		virtual void exitQualified_predicate(ratioParser::Qualified_predicateContext *ctx) = 0;

		virtual void enterPredicate_list(ratioParser::Predicate_listContext *ctx) = 0;
		virtual void exitPredicate_list(ratioParser::Predicate_listContext *ctx) = 0;


	};

}  // namespace lucy
