#pragma once

#include "parser/ratioBaseVisitor.h"

namespace lucy
{

class core;
class context;

class expression_visitor : public ratioBaseVisitor
{
public:
  expression_visitor(core &cr, context &cntx);
  expression_visitor(const expression_visitor &orig) = delete;
  virtual ~expression_visitor();

private:
  antlrcpp::Any visitLiteral_expression(ratioParser::Literal_expressionContext *ctx) override;
  antlrcpp::Any visitParentheses_expression(ratioParser::Parentheses_expressionContext *ctx) override;
  antlrcpp::Any visitMultiplication_expression(ratioParser::Multiplication_expressionContext *ctx) override;
  antlrcpp::Any visitDivision_expression(ratioParser::Division_expressionContext *ctx) override;
  antlrcpp::Any visitAddition_expression(ratioParser::Addition_expressionContext *ctx) override;
  antlrcpp::Any visitSubtraction_expression(ratioParser::Subtraction_expressionContext *ctx) override;
  antlrcpp::Any visitMinus_expression(ratioParser::Minus_expressionContext *ctx) override;
  antlrcpp::Any visitNot_expression(ratioParser::Not_expressionContext *ctx) override;
  antlrcpp::Any visitQualified_id(ratioParser::Qualified_idContext *ctx) override;
  antlrcpp::Any visitQualified_id_expression(ratioParser::Qualified_id_expressionContext *ctx) override;
  antlrcpp::Any visitFunction_expression(ratioParser::Function_expressionContext *ctx) override;
  antlrcpp::Any visitRange_expression(ratioParser::Range_expressionContext *ctx) override;
  antlrcpp::Any visitConstructor_expression(ratioParser::Constructor_expressionContext *ctx) override;
  antlrcpp::Any visitEq_expression(ratioParser::Eq_expressionContext *ctx) override;
  antlrcpp::Any visitLt_expression(ratioParser::Lt_expressionContext *ctx) override;
  antlrcpp::Any visitLeq_expression(ratioParser::Leq_expressionContext *ctx) override;
  antlrcpp::Any visitGeq_expression(ratioParser::Geq_expressionContext *ctx) override;
  antlrcpp::Any visitGt_expression(ratioParser::Gt_expressionContext *ctx) override;
  antlrcpp::Any visitNeq_expression(ratioParser::Neq_expressionContext *ctx) override;
  antlrcpp::Any visitImplication_expression(ratioParser::Implication_expressionContext *ctx) override;
  antlrcpp::Any visitConjunction_expression(ratioParser::Conjunction_expressionContext *ctx) override;
  antlrcpp::Any visitDisjunction_expression(ratioParser::Disjunction_expressionContext *ctx) override;
  antlrcpp::Any visitExtc_one_expression(ratioParser::Extc_one_expressionContext *ctx) override;

private:
  core &cr;
  context &cntx;
};
}