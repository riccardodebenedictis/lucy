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

  void new_predicate(predicate &pred) override;
  bool new_fact(atom &atm) override;
  bool new_goal(atom &atm) override;

  class rr_constructor : public constructor
  {
  public:
    rr_constructor(reusable_resource &rr) : constructor(rr.graph, rr, {new field(rr.graph.get_type("real"), REUSABLE_RESOURCE_CAPACITY)}) {}
    rr_constructor(rr_constructor &&) = delete;

    virtual ~rr_constructor() {}

  private:
    bool invoke(item &i, const std::vector<expr> &exprs) override
    {
      assert(exprs.size() == 1);
      set(i, REUSABLE_RESOURCE_CAPACITY, exprs[0]);
      return true;
    }
  };

  class use_predicate : public predicate
  {
  public:
    use_predicate(reusable_resource &rr);
    use_predicate(use_predicate &&) = delete;

    virtual ~use_predicate();

  private:
    bool apply_rule(atom &a) const override;
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

    std::string get_label() const override { return "rr-flaw"; }

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
    bool apply() override;

  private:
    const lit to_do;
  };

  class order_resolver : public rr_resolver
  {
  public:
    order_resolver(causal_graph &graph, const lin &cost, rr_flaw &f, const atom &before, const atom &after, const lit &to_do);
    order_resolver(const order_resolver &that) = delete;
    virtual ~order_resolver();

    std::string get_label() const override { return "e" + std::to_string(before.state) + " <= e" + std::to_string(after.state); }

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
      enum_expr scp = a.get("scope");
      return "scope (e" + std::to_string(scp->ev) + ") != " + std::to_string(reinterpret_cast<uintptr_t>(&i));
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