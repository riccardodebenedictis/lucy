
// Generated from ratio.g4 by ANTLR 4.7

#pragma once

#include "antlr4-runtime.h"
#include "ratioParser.h"

namespace lucy
{

/**
	 * This class defines an abstract visitor for a parse tree
	 * produced by ratioParser.
	 */
class ratioVisitor : public antlr4::tree::AbstractParseTreeVisitor
{
  public:
	/**
		 * Visit parse trees produced by ratioParser.
		 */
	virtual antlrcpp::Any visitCompilation_unit(ratioParser::Compilation_unitContext *context) = 0;

	virtual antlrcpp::Any visitType_declaration(ratioParser::Type_declarationContext *context) = 0;

	virtual antlrcpp::Any visitTypedef_declaration(ratioParser::Typedef_declarationContext *context) = 0;

	virtual antlrcpp::Any visitEnum_declaration(ratioParser::Enum_declarationContext *context) = 0;

	virtual antlrcpp::Any visitEnum_constants(ratioParser::Enum_constantsContext *context) = 0;

	virtual antlrcpp::Any visitClass_declaration(ratioParser::Class_declarationContext *context) = 0;

	virtual antlrcpp::Any visitMember(ratioParser::MemberContext *context) = 0;

	virtual antlrcpp::Any visitField_declaration(ratioParser::Field_declarationContext *context) = 0;

	virtual antlrcpp::Any visitVariable_dec(ratioParser::Variable_decContext *context) = 0;

	virtual antlrcpp::Any visitVoid_method_declaration(ratioParser::Void_method_declarationContext *context) = 0;

	virtual antlrcpp::Any visitType_method_declaration(ratioParser::Type_method_declarationContext *context) = 0;

	virtual antlrcpp::Any visitConstructor_declaration(ratioParser::Constructor_declarationContext *context) = 0;

	virtual antlrcpp::Any visitInitializer_element(ratioParser::Initializer_elementContext *context) = 0;

	virtual antlrcpp::Any visitPredicate_declaration(ratioParser::Predicate_declarationContext *context) = 0;

	virtual antlrcpp::Any visitStatement(ratioParser::StatementContext *context) = 0;

	virtual antlrcpp::Any visitBlock(ratioParser::BlockContext *context) = 0;

	virtual antlrcpp::Any visitAssignment_statement(ratioParser::Assignment_statementContext *context) = 0;

	virtual antlrcpp::Any visitLocal_variable_statement(ratioParser::Local_variable_statementContext *context) = 0;

	virtual antlrcpp::Any visitExpression_statement(ratioParser::Expression_statementContext *context) = 0;

	virtual antlrcpp::Any visitDisjunction_statement(ratioParser::Disjunction_statementContext *context) = 0;

	virtual antlrcpp::Any visitConjunction(ratioParser::ConjunctionContext *context) = 0;

	virtual antlrcpp::Any visitFormula_statement(ratioParser::Formula_statementContext *context) = 0;

	virtual antlrcpp::Any visitReturn_statement(ratioParser::Return_statementContext *context) = 0;

	virtual antlrcpp::Any visitAssignment_list(ratioParser::Assignment_listContext *context) = 0;

	virtual antlrcpp::Any visitAssignment(ratioParser::AssignmentContext *context) = 0;

	virtual antlrcpp::Any visitCast_expression(ratioParser::Cast_expressionContext *context) = 0;

	virtual antlrcpp::Any visitQualified_id_expression(ratioParser::Qualified_id_expressionContext *context) = 0;

	virtual antlrcpp::Any visitDivision_expression(ratioParser::Division_expressionContext *context) = 0;

	virtual antlrcpp::Any visitSubtraction_expression(ratioParser::Subtraction_expressionContext *context) = 0;

	virtual antlrcpp::Any visitExtc_one_expression(ratioParser::Extc_one_expressionContext *context) = 0;

	virtual antlrcpp::Any visitPlus_expression(ratioParser::Plus_expressionContext *context) = 0;

	virtual antlrcpp::Any visitFunction_expression(ratioParser::Function_expressionContext *context) = 0;

	virtual antlrcpp::Any visitAddition_expression(ratioParser::Addition_expressionContext *context) = 0;

	virtual antlrcpp::Any visitParentheses_expression(ratioParser::Parentheses_expressionContext *context) = 0;

	virtual antlrcpp::Any visitMinus_expression(ratioParser::Minus_expressionContext *context) = 0;

	virtual antlrcpp::Any visitImplication_expression(ratioParser::Implication_expressionContext *context) = 0;

	virtual antlrcpp::Any visitLt_expression(ratioParser::Lt_expressionContext *context) = 0;

	virtual antlrcpp::Any visitNot_expression(ratioParser::Not_expressionContext *context) = 0;

	virtual antlrcpp::Any visitConjunction_expression(ratioParser::Conjunction_expressionContext *context) = 0;

	virtual antlrcpp::Any visitGeq_expression(ratioParser::Geq_expressionContext *context) = 0;

	virtual antlrcpp::Any visitRange_expression(ratioParser::Range_expressionContext *context) = 0;

	virtual antlrcpp::Any visitMultiplication_expression(ratioParser::Multiplication_expressionContext *context) = 0;

	virtual antlrcpp::Any visitLeq_expression(ratioParser::Leq_expressionContext *context) = 0;

	virtual antlrcpp::Any visitGt_expression(ratioParser::Gt_expressionContext *context) = 0;

	virtual antlrcpp::Any visitConstructor_expression(ratioParser::Constructor_expressionContext *context) = 0;

	virtual antlrcpp::Any visitDisjunction_expression(ratioParser::Disjunction_expressionContext *context) = 0;

	virtual antlrcpp::Any visitLiteral_expression(ratioParser::Literal_expressionContext *context) = 0;

	virtual antlrcpp::Any visitEq_expression(ratioParser::Eq_expressionContext *context) = 0;

	virtual antlrcpp::Any visitNeq_expression(ratioParser::Neq_expressionContext *context) = 0;

	virtual antlrcpp::Any visitExpr_list(ratioParser::Expr_listContext *context) = 0;

	virtual antlrcpp::Any visitLiteral(ratioParser::LiteralContext *context) = 0;

	virtual antlrcpp::Any visitQualified_id(ratioParser::Qualified_idContext *context) = 0;

	virtual antlrcpp::Any visitType(ratioParser::TypeContext *context) = 0;

	virtual antlrcpp::Any visitClass_type(ratioParser::Class_typeContext *context) = 0;

	virtual antlrcpp::Any visitPrimitive_type(ratioParser::Primitive_typeContext *context) = 0;

	virtual antlrcpp::Any visitType_list(ratioParser::Type_listContext *context) = 0;

	virtual antlrcpp::Any visitTyped_list(ratioParser::Typed_listContext *context) = 0;

	virtual antlrcpp::Any visitQualified_predicate(ratioParser::Qualified_predicateContext *context) = 0;

	virtual antlrcpp::Any visitPredicate_list(ratioParser::Predicate_listContext *context) = 0;
};

} // namespace lucy
