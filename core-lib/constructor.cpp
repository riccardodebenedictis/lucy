#include "constructor.h"
#include "field.h"
#include "type.h"
#include "context.h"
#include <cassert>

namespace lucy
{

constructor::constructor(core &cr, scope &scp, const std::vector<field *> &args) : scope(cr, scp), args(args)
{
    fields.insert({THIS_KEYWORD, new field(static_cast<type &>(scp), THIS_KEYWORD, true)});
    for (const auto &arg : args)
    {
        fields.insert({arg->name, new field(arg->tp, arg->name)});
    }
}

constructor::~constructor() {}

expr constructor::new_instance(context &ctx, const std::vector<expr> &exprs)
{
    assert(args.size() == exprs.size());

    type &t = static_cast<type &>(scp);
    expr i = t.new_instance(ctx);

    invoke(*i, exprs);

    return i;
}
}