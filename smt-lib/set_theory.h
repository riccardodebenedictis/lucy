#pragma once

#include "visibility.h"
#include "theory.h"
#include <unordered_set>
#include <unordered_map>
#include <list>

namespace smt
{

class set_value_listener;

class DLL_PUBLIC set_item
{
public:
  set_item() {}

  virtual ~set_item() {}
};

class DLL_PUBLIC set_theory : public theory
{
  friend class set_value_listener;

public:
  set_theory(sat_core &sat);
  set_theory(const set_theory &orig) = delete;
  virtual ~set_theory();

  var new_var(const std::unordered_set<set_item *> &items);

  var allows(const var &left, set_item &right) const;
  var eq(const var &left, const var &right);

  std::unordered_set<set_item *> value(var v) const;

private:
  bool propagate(const lit &p, std::vector<lit> &cnfl) override;
  bool check(std::vector<lit> &cnfl) override;

  void push() override;

  void pop() override;

  void listen(var v, set_value_listener *const l);
  void forget(var v, set_value_listener *const l);

private:
  class layer
  {
  public:
    layer() {}

  public:
    // the updated variables..
    std::unordered_set<var> vars;
  };
  // the current assignments..
  std::vector<std::unordered_map<set_item *, var>> assigns;
  // the already existing expressions (string to bool variable)..
  std::unordered_map<std::string, var> exprs;
  std::unordered_map<var, var> is_contained_in;
  // we store the updated variables..
  std::vector<layer> layers;
  std::unordered_map<var, std::list<set_value_listener *>> listening;
};
}