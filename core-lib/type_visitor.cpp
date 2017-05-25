#include "type_visitor.h"
#include "core.h"
#include "type.h"
#include "field.h"

namespace lucy
{

type_visitor::type_visitor(core &cr) : cr(cr) {}

type_visitor::~type_visitor() {}

antlrcpp::Any type_visitor::visitLiteral_expression(ratioParser::Literal_expressionContext *ctx)
{
	if (ctx->literal()->numeric)
	{
		if (ctx->literal()->numeric->getText().find('.') != ctx->literal()->numeric->getText().npos)
		{
			return &cr.get_type(REAL_KEYWORD);
		}
		else
		{
			return &cr.get_type(INT_KEYWORD);
		}
	}
	else if (ctx->literal()->string)
	{
		return &cr.get_type(STRING_KEYWORD);
	}
	else if (ctx->literal()->t)
	{
		return &cr.get_type(BOOL_KEYWORD);
	}
	else if (ctx->literal()->f)
	{
		return &cr.get_type(BOOL_KEYWORD);
	}
	else
	{
		std::unexpected();
	}
}

antlrcpp::Any type_visitor::visitCast_expression(ratioParser::Cast_expressionContext *ctx)
{
	return visit(ctx->type()).as<type *>();
}

antlrcpp::Any type_visitor::visitPrimitive_type(ratioParser::Primitive_typeContext *ctx)
{
	return &cr.get_type(ctx->getText());
}

antlrcpp::Any type_visitor::visitClass_type(ratioParser::Class_typeContext *ctx)
{
	scope *s = cr.scopes.at(ctx);
	for (const auto &id : ctx->ID())
	{
		try
		{
			s = &s->get_type(id->getText());
		}
		catch (const std::out_of_range &ex)
		{
			cr.p->notifyErrorListeners(id->getSymbol(), "cannot find symbol..", nullptr);
			throw ex;
		}
	}
	return static_cast<type *>(s);
}

antlrcpp::Any type_visitor::visitQualified_id(ratioParser::Qualified_idContext *ctx)
{
	const scope *s = cr.scopes.at(ctx);
	if (ctx->t)
	{
		s = &s->get_field(THIS_KEYWORD).tp;
	}
	for (const auto &id : ctx->ID())
	{
		try
		{
			s = &s->get_field(id->getText()).tp;
		}
		catch (const std::out_of_range &ex)
		{
			cr.p->notifyErrorListeners(id->getSymbol(), "cannot find symbol..", nullptr);
			throw ex;
		}
	}
	return const_cast<type *>(static_cast<const type *>(s));
}

antlrcpp::Any type_visitor::visitQualified_id_expression(ratioParser::Qualified_id_expressionContext *ctx)
{
	return visit(ctx->qualified_id()).as<type *>();
}

antlrcpp::Any type_visitor::visitConstructor_expression(ratioParser::Constructor_expressionContext *ctx)
{
	return visit(ctx->type()).as<type *>();
}
}