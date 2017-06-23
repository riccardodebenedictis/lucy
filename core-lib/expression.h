#pragma once

#include <vector>
#include <string>

namespace lucy
{

namespace ast
{

class bool_expression;
class arith_expression;

class expression
{
public:
  expression();
  expression(const expression &orig) = delete;
  virtual ~expression();
};

class cast_expression : public expression
{
public:
  cast_expression(const std::vector<std::string> &tp, expression *const e);
  cast_expression(const cast_expression &orig) = delete;
  virtual ~cast_expression();

private:
  std::vector<std::string> cast_to_type;
  expression *xpr;
};

class constructor_expression : public expression
{
public:
  constructor_expression(const std::vector<std::string> &it, const std::vector<expression *> &es);
  constructor_expression(const constructor_expression &orig) = delete;
  virtual ~constructor_expression();

private:
  std::vector<std::string> instance_type;
  std::vector<expression *> expressions;
};

class id_expression : public expression
{
public:
  id_expression(const std::vector<std::string> &is);
  id_expression(const id_expression &orig) = delete;
  virtual ~id_expression();

private:
  std::vector<std::string> ids;
};

class function_expression : public expression
{
public:
  function_expression(const std::vector<std::string> &is, const std::string &fn, const std::vector<expression *> &es);
  function_expression(const function_expression &orig) = delete;
  virtual ~function_expression();

private:
  std::vector<std::string> ids;
  std::string function_name;
  std::vector<expression *> expressions;
};

class string_literal_expression : public expression
{
public:
  string_literal_expression(const std::string &l);
  string_literal_expression(const string_literal_expression &orig) = delete;
  virtual ~string_literal_expression();

private:
  std::string literal;
};

class bool_expression : public expression
{
public:
  bool_expression();
  bool_expression(const bool_expression &orig) = delete;
  virtual ~bool_expression();
};

class bool_literal_expression : public bool_expression
{
public:
  bool_literal_expression(const bool &l);
  bool_literal_expression(const bool_literal_expression &orig) = delete;
  virtual ~bool_literal_expression();

private:
  bool literal;
};

class eq_expression : public bool_expression
{
public:
  eq_expression(expression *const l, expression *const r);
  eq_expression(const eq_expression &orig) = delete;
  virtual ~eq_expression();

private:
  expression *left;
  expression *right;
};

class neq_expression : public bool_expression
{
public:
  neq_expression(expression *const l, expression *const r);
  neq_expression(const neq_expression &orig) = delete;
  virtual ~neq_expression();

private:
  expression *left;
  expression *right;
};

class lt_expression : public bool_expression
{
public:
  lt_expression(arith_expression *const l, arith_expression *const r);
  lt_expression(const lt_expression &orig) = delete;
  virtual ~lt_expression();

private:
  arith_expression *left;
  arith_expression *right;
};

class leq_expression : public bool_expression
{
public:
  leq_expression(arith_expression *const l, arith_expression *const r);
  leq_expression(const leq_expression &orig) = delete;
  virtual ~leq_expression();

private:
  arith_expression *left;
  arith_expression *right;
};

class geq_expression : public bool_expression
{
public:
  geq_expression(arith_expression *const l, arith_expression *const r);
  geq_expression(const geq_expression &orig) = delete;
  virtual ~geq_expression();

private:
  arith_expression *left;
  arith_expression *right;
};

class gt_expression : public bool_expression
{
public:
  gt_expression(arith_expression *const l, arith_expression *const r);
  gt_expression(const gt_expression &orig) = delete;
  virtual ~gt_expression();

private:
  arith_expression *left;
  arith_expression *right;
};

class implication_expression : public bool_expression
{
public:
  implication_expression(bool_expression *const l, bool_expression *const r);
  implication_expression(const implication_expression &orig) = delete;
  virtual ~implication_expression();

private:
  bool_expression *left;
  bool_expression *right;
};

class disjunction_expression : public bool_expression
{
public:
  disjunction_expression(std::vector<bool_expression *> es);
  disjunction_expression(const disjunction_expression &orig) = delete;
  virtual ~disjunction_expression();

private:
  std::vector<bool_expression *> expressions;
};

class conjunction_expression : public bool_expression
{
public:
  conjunction_expression(std::vector<bool_expression *> es);
  conjunction_expression(const conjunction_expression &orig) = delete;
  virtual ~conjunction_expression();

private:
  std::vector<bool_expression *> expressions;
};

class exct_one_expression : public bool_expression
{
public:
  exct_one_expression(std::vector<bool_expression *> es);
  exct_one_expression(const exct_one_expression &orig) = delete;
  virtual ~exct_one_expression();

private:
  std::vector<bool_expression *> expressions;
};

class not_expression : public bool_expression
{
public:
  not_expression(bool_expression *const e);
  not_expression(const not_expression &orig) = delete;
  virtual ~not_expression();

private:
  bool_expression *xpr;
};

class arith_expression : public expression
{
public:
  arith_expression();
  arith_expression(const arith_expression &orig) = delete;
  virtual ~arith_expression();
};

class arith_literal_expression : public arith_expression
{
public:
  arith_literal_expression(const double &l);
  arith_literal_expression(const arith_literal_expression &orig) = delete;
  virtual ~arith_literal_expression();

private:
  double literal;
};

class plus_expression : public arith_expression
{
public:
  plus_expression(arith_expression *const e);
  plus_expression(const plus_expression &orig) = delete;
  virtual ~plus_expression();

private:
  arith_expression *xpr;
};

class minus_expression : public arith_expression
{
public:
  minus_expression(arith_expression *const e);
  minus_expression(const minus_expression &orig) = delete;
  virtual ~minus_expression();

private:
  arith_expression *xpr;
};

class range_expression : public arith_expression
{
public:
  range_expression(arith_expression *const min_e, arith_expression *const max_e);
  range_expression(const range_expression &orig) = delete;
  virtual ~range_expression();

private:
  arith_expression *min_xpr;
  arith_expression *max_xpr;
};

class addition_expression : public arith_expression
{
public:
  addition_expression(std::vector<arith_expression *> es);
  addition_expression(const addition_expression &orig) = delete;
  virtual ~addition_expression();

private:
  std::vector<arith_expression *> expressions;
};

class subtraction_expression : public arith_expression
{
public:
  subtraction_expression(std::vector<arith_expression *> es);
  subtraction_expression(const subtraction_expression &orig) = delete;
  virtual ~subtraction_expression();

private:
  std::vector<arith_expression *> expressions;
};

class multiplication_expression : public arith_expression
{
public:
  multiplication_expression(std::vector<arith_expression *> es);
  multiplication_expression(const multiplication_expression &orig) = delete;
  virtual ~multiplication_expression();

private:
  std::vector<arith_expression *> expressions;
};

class division_expression : public arith_expression
{
public:
  division_expression(std::vector<arith_expression *> es);
  division_expression(const division_expression &orig) = delete;
  virtual ~division_expression();

private:
  std::vector<arith_expression *> expressions;
};
}
}