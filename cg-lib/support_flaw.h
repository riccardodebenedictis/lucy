#pragma once

#include "flaw.h"
#include "atom.h"
#include "type.h"
#include "resolver.h"

using namespace lucy;

namespace cg
{

class support_flaw : public flaw
{
public:
  support_flaw(solver &g, atom &a, bool is_fact);
  support_flaw(const support_flaw &orig) = delete;
  virtual ~support_flaw();

  atom &get_atom() const { return atm; }
  std::string get_label() const override { return "φ" + std::to_string(get_phi()) + (is_fact ? " fact σ" : " goal σ") + std::to_string(atm.sigma) + " " + atm.tp.name; }

private:
  void compute_resolvers() override;

  class add_fact : public resolver
  {
  public:
    add_fact(solver &g, support_flaw &f, atom &a);
    add_fact(const add_fact &that) = delete;
    virtual ~add_fact();

    std::string get_label() const override { return "ρ" + std::to_string(rho) + " add fact"; }

  private:
    void apply() override;

  private:
    atom &atm;
  };

  class expand_goal : public resolver
  {
  public:
    expand_goal(solver &g, support_flaw &f, atom &a);
    expand_goal(const expand_goal &that) = delete;
    virtual ~expand_goal();

    std::string get_label() const override { return "ρ" + std::to_string(rho) + " expand goal"; }

  private:
    void apply() override;

  private:
    atom &atm;
  };

  class unify_atom : public resolver
  {
  public:
    unify_atom(solver &graph, support_flaw &atm_flaw, atom &atm, atom &with, const std::vector<lit> &unif_vars);
    unify_atom(const unify_atom &that) = delete;
    virtual ~unify_atom();

    std::string get_label() const override { return "ρ" + std::to_string(rho) + " unify"; }

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