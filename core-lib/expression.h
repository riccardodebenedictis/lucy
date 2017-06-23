#pragma once

#include <vector>
#include <string>

namespace lucy
{

namespace ast
{

class bool_expr;
class arith_expr;

class expr
{
public:
  expr();
  expr(const expr &orig) = delete;
  virtual ~expr();
};

class cast_expr : public expr
{
public:
  cast_expr(const std::vector<std::string> &tp, expr *const e);
  cast_expr(const cast_expr &orig) = delete;
  virtual ~cast_expr();

private:
  std::vector<std::string> cast_to_type;
  expr *xpr;
};

class constructor_expr : public expr
{
public:
  constructor_expr(const std::vector<std::string> &it, const std::vector<expr *> &es);
  constructor_expr(const constructor_expr &orig) = delete;
  virtual ~constructor_expr();

private:
  std::vector<std::string> instance_type;
  std::vector<expr *> exprs;
};

class id_expr : public expr
{
public:
  id_expr(const std::vector<std::string> &is);
  id_expr(const id_expr &orig) = delete;
  virtual ~id_expr();

private:
  std::vector<std::string> ids;
};

class function_expr : public expr
{
public:
  function_expr(const std::vector<std::string> &is, const std::string &fn, const std::vector<expr *> &es);
  function_expr(const function_expr &orig) = delete;
  virtual ~function_expr();

private:
  std::vector<std::string> ids;
  std::string function_name;
  std::vector<expr *> exprs;
};

class string_literal_expr : public expr
{
public:
  string_literal_expr(const std::string &l);
  string_literal_expr(const string_literal_expr &orig) = delete;
  virtual ~string_literal_expr();

private:
  std::string literal;
};

class bool_expr : public expr
{
public:
  bool_expr();
  bool_expr(const bool_expr &orig) = delete;
  virtual ~bool_expr();
};

class bool_literal_expr : public bool_expr
{
public:
  bool_literal_expr(const bool &l);
  bool_literal_expr(const bool_literal_expr &orig) = delete;
  virtual ~bool_literal_expr();

private:
  bool literal;
};

class eq_expr : public bool_expr
{
public:
  eq_expr(expr *const l, expr *const r);
  eq_expr(const eq_expr &orig) = delete;
  virtual ~eq_expr();

private:
  expr *left;
  expr *right;
};

class neq_expr : public bool_expr
{
public:
  neq_expr(expr *const l, expr *const r);
  neq_expr(const neq_expr &orig) = delete;
  virtual ~neq_expr();

private:
  expr *left;
  expr *right;
};

class lt_expr : public bool_expr
{
public:
  lt_expr(arith_expr *const l, arith_expr *const r);
  lt_expr(const lt_expr &orig) = delete;
  virtual ~lt_expr();

private:
  arith_expr *left;
  arith_expr *right;
};

class leq_expr : public bool_expr
{
public:
  leq_expr(arith_expr *const l, arith_expr *const r);
  leq_expr(const leq_expr &orig) = delete;
  virtual ~leq_expr();

private:
  arith_expr *left;
  arith_expr *right;
};

class geq_expr : public bool_expr
{
public:
  geq_expr(arith_expr *const l, arith_expr *const r);
  geq_expr(const geq_expr &orig) = delete;
  virtual ~geq_expr();

private:
  arith_expr *left;
  arith_expr *right;
};

class gt_expr : public bool_expr
{
public:
  gt_expr(arith_expr *const l, arith_expr *const r);
  gt_expr(const gt_expr &orig) = delete;
  virtual ~gt_expr();

private:
  arith_expr *left;
  arith_expr *right;
};

class implication_expr : public bool_expr
{
public:
  implication_expr(bool_expr *const l, bool_expr *const r);
  implication_expr(const implication_expr &orig) = delete;
  virtual ~implication_expr();

private:
  bool_expr *left;
  bool_expr *right;
};

class disjunction_expr : public bool_expr
{
public:
  disjunction_expr(std::vector<bool_expr *> es);
  disjunction_expr(const disjunction_expr &orig) = delete;
  virtual ~disjunction_expr();

private:
  std::vector<bool_expr *> exprs;
};

class conjunction_expr : public bool_expr
{
public:
  conjunction_expr(std::vector<bool_expr *> es);
  conjunction_expr(const conjunction_expr &orig) = delete;
  virtual ~conjunction_expr();

private:
  std::vector<bool_expr *> exprs;
};

class exct_one_expr : public bool_expr
{
public:
  exct_one_expr(std::vector<bool_expr *> es);
  exct_one_expr(const exct_one_expr &orig) = delete;
  virtual ~exct_one_expr();

private:
  std::vector<bool_expr *> exprs;
};

class not_expr : public bool_expr
{
public:
  not_expr(bool_expr *const e);
  not_expr(const not_expr &orig) = delete;
  virtual ~not_expr();

private:
  bool_expr *xpr;
};

class arith_expr : public expr
{
public:
  arith_expr();
  arith_expr(const arith_expr &orig) = delete;
  virtual ~arith_expr();
};

class arith_literal_expr : public arith_expr
{
public:
  arith_literal_expr(const double &l);
  arith_literal_expr(const arith_literal_expr &orig) = delete;
  virtual ~arith_literal_expr();

private:
  double literal;
};

class plus_expr : public arith_expr
{
public:
  plus_expr(arith_expr *const e);
  plus_expr(const plus_expr &orig) = delete;
  virtual ~plus_expr();

private:
  arith_expr *xpr;
};

class minus_expr : public arith_expr
{
public:
  minus_expr(arith_expr *const e);
  minus_expr(const minus_expr &orig) = delete;
  virtual ~minus_expr();

private:
  arith_expr *xpr;
};

class range_expr : public arith_expr
{
public:
  range_expr(arith_expr *const min_e, arith_expr *const max_e);
  range_expr(const range_expr &orig) = delete;
  virtual ~range_expr();

private:
  arith_expr *min_xpr;
  arith_expr *max_xpr;
};

class addition_expr : public arith_expr
{
public:
  addition_expr(std::vector<arith_expr *> es);
  addition_expr(const addition_expr &orig) = delete;
  virtual ~addition_expr();

private:
  std::vector<arith_expr *> exprs;
};

class subtraction_expr : public arith_expr
{
public:
  subtraction_expr(std::vector<arith_expr *> es);
  subtraction_expr(const subtraction_expr &orig) = delete;
  virtual ~subtraction_expr();

private:
  std::vector<arith_expr *> exprs;
};

class multiplication_expr : public arith_expr
{
public:
  multiplication_expr(std::vector<arith_expr *> es);
  multiplication_expr(const multiplication_expr &orig) = delete;
  virtual ~multiplication_expr();

private:
  std::vector<arith_expr *> exprs;
};

class division_expr : public arith_expr
{
public:
  division_expr(std::vector<arith_expr *> es);
  division_expr(const division_expr &orig) = delete;
  virtual ~division_expr();

private:
  std::vector<arith_expr *> exprs;
};
}
}