#include "defined_method.h"
#include "statement_visitor.h"

namespace lucy
{

defined_method::defined_method(core &cr, scope &scp, const std::string &name, const std::vector<field *> &args, ratioParser::BlockContext &b, const type *const return_type) : method(cr, scp, name, args, return_type), block(b) {}

defined_method::~defined_method() {}

bool defined_method::invoke(context &ctx, const std::vector<expr> &exprs)
{
    return statement_visitor(cr, ctx).visit(&block).as<bool>();
}
}