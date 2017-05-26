#pragma once

#include "smart_type.h"
#include "constructor.h"
#include "flaw.h"
#include "resolver.h"

#define STATE_VARIABLE_NAME "StateVariable"

namespace cg
{

class state_variable : public smart_type
{
public:
  state_variable(causal_graph &graph);
  state_variable(const state_variable &orig) = delete;
  virtual ~state_variable();

private:
  std::vector<flaw *> get_flaws() override;

  void new_predicate(predicate &pred) override;
  bool new_fact(atom &atm) override;
  bool new_goal(atom &atm) override;

  class sv_constructor : public constructor
  {
  public:
    sv_constructor(state_variable &sv) : constructor(sv.graph, sv, {}) {}
    sv_constructor(sv_constructor &&) = delete;

    virtual ~sv_constructor() {}

  private:
    bool invoke(item &i, const std::vector<expr> &exprs) override
    {
      return true;
    }
  };

  class sv_atom_listener : public atom_listener
  {
  public:
    sv_atom_listener(state_variable &sv, atom &atm);
    sv_atom_listener(sv_atom_listener &&) = delete;
    virtual ~sv_atom_listener();

  private:
    void something_changed();

    void sat_value_change(size_t var) override { something_changed(); }
    void la_value_change(size_t var) override { something_changed(); }
    void set_value_change(size_t var) override { something_changed(); }

  protected:
    state_variable &sv;
  };

  class sv_flaw : public flaw
  {
  public:
    sv_flaw(causal_graph &g, const std::set<atom *> &overlapping_atoms);
    sv_flaw(sv_flaw &&) = delete;
    virtual ~sv_flaw();

    std::string get_label() const override { return "sv-flaw"; }

  private:
    void compute_resolvers() override;

  private:
    const std::set<atom *> overlapping_atoms;
  };

  class sv_resolver : public resolver
  {
  public:
    sv_resolver(causal_graph &graph, const lin &cost, sv_flaw &f, const lit &to_do);
    sv_resolver(const sv_resolver &that) = delete;
    virtual ~sv_resolver();

  private:
    bool apply() override;

  private:
    const smt::lit to_do;
  };

  class order_resolver : public sv_resolver
  {
  public:
    order_resolver(causal_graph &graph, const lin &cost, sv_flaw &f, const atom &before, const atom &after, const lit &to_do);
    order_resolver(const order_resolver &that) = delete;
    virtual ~order_resolver();

    std::string get_label() const override { return "e" + std::to_string(before.state) + " <= e" + std::to_string(after.state); }

  private:
    const atom &before;
    const atom &after;
  };

  class displace_resolver : public sv_resolver
  {
  public:
    displace_resolver(causal_graph &graph, const lin &cost, sv_flaw &f, const atom &a, const item &i, const lit &to_do);
    displace_resolver(const displace_resolver &that) = delete;
    virtual ~displace_resolver();

    std::string get_label() const override
    {
      enum_expr scp = a.get("scope");
      return "scope (e" + std::to_string(scp->ev) + ") != " + std::to_string(reinterpret_cast<uintptr_t>(&i));
    }

  private:
    const atom &a;
    const item &i;
  };

private:
  std::set<item *> to_check;
  std::vector<std::pair<atom *, sv_atom_listener *>> atoms;
};
}