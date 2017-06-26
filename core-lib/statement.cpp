#include "statement.h"
#include "item.h"
#include "expression.h"

namespace lucy
{

namespace ast
{

statement::statement() {}
statement::~statement() {}

assignment_statement::assignment_statement(const std::vector<std::string> &is, const std::string &i, const expression *const e) : ids(is), id(i), xpr(e) {}
assignment_statement::~assignment_statement() {}

bool assignment_statement::execute(const scope &scp, context &ctx) const
{
    env *c_e = &*ctx;
    for (const auto &c_id : ids)
    {
        c_e = &*c_e->get(c_id);
    }
    c_e->items.insert({id, xpr->evaluate(ctx)});
    return true;
}

local_field_statement::local_field_statement(const std::vector<std::string> &ft, const std::string &n, const expression *const e) : field_type(ft), name(n), xpr(e) {}
local_field_statement::~local_field_statement() {}
bool local_field_statement::execute(const scope &scp, context &ctx) const { return false; }

expression_statement::expression_statement(const bool_expression *const e) : xpr(e) {}
expression_statement::~expression_statement() {}
bool expression_statement::execute(const scope &scp, context &ctx) const { return false; }

block_statement::block_statement(const std::vector<statement *> &stmnts) : statements(stmnts) {}
block_statement::~block_statement() {}
bool block_statement::execute(const scope &scp, context &ctx) const { return false; }

disjunction_statement::disjunction_statement(const std::vector<block_statement *> &disjs) : disjunctions(disjs) {}
disjunction_statement::~disjunction_statement() {}
bool disjunction_statement::execute(const scope &scp, context &ctx) const { return false; }

formula_statement::formula_statement(const bool &isf, const std::string &fn, const std::vector<std::string> &scp, const std::string &pn, const std::vector<std::pair<std::string, expression *>> &assns) : is_fact(isf), formula_name(fn), formula_scope(scp), predicate_name(pn), assignments(assns) {}
formula_statement::~formula_statement() {}
bool formula_statement::execute(const scope &scp, context &ctx) const { return false; }

return_statement::return_statement(const expression *const e) : xpr(e) {}
return_statement::~return_statement() {}
bool return_statement::execute(const scope &scp, context &ctx) const { return false; }
}
}