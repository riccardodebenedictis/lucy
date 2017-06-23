#include "expression.h"

namespace lucy
{

namespace ast
{

expression::expression() {}
expression::~expression() {}

cast_expression::cast_expression(const std::vector<std::string> &tp, expression *const e) : cast_to_type(tp), xpr(e) {}
cast_expression::~cast_expression() {}

constructor_expression::constructor_expression(const std::vector<std::string> &it, const std::vector<expression *> &es) : instance_type(it), expressions(es) {}
constructor_expression::~constructor_expression() {}

id_expression::id_expression(const std::vector<std::string> &is) : ids(is) {}
id_expression::~id_expression() {}

function_expression::function_expression(const std::vector<std::string> &is, const std::string &fn, const std::vector<expression *> &es) : ids(is), function_name(fn), expressions(es) {}
function_expression::~function_expression() {}

string_literal_expression::string_literal_expression(const std::string &l) : literal(l) {}
string_literal_expression::~string_literal_expression() {}

bool_expression::bool_expression() {}
bool_expression::~bool_expression() {}

bool_literal_expression::bool_literal_expression(const bool &l) : literal(l) {}
bool_literal_expression::~bool_literal_expression() {}

eq_expression::eq_expression(expression *const l, expression *const r) : left(l), right(r) {}
eq_expression::~eq_expression() {}

neq_expression::neq_expression(expression *const l, expression *const r) : left(l), right(r) {}
neq_expression::~neq_expression() {}

lt_expression::lt_expression(arith_expression *const l, arith_expression *const r) : left(l), right(r) {}
lt_expression::~lt_expression() {}

leq_expression::leq_expression(arith_expression *const l, arith_expression *const r) : left(l), right(r) {}
leq_expression::~leq_expression() {}

geq_expression::geq_expression(arith_expression *const l, arith_expression *const r) : left(l), right(r) {}
geq_expression::~geq_expression() {}

gt_expression::gt_expression(arith_expression *const l, arith_expression *const r) : left(l), right(r) {}
gt_expression::~gt_expression() {}

implication_expression::implication_expression(bool_expression *const l, bool_expression *const r) : left(l), right(r) {}
implication_expression::~implication_expression() {}

disjunction_expression::disjunction_expression(std::vector<bool_expression *> es) : expressions(es) {}
disjunction_expression::~disjunction_expression() {}

conjunction_expression::conjunction_expression(std::vector<bool_expression *> es) : expressions(es) {}
conjunction_expression::~conjunction_expression() {}

exct_one_expression::exct_one_expression(std::vector<bool_expression *> es) : expressions(es) {}
exct_one_expression::~exct_one_expression() {}

not_expression::not_expression(bool_expression *const e) : xpr(e) {}
not_expression::~not_expression() {}

arith_expression::arith_expression() {}
arith_expression::~arith_expression() {}

arith_literal_expression::arith_literal_expression(const double &l) : literal(l) {}
arith_literal_expression::~arith_literal_expression() {}

plus_expression::plus_expression(arith_expression *const e) : xpr(e) {}
plus_expression::~plus_expression() {}

minus_expression::minus_expression(arith_expression *const e) : xpr(e) {}
minus_expression::~minus_expression() {}

range_expression::range_expression(arith_expression *const min_e, arith_expression *const max_e) : min_xpr(min_e), max_xpr(max_e) {}
range_expression::~range_expression() {}

addition_expression::addition_expression(std::vector<arith_expression *> es) : expressions(es) {}
addition_expression::~addition_expression() {}

subtraction_expression::subtraction_expression(std::vector<arith_expression *> es) : expressions(es) {}
subtraction_expression::~subtraction_expression() {}

multiplication_expression::multiplication_expression(std::vector<arith_expression *> es) : expressions(es) {}
multiplication_expression::~multiplication_expression() {}

division_expression::division_expression(std::vector<arith_expression *> es) : expressions(es) {}
division_expression::~division_expression() {}
}
}