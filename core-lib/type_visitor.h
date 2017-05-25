#pragma once

#include "parser/ratioBaseVisitor.h"

namespace lucy
{

class core;

class type_visitor : public ratioBaseVisitor
{
  public:
	type_visitor(core &cr);
	type_visitor(const type_visitor &orig) = delete;
	virtual ~type_visitor();

  private:
	antlrcpp::Any visitLiteral_expression(ratioParser::Literal_expressionContext *ctx) override;
	antlrcpp::Any visitCast_expression(ratioParser::Cast_expressionContext *ctx) override;
	antlrcpp::Any visitPrimitive_type(ratioParser::Primitive_typeContext *ctx) override;
	antlrcpp::Any visitClass_type(ratioParser::Class_typeContext *ctx) override;
	antlrcpp::Any visitQualified_id(ratioParser::Qualified_idContext *ctx) override;
	antlrcpp::Any visitQualified_id_expression(ratioParser::Qualified_id_expressionContext *ctx) override;
	antlrcpp::Any visitConstructor_expression(ratioParser::Constructor_expressionContext *ctx) override;

  private:
	core &cr;
};
}