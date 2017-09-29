#pragma once

#include "flaw.h"
#include "resolver.h"
#include "atom.h"
#include "type.h"

using namespace lucy;

namespace cg
{

class support_flaw : public flaw
{
public:
  support_flaw(solver &slv, atom &a, const bool is_fact);
  support_flaw(const support_flaw &orig) = delete;
  virtual ~support_flaw();

  atom &get_atom() const { return atm; }
  std::string get_label() const override { return "φ" + std::to_string(get_phi()) + (is_fact ? " fact σ" : " goal σ") + std::to_string(atm.sigma) + " " + atm.tp.name; }

private:
  void compute_resolvers() override;

  class activate_fact : public resolver
  {
  public:
    activate_fact(solver &slv, support_flaw &f, atom &a);
    activate_fact(const activate_fact &that) = delete;
    virtual ~activate_fact();

    std::string get_label() const override { return "ρ" + std::to_string(rho) + " add fact"; }

  private:
    void apply() override;

  private:
    atom &atm;
  };

  class activate_goal : public resolver
  {
  public:
    activate_goal(solver &slv, support_flaw &f, atom &a);
    activate_goal(const activate_goal &that) = delete;
    virtual ~activate_goal();

    std::string get_label() const override { return "ρ" + std::to_string(rho) + " expand goal"; }

  private:
    void apply() override;

  private:
    atom &atm;
  };

  class unify_atom : public resolver
  {
  public:
    unify_atom(solver &slv, support_flaw &atm_flaw, atom &atm, atom &trgt, const std::vector<lit> &unif_vars);
    unify_atom(const unify_atom &that) = delete;
    virtual ~unify_atom();

    std::string get_label() const override { return "ρ" + std::to_string(rho) + " unify"; }

  private:
    void apply() override;

  private:
    atom &atm;
    atom &trgt;
    const std::vector<lit> unif_lits;
  };

private:
  atom &atm;
  const bool is_fact;
};
}