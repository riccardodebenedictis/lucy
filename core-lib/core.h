#pragma once

#include "scope.h"
#include "env.h"
#include "sat_core.h"
#include "la_theory.h"
#include "set_theory.h"
#include "parser/ratioLexer.h"
#include "parser/ratioParser.h"

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

class DLL_PUBLIC core : public scope, public env
{
  friend class type;
  friend class type_declaration_listener;
  friend class type_refinement_listener;
  friend class statement_visitor;
  friend class type_visitor;
  friend class expression_visitor;

public:
  core();
  core(const core &orig) = delete;
  ~core();

  bool read(const std::string &script);
  bool read(const std::vector<std::string> &files);

  bool_expr new_bool();
  bool_expr new_bool(const bool &val);
  arith_expr new_int();
  arith_expr new_int(const long &val);
  arith_expr new_real();
  arith_expr new_real(const double &val);
  string_expr new_string();
  string_expr new_string(const std::string &val);
  virtual expr new_enum(const type &tp, const std::unordered_set<item *> &allowed_vals);

  bool_expr negate(bool_expr var);
  bool_expr eq(bool_expr left, bool_expr right);
  bool_expr conj(const std::vector<bool_expr> &exprs);
  bool_expr disj(const std::vector<bool_expr> &exprs);
  bool_expr exct_one(const std::vector<bool_expr> &exprs);

  arith_expr add(const std::vector<arith_expr> &exprs);
  arith_expr sub(const std::vector<arith_expr> &exprs);
  arith_expr mult(const std::vector<arith_expr> &exprs);
  arith_expr div(arith_expr left, arith_expr right);
  arith_expr minus(arith_expr ex);

  bool_expr lt(arith_expr left, arith_expr right);
  bool_expr leq(arith_expr left, arith_expr right);
  bool_expr eq(arith_expr left, arith_expr right);
  bool_expr geq(arith_expr left, arith_expr right);
  bool_expr gt(arith_expr left, arith_expr right);

  bool_expr eq(expr i0, expr i1);

  bool assert_facts(const std::vector<lit> &facts);

  field &get_field(const std::string &name) const override;

  method &get_method(const std::string &name, const std::vector<const type *> &ts) const override;
  std::vector<method *> get_methods() const noexcept override
  {
    std::vector<method *> c_methods;
    for (const auto &ms : methods)
    {
      c_methods.insert(c_methods.begin(), ms.second.begin(), ms.second.end());
    }
    return c_methods;
  }

  predicate &get_predicate(const std::string &name) const override;
  std::unordered_map<std::string, predicate *> get_predicates() const noexcept override { return predicates; }

  type &get_type(const std::string &name) const override;
  std::unordered_map<std::string, type *> get_types() const noexcept override { return types; }

  expr get(const std::string &name) const override;

  lbool bool_value(const bool_expr &var) const noexcept;
  interval arith_bounds(const arith_expr &var) const noexcept;
  double arith_value(const arith_expr &var) const noexcept;
  std::unordered_set<set_item *> enum_value(const enum_expr &var) const noexcept;

  virtual bool solve() = 0;

protected:
  virtual bool new_fact(atom &atm);
  virtual bool new_goal(atom &atm);
  virtual void new_disjunction(context &ctx, disjunction &disj) = 0;

protected:
  void set_var(var v)
  {
    tmp_var = ctr_var;
    ctr_var = v;
  }

  void restore_var()
  {
    ctr_var = tmp_var;
  }

public:
  std::string to_string();

private:
  std::string to_string(item *i);
  std::string to_string(atom *i);
  std::string to_string(std::unordered_map<std::string, expr> items);

public:
  sat_core sat;      // the sat core..
  la_theory la_th;   // the linear arithmetic theory..
  set_theory set_th; // the set theory..

  atom_state *const active;
  atom_state *const inactive;
  atom_state *const unified;

private:
  var tmp_var;
  var ctr_var = TRUE;

protected:
  std::unordered_map<std::string, std::vector<method *>> methods;
  std::unordered_map<std::string, type *> types;
  std::unordered_map<std::string, predicate *> predicates;

private:
  std::vector<ratioParser *> parsers;
  std::map<antlr4::tree::ParseTree *, scope *> scopes;
  ratioParser *p;

  class snippet
  {
    friend class core;

  private:
    snippet(const std::string &file, ratioParser &p, ratioParser::Compilation_unitContext *const cu) : file(file), p(p), cu(cu) {}
    snippet(const snippet &that) = delete;

  private:
    const std::string file;
    ratioParser &p;
    ratioParser::Compilation_unitContext *const cu;
  };
};

class DLL_PUBLIC atom_state : public set_item
{
  friend class core;

private:
  atom_state() {}
  atom_state(const atom_state &that) = delete;
  virtual ~atom_state() {}
};
}