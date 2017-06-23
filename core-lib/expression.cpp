#include "expression.h"

namespace lucy
{

namespace ast
{

expr::expr() {}
expr::~expr() {}

cast_expr::cast_expr(const std::vector<std::string> &tp, expr *const e) : cast_to_type(tp), xpr(e) {}
cast_expr::~cast_expr() {}

constructor_expr::constructor_expr(const std::vector<std::string> &it, const std::vector<expr *> &es) : instance_type(it), exprs(es) {}
constructor_expr::~constructor_expr() {}

id_expr::id_expr(const std::vector<std::string> &is) : ids(is) {}
id_expr::~id_expr() {}

function_expr::function_expr(const std::vector<std::string> &is, const std::string &fn, const std::vector<expr *> &es) : ids(is), function_name(fn), exprs(es) {}
function_expr::~function_expr() {}

string_literal_expr::string_literal_expr(const std::string &l) : literal(l) {}
string_literal_expr::~string_literal_expr() {}

bool_expr::bool_expr() {}
bool_expr::~bool_expr() {}

bool_literal_expr::bool_literal_expr(const bool &l) : literal(l) {}
bool_literal_expr::~bool_literal_expr() {}

eq_expr::eq_expr(expr *const l, expr *const r) : left(l), right(r) {}
eq_expr::~eq_expr() {}

neq_expr::neq_expr(expr *const l, expr *const r) : left(l), right(r) {}
neq_expr::~neq_expr() {}

lt_expr::lt_expr(arith_expr *const l, arith_expr *const r) : left(l), right(r) {}
lt_expr::~lt_expr() {}

leq_expr::leq_expr(arith_expr *const l, arith_expr *const r) : left(l), right(r) {}
leq_expr::~leq_expr() {}

geq_expr::geq_expr(arith_expr *const l, arith_expr *const r) : left(l), right(r) {}
geq_expr::~geq_expr() {}

gt_expr::gt_expr(arith_expr *const l, arith_expr *const r) : left(l), right(r) {}
gt_expr::~gt_expr() {}

implication_expr::implication_expr(bool_expr *const l, bool_expr *const r) : left(l), right(r) {}
implication_expr::~implication_expr() {}

disjunction_expr::disjunction_expr(std::vector<bool_expr *> es) : exprs(es) {}
disjunction_expr::~disjunction_expr() {}

conjunction_expr::conjunction_expr(std::vector<bool_expr *> es) : exprs(es) {}
conjunction_expr::~conjunction_expr() {}

exct_one_expr::exct_one_expr(std::vector<bool_expr *> es) : exprs(es) {}
exct_one_expr::~exct_one_expr() {}

not_expr::not_expr(bool_expr *const e) : xpr(e) {}
not_expr::~not_expr() {}

arith_expr::arith_expr() {}
arith_expr::~arith_expr() {}

arith_literal_expr::arith_literal_expr(const double &l) : literal(l) {}
arith_literal_expr::~arith_literal_expr() {}

plus_expr::plus_expr(arith_expr *const e) : xpr(e) {}
plus_expr::~plus_expr() {}

minus_expr::minus_expr(arith_expr *const e) : xpr(e) {}
minus_expr::~minus_expr() {}

range_expr::range_expr(arith_expr *const min_e, arith_expr *const max_e) : min_xpr(min_e), max_xpr(max_e) {}
range_expr::~range_expr() {}

addition_expr::addition_expr(std::vector<arith_expr *> es) : exprs(es) {}
addition_expr::~addition_expr() {}

subtraction_expr::subtraction_expr(std::vector<arith_expr *> es) : exprs(es) {}
subtraction_expr::~subtraction_expr() {}

multiplication_expr::multiplication_expr(std::vector<arith_expr *> es) : exprs(es) {}
multiplication_expr::~multiplication_expr() {}

division_expr::division_expr(std::vector<arith_expr *> es) : exprs(es) {}
division_expr::~division_expr() {}
}
}