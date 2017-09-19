#pragma once

#include "scope.h"
#include "env.h"
#include "parser.h"
#include "sat_core.h"
#include "la_theory.h"
#include "set_theory.h"

#define BOOL_KEYWORD "bool"
#define INT_KEYWORD "int"
#define REAL_KEYWORD "real"
#define STRING_KEYWORD "string"

using namespace smt;

namespace lucy
{

class bool_expr;
class arith_expr;
class string_expr;
class enum_expr;
class atom;
class disjunction;
class atom_state;
class parser;

namespace ast
{
class typedef_declaration;
class enum_declaration;
class class_declaration;
class method_declaration;
class predicate_declaration;
class compilation_unit;
class disjunction_statement;
class formula_statement;
}

class unsolvable_exception : public std::runtime_error
{

public:
  unsolvable_exception() : runtime_error("the problem is unsolvable") {}
  unsolvable_exception(const std::string &what_arg) : runtime_error(what_arg) {}
};

class inconsistency_exception : public std::runtime_error
{

public:
  inconsistency_exception() : runtime_error("an inconsistency has been found within the current scope") {}
  inconsistency_exception(const std::string &what_arg) : runtime_error(what_arg) {}
};

class core : public scope, public env
{
  friend class type;
  friend class ast::typedef_declaration;
  friend class ast::enum_declaration;
  friend class ast::class_declaration;
  friend class ast::method_declaration;
  friend class ast::predicate_declaration;
  friend class ast::disjunction_statement;
  friend class ast::formula_statement;

public:
  core();
  core(const core &orig) = delete;
  ~core();

  void read(const std::string &script);
  void read(const std::vector<std::string> &files);

  bool_expr new_bool();
  bool_expr new_bool(const bool &val);
  arith_expr new_int();
  arith_expr new_int(const long &val);
  arith_expr new_real();
  arith_expr new_real(const double &val);
  string_expr new_string();
  string_expr new_string(const std::string &val);
  virtual expr new_enum(const type &tp, const std::unordered_set<item *> &allowed_vals);

private:
  expr new_enum(const type &tp, const std::vector<var> &vars, const std::vector<item *> &vals);

public:
  bool_expr negate(bool_expr var);
  bool_expr eq(bool_expr left, bool_expr right);
  bool_expr conj(const std::vector<bool_expr> &exprs);
  bool_expr disj(const std::vector<bool_expr> &exprs);
  bool_expr exct_one(const std::vector<bool_expr> &exprs);

  arith_expr add(const std::vector<arith_expr> &exprs);
  arith_expr sub(const std::vector<arith_expr> &exprs);
  arith_expr mult(const std::vector<arith_expr> &exprs);
  arith_expr div(const std::vector<arith_expr> &exprs);
  arith_expr minus(arith_expr ex);

  bool_expr lt(arith_expr left, arith_expr right);
  bool_expr leq(arith_expr left, arith_expr right);
  bool_expr eq(arith_expr left, arith_expr right);
  bool_expr geq(arith_expr left, arith_expr right);
  bool_expr gt(arith_expr left, arith_expr right);

  bool_expr eq(expr i0, expr i1);

  void assert_facts(const std::vector<lit> &facts);

  field &get_field(const std::string &name) const override;

  method &get_method(const std::string &name, const std::vector<const type *> &ts) const override;
  std::vector<method *> get_methods() const noexcept override
  {
    std::vector<method *> c_methods;
    for (const auto &ms : methods)
      c_methods.insert(c_methods.begin(), ms.second.begin(), ms.second.end());
    return c_methods;
  }

  predicate &get_predicate(const std::string &name) const override;
  std::map<std::string, predicate *> get_predicates() const noexcept override { return predicates; }

  type &get_type(const std::string &name) const override;
  std::map<std::string, type *> get_types() const noexcept override { return types; }

  expr get(const std::string &name) const override;

  lbool bool_value(const bool_expr &x) const noexcept;
  interval arith_bounds(const arith_expr &x) const noexcept;
  double arith_value(const arith_expr &x) const noexcept;
  std::unordered_set<set_item *> enum_value(const enum_expr &x) const noexcept;

  virtual void solve() = 0;

protected:
  virtual void new_fact(atom &atm) = 0;
  virtual void new_goal(atom &atm) = 0;
  virtual void new_disjunction(context &ctx, const disjunction &disj) = 0;

protected:
  void set_var(const var &v)
  {
    tmp_var = ctr_var;
    ctr_var = v;
  }

  void restore_var() { ctr_var = tmp_var; }

public:
  std::string to_string() const;

private:
  std::string to_string(const item *const i) const;
  std::string to_string(const atom *const i) const;
  std::string to_string(const std::map<std::string, expr> &items) const;

private:
  parser prs;
  std::vector<ast::compilation_unit *> cus;

public:
  sat_core sat;      // the sat core..
  la_theory la_th;   // the linear arithmetic theory..
  set_theory set_th; // the set theory..

private:
  var tmp_var;
  var ctr_var = TRUE_var;

protected:
  std::map<std::string, std::vector<method *>> methods;
  std::map<std::string, type *> types;
  std::map<std::string, predicate *> predicates;
};
}