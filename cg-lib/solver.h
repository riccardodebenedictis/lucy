#pragma once

#include "core.h"

using namespace lucy;

namespace cg
{

class flaw;
class atom_flaw;
class resolver;
class cg_listener;

class solver : public core, public theory
{
  friend class flaw;
  friend class atom_flaw;
  friend class super_flaw;
  friend class resolver;
  friend class cg_listener;

public:
  solver();
  solver(const solver &orig) = delete;
  virtual ~solver();

  void init(); // initializes the solver..

  expr new_enum(const type &tp, const std::unordered_set<item *> &allowed_vals) override;

private:
  void new_fact(atom &atm) override;
  void new_goal(atom &atm) override;
  void new_disjunction(context &d_ctx, const disjunction &disj) override;

public:
  void solve() override; // solves the given problem..

  atom_flaw &get_flaw(const atom &atm) const { return *reason.at(&atm); } // returns the flaw which has given rise to the atom..

private:
  void build();                // builds the planning graph..
  bool is_deferrable(flaw &f); // checks whether the given flaw is deferrable..
  void add_layer();            // adds a layer to the current planning graph..
  bool has_inconsistencies();  // checks whether the types have some inconsistency..
  void expand_flaw(flaw &f);   // expands the given flaw into the planning graph..

  void new_flaw(flaw &f);
  void new_resolver(resolver &r);
  void new_causal_link(flaw &f, resolver &r);

  void set_est_cost(resolver &r, const double &cst); // sets the estimated cost of the given resolver and propagates it to other resolvers..
  flaw *select_flaw();                               // selects the most expensive flaw from the 'flaws' set, returns a nullptr if there are no active flaws..
  resolver &select_resolver(flaw &f);                // selects the least expensive resolver for the given flaw..

  bool propagate(const lit &p, std::vector<lit> &cnfl) override;
  bool check(std::vector<lit> &cnfl) override;
  void push() override;
  void pop() override;

private:
  struct layer
  {

    layer(resolver *const r) : r(r) {}

    resolver *const r;
    std::unordered_map<resolver *, double> old_costs; // the old estimated resolvers' costs..
    std::unordered_set<flaw *> new_flaws;             // the just activated flaws..
    std::unordered_set<flaw *> solved_flaws;          // the just solved flaws..
  };

  std::vector<cg_listener *> listeners;                  // the causal-graph listeners..
  resolver *res = nullptr;                               // the current resolver (will be into the trail)..
  var gamma;                                             // this variable represents the validity of the current graph..
  bool building_graph = false;                           // we are either in a building graph phase or in a solving phase..
  std::list<flaw *> flaw_q;                              // the flaw queue (for graph building procedure)..
  std::unordered_set<flaw *> flaws;                      // the current active flaws..
  std::unordered_map<var, std::vector<flaw *>> phis;     // the phi variables (boolean variable to flaws) of the flaws..
  std::unordered_map<var, std::vector<resolver *>> rhos; // the rho variables (boolean variable to resolver) of the resolvers..
  std::unordered_map<const atom *, atom_flaw *> reason;  // the reason for having introduced an atom..
  std::vector<layer> trail;                              // the list of resolvers in chronological order..
};
}