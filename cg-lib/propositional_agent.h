#pragma once

#include "smart_type.h"
#include "constructor.h"
#include "flaw.h"
#include "resolver.h"

#define PROPOSITIONAL_AGENT_NAME "PropositionalAgent"

namespace cg
{

class propositional_agent : public smart_type
{
public:
  propositional_agent(causal_graph &g);
  propositional_agent(const propositional_agent &orig) = delete;
  virtual ~propositional_agent();

private:
  std::vector<flaw *> get_flaws() override;

  void new_fact(atom_flaw &f) override;
  void new_goal(atom_flaw &f) override;

  class agnt_constructor : public constructor
  {
  public:
    agnt_constructor(propositional_agent &agnt) : constructor(agnt.graph, agnt, {}, {}, {}) {}
    agnt_constructor(agnt_constructor &&) = delete;
    virtual ~agnt_constructor() {}
  };

  class agnt_atom_listener : public atom_listener
  {
  public:
    agnt_atom_listener(propositional_agent &agnt, atom &a);
    agnt_atom_listener(agnt_atom_listener &&) = delete;
    virtual ~agnt_atom_listener();

  private:
    void something_changed();

    void sat_value_change(size_t var) override { something_changed(); }
    void la_value_change(size_t var) override { something_changed(); }
    void set_value_change(size_t var) override { something_changed(); }

  protected:
    propositional_agent &agnt;
  };

  class agnt_flaw : public flaw
  {
  public:
    agnt_flaw(causal_graph &graph, const std::set<atom *> &overlapping_atoms);
    agnt_flaw(agnt_flaw &&) = delete;
    virtual ~agnt_flaw();

    std::string get_label() const override { return "agent-flaw"; }

  private:
    void compute_resolvers() override;

  private:
    const std::set<atom *> overlapping_atoms;
  };

  class agnt_resolver : public resolver
  {
  public:
    agnt_resolver(causal_graph &graph, const lin &cost, agnt_flaw &f, const atom &before, const atom &after, const lit &to_do);
    agnt_resolver(const agnt_resolver &that) = delete;
    virtual ~agnt_resolver();

    std::string get_label() const override { return "σ" + std::to_string(before.state) + " <= σ" + std::to_string(after.state); }

  private:
    void apply() override;

  private:
    const atom &before;
    const atom &after;
    const lit to_do;
  };

private:
  std::set<atom *> to_check;
  std::vector<std::pair<atom *, agnt_atom_listener *>> atoms;
};
}