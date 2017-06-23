#include "statement.h"

namespace lucy
{

namespace ast
{

statement::statement() {}
statement::~statement() {}

assignment_statement::assignment_statement(const std::vector<std::string> &q_id, expr *const e) : qualified_id(q_id), xpr(e) {}
assignment_statement::~assignment_statement() {}

local_field_statement::local_field_statement(const std::vector<std::string> &ft, const std::string &n, expr *const e) : field_type(ft), name(n), xpr(e) {}
local_field_statement::~local_field_statement() {}

expression_statement::expression_statement(bool_expr *const e) : xpr(e) {}
expression_statement::~expression_statement() {}

block_statement::block_statement(const std::vector<statement *> &stmnts) : statements(stmnts) {}
block_statement::~block_statement() {}

disjunction_statement::disjunction_statement(const std::vector<block_statement *> &disjs) : disjunctions(disjs) {}
disjunction_statement::~disjunction_statement() {}

formula_statement::formula_statement(const bool &isf, const std::string &fn, const std::vector<std::string> &scp, const std::string &pn, const std::vector<std::pair<std::string, expr *>> &assns) : is_fact(isf), formula_name(fn), formula_scope(scp), predicate_name(pn), assignments(assns) {}
formula_statement::~formula_statement() {}

return_statement::return_statement(expr *const e) : xpr(e) {}
return_statement::~return_statement() {}
}
}