#pragma once

#include "visibility.h"
#include <vector>
#include <string>

namespace lucy
{

class scope;
class context;
class expr;

namespace ast
{

class DLL_PUBLIC expression
{
public:
  expression();
  expression(const expression &orig) = delete;
  virtual ~expression();

  virtual expr evaluate(const scope &scp, context &ctx) const = 0;
};

#pragma warning(disable : 4251)
class DLL_PUBLIC cast_expression : public expression
{
public:
  cast_expression(const std::vector<std::string> &tp, const expression *const e);
  cast_expression(const cast_expression &orig) = delete;
  virtual ~cast_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const std::vector<std::string> cast_to_type;
  const expression *const xpr;
};

class DLL_PUBLIC constructor_expression : public expression
{
public:
  constructor_expression(const std::vector<std::string> &it, const std::vector<expression *> &es);
  constructor_expression(const constructor_expression &orig) = delete;
  virtual ~constructor_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const std::vector<std::string> instance_type;
  const std::vector<expression *> expressions;
};

class DLL_PUBLIC id_expression : public expression
{
public:
  id_expression(const std::vector<std::string> &is);
  id_expression(const id_expression &orig) = delete;
  virtual ~id_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const std::vector<std::string> ids;
};

class DLL_PUBLIC function_expression : public expression
{
public:
  function_expression(const std::vector<std::string> &is, const std::string &fn, const std::vector<expression *> &es);
  function_expression(const function_expression &orig) = delete;
  virtual ~function_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const std::vector<std::string> ids;
  const std::string function_name;
  const std::vector<expression *> expressions;
};

class DLL_PUBLIC string_literal_expression : public expression
{
public:
  string_literal_expression(const std::string &l);
  string_literal_expression(const string_literal_expression &orig) = delete;
  virtual ~string_literal_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const std::string literal;
};

class DLL_PUBLIC int_literal_expression : public expression
{
public:
  int_literal_expression(const long &l);
  int_literal_expression(const int_literal_expression &orig) = delete;
  virtual ~int_literal_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const long literal;
};

class DLL_PUBLIC real_literal_expression : public expression
{
public:
  real_literal_expression(const double &l);
  real_literal_expression(const real_literal_expression &orig) = delete;
  virtual ~real_literal_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const double literal;
};

class DLL_PUBLIC plus_expression : public expression
{
public:
  plus_expression(const expression *const e);
  plus_expression(const plus_expression &orig) = delete;
  virtual ~plus_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const expression *const xpr;
};

class DLL_PUBLIC minus_expression : public expression
{
public:
  minus_expression(const expression *const e);
  minus_expression(const minus_expression &orig) = delete;
  virtual ~minus_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const expression *const xpr;
};

class DLL_PUBLIC range_expression : public expression
{
public:
  range_expression(const expression *const min_e, const expression *const max_e);
  range_expression(const range_expression &orig) = delete;
  virtual ~range_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const expression *const min_xpr;
  const expression *const max_xpr;
};

class DLL_PUBLIC addition_expression : public expression
{
public:
  addition_expression(const std::vector<expression *> &es);
  addition_expression(const addition_expression &orig) = delete;
  virtual ~addition_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const std::vector<expression *> expressions;
};

class DLL_PUBLIC subtraction_expression : public expression
{
public:
  subtraction_expression(const std::vector<expression *> &es);
  subtraction_expression(const subtraction_expression &orig) = delete;
  virtual ~subtraction_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const std::vector<expression *> expressions;
};

class DLL_PUBLIC multiplication_expression : public expression
{
public:
  multiplication_expression(const std::vector<expression *> &es);
  multiplication_expression(const multiplication_expression &orig) = delete;
  virtual ~multiplication_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const std::vector<expression *> expressions;
};

class DLL_PUBLIC division_expression : public expression
{
public:
  division_expression(const std::vector<expression *> &es);
  division_expression(const division_expression &orig) = delete;
  virtual ~division_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const std::vector<expression *> expressions;
};

class DLL_PUBLIC bool_literal_expression : public expression
{
public:
  bool_literal_expression(const bool &l);
  bool_literal_expression(const bool_literal_expression &orig) = delete;
  virtual ~bool_literal_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const bool literal;
};

class DLL_PUBLIC eq_expression : public expression
{
public:
  eq_expression(const expression *const l, const expression *const r);
  eq_expression(const eq_expression &orig) = delete;
  virtual ~eq_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const expression *const left;
  const expression *const right;
};

class DLL_PUBLIC neq_expression : public expression
{
public:
  neq_expression(const expression *const l, const expression *const r);
  neq_expression(const neq_expression &orig) = delete;
  virtual ~neq_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const expression *const left;
  const expression *const right;
};

class DLL_PUBLIC lt_expression : public expression
{
public:
  lt_expression(const expression *const l, const expression *const r);
  lt_expression(const lt_expression &orig) = delete;
  virtual ~lt_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const expression *const left;
  const expression *const right;
};

class DLL_PUBLIC leq_expression : public expression
{
public:
  leq_expression(const expression *const l, const expression *const r);
  leq_expression(const leq_expression &orig) = delete;
  virtual ~leq_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const expression *const left;
  const expression *const right;
};

class DLL_PUBLIC geq_expression : public expression
{
public:
  geq_expression(const expression *const l, const expression *const r);
  geq_expression(const geq_expression &orig) = delete;
  virtual ~geq_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const expression *const left;
  const expression *const right;
};

class DLL_PUBLIC gt_expression : public expression
{
public:
  gt_expression(const expression *const l, const expression *const r);
  gt_expression(const gt_expression &orig) = delete;
  virtual ~gt_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const expression *const left;
  const expression *const right;
};

class DLL_PUBLIC implication_expression : public expression
{
public:
  implication_expression(const expression *const l, const expression *const r);
  implication_expression(const implication_expression &orig) = delete;
  virtual ~implication_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const expression *const left;
  const expression *const right;
};

class DLL_PUBLIC disjunction_expression : public expression
{
public:
  disjunction_expression(const std::vector<expression *> &es);
  disjunction_expression(const disjunction_expression &orig) = delete;
  virtual ~disjunction_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const std::vector<expression *> expressions;
};

class DLL_PUBLIC conjunction_expression : public expression
{
public:
  conjunction_expression(const std::vector<expression *> &es);
  conjunction_expression(const conjunction_expression &orig) = delete;
  virtual ~conjunction_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const std::vector<expression *> expressions;
};

class DLL_PUBLIC exct_one_expression : public expression
{
public:
  exct_one_expression(const std::vector<expression *> &es);
  exct_one_expression(const exct_one_expression &orig) = delete;
  virtual ~exct_one_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const std::vector<expression *> expressions;
};

class DLL_PUBLIC not_expression : public expression
{
public:
  not_expression(const expression *const e);
  not_expression(const not_expression &orig) = delete;
  virtual ~not_expression();

  expr evaluate(const scope &scp, context &ctx) const override;

private:
  const expression *const xpr;
};
}
}