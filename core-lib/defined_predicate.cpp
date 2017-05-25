#include "defined_predicate.h"
#include "context.h"
#include "atom.h"
#include "statement_visitor.h"

namespace lucy
{

defined_predicate::defined_predicate(core &cr, scope &scp, const std::string &name, const std::vector<field *> &args, ratioParser::BlockContext &b) : predicate(cr, scp, name, args), block(b) {}

defined_predicate::~defined_predicate() {}

bool defined_predicate::apply_rule(atom &a) const
{
    for (const auto &sp : supertypes)
    {
        if (!static_cast<predicate *>(sp)->apply_rule(a))
        {
            return false;
        }
    }

    context ctx(new env(cr, &a));
    set(*ctx, THIS_KEYWORD, &a);
    return statement_visitor(cr, ctx).visit(&block).as<bool>();
}
}