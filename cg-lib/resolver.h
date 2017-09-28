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
  resolver(solver &graph, const var &r, const lin &cost, flaw &eff);
  resolver(solver &graph, const lin &cost, flaw &eff);
  resolver(const resolver &orig) = delete;
  virtual ~resolver();

  virtual void apply() = 0;

  const var &get_rho() const { return rho; }
  flaw &get_effect() const { return effect; }
  std::vector<flaw *> get_preconditions() const { return preconditions; }
  double get_cost() const;

  virtual std::string get_label() const;

protected:
  solver &graph;
  const var rho;
  const lin cost;
  // the preconditions of this resolver..
  std::vector<flaw *> preconditions;
  // the flaw solved by this resolver..
  flaw &effect;
};
}