#include "instantiated_field.h"
#include "context.h"
#include "item.h"
#include "expression_visitor.h"

namespace lucy
{

instantiated_field::instantiated_field(const type &t, const std::string &name, ratioParser::ExprContext &expr_c) : field(t, name), expr_c(expr_c) {}

instantiated_field::~instantiated_field() {}

expr instantiated_field::new_instance(context &ctx)
{
	return expression_visitor(ctx->get_core(), ctx).visit(&expr_c).as<expr>();
}
}