#include "solver.h"
#include <cassert>

namespace cg
{

solver::solver() : core(), theory(sat_cr) { read(std::vector<std::string>({"init.rddl"})); }

solver::~solver() {}

expr solver::new_enum(const type &tp, const std::unordered_set<item *> &allowed_vals) { return nullptr; }

void solver::new_fact(atom &atm) {}

void solver::new_goal(atom &atm) {}

void solver::new_disjunction(context &d_ctx, const disjunction &disj) {}

void solver::solve() {}

bool solver::propagate(const lit &p, std::vector<lit> &cnfl) { return false; }

bool solver::check(std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    return true;
}

void solver::push() {}

void solver::pop() {}
}