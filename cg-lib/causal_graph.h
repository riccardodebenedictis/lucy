#pragma once

#include "core.h"

using namespace lucy;

namespace cg
{

class flaw;
class atom_flaw;
class causal_graph_listener;

class resolver;

class causal_graph : public core, public theory
{
  friend class flaw;
  friend class atom_flaw;
  friend class causal_graph_listener;

public:
  causal_graph();
  causal_graph(const causal_graph &orig) = delete;
  virtual ~causal_graph();

  expr new_enum(const type &tp, const std::unordered_set<item *> &allowed_vals) override;

private:
  void new_fact(atom &atm) override;
  void new_goal(atom &atm) override;
  void new_disjunction(context &d_ctx, const disjunction &disj) override;

public:
  void solve() override;

private:
  void new_flaw(flaw &f);
  void new_resolver(resolver &r);
  void new_causal_link(flaw &f, resolver &r);

  bool propagate(const lit &p, std::vector<lit> &cnfl) override;
  bool check(std::vector<lit> &cnfl) override;
  void push() override;
  void pop() override;

  void build();
  void add_layer();
  inline bool has_solution();
  bool is_deferrable(flaw &f);
  void set_cost(flaw &f, double cost);
  void propagate_costs();
  bool has_inconsistencies();

  flaw *select_flaw();
  resolver &select_resolver(flaw &f);

private:
  struct layer
  {

    layer(resolver *r) : r(r) {}

    resolver *r;
    // the estimated flaw costs..
    std::unordered_map<flaw *, double> old_costs;
    // the new flaws..
    std::unordered_set<flaw *> new_flaws;
    // the solved flaws..
    std::unordered_set<flaw *> solved_flaws;
  };

  bool building_graph = false;
  // the reason for having introduced a flaw..
  std::unordered_map<atom *, atom_flaw *> reason;
  // the flaw queue..
  std::queue<flaw *> flaw_q;
  // the flaw costs queue (for flaw cost propagation)..
  std::queue<flaw *> flaw_costs_q;
  // the current assumed resolvers..
  std::list<resolver *> resolvers;
  // the current flaws..
  std::unordered_set<flaw *> flaws;
  // the phi variables (boolean variable to flaws) of the flaws..
  std::unordered_map<var, std::vector<flaw *>> phis;
  // the rho variables (boolean variable to resolver) of the resolvers..
  std::unordered_map<var, std::vector<resolver *>> rhos;
  // this variable represents the validity of the current graph..
  var graph_var;
  // the current resolver (will be into the trail)..
  resolver *res = nullptr;
  // the list of resolvers in chronological order..
  std::vector<layer> trail;
  std::vector<causal_graph_listener *> listeners;
};
}