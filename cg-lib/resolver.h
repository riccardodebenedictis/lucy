#pragma once

#include "la_theory.h"

using namespace smt;

namespace cg
{

class causal_graph;
class flaw;

class resolver
{
  friend class causal_graph;
  friend class flaw;

public:
  resolver(causal_graph &graph, const var &r, const lin &cost, flaw &eff);
  resolver(causal_graph &graph, const lin &cost, flaw &eff);
  resolver(const resolver &orig) = delete;
  virtual ~resolver();

  virtual void apply() = 0;

  const var &get_rho() const { return rho; }
  flaw &get_effect() const { return effect; }
  std::vector<flaw *> get_preconditions() const { return preconditions; }
  double get_cost() const;

  virtual std::string get_label() const;

protected:
  causal_graph &graph;
  const var rho;
  const lin cost;
  // the preconditions of this resolver..
  std::vector<flaw *> preconditions;
  // the flaw solved by this resolver..
  flaw &effect;
};
}