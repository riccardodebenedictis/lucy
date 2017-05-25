#pragma once

#include "parser/ratioBaseVisitor.h"

namespace lucy
{

class core;
class context;

class statement_visitor : public ratioBaseVisitor
{
  public:
	statement_visitor(core &cr, context &cntx);
	statement_visitor(const statement_visitor &orig) = delete;
	virtual ~statement_visitor();

  private:
	antlrcpp::Any visitCompilation_unit(ratioParser::Compilation_unitContext *ctx) override;
	antlrcpp::Any visitBlock(ratioParser::BlockContext *ctx) override;
	antlrcpp::Any visitConjunction(ratioParser::ConjunctionContext *ctx) override;
	antlrcpp::Any visitAssignment_statement(ratioParser::Assignment_statementContext *ctx) override;
	antlrcpp::Any visitLocal_variable_statement(ratioParser::Local_variable_statementContext *ctx) override;
	antlrcpp::Any visitExpression_statement(ratioParser::Expression_statementContext *ctx) override;
	antlrcpp::Any visitFormula_statement(ratioParser::Formula_statementContext *ctx) override;
	antlrcpp::Any visitReturn_statement(ratioParser::Return_statementContext *ctx) override;
	antlrcpp::Any visitDisjunction_statement(ratioParser::Disjunction_statementContext *ctx) override;

  private:
	core &cr;
	context &cntx;
};
}