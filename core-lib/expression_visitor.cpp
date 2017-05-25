#include "expression_visitor.h"
#include "core.h"
#include "context.h"
#include "item.h"
#include "type.h"
#include "field.h"
#include "method.h"
#include "constructor.h"
#include "type_visitor.h"

namespace lucy
{

expression_visitor::expression_visitor(core &cr, context &cntx) : cr(cr), cntx(cntx) {}

expression_visitor::~expression_visitor() {}

antlrcpp::Any expression_visitor::visitLiteral_expression(ratioParser::Literal_expressionContext *ctx)
{
    if (ctx->literal()->numeric)
    {
        if (ctx->literal()->numeric->getText().find('.') != ctx->literal()->numeric->getText().npos)
        {
            return static_cast<expr>(cr.new_real(std::stod(ctx->literal()->numeric->getText())));
        }
        else
        {
            return static_cast<expr>(cr.new_int(std::stol(ctx->literal()->numeric->getText())));
        }
    }
    else if (ctx->literal()->string)
    {
        std::string val = ctx->literal()->string->getText();
        val = val.substr(1, val.size() - 2);
        return static_cast<expr>(cr.new_string(val));
    }
    else if (ctx->literal()->t)
    {
        return static_cast<expr>(cr.new_bool(true));
    }
    else if (ctx->literal()->f)
    {
        return static_cast<expr>(cr.new_bool(false));
    }
    else
    {
        return nullptr;
    }
}

antlrcpp::Any expression_visitor::visitParentheses_expression(ratioParser::Parentheses_expressionContext *ctx)
{
    return visit(ctx->expr()).as<expr>();
}

antlrcpp::Any expression_visitor::visitMultiplication_expression(ratioParser::Multiplication_expressionContext *ctx)
{
    std::vector<arith_expr> is;
    for (const auto &e : ctx->expr())
    {
        is.push_back(visit(e).as<expr>());
    }
    return static_cast<expr>(cr.mult(is));
}

antlrcpp::Any expression_visitor::visitDivision_expression(ratioParser::Division_expressionContext *ctx)
{
    return static_cast<expr>(cr.div(visit(ctx->expr(0)).as<expr>(), visit(ctx->expr(1)).as<expr>()));
}

antlrcpp::Any expression_visitor::visitAddition_expression(ratioParser::Addition_expressionContext *ctx)
{
    std::vector<arith_expr> is;
    for (const auto &e : ctx->expr())
    {
        is.push_back(visit(e).as<expr>());
    }
    return static_cast<expr>(cr.add(is));
}

antlrcpp::Any expression_visitor::visitSubtraction_expression(ratioParser::Subtraction_expressionContext *ctx)
{
    std::vector<arith_expr> is;
    for (const auto &e : ctx->expr())
    {
        is.push_back(visit(e).as<expr>());
    }
    return static_cast<expr>(cr.sub(is));
}

antlrcpp::Any expression_visitor::visitMinus_expression(ratioParser::Minus_expressionContext *ctx)
{
    return static_cast<expr>(cr.minus(visit(ctx->expr()).as<expr>()));
}

antlrcpp::Any expression_visitor::visitNot_expression(ratioParser::Not_expressionContext *ctx)
{
    return static_cast<expr>(cr.negate(visit(ctx->expr()).as<expr>()));
}

antlrcpp::Any expression_visitor::visitQualified_id(ratioParser::Qualified_idContext *ctx)
{
    env *c_env = &*cntx;
    if (ctx->t)
    {
        c_env = &*c_env->get(THIS_KEYWORD);
    }
    for (const auto &id : ctx->ID())
    {
        c_env = &*c_env->get(id->getText());
        if (!c_env)
        {
            cr.p->notifyErrorListeners(id->getSymbol(), "cannot find symbol..", nullptr);
            return nullptr;
        }
    }
    return expr(static_cast<item *>(c_env));
}

antlrcpp::Any expression_visitor::visitQualified_id_expression(ratioParser::Qualified_id_expressionContext *ctx)
{
    return visit(ctx->qualified_id()).as<expr>();
}

antlrcpp::Any expression_visitor::visitFunction_expression(ratioParser::Function_expressionContext *ctx)
{
    std::vector<expr> exprs;
    std::vector<const type *> par_types;
    if (ctx->expr_list())
    {
        for (const auto &ex : ctx->expr_list()->expr())
        {
            expr i = expression_visitor(cr, cntx).visit(ex).as<expr>();
            exprs.push_back(i);
            par_types.push_back(&i->tp);
        }
    }

    try
    {
        method *m;
        if (ctx->object)
        {
            expr obj = visit(ctx->object).as<expr>();
            m = &obj->tp.get_method(ctx->function_name->getText(), par_types);
        }
        else
        {
            m = &cr.scopes.at(ctx)->get_method(ctx->function_name->getText(), par_types);
        }

        context c_e(new env(cr, cntx));
        if (item *i = dynamic_cast<item *>(&*cntx->get_ctx()))
        {
            c_e->items.insert({THIS_KEYWORD, expr(i)});
        }
        for (unsigned int j = 0; j < m->args.size(); j++)
        {
            c_e->items.insert({m->args[j]->name, exprs[j]});
        }
        bool invoke = m->invoke(cntx, exprs);
        assert(invoke && "functions should not create inconsistencies..");
        return c_e->get(RETURN_KEYWORD);
    }
    catch (const std::out_of_range &ex)
    {
        cr.p->notifyErrorListeners(ctx->function_name, "cannot find method..", nullptr);
        throw ex;
    }
}

antlrcpp::Any expression_visitor::visitRange_expression(ratioParser::Range_expressionContext *ctx)
{
    arith_expr min = visit(ctx->min).as<expr>();
    arith_expr max = visit(ctx->max).as<expr>();
    arith_expr var = (min->tp.name.compare(REAL_KEYWORD) == 0 || max->tp.name.compare(REAL_KEYWORD) == 0) ? cr.new_real() : cr.new_int();
    bool assert_facts = cr.assert_facts({cr.geq(var, min)->l, cr.leq(var, max)->l});
    assert(assert_facts && "invalid range expression..");
    return static_cast<expr>(var);
}

antlrcpp::Any expression_visitor::visitConstructor_expression(ratioParser::Constructor_expressionContext *ctx)
{
    type *t = type_visitor(cr).visit(ctx->type()).as<type *>();
    std::vector<expr> exprs;
    std::vector<const type *> par_types;
    if (ctx->expr_list())
    {
        for (const auto &ex : ctx->expr_list()->expr())
        {
            expr i = expression_visitor(cr, cntx).visit(ex).as<expr>();
            exprs.push_back(i);
            par_types.push_back(&i->tp);
        }
    }

    try
    {
        return t->get_constructor(par_types).new_instance(cntx, exprs);
    }
    catch (const std::out_of_range &ex)
    {
        cr.p->notifyErrorListeners(ctx->start, "cannot find constructor..", nullptr);
        throw ex;
    }
}

antlrcpp::Any expression_visitor::visitEq_expression(ratioParser::Eq_expressionContext *ctx)
{
    return static_cast<expr>(cr.eq(visit(ctx->expr(0)).as<expr>(), visit(ctx->expr(1)).as<expr>()));
}

antlrcpp::Any expression_visitor::visitLt_expression(ratioParser::Lt_expressionContext *ctx)
{
    return static_cast<expr>(cr.lt(visit(ctx->expr(0)).as<expr>(), visit(ctx->expr(1)).as<expr>()));
}

antlrcpp::Any expression_visitor::visitLeq_expression(ratioParser::Leq_expressionContext *ctx)
{
    return static_cast<expr>(cr.leq(visit(ctx->expr(0)).as<expr>(), visit(ctx->expr(1)).as<expr>()));
}

antlrcpp::Any expression_visitor::visitGeq_expression(ratioParser::Geq_expressionContext *ctx)
{
    return static_cast<expr>(cr.geq(visit(ctx->expr(0)).as<expr>(), visit(ctx->expr(1)).as<expr>()));
}

antlrcpp::Any expression_visitor::visitGt_expression(ratioParser::Gt_expressionContext *ctx)
{
    return static_cast<expr>(cr.gt(visit(ctx->expr(0)).as<expr>(), visit(ctx->expr(1)).as<expr>()));
}

antlrcpp::Any expression_visitor::visitNeq_expression(ratioParser::Neq_expressionContext *ctx)
{
    return static_cast<expr>(cr.negate(cr.eq(visit(ctx->expr(0)).as<expr>(), visit(ctx->expr(1)).as<expr>())));
}

antlrcpp::Any expression_visitor::visitImplication_expression(ratioParser::Implication_expressionContext *ctx)
{
    return static_cast<expr>(cr.disj({cr.negate(visit(ctx->expr(0)).as<expr>()), visit(ctx->expr(1)).as<expr>()}));
}

antlrcpp::Any expression_visitor::visitConjunction_expression(ratioParser::Conjunction_expressionContext *ctx)
{
    std::vector<bool_expr> is;
    for (const auto &e : ctx->expr())
    {
        is.push_back(visit(e).as<expr>());
    }
    return static_cast<expr>(cr.conj(is));
}

antlrcpp::Any expression_visitor::visitDisjunction_expression(ratioParser::Disjunction_expressionContext *ctx)
{
    std::vector<bool_expr> is;
    for (const auto &e : ctx->expr())
    {
        is.push_back(visit(e).as<expr>());
    }
    return static_cast<expr>(cr.disj(is));
}

antlrcpp::Any expression_visitor::visitExtc_one_expression(ratioParser::Extc_one_expressionContext *ctx)
{
    std::vector<bool_expr> is;
    for (const auto &e : ctx->expr())
    {
        is.push_back(visit(e).as<expr>());
    }
    return static_cast<expr>(cr.exct_one(is));
}
}