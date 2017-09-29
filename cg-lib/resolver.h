#pragma once

#include "la_theory.h"
#include <limits>

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

  virtual void apply() = 0;

  const var &get_rho() const { return rho; }
  flaw &get_effect() const { return effect; }
  std::vector<flaw *> get_preconditions() const { return preconditions; }
  double get_cost() const;

  virtual std::string get_label() const;

protected:
  solver &slv;                                               // the solver this resolver belongs to..
  const var rho;                                             // the propositional variable indicates whether the flaw is active or not..
  const lin cost;                                            // the intrinsic cost of the resolver..
  std::vector<flaw *> preconditions;                         // the preconditions of this resolver..
  flaw &effect;                                              // the flaw solved by this resolver..
  double est_cost = std::numeric_limits<double>::infinity(); // the estimated cost of the resolver..
};
}