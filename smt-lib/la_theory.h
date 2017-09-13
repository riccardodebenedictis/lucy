#pragma once

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

class la_theory : public theory
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

  interval bounds(const var &v) const { return interval(assigns[lb_index(v)].value, assigns[ub_index(v)].value); }

  interval bounds(const lin &l) const
  {
    interval b(l.known_term);
    for (const auto &term : l.vars)
      b += bounds(term.first) * term.second;
    return b;
  }

  double lb(const var &v) const { return assigns[lb_index(v)].value; } // the current lower bound of variable 'v'..
  double ub(const var &v) const { return assigns[ub_index(v)].value; } // the current upper bound of variable 'v'..
  double value(const var &v) const { return vals[v]; }                 // the current value of variable 'v'..

  double value(const lin &l) const
  {
    double v(l.known_term);
    for (const auto &term : l.vars)
      v += value(term.first) * term.second;
    return v;
  }

private:
  var mk_slack(const lin &l);

  bool propagate(const lit &p, std::vector<lit> &cnfl) override;
  bool check(std::vector<lit> &cnfl) override;
  void push() override;
  void pop() override;

  bool assert_lower(const var &x_i, const double val, const lit &p, std::vector<lit> &cnfl);
  bool assert_upper(const var &x_i, const double val, const lit &p, std::vector<lit> &cnfl);
  void update(const var &x_i, const double v);
  void pivot_and_update(const var &x_i, const var &x_j, const double v);
  void pivot(const var x_i, const var x_j);

  void listen(const var &v, la_value_listener *const l);
  void forget(const var &v, la_value_listener *const l);

  static size_t lb_index(const var &v) { return v << 1; }
  static size_t ub_index(const var &v) { return (v << 1) ^ 1; }

public:
  std::string to_string();

private:
  struct bound
  {
    double value; // the value of the bound..
    lit *reason;  // the reason for the value..
  };

  // the current assignments..
  std::vector<bound> assigns;
  // the current values..
  std::vector<double> vals;
  // the sparse matrix..
  std::map<var, row *> tableau;
  // the expressions (string to numeric variable) for which already exist slack variables..
  std::unordered_map<std::string, var> exprs;
  // the assertions (string to boolean variable) used for reducing the number of boolean variables..
  std::unordered_map<std::string, var> s_asrts;
  // the assertions (boolean variable to assertion) used for enforcing (negating) assertions..
  std::unordered_map<var, assertion *> v_asrts;
  // for each variable 'v', a list of assertions watching 'v'..
  std::vector<std::vector<assertion *>> a_watches;
  // for each variable 'v', a list of tableau rows watching 'v'..
  std::vector<std::set<row *>> t_watches;
  // we store the updated bounds..
  std::vector<std::unordered_map<size_t, bound>> layers;
  std::unordered_map<var, std::list<la_value_listener *>> listening;
};
}