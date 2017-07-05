#pragma once

#include "smart_type.h"
#include "constructor.h"
#include "predicate.h"
#include "flaw.h"
#include "resolver.h"

#define PROPOSITIONAL_STATE_NAME "PropositionalState"
#define PROPOSITIONAL_STATE_PREDICATE_NAME "Use"
#define PROPOSITIONAL_STATE_POLARITY_NAME "polarity"

namespace cg
{

class propositional_state : public smart_type
{
public:
  propositional_state(causal_graph &g);
  propositional_state(const propositional_state &orig) = delete;
  virtual ~propositional_state();

private:
  std::vector<flaw *> get_flaws() override;

  void new_predicate(predicate &pred) override;
  void new_fact(atom &atm) override;
  void new_goal(atom &atm) override;

  class ps_constructor : public constructor
  {
  public:
    ps_constructor(propositional_state &ps) : constructor(ps.graph, ps, {}, {}, {}) {}
    ps_constructor(ps_constructor &&) = delete;
    virtual ~ps_constructor() {}
  };

  class ps_predicate : public predicate
  {
  public:
    ps_predicate(propositional_state &rr);
    ps_predicate(ps_predicate &&) = delete;
    virtual ~ps_predicate();
  };

  class ps_atom_listener : public atom_listener
  {
  public:
    ps_atom_listener(propositional_state &ps, atom &a);
    ps_atom_listener(ps_atom_listener &&) = delete;
    virtual ~ps_atom_listener();

  private:
    void something_changed();

    void sat_value_change(size_t var) override { something_changed(); }
    void la_value_change(size_t var) override { something_changed(); }
    void set_value_change(size_t var) override { something_changed(); }

  protected:
    propositional_state &ps;
  };

  class ps_flaw : public flaw
  {
  public:
    ps_flaw(causal_graph &graph, const std::set<atom *> &overlapping_atoms);
    ps_flaw(ps_flaw &&) = delete;
    virtual ~ps_flaw();

    std::string get_label() const override { return "ps-flaw"; }

  private:
    void compute_resolvers() override;

  private:
    const std::set<atom *> overlapping_atoms;
  };

  class ps_resolver : public resolver
  {
  public:
    ps_resolver(causal_graph &graph, const lin &cost, ps_flaw &f, const lit &to_do);
    ps_resolver(const ps_resolver &that) = delete;
    virtual ~ps_resolver();

  private:
    void apply() override;

  private:
    const lit to_do;
  };

  class order_resolver : public ps_resolver
  {
  public:
    order_resolver(causal_graph &graph, const lin &cost, ps_flaw &f, const atom &before, const atom &after, const lit &to_do);
    order_resolver(const order_resolver &that) = delete;
    virtual ~order_resolver();

    std::string get_label() const override { return "e" + std::to_string(before.state) + " <= e" + std::to_string(after.state); }

  private:
    const atom &before;
    const atom &after;
  };

  class displace_resolver : public ps_resolver
  {
  public:
    displace_resolver(causal_graph &graph, const lin &cost, ps_flaw &f, const atom &a, const std::string &f_name, const item &i, const lit &to_do);
    displace_resolver(const displace_resolver &that) = delete;
    virtual ~displace_resolver();

    std::string get_label() const override
    {
      enum_expr c_scp = a.get(f_name);
      return f_name + " (e" + std::to_string(c_scp->ev) + ") != " + std::to_string(reinterpret_cast<uintptr_t>(&i));
    }

  private:
    const atom &a;
    const std::string f_name;
    const item &i;
  };

private:
  std::set<atom *> to_check;
  std::vector<std::pair<atom *, ps_atom_listener *>> atoms;
};
}