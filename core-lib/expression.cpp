#include "expression.h"
#include "context.h"

namespace lucy
{

namespace ast
{

expression::expression(core &cr) : cr(cr) {}
expression::~expression() {}

cast_expression::cast_expression(core &cr, const std::vector<std::string> &tp, const expression *const e) : expression(cr), cast_to_type(tp), xpr(e) {}
cast_expression::~cast_expression() {}
expr cast_expression::evaluate(context &ctx) const { return expr(nullptr); }

constructor_expression::constructor_expression(core &cr, const std::vector<std::string> &it, const std::vector<expression *> &es) : expression(cr), instance_type(it), expressions(es) {}
constructor_expression::~constructor_expression() {}
expr constructor_expression::evaluate(context &ctx) const { return expr(nullptr); }

id_expression::id_expression(core &cr, const std::vector<std::string> &is) : expression(cr), ids(is) {}
id_expression::~id_expression() {}
expr id_expression::evaluate(context &ctx) const { return expr(nullptr); }

function_expression::function_expression(core &cr, const std::vector<std::string> &is, const std::string &fn, const std::vector<expression *> &es) : expression(cr), ids(is), function_name(fn), expressions(es) {}
function_expression::~function_expression() {}
expr function_expression::evaluate(context &ctx) const { return expr(nullptr); }

string_literal_expression::string_literal_expression(core &cr, const std::string &l) : expression(cr), literal(l) {}
string_literal_expression::~string_literal_expression() {}
expr string_literal_expression::evaluate(context &ctx) const { return expr(nullptr); }

arith_expression::arith_expression(core &cr) : expression(cr) {}
arith_expression::~arith_expression() {}

arith_literal_expression::arith_literal_expression(core &cr, const double &l) : arith_expression(cr), literal(l) {}
arith_literal_expression::~arith_literal_expression() {}
expr arith_literal_expression::evaluate(context &ctx) const { return expr(nullptr); }

plus_expression::plus_expression(core &cr, const arith_expression *const e) : arith_expression(cr), xpr(e) {}
plus_expression::~plus_expression() {}
expr plus_expression::evaluate(context &ctx) const { return expr(nullptr); }

minus_expression::minus_expression(core &cr, const arith_expression *const e) : arith_expression(cr), xpr(e) {}
minus_expression::~minus_expression() {}
expr minus_expression::evaluate(context &ctx) const { return expr(nullptr); }

range_expression::range_expression(core &cr, const arith_expression *const min_e, const arith_expression *const max_e) : arith_expression(cr), min_xpr(min_e), max_xpr(max_e) {}
range_expression::~range_expression() {}
expr range_expression::evaluate(context &ctx) const { return expr(nullptr); }

addition_expression::addition_expression(core &cr, const std::vector<arith_expression *> &es) : arith_expression(cr), expressions(es) {}
addition_expression::~addition_expression() {}
expr addition_expression::evaluate(context &ctx) const { return expr(nullptr); }

subtraction_expression::subtraction_expression(core &cr, const std::vector<arith_expression *> &es) : arith_expression(cr), expressions(es) {}
subtraction_expression::~subtraction_expression() {}
expr subtraction_expression::evaluate(context &ctx) const { return expr(nullptr); }

multiplication_expression::multiplication_expression(core &cr, const std::vector<arith_expression *> &es) : arith_expression(cr), expressions(es) {}
multiplication_expression::~multiplication_expression() {}
expr multiplication_expression::evaluate(context &ctx) const { return expr(nullptr); }

division_expression::division_expression(core &cr, const std::vector<arith_expression *> &es) : arith_expression(cr), expressions(es) {}
division_expression::~division_expression() {}
expr division_expression::evaluate(context &ctx) const { return expr(nullptr); }

bool_expression::bool_expression(core &cr) : expression(cr) {}
bool_expression::~bool_expression() {}

bool_literal_expression::bool_literal_expression(core &cr, const bool &l) : bool_expression(cr), literal(l) {}
bool_literal_expression::~bool_literal_expression() {}
expr bool_literal_expression::evaluate(context &ctx) const { return expr(nullptr); }

eq_expression::eq_expression(core &cr, const expression *const l, const expression *const r) : bool_expression(cr), left(l), right(r) {}
eq_expression::~eq_expression() {}
expr eq_expression::evaluate(context &ctx) const { return expr(nullptr); }

neq_expression::neq_expression(core &cr, const expression *const l, const expression *const r) : bool_expression(cr), left(l), right(r) {}
neq_expression::~neq_expression() {}
expr neq_expression::evaluate(context &ctx) const { return expr(nullptr); }

lt_expression::lt_expression(core &cr, const arith_expression *const l, const arith_expression *const r) : bool_expression(cr), left(l), right(r) {}
lt_expression::~lt_expression() {}
expr lt_expression::evaluate(context &ctx) const { return expr(nullptr); }

leq_expression::leq_expression(core &cr, const arith_expression *const l, const arith_expression *const r) : bool_expression(cr), left(l), right(r) {}
leq_expression::~leq_expression() {}
expr leq_expression::evaluate(context &ctx) const { return expr(nullptr); }

geq_expression::geq_expression(core &cr, const arith_expression *const l, const arith_expression *const r) : bool_expression(cr), left(l), right(r) {}
geq_expression::~geq_expression() {}
expr geq_expression::evaluate(context &ctx) const { return expr(nullptr); }

gt_expression::gt_expression(core &cr, const arith_expression *const l, const arith_expression *const r) : bool_expression(cr), left(l), right(r) {}
gt_expression::~gt_expression() {}
expr gt_expression::evaluate(context &ctx) const { return expr(nullptr); }

implication_expression::implication_expression(core &cr, const bool_expression *const l, const bool_expression *const r) : bool_expression(cr), left(l), right(r) {}
implication_expression::~implication_expression() {}
expr implication_expression::evaluate(context &ctx) const { return expr(nullptr); }

disjunction_expression::disjunction_expression(core &cr, const std::vector<bool_expression *> &es) : bool_expression(cr), expressions(es) {}
disjunction_expression::~disjunction_expression() {}
expr disjunction_expression::evaluate(context &ctx) const { return expr(nullptr); }

conjunction_expression::conjunction_expression(core &cr, const std::vector<bool_expression *> &es) : bool_expression(cr), expressions(es) {}
conjunction_expression::~conjunction_expression() {}
expr conjunction_expression::evaluate(context &ctx) const { return expr(nullptr); }

exct_one_expression::exct_one_expression(core &cr, const std::vector<bool_expression *> &es) : bool_expression(cr), expressions(es) {}
exct_one_expression::~exct_one_expression() {}
expr exct_one_expression::evaluate(context &ctx) const { return expr(nullptr); }

not_expression::not_expression(core &cr, const bool_expression *const e) : bool_expression(cr), xpr(e) {}
not_expression::~not_expression() {}
expr not_expression::evaluate(context &ctx) const { return expr(nullptr); }
}
}