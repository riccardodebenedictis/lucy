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
  state_variable(solver &slv);
  state_variable(const state_variable &orig) = delete;
  virtual ~state_variable();

private:
  std::vector<flaw *> get_flaws() override;

  void new_predicate(predicate &pred) override;
  void new_fact(atom_flaw &f) override;
  void new_goal(atom_flaw &f) override;

  class sv_constructor : public constructor
  {
  public:
    sv_constructor(state_variable &sv) : constructor(sv.slv, sv, {}, {}, {}) {}
    sv_constructor(sv_constructor &&) = delete;
    virtual ~sv_constructor() {}
  };

  class sv_atom_listener : public atom_listener
  {
  public:
    sv_atom_listener(state_variable &sv, atom &atm);
    sv_atom_listener(sv_atom_listener &&) = delete;
    virtual ~sv_atom_listener();

  private:
    void something_changed();

    void sat_value_change(const var &) override { something_changed(); }
    void la_value_change(const var &) override { something_changed(); }
    void set_value_change(const var &) override { something_changed(); }

  protected:
    state_variable &sv;
  };

  class sv_flaw : public flaw
  {
  public:
    sv_flaw(solver &slv, const std::set<atom *> &overlapping_atoms);
    sv_flaw(sv_flaw &&) = delete;
    virtual ~sv_flaw();

    std::string get_label() const override { return "φ" + std::to_string(get_phi()) + "sv-flaw"; }

  private:
    void compute_resolvers() override;

  private:
    const std::set<atom *> overlapping_atoms;
  };

  class sv_resolver : public resolver
  {
  public:
    sv_resolver(solver &slv, const lin &cost, sv_flaw &f, const lit &to_do);
    sv_resolver(const sv_resolver &that) = delete;
    virtual ~sv_resolver();

  private:
    void apply() override;

  private:
    const lit to_do;
  };

  class order_resolver : public sv_resolver
  {
  public:
    order_resolver(solver &slv, const lin &cost, sv_flaw &f, const atom &before, const atom &after, const lit &to_do);
    order_resolver(const order_resolver &that) = delete;
    virtual ~order_resolver();

    std::string get_label() const override { return "ρ" + std::to_string(rho) + " σ" + std::to_string(before.sigma) + " <= σ" + std::to_string(after.sigma); }

  private:
    const atom &before;
    const atom &after;
  };

  class displace_resolver : public sv_resolver
  {
  public:
    displace_resolver(solver &slv, const lin &cost, sv_flaw &f, const atom &a, const item &i, const lit &to_do);
    displace_resolver(const displace_resolver &that) = delete;
    virtual ~displace_resolver();

    std::string get_label() const override
    {
      // this should be an enumerative expression (or the resolver should not have been created)..
      var_expr c_scp = a.get(TAU);
      return "ρ" + std::to_string(rho) + " scope (τ" + std::to_string(c_scp->ev) + ") != " + std::to_string(reinterpret_cast<uintptr_t>(&i));
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