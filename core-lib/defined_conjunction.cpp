#include "defined_conjunction.h"
#include "statement_visitor.h"
#include "context.h"
#include "env.h"

namespace lucy
{

defined_conjunction::defined_conjunction(core &cr, scope &scp, const lin &cst, ratioParser::BlockContext &b) : conjunction(cr, scp, cst), block(b) {}

defined_conjunction::~defined_conjunction() {}

bool defined_conjunction::apply(context &ctx) const
{
	context c(new env(cr, ctx));
	return statement_visitor(cr, c).visit(&block).as<bool>();
}
}