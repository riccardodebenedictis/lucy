#pragma once

#include "la_theory.h"
#include <limits>

using namespace smt;

namespace cg
{

class solver;
class resolver;

class flaw
{
  friend class solver;
  friend class resolver;

public:
  flaw(solver &graph, const bool &exclusive = false, const bool &structural = false);
  flaw(const flaw &orig) = delete;
  virtual ~flaw();

  bool is_expanded() const { return expanded; }
  const var &get_phi() const { return phi; }
  std::vector<resolver *> get_causes() const { return causes; }
  std::vector<resolver *> get_supports() const { return supports; }
  double get_cost() const { return cost; }

  virtual std::string get_label() const;

private:
  virtual void init();
  void expand();
  virtual void compute_resolvers() = 0;

protected:
  void add_resolver(resolver &r);

protected:
  solver &graph;

private:
  const bool exclusive;
  const bool structural;
  bool expanded = false;
  var phi;
  // the resolvers for this flaw..
  std::vector<resolver *> resolvers;
  // the causes for having this flaw..
  std::vector<resolver *> causes;
  // the resolvers supported by this flaw..
  std::vector<resolver *> supports;
  double cost = std::numeric_limits<double>::infinity();
};
}