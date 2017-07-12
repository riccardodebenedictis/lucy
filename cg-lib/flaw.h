#pragma once

#include "la_theory.h"
#include <limits>

using namespace smt;

namespace cg
{

class causal_graph;
class resolver;

class flaw
{
  friend class causal_graph;
  friend class resolver;

public:
  flaw(causal_graph &graph, const bool &exclusive = false);
  flaw(const flaw &orig) = delete;
  virtual ~flaw();

  bool is_expanded() const { return expanded; }
  bool is_initialized() const { return initialized; }
  var get_in_plan() const { return in_plan; }
  std::vector<resolver *> get_causes() const { return causes; }
  std::vector<resolver *> get_supports() const { return supports; }
  double get_cost() const { return cost; }

  virtual std::string get_label() const;

private:
  virtual void init();
  void expand();
  virtual void compute_resolvers() = 0;
  bool has_subgoals();

protected:
  void add_resolver(resolver &r);

protected:
  causal_graph &graph;

private:
  const bool exclusive;
  bool initialized = false;
  bool expanded = false;
  var in_plan;
  // the resolvers for this flaw..
  std::vector<resolver *> resolvers;
  // the causes for having this flaw..
  std::vector<resolver *> causes;
  // the resolvers supported by this flaw..
  std::vector<resolver *> supports;
  double cost = std::numeric_limits<double>::infinity();
};
}