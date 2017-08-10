#pragma once

#include "flaw.h"
#include "atom.h"
#include "type.h"
#include "resolver.h"

using namespace lucy;

namespace cg
{

class atom_flaw : public flaw
{
public:
  atom_flaw(causal_graph &g, atom &a, bool is_fact);
  atom_flaw(const atom_flaw &orig) = delete;
  virtual ~atom_flaw();

  atom &get_atom() const { return atm; }
  std::string get_label() const override { return "φ" + std::to_string(get_in_plan()) + (is_fact ? " fact σ" : " goal σ") + std::to_string(atm.state) + " " + atm.tp.name; }

private:
  void compute_resolvers() override;

  class add_fact : public resolver
  {
  public:
    add_fact(causal_graph &g, atom_flaw &f, atom &a);
    add_fact(const add_fact &that) = delete;
    virtual ~add_fact();

    std::string get_label() const override { return "ρ" + std::to_string(chosen) + " add fact"; }

  private:
    void apply() override;

  private:
    atom &atm;
  };

  class expand_goal : public resolver
  {
  public:
    expand_goal(causal_graph &g, atom_flaw &f, atom &a);
    expand_goal(const expand_goal &that) = delete;
    virtual ~expand_goal();

    std::string get_label() const override { return "ρ" + std::to_string(chosen) + " expand goal"; }

  private:
    void apply() override;

  private:
    atom &atm;
  };

  class unify_atom : public resolver
  {
  public:
    unify_atom(causal_graph &graph, atom_flaw &atm_flaw, atom &atm, atom &with, const std::vector<lit> &unif_vars);
    unify_atom(const unify_atom &that) = delete;
    virtual ~unify_atom();

    std::string get_label() const override { return "ρ" + std::to_string(chosen) + " unify"; }

  private:
    void apply() override;

  private:
    atom &atm;
    atom &with;
    std::vector<lit> unif_lits;
  };

private:
  atom &atm;
  bool is_fact;
};
}