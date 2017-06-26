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
    context ctx(new env(cr, &i));
    ctx->items.insert({THIS_KEYWORD, expr(&i)});
    for (size_t i = 0; i < args.size(); i++)
    {
        ctx->items.insert({args[i]->name, exprs[i]});
    }

    // we initialize the supertypes..
    size_t il_idx = 0;
    for (const auto &st : static_cast<type &>(scp).get_supertypes())
    {
        if (il_idx < init_list.size() && init_list[il_idx].first.compare(st->name) == 0) // explicit supertype constructor invocation..
        {
            std::vector<expr> exprs;
            std::vector<const type *> par_types;
            for (const auto &ex : init_list[il_idx].second)
            {
                expr c_expr = ex->evaluate(ctx);
                exprs.push_back(c_expr);
                par_types.push_back(&c_expr->tp);
            }

            // we assume the constructor exists..
            if (!st->get_constructor(par_types).invoke(i, exprs))
                return false;
            il_idx++;
        }
        else // implicit supertype (default) constructor invocation..
        {
            // we assume the default constructor exists..
            if (!st->get_constructor({}).invoke(i, {}))
                return false;
        }
    }
    for (; il_idx < init_list.size(); il_idx++)
    {
        std::vector<expr> exprs;
        std::vector<const type *> par_types;
        for (const auto &ex : init_list[il_idx].second)
        {
            expr c_expr = ex->evaluate(ctx);
            exprs.push_back(c_expr);
            par_types.push_back(&c_expr->tp);
        }
        i.items.insert({init_list[il_idx].first, static_cast<type &>(scp).get_field(init_list[il_idx].first).tp.get_constructor(par_types).new_instance(ctx, exprs)});
    }

    // we instantiate the uninstantiated fields..
    for (const auto &f : scp.get_fields())
    {
        if (!f.second->synthetic && !i.is_instantiated(f.second->name))
        {
            i.items.insert({f.second->name, f.second->new_instance(ctx)});
        }
    }

    // we execute the constructor body..
    for (const auto &s : statements)
    {
        if (!s->execute(ctx))
            return false;
    }
    return true;
}
}