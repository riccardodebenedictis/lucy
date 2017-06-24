#include "constructor.h"
#include "field.h"
#include "type.h"
#include "item.h"
#include <cassert>

namespace lucy
{

constructor::constructor(core &cr, scope &scp, const std::vector<field *> &args, const std::vector<std::pair<std::string, std::vector<ast::expression *>>> &il, const std::vector<ast::statement *> &stmnts) : scope(cr, scp), args(args), init_list(il), statements(stmnts)
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

bool constructor::invoke(item &i, const std::vector<expr> &exprs)
{
    context c_ctx(&i);
    for (size_t i = 0; i < args.size(); i++)
    {
        set(*c_ctx, args[i]->name, exprs[i]);
    }

    for (const auto &s : statements)
    {
        if (!s->execute(c_ctx))
            return false;
    }
    return true;
}
}