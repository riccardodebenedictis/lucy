#include "statement.h"
#include "atom.h"
#include "predicate.h"
#include "core.h"
#include "disjunction.h"
#include "field.h"
#include "expression.h"

namespace lucy
{

namespace ast
{

statement::statement() {}
statement::~statement() {}

assignment_statement::assignment_statement(const std::vector<std::string> &is, const std::string &i, const expression *const e) : ids(is), id(i), xpr(e) {}
assignment_statement::~assignment_statement() { delete xpr; }
void assignment_statement::execute(const scope &scp, context &ctx) const
{
    env *c_e = &*ctx;
    for (const auto &c_id : ids)
        c_e = &*c_e->get(c_id);
    c_e->items.insert({id, xpr->evaluate(scp, ctx)});
}

local_field_statement::local_field_statement(const std::vector<std::string> &ft, const std::string &n, const expression *const e) : field_type(ft), name(n), xpr(e) {}
local_field_statement::~local_field_statement() { delete xpr; }
void local_field_statement::execute(const scope &scp, context &ctx) const
{
    if (xpr)
        ctx->items.insert({name, xpr->evaluate(scp, ctx)});
    else
    {
        scope *s = const_cast<scope *>(&scp);
        for (const auto &tp : field_type)
            s = &s->get_type(tp);
        type *t = static_cast<type *>(s);
        if (t->primitive)
            ctx->items.insert({name, t->new_instance(ctx)});
        else
            ctx->items.insert({name, t->new_existential()});
    }
    if (const core *c = dynamic_cast<const core *>(&scp)) // we create fields for root items..
        const_cast<core *>(c)->fields.insert({name, new field(ctx->items.at(name)->tp, name)});
}

expression_statement::expression_statement(const expression *const e) : xpr(e) {}
expression_statement::~expression_statement() { delete xpr; }
void expression_statement::execute(const scope &scp, context &ctx) const
{
    bool_expr be = xpr->evaluate(scp, ctx);
    if (scp.get_core().sat_cr.value(be->l) != False)
        scp.get_core().assert_facts({be->l});
    else
        throw inconsistency_exception();
}

block_statement::block_statement(const std::vector<const statement *> &stmnts) : statements(stmnts) {}
block_statement::~block_statement()
{
    for (const auto &st : statements)
        delete st;
}
void block_statement::execute(const scope &scp, context &ctx) const
{
    for (const auto &st : statements)
        st->execute(scp, ctx);
}

disjunction_statement::disjunction_statement(const std::vector<std::pair<std::vector<const statement *>, const expression *const>> &conjs) : conjunctions(conjs) {}
disjunction_statement::~disjunction_statement()
{
    for (const auto &c : conjunctions)
    {
        for (const auto &s : c.first)
            delete s;
        delete c.second;
    }
}
void disjunction_statement::execute(const scope &scp, context &ctx) const
{
    std::vector<const conjunction *> cs;
    for (const auto &c : conjunctions)
    {
        lin cost(1);
        if (c.second)
        {
            arith_expr a_xpr = c.second->evaluate(scp, ctx);
            cost = a_xpr->l;
        }
        cs.push_back(new conjunction(scp.get_core(), const_cast<scope &>(scp), cost, c.first));
    }
    disjunction *d = new disjunction(scp.get_core(), const_cast<scope &>(scp), cs);
    scp.get_core().new_disjunction(ctx, *d);
}

formula_statement::formula_statement(const bool &isf, const std::string &fn, const std::vector<std::string> &scp, const std::string &pn, const std::vector<std::pair<std::string, const expression *>> &assns) : is_fact(isf), formula_name(fn), formula_scope(scp), predicate_name(pn), assignments(assns) {}
formula_statement::~formula_statement()
{
    for (const auto &asgnmnt : assignments)
        delete asgnmnt.second;
}
void formula_statement::execute(const scope &scp, context &ctx) const
{
    predicate *p = nullptr;
    std::unordered_map<std::string, expr> assgnments;
    if (!formula_scope.empty()) // the scope is explicitely declared..
    {
        env *c_scope = &*ctx;
        for (const auto &s : formula_scope)
            c_scope = &*c_scope->get(s);
        p = &static_cast<item *>(c_scope)->tp.get_predicate(predicate_name);

        if (var_item *ee = dynamic_cast<var_item *>(c_scope)) // the scope is an enumerative expression..
            assgnments.insert({TAU, ee});
        else // the scope is a single item..
            assgnments.insert({TAU, context(c_scope)});
    }
    else
    {
        p = &scp.get_predicate(predicate_name);
        if (&p->get_scope() != &scp.get_core()) // we inherit the scope..
            assgnments.insert({TAU, ctx->get(TAU)});
    }

    for (const auto &a : assignments)
    {
        expr e = a.second->evaluate(scp, ctx);
        const type &tt = p->get_field(a.first).tp; // the target type..
        if (tt.is_assignable_from(e->tp))          // the target type is a superclass of the assignment..
            assgnments.insert({a.first, e});
        else if (e->tp.is_assignable_from(tt))                // the target type is a subclass of the assignment..
            if (var_item *ae = dynamic_cast<var_item *>(&*e)) // some of the allowed values might be inhibited..
            {
                std::unordered_set<var_value *> alwd_vals = scp.get_core().ov_th.value(ae->ev); // the allowed values..
                std::vector<lit> not_alwd_vals;                                                 // the not allowed values..
                for (const auto &ev : alwd_vals)
                    if (!tt.is_assignable_from(static_cast<item *>(ev)->tp)) // the target type is not a superclass of the value..
                        not_alwd_vals.push_back(lit(scp.get_core().ov_th.allows(ae->ev, *ev), false));
                if (alwd_vals.size() == not_alwd_vals.size()) // none of the values is allowed..
                    throw inconsistency_exception();          // no need to go further..
                else
                    scp.get_core().assert_facts(not_alwd_vals); // we inhibit the not allowed values..
            }
            else
                throw inconsistency_exception();
        else
            throw inconsistency_exception();
    }

    atom *a;
    if (assgnments.find(TAU) == assgnments.end())
    {
        // the new atom's scope is the core..
        context c_scope = &scp.get_core();
        a = static_cast<atom *>(&*p->new_instance(c_scope));
    }
    else
    {
        // we have computed the new atom's scope above..
        context c_scope = assgnments.at(TAU);
        a = static_cast<atom *>(&*p->new_instance(c_scope));
    }

    // we assign fields..
    a->items.insert(assgnments.begin(), assgnments.end());

    // we initialize atom's fields..
    std::queue<predicate *> q;
    q.push(p);
    while (!q.empty())
    {
        for (const auto &arg : q.front()->get_args())
        {
            if (a->items.find(arg->name) == a->items.end())
            {
                // the field is uninstantiated..
                type &tp = const_cast<type &>(arg->tp);
                if (tp.primitive)
                    a->items.insert({arg->name, tp.new_instance(ctx)});
                else
                    a->items.insert({arg->name, tp.new_existential()});
            }
        }
        for (const auto &sp : q.front()->get_supertypes())
            q.push(static_cast<predicate *>(sp));
        q.pop();
    }

    if (is_fact)
        scp.get_core().new_fact(*a);
    else
        scp.get_core().new_goal(*a);

    ctx->items.insert({formula_name, expr(a)});
}

return_statement::return_statement(const expression *const e) : xpr(e) {}
return_statement::~return_statement() { delete xpr; }
void return_statement::execute(const scope &scp, context &ctx) const { ctx->items.insert({RETURN_KEYWORD, xpr->evaluate(scp, ctx)}); }
}
}