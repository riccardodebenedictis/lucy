
// Generated from ratio.g4 by ANTLR 4.7

#pragma once

#include "antlr4-runtime.h"
#include "ratioListener.h"

namespace lucy
{

/**
 * This class provides an empty implementation of ratioListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class ratioBaseListener : public ratioListener
{
public:
  virtual void enterCompilation_unit(ratioParser::Compilation_unitContext * /*ctx*/) override {}
  virtual void exitCompilation_unit(ratioParser::Compilation_unitContext * /*ctx*/) override {}

  virtual void enterType_declaration(ratioParser::Type_declarationContext * /*ctx*/) override {}
  virtual void exitType_declaration(ratioParser::Type_declarationContext * /*ctx*/) override {}

  virtual void enterTypedef_declaration(ratioParser::Typedef_declarationContext * /*ctx*/) override {}
  virtual void exitTypedef_declaration(ratioParser::Typedef_declarationContext * /*ctx*/) override {}

  virtual void enterEnum_declaration(ratioParser::Enum_declarationContext * /*ctx*/) override {}
  virtual void exitEnum_declaration(ratioParser::Enum_declarationContext * /*ctx*/) override {}

  virtual void enterEnum_constants(ratioParser::Enum_constantsContext * /*ctx*/) override {}
  virtual void exitEnum_constants(ratioParser::Enum_constantsContext * /*ctx*/) override {}

  virtual void enterClass_declaration(ratioParser::Class_declarationContext * /*ctx*/) override {}
  virtual void exitClass_declaration(ratioParser::Class_declarationContext * /*ctx*/) override {}

  virtual void enterMember(ratioParser::MemberContext * /*ctx*/) override {}
  virtual void exitMember(ratioParser::MemberContext * /*ctx*/) override {}

  virtual void enterField_declaration(ratioParser::Field_declarationContext * /*ctx*/) override {}
  virtual void exitField_declaration(ratioParser::Field_declarationContext * /*ctx*/) override {}

  virtual void enterVariable_dec(ratioParser::Variable_decContext * /*ctx*/) override {}
  virtual void exitVariable_dec(ratioParser::Variable_decContext * /*ctx*/) override {}

  virtual void enterVoid_method_declaration(ratioParser::Void_method_declarationContext * /*ctx*/) override {}
  virtual void exitVoid_method_declaration(ratioParser::Void_method_declarationContext * /*ctx*/) override {}

  virtual void enterType_method_declaration(ratioParser::Type_method_declarationContext * /*ctx*/) override {}
  virtual void exitType_method_declaration(ratioParser::Type_method_declarationContext * /*ctx*/) override {}

  virtual void enterConstructor_declaration(ratioParser::Constructor_declarationContext * /*ctx*/) override {}
  virtual void exitConstructor_declaration(ratioParser::Constructor_declarationContext * /*ctx*/) override {}

  virtual void enterInitializer_element(ratioParser::Initializer_elementContext * /*ctx*/) override {}
  virtual void exitInitializer_element(ratioParser::Initializer_elementContext * /*ctx*/) override {}

  virtual void enterPredicate_declaration(ratioParser::Predicate_declarationContext * /*ctx*/) override {}
  virtual void exitPredicate_declaration(ratioParser::Predicate_declarationContext * /*ctx*/) override {}

  virtual void enterStatement(ratioParser::StatementContext * /*ctx*/) override {}
  virtual void exitStatement(ratioParser::StatementContext * /*ctx*/) override {}

  virtual void enterBlock(ratioParser::BlockContext * /*ctx*/) override {}
  virtual void exitBlock(ratioParser::BlockContext * /*ctx*/) override {}

  virtual void enterAssignment_statement(ratioParser::Assignment_statementContext * /*ctx*/) override {}
  virtual void exitAssignment_statement(ratioParser::Assignment_statementContext * /*ctx*/) override {}

  virtual void enterLocal_variable_statement(ratioParser::Local_variable_statementContext * /*ctx*/) override {}
  virtual void exitLocal_variable_statement(ratioParser::Local_variable_statementContext * /*ctx*/) override {}

  virtual void enterExpression_statement(ratioParser::Expression_statementContext * /*ctx*/) override {}
  virtual void exitExpression_statement(ratioParser::Expression_statementContext * /*ctx*/) override {}

  virtual void enterDisjunction_statement(ratioParser::Disjunction_statementContext * /*ctx*/) override {}
  virtual void exitDisjunction_statement(ratioParser::Disjunction_statementContext * /*ctx*/) override {}

  virtual void enterConjunction(ratioParser::ConjunctionContext * /*ctx*/) override {}
  virtual void exitConjunction(ratioParser::ConjunctionContext * /*ctx*/) override {}

  virtual void enterFormula_statement(ratioParser::Formula_statementContext * /*ctx*/) override {}
  virtual void exitFormula_statement(ratioParser::Formula_statementContext * /*ctx*/) override {}

  virtual void enterReturn_statement(ratioParser::Return_statementContext * /*ctx*/) override {}
  virtual void exitReturn_statement(ratioParser::Return_statementContext * /*ctx*/) override {}

  virtual void enterAssignment_list(ratioParser::Assignment_listContext * /*ctx*/) override {}
  virtual void exitAssignment_list(ratioParser::Assignment_listContext * /*ctx*/) override {}

  virtual void enterAssignment(ratioParser::AssignmentContext * /*ctx*/) override {}
  virtual void exitAssignment(ratioParser::AssignmentContext * /*ctx*/) override {}

  virtual void enterCast_expression(ratioParser::Cast_expressionContext * /*ctx*/) override {}
  virtual void exitCast_expression(ratioParser::Cast_expressionContext * /*ctx*/) override {}

  virtual void enterQualified_id_expression(ratioParser::Qualified_id_expressionContext * /*ctx*/) override {}
  virtual void exitQualified_id_expression(ratioParser::Qualified_id_expressionContext * /*ctx*/) override {}

  virtual void enterDivision_expression(ratioParser::Division_expressionContext * /*ctx*/) override {}
  virtual void exitDivision_expression(ratioParser::Division_expressionContext * /*ctx*/) override {}

  virtual void enterSubtraction_expression(ratioParser::Subtraction_expressionContext * /*ctx*/) override {}
  virtual void exitSubtraction_expression(ratioParser::Subtraction_expressionContext * /*ctx*/) override {}

  virtual void enterExtc_one_expression(ratioParser::Extc_one_expressionContext * /*ctx*/) override {}
  virtual void exitExtc_one_expression(ratioParser::Extc_one_expressionContext * /*ctx*/) override {}

  virtual void enterPlus_expression(ratioParser::Plus_expressionContext * /*ctx*/) override {}
  virtual void exitPlus_expression(ratioParser::Plus_expressionContext * /*ctx*/) override {}

  virtual void enterFunction_expression(ratioParser::Function_expressionContext * /*ctx*/) override {}
  virtual void exitFunction_expression(ratioParser::Function_expressionContext * /*ctx*/) override {}

  virtual void enterAddition_expression(ratioParser::Addition_expressionContext * /*ctx*/) override {}
  virtual void exitAddition_expression(ratioParser::Addition_expressionContext * /*ctx*/) override {}

  virtual void enterParentheses_expression(ratioParser::Parentheses_expressionContext * /*ctx*/) override {}
  virtual void exitParentheses_expression(ratioParser::Parentheses_expressionContext * /*ctx*/) override {}

  virtual void enterMinus_expression(ratioParser::Minus_expressionContext * /*ctx*/) override {}
  virtual void exitMinus_expression(ratioParser::Minus_expressionContext * /*ctx*/) override {}

  virtual void enterImplication_expression(ratioParser::Implication_expressionContext * /*ctx*/) override {}
  virtual void exitImplication_expression(ratioParser::Implication_expressionContext * /*ctx*/) override {}

  virtual void enterLt_expression(ratioParser::Lt_expressionContext * /*ctx*/) override {}
  virtual void exitLt_expression(ratioParser::Lt_expressionContext * /*ctx*/) override {}

  virtual void enterNot_expression(ratioParser::Not_expressionContext * /*ctx*/) override {}
  virtual void exitNot_expression(ratioParser::Not_expressionContext * /*ctx*/) override {}

  virtual void enterConjunction_expression(ratioParser::Conjunction_expressionContext * /*ctx*/) override {}
  virtual void exitConjunction_expression(ratioParser::Conjunction_expressionContext * /*ctx*/) override {}

  virtual void enterGeq_expression(ratioParser::Geq_expressionContext * /*ctx*/) override {}
  virtual void exitGeq_expression(ratioParser::Geq_expressionContext * /*ctx*/) override {}

  virtual void enterRange_expression(ratioParser::Range_expressionContext * /*ctx*/) override {}
  virtual void exitRange_expression(ratioParser::Range_expressionContext * /*ctx*/) override {}

  virtual void enterMultiplication_expression(ratioParser::Multiplication_expressionContext * /*ctx*/) override {}
  virtual void exitMultiplication_expression(ratioParser::Multiplication_expressionContext * /*ctx*/) override {}

  virtual void enterLeq_expression(ratioParser::Leq_expressionContext * /*ctx*/) override {}
  virtual void exitLeq_expression(ratioParser::Leq_expressionContext * /*ctx*/) override {}

  virtual void enterGt_expression(ratioParser::Gt_expressionContext * /*ctx*/) override {}
  virtual void exitGt_expression(ratioParser::Gt_expressionContext * /*ctx*/) override {}

  virtual void enterConstructor_expression(ratioParser::Constructor_expressionContext * /*ctx*/) override {}
  virtual void exitConstructor_expression(ratioParser::Constructor_expressionContext * /*ctx*/) override {}

  virtual void enterDisjunction_expression(ratioParser::Disjunction_expressionContext * /*ctx*/) override {}
  virtual void exitDisjunction_expression(ratioParser::Disjunction_expressionContext * /*ctx*/) override {}

  virtual void enterLiteral_expression(ratioParser::Literal_expressionContext * /*ctx*/) override {}
  virtual void exitLiteral_expression(ratioParser::Literal_expressionContext * /*ctx*/) override {}

  virtual void enterEq_expression(ratioParser::Eq_expressionContext * /*ctx*/) override {}
  virtual void exitEq_expression(ratioParser::Eq_expressionContext * /*ctx*/) override {}

  virtual void enterNeq_expression(ratioParser::Neq_expressionContext * /*ctx*/) override {}
  virtual void exitNeq_expression(ratioParser::Neq_expressionContext * /*ctx*/) override {}

  virtual void enterExpr_list(ratioParser::Expr_listContext * /*ctx*/) override {}
  virtual void exitExpr_list(ratioParser::Expr_listContext * /*ctx*/) override {}

  virtual void enterLiteral(ratioParser::LiteralContext * /*ctx*/) override {}
  virtual void exitLiteral(ratioParser::LiteralContext * /*ctx*/) override {}

  virtual void enterQualified_id(ratioParser::Qualified_idContext * /*ctx*/) override {}
  virtual void exitQualified_id(ratioParser::Qualified_idContext * /*ctx*/) override {}

  virtual void enterType(ratioParser::TypeContext * /*ctx*/) override {}
  virtual void exitType(ratioParser::TypeContext * /*ctx*/) override {}

  virtual void enterClass_type(ratioParser::Class_typeContext * /*ctx*/) override {}
  virtual void exitClass_type(ratioParser::Class_typeContext * /*ctx*/) override {}

  virtual void enterPrimitive_type(ratioParser::Primitive_typeContext * /*ctx*/) override {}
  virtual void exitPrimitive_type(ratioParser::Primitive_typeContext * /*ctx*/) override {}

  virtual void enterType_list(ratioParser::Type_listContext * /*ctx*/) override {}
  virtual void exitType_list(ratioParser::Type_listContext * /*ctx*/) override {}

  virtual void enterTyped_list(ratioParser::Typed_listContext * /*ctx*/) override {}
  virtual void exitTyped_list(ratioParser::Typed_listContext * /*ctx*/) override {}

  virtual void enterQualified_predicate(ratioParser::Qualified_predicateContext * /*ctx*/) override {}
  virtual void exitQualified_predicate(ratioParser::Qualified_predicateContext * /*ctx*/) override {}

  virtual void enterPredicate_list(ratioParser::Predicate_listContext * /*ctx*/) override {}
  virtual void exitPredicate_list(ratioParser::Predicate_listContext * /*ctx*/) override {}

  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override {}
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override {}
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override {}
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override {}
};

} // namespace lucy
