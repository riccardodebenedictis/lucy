#include "statement.h"
#include "context.h"

namespace lucy
{

namespace ast
{

statement::statement(core &cr) : cr(cr) {}
statement::~statement() {}

assignment_statement::assignment_statement(core &cr, const std::vector<std::string> &q_id, expression *const e) : statement(cr), qualified_id(q_id), xpr(e) {}
assignment_statement::~assignment_statement() {}
bool assignment_statement::execute(context &ctx) const { return false; }

local_field_statement::local_field_statement(core &cr, const std::vector<std::string> &ft, const std::string &n, expression *const e) : statement(cr), field_type(ft), name(n), xpr(e) {}
local_field_statement::~local_field_statement() {}
bool local_field_statement::execute(context &ctx) const { return false; }

expression_statement::expression_statement(core &cr, bool_expression *const e) : statement(cr), xpr(e) {}
expression_statement::~expression_statement() {}
bool expression_statement::execute(context &ctx) const { return false; }

block_statement::block_statement(core &cr, const std::vector<statement *> &stmnts) : statement(cr), statements(stmnts) {}
block_statement::~block_statement() {}
bool block_statement::execute(context &ctx) const { return false; }

disjunction_statement::disjunction_statement(core &cr, const std::vector<block_statement *> &disjs) : statement(cr), disjunctions(disjs) {}
disjunction_statement::~disjunction_statement() {}
bool disjunction_statement::execute(context &ctx) const { return false; }

formula_statement::formula_statement(core &cr, const bool &isf, const std::string &fn, const std::vector<std::string> &scp, const std::string &pn, const std::vector<std::pair<std::string, expression *>> &assns) : statement(cr), is_fact(isf), formula_name(fn), formula_scope(scp), predicate_name(pn), assignments(assns) {}
formula_statement::~formula_statement() {}
bool formula_statement::execute(context &ctx) const { return false; }

return_statement::return_statement(core &cr, expression *const e) : statement(cr), xpr(e) {}
return_statement::~return_statement() {}
bool return_statement::execute(context &ctx) const { return false; }
}
}