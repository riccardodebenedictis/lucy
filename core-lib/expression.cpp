#include "expression.h"
#include "core.h"
#include "item.h"
#include "type.h"
#include "constructor.h"
#include "method.h"

namespace lucy
{

namespace ast
{

expression::expression() {}
expression::~expression() {}

cast_expression::cast_expression(const std::vector<std::string> &tp, const expression *const e) : cast_to_type(tp), xpr(e) {}
cast_expression::~cast_expression() {}
expr cast_expression::evaluate(const scope &scp, context &ctx) const { return xpr->evaluate(scp, ctx); }

constructor_expression::constructor_expression(const std::vector<std::string> &it, const std::vector<expression *> &es) : instance_type(it), expressions(es) {}
constructor_expression::~constructor_expression() {}
expr constructor_expression::evaluate(const scope &scp, context &ctx) const
{
    scope *s = const_cast<scope *>(&scp);
    for (const auto &tp : instance_type)
    {
        s = &s->get_type(tp);
    }

    std::vector<expr> exprs;
    std::vector<const type *> par_types;
    for (const auto &ex : expressions)
    {
        expr i = ex->evaluate(scp, ctx);
        exprs.push_back(i);
        par_types.push_back(&i->tp);
    }

    return static_cast<type *>(s)->get_constructor(par_types).new_instance(ctx, exprs);
}

id_expression::id_expression(const std::vector<std::string> &is) : ids(is) {}
id_expression::~id_expression() {}
expr id_expression::evaluate(const scope &scp, context &ctx) const
{
    env *c_e = &*ctx;
    for (const auto &id : ids)
    {
        c_e = &*c_e->get(id);
    }
    return expr(static_cast<item *>(c_e));
}

function_expression::function_expression(const std::vector<std::string> &is, const std::string &fn, const std::vector<expression *> &es) : ids(is), function_name(fn), expressions(es) {}
function_expression::~function_expression() {}
expr function_expression::evaluate(const scope &scp, context &ctx) const
{
    scope *s = const_cast<scope *>(&scp);
    for (const auto &id : ids)
    {
        s = &s->get_type(id);
    }

    std::vector<expr> exprs;
    std::vector<const type *> par_types;
    for (const auto &ex : expressions)
    {
        expr i = ex->evaluate(scp, ctx);
        exprs.push_back(i);
        par_types.push_back(&i->tp);
    }

    method &m = s->get_method(function_name, par_types);
    if (m.return_type)
    {
        if (m.return_type == &scp.get_core().get_type(BOOL_KEYWORD))
        {
            return bool_expr(static_cast<bool_item *>(m.invoke(ctx, exprs)));
        }
        else if (m.return_type == &scp.get_core().get_type(INT_KEYWORD) || m.return_type == &scp.get_core().get_type(REAL_KEYWORD))
        {
            return arith_expr(static_cast<arith_item *>(m.invoke(ctx, exprs)));
        }
        else
        {
            return expr(m.invoke(ctx, exprs));
        }
    }
    else
    {
        return scp.get_core().new_bool(true);
    }
}

string_literal_expression::string_literal_expression(const std::string &l) : literal(l) {}
string_literal_expression::~string_literal_expression() {}
expr string_literal_expression::evaluate(const scope &scp, context &ctx) const { return scp.get_core().new_string(literal); }

arith_expression::arith_expression() {}
arith_expression::~arith_expression() {}

int_literal_expression::int_literal_expression(const long &l) : literal(l) {}
int_literal_expression::~int_literal_expression() {}
expr int_literal_expression::evaluate(const scope &scp, context &ctx) const { return scp.get_core().new_int(literal); }

real_literal_expression::real_literal_expression(const double &l) : literal(l) {}
real_literal_expression::~real_literal_expression() {}
expr real_literal_expression::evaluate(const scope &scp, context &ctx) const { return scp.get_core().new_real(literal); }

plus_expression::plus_expression(const arith_expression *const e) : xpr(e) {}
plus_expression::~plus_expression() {}
expr plus_expression::evaluate(const scope &scp, context &ctx) const { return xpr->evaluate(scp, ctx); }

minus_expression::minus_expression(const arith_expression *const e) : xpr(e) {}
minus_expression::~minus_expression() {}
expr minus_expression::evaluate(const scope &scp, context &ctx) const { return scp.get_core().minus(xpr->evaluate(scp, ctx)); }

range_expression::range_expression(const arith_expression *const min_e, const arith_expression *const max_e) : min_xpr(min_e), max_xpr(max_e) {}
range_expression::~range_expression() {}
expr range_expression::evaluate(const scope &scp, context &ctx) const
{
    arith_expr min = min_xpr->evaluate(scp, ctx);
    arith_expr max = max_xpr->evaluate(scp, ctx);
    arith_expr var = (min->tp.name.compare(REAL_KEYWORD) == 0 || max->tp.name.compare(REAL_KEYWORD) == 0) ? scp.get_core().new_real() : scp.get_core().new_int();
    scp.get_core().assert_facts({scp.get_core().geq(var, min)->l, scp.get_core().leq(var, max)->l});
    return var;
}

addition_expression::addition_expression(const std::vector<arith_expression *> &es) : expressions(es) {}
addition_expression::~addition_expression() {}
expr addition_expression::evaluate(const scope &scp, context &ctx) const
{
    std::vector<arith_expr> exprs;
    for (const auto &e : expressions)
    {
        exprs.push_back(e->evaluate(scp, ctx));
    }
    return scp.get_core().add(exprs);
}

subtraction_expression::subtraction_expression(const std::vector<arith_expression *> &es) : expressions(es) {}
subtraction_expression::~subtraction_expression() {}
expr subtraction_expression::evaluate(const scope &scp, context &ctx) const
{
    std::vector<arith_expr> exprs;
    for (const auto &e : expressions)
    {
        exprs.push_back(e->evaluate(scp, ctx));
    }
    return scp.get_core().sub(exprs);
}

multiplication_expression::multiplication_expression(const std::vector<arith_expression *> &es) : expressions(es) {}
multiplication_expression::~multiplication_expression() {}
expr multiplication_expression::evaluate(const scope &scp, context &ctx) const
{
    std::vector<arith_expr> exprs;
    for (const auto &e : expressions)
    {
        exprs.push_back(e->evaluate(scp, ctx));
    }
    return scp.get_core().mult(exprs);
}

division_expression::division_expression(const std::vector<arith_expression *> &es) : expressions(es) {}
division_expression::~division_expression() {}
expr division_expression::evaluate(const scope &scp, context &ctx) const
{
    std::vector<arith_expr> exprs;
    for (const auto &e : expressions)
    {
        exprs.push_back(e->evaluate(scp, ctx));
    }
    return scp.get_core().div(exprs);
}

bool_expression::bool_expression() {}
bool_expression::~bool_expression() {}

bool_literal_expression::bool_literal_expression(const bool &l) : literal(l) {}
bool_literal_expression::~bool_literal_expression() {}
expr bool_literal_expression::evaluate(const scope &scp, context &ctx) const { return scp.get_core().new_bool(literal); }

eq_expression::eq_expression(const expression *const l, const expression *const r) : left(l), right(r) {}
eq_expression::~eq_expression() {}
expr eq_expression::evaluate(const scope &scp, context &ctx) const
{
    expr l = left->evaluate(scp, ctx);
    expr r = right->evaluate(scp, ctx);
    return scp.get_core().eq(l, r);
}

neq_expression::neq_expression(const expression *const l, const expression *const r) : left(l), right(r) {}
neq_expression::~neq_expression() {}
expr neq_expression::evaluate(const scope &scp, context &ctx) const
{
    expr l = left->evaluate(scp, ctx);
    expr r = right->evaluate(scp, ctx);
    return scp.get_core().negate(scp.get_core().eq(l, r));
}

lt_expression::lt_expression(const arith_expression *const l, const arith_expression *const r) : left(l), right(r) {}
lt_expression::~lt_expression() {}
expr lt_expression::evaluate(const scope &scp, context &ctx) const
{
    arith_expr l = left->evaluate(scp, ctx);
    arith_expr r = right->evaluate(scp, ctx);
    return scp.get_core().lt(l, r);
}

leq_expression::leq_expression(const arith_expression *const l, const arith_expression *const r) : left(l), right(r) {}
leq_expression::~leq_expression() {}
expr leq_expression::evaluate(const scope &scp, context &ctx) const
{
    arith_expr l = left->evaluate(scp, ctx);
    arith_expr r = right->evaluate(scp, ctx);
    return scp.get_core().leq(l, r);
}

geq_expression::geq_expression(const arith_expression *const l, const arith_expression *const r) : left(l), right(r) {}
geq_expression::~geq_expression() {}
expr geq_expression::evaluate(const scope &scp, context &ctx) const
{
    arith_expr l = left->evaluate(scp, ctx);
    arith_expr r = right->evaluate(scp, ctx);
    return scp.get_core().geq(l, r);
}

gt_expression::gt_expression(const arith_expression *const l, const arith_expression *const r) : left(l), right(r) {}
gt_expression::~gt_expression() {}
expr gt_expression::evaluate(const scope &scp, context &ctx) const
{
    arith_expr l = left->evaluate(scp, ctx);
    arith_expr r = right->evaluate(scp, ctx);
    return scp.get_core().gt(l, r);
}

implication_expression::implication_expression(const bool_expression *const l, const bool_expression *const r) : left(l), right(r) {}
implication_expression::~implication_expression() {}
expr implication_expression::evaluate(const scope &scp, context &ctx) const
{
    bool_expr l = left->evaluate(scp, ctx);
    bool_expr r = right->evaluate(scp, ctx);
    return scp.get_core().disj({scp.get_core().negate(l), r});
}

disjunction_expression::disjunction_expression(const std::vector<bool_expression *> &es) : expressions(es) {}
disjunction_expression::~disjunction_expression() {}
expr disjunction_expression::evaluate(const scope &scp, context &ctx) const
{
    std::vector<bool_expr> exprs;
    for (const auto &e : expressions)
    {
        exprs.push_back(e->evaluate(scp, ctx));
    }
    return scp.get_core().disj(exprs);
}

conjunction_expression::conjunction_expression(const std::vector<bool_expression *> &es) : expressions(es) {}
conjunction_expression::~conjunction_expression() {}
expr conjunction_expression::evaluate(const scope &scp, context &ctx) const
{
    std::vector<bool_expr> exprs;
    for (const auto &e : expressions)
    {
        exprs.push_back(e->evaluate(scp, ctx));
    }
    return scp.get_core().conj(exprs);
}

exct_one_expression::exct_one_expression(const std::vector<bool_expression *> &es) : expressions(es) {}
exct_one_expression::~exct_one_expression() {}
expr exct_one_expression::evaluate(const scope &scp, context &ctx) const
{
    std::vector<bool_expr> exprs;
    for (const auto &e : expressions)
    {
        exprs.push_back(e->evaluate(scp, ctx));
    }
    return scp.get_core().exct_one(exprs);
}

not_expression::not_expression(const bool_expression *const e) : xpr(e) {}
not_expression::~not_expression() {}
expr not_expression::evaluate(const scope &scp, context &ctx) const
{
    return scp.get_core().negate(xpr->evaluate(scp, ctx));
}
}
}