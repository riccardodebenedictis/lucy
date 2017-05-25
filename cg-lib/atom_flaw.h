#pragma once

#include "flaw.h"
#include "atom.h"
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

  std::string get_label() const override { return is_fact ? "fact e" + std::to_string(atm.state) : "goal e" + std::to_string(atm.state); }

private:
  void compute_resolvers() override;

  class add_fact : public resolver
  {
  public:
    add_fact(causal_graph &g, atom_flaw &f, atom &a);
    add_fact(const add_fact &that) = delete;
    virtual ~add_fact();

    std::string get_label() const override { return "add fact"; }

  private:
    bool apply() override;

  private:
    atom &atm;
  };

  class expand_goal : public resolver
  {
  public:
    expand_goal(causal_graph &g, atom_flaw &f, atom &a);
    expand_goal(const expand_goal &that) = delete;
    virtual ~expand_goal();

    std::string get_label() const override { return "expand goal"; }

  private:
    bool apply() override;

  private:
    atom &atm;
  };

  class unify_atom : public resolver
  {
  public:
    unify_atom(causal_graph &graph, atom_flaw &atm_flaw, atom &atm, atom &with, const std::vector<lit> &unif_vars);
    unify_atom(const unify_atom &that) = delete;
    virtual ~unify_atom();

    std::string get_label() const override { return "unify"; }

  private:
    bool apply() override;

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