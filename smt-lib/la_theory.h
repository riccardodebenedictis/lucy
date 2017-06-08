#pragma once

#include "visibility.h"
#include "theory.h"
#include "lin.h"
#include "interval.h"
#include <unordered_map>
#include <list>

namespace smt
{

class la_value_listener;
class assertion;
class row;

class DLL_PUBLIC la_theory : public theory
{
  friend class la_value_listener;
  friend class assertion;
  friend class row;

public:
  la_theory(sat_core &sat);
  la_theory(const la_theory &orig) = delete;
  virtual ~la_theory();

  var new_var();

  var new_leq(const lin &left, const lin &right);
  var new_geq(const lin &left, const lin &right);

  interval bounds(var v) const
  {
    return assigns[v];
  }

  interval bounds(const lin &l) const
  {
    interval b(l.known_term);
    for (const auto &term : l.vars)
    {
      b += bounds(term.first) * term.second;
    }
    return b;
  }

  double value(var v) const
  {
    return vals[v];
  }

  double value(const lin &l) const
  {
    double v(l.known_term);
    for (const auto &term : l.vars)
    {
      v += value(term.first) * term.second;
    }
    return v;
  }

private:
  var mk_slack(const lin &l);

  bool propagate(const lit &p, std::vector<lit> &cnfl) override;
  bool check(std::vector<lit> &cnfl) override;
  void push() override;
  void pop() override;

  bool assert_lower(var x_i, double val, const lit &p, std::vector<lit> &cnfl);
  bool assert_upper(var x_i, double val, const lit &p, std::vector<lit> &cnfl);
  void update(var x_i, double v);
  void pivot_and_update(var x_i, var x_j, double v);
  void pivot(var x_i, var x_j);

  void listen(var v, la_value_listener *const l);
  void forget(var v, la_value_listener *const l);

public:
  std::string to_string();

private:
  class layer
  {
  public:
    layer() {}

  public:
    // the old lower bounds (for backtracking)..
    std::unordered_map<var, double> lbs;
    // the old upper bounds (for backtracking)..
    std::unordered_map<var, double> ubs;
  };

  enum op
  {
    leq,
    geq
  };

  class assertion
  {
    friend class la_theory;
    friend class row;

  public:
    assertion(la_theory &th, op o, var b, var x, double v);
    assertion(const assertion &orig) = delete;
    virtual ~assertion();

    std::string to_string() const;

  private:
    bool propagate_lb(var x, std::vector<lit> &cnfl);
    bool propagate_ub(var x, std::vector<lit> &cnfl);

  private:
    la_theory &th;
    op o;
    var b;
    var x;
    double v;
  };

  class row
  {
    friend class la_theory;

  public:
    row(la_theory &th, var x, lin l);
    row(const assertion &orig) = delete;
    virtual ~row();

    std::string to_string() const;

  private:
    bool propagate_lb(var x, std::vector<lit> &cnfl);
    bool propagate_ub(var x, std::vector<lit> &cnfl);

  private:
    la_theory &th;
    var x;
    lin l;
  };

  // the current assignments..
  std::vector<interval> assigns;
  // the current values..
  std::vector<double> vals;
  // the sparse matrix..
  std::map<var, row *> tableau;
  // the expressions (string to numeric variable) for which already exist slack variables..
  std::unordered_map<std::string, var> exprs;
  // the assertions (string to boolean variable) used both for reducing the number of boolean variables and for generating explanations..
  std::unordered_map<std::string, var> s_asrts;
  // the assertions (boolean variable to assertion) used for enforcing (negating) assertions..
  std::unordered_map<var, assertion *> v_asrts;
  // for each variable v, a list of assertions watching v..
  std::vector<std::vector<assertion *>> a_watches;
  // for each variable v, a list of tableau rows watching v..
  std::vector<std::set<row *>> t_watches;
  // we store the updated bounds..
  std::vector<layer> layers;
  std::unordered_map<var, std::list<la_value_listener *>> listening;
};
}