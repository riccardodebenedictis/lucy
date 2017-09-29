#pragma once

#include "core.h"

using namespace lucy;

namespace cg
{

class flaw;
class support_flaw;
class resolver;
class cg_listener;

class solver : public core, public theory
{
  friend class cg_listener;

public:
  solver();
  solver(const solver &orig) = delete;
  virtual ~solver();

  expr new_enum(const type &tp, const std::unordered_set<item *> &allowed_vals) override;

private:
  void new_fact(atom &atm) override;
  void new_goal(atom &atm) override;
  void new_disjunction(context &d_ctx, const disjunction &disj) override;

public:
  void solve() override;

  support_flaw &get_support_flaw(const atom &atm) const { return *reason.at(&atm); }

private:
  bool propagate(const lit &p, std::vector<lit> &cnfl) override;
  bool check(std::vector<lit> &cnfl) override;
  void push() override;
  void pop() override;

  flaw &select_flaw();                // selects the most expensive flaw from the 'flaws' set..
  resolver &select_resolver(flaw &f); // select the least expensive resolver for the given flaw..

private:
  struct layer
  {

    layer(resolver *const r) : r(r) {}

    resolver *const r;
    std::unordered_map<resolver *, double> old_costs; // the estimated resolvers' estimated costs..
    std::unordered_set<flaw *> new_flaws;             // the newly activated flaws..
    std::unordered_set<flaw *> solved_flaws;          // the solved flaws..
  };

  std::unordered_set<flaw *> flaws;                        // the current active flaws..
  std::queue<flaw *> flaw_q;                               // the flaw queue..
  std::vector<cg_listener *> listeners;                    // the causal-graph listeners..
  std::unordered_map<const atom *, support_flaw *> reason; // the reason for having introduced an atom..
  resolver *res = nullptr;                                 // the current resolver (will be into the trail)..
  std::vector<layer> trail;                                // the list of resolvers in chronological order..
};
}