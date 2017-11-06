#pragma once

#include "la_theory.h"

using namespace smt;

namespace cg
{

class solver;
class flaw;

class resolver
{
  friend class solver;
  friend class flaw;

public:
  resolver(solver &slv, const var &r, const lin &cost, flaw &eff);
  resolver(solver &slv, const lin &cost, flaw &eff);
  resolver(const resolver &orig) = delete;
  virtual ~resolver();

private:
  void init();
  virtual void apply() = 0;

public:
  const var &get_rho() const { return rho; }
  flaw &get_effect() const { return effect; }
  std::vector<flaw *> get_preconditions() const { return preconditions; }
  rational get_cost() const;

  virtual std::string get_label() const = 0;

protected:
  solver &slv;                        // the solver this resolver belongs to..
  const var rho;                      // the propositional variable indicating whether the resolver is active or not..
  const lin cost;                     // the intrinsic cost of the resolver..
  std::vector<flaw *> preconditions;  // the preconditions of this resolver..
  flaw &effect;                       // the flaw solved by this resolver..
  rational est_cost = rational(1, 0); // the estimated cost of the resolver..
};
}