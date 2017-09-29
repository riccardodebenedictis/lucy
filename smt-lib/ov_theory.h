#pragma once

#include "theory.h"
#include <unordered_set>
#include <unordered_map>
#include <list>

namespace smt
{

class set_value_listener;

class set_item
{
public:
  set_item() {}

  virtual ~set_item() {}
};

class ov_theory : public theory
{
  friend class set_value_listener;

public:
  ov_theory(sat_core &sat);
  ov_theory(const ov_theory &orig) = delete;
  virtual ~ov_theory();

  const var new_var(const std::unordered_set<set_item *> &items);
  const var new_var(const std::vector<var> &vars, const std::vector<set_item *> &vals);

  const var allows(const var &left, set_item &right) const;
  const var eq(const var &left, const var &right);

  std::unordered_set<set_item *> value(var v) const;

private:
  bool propagate(const lit &p, std::vector<lit> &cnfl) override;
  bool check(std::vector<lit> &cnfl) override;

  void push() override;

  void pop() override;

  void listen(const var &v, set_value_listener *const l);
  void forget(const var &v, set_value_listener *const l);

private:
  class layer
  {
  public:
    layer() {}

  public:
    // the updated variables..
    std::unordered_set<var> vars;
  };
  // the current assignments (val to bool variable)..
  std::vector<std::unordered_map<set_item *, var>> assigns;
  // the already existing expressions (string to bool variable)..
  std::unordered_map<std::string, var> exprs;
  // the boolean variable contained in the set variables (bool variable to vector of set variables)..
  std::unordered_map<var, std::vector<var>> is_contained_in;
  // we store the updated variables..
  std::vector<layer> layers;
  std::unordered_map<var, std::list<set_value_listener *>> listening;
};

class set_value_listener
{
  friend class ov_theory;

public:
  set_value_listener(ov_theory &s) : th(s) {}
  set_value_listener(const set_value_listener &that) = delete;

  virtual ~set_value_listener()
  {
    for (const auto &v : la_vars)
      th.forget(v, this);
  }

protected:
  void listen_set(var v)
  {
    th.listen(v, this);
    la_vars.push_back(v);
  }

private:
  virtual void set_value_change(const var &) {}

private:
  ov_theory &th;
  std::vector<var> la_vars;
};
}