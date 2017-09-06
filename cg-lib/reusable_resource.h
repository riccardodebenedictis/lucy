#pragma once

#include "smart_type.h"
#include "constructor.h"
#include "flaw.h"
#include "resolver.h"
#include "predicate.h"

#define REUSABLE_RESOURCE_NAME "ReusableResource"
#define REUSABLE_RESOURCE_CAPACITY "capacity"
#define REUSABLE_RESOURCE_USE_PREDICATE_NAME "Use"
#define REUSABLE_RESOURCE_USE_AMOUNT_NAME "amount"

namespace cg
{

class reusable_resource : public smart_type
{
public:
  reusable_resource(causal_graph &graph);
  reusable_resource(const reusable_resource &orig) = delete;
  virtual ~reusable_resource();

private:
  std::vector<flaw *> get_flaws() override;

  void new_predicate(predicate &pred) override { throw std::logic_error("it is not possible to define predicates on a reusable resource.."); }
  void new_fact(atom_flaw &f) override;
  void new_goal(atom_flaw &f) override;

  class rr_constructor : public constructor
  {
  public:
    rr_constructor(reusable_resource &rr);
    rr_constructor(rr_constructor &&) = delete;
    virtual ~rr_constructor();
  };

  class use_predicate : public predicate
  {
  public:
    use_predicate(reusable_resource &rr);
    use_predicate(use_predicate &&) = delete;
    virtual ~use_predicate();
  };

  class rr_atom_listener : public atom_listener
  {
  public:
    rr_atom_listener(reusable_resource &rr, atom &atm);
    rr_atom_listener(rr_atom_listener &&) = delete;
    virtual ~rr_atom_listener();

  private:
    void something_changed();

    void sat_value_change(size_t var) override { something_changed(); }
    void la_value_change(size_t var) override { something_changed(); }
    void set_value_change(size_t var) override { something_changed(); }

  protected:
    reusable_resource &rr;
  };

  class rr_flaw : public flaw
  {
  public:
    rr_flaw(causal_graph &graph, const std::set<atom *> &overlapping_atoms);
    rr_flaw(rr_flaw &&) = delete;
    virtual ~rr_flaw();

    std::string get_label() const override { return "φ" + std::to_string(get_phi()) + "rr-flaw"; }

  private:
    void compute_resolvers() override;

  private:
    const std::set<atom *> overlapping_atoms;
  };

  class rr_resolver : public resolver
  {
  public:
    rr_resolver(causal_graph &graph, const lin &cost, rr_flaw &f, const lit &to_do);
    rr_resolver(const rr_resolver &that) = delete;
    virtual ~rr_resolver();

  private:
    void apply() override;

  private:
    const lit to_do;
  };

  class order_resolver : public rr_resolver
  {
  public:
    order_resolver(causal_graph &graph, const lin &cost, rr_flaw &f, const atom &before, const atom &after, const lit &to_do);
    order_resolver(const order_resolver &that) = delete;
    virtual ~order_resolver();

    std::string get_label() const override { return "ρ" + std::to_string(rho) + " σ" + std::to_string(before.state) + " <= σ" + std::to_string(after.state); }

  private:
    const atom &before;
    const atom &after;
  };

  class displace_resolver : public rr_resolver
  {
  public:
    displace_resolver(causal_graph &graph, const lin &cost, rr_flaw &f, const atom &a, const item &i, const lit &to_do);
    displace_resolver(const displace_resolver &that) = delete;
    virtual ~displace_resolver();

    std::string get_label() const override
    {
      // this should be an enumerative expression (or the resolver should not have been created)..
      enum_expr c_scp = a.get("scope");
      return "ρ" + std::to_string(rho) + " scope (τ" + std::to_string(c_scp->ev) + ") != " + std::to_string(reinterpret_cast<uintptr_t>(&i));
    }

  private:
    const atom &a;
    const item &i;
  };

private:
  std::set<item *> to_check;
  std::vector<std::pair<atom *, rr_atom_listener *>> atoms;
};
}