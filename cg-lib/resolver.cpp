#include "resolver.h"
#include "solver.h"

namespace cg
{

resolver::resolver(solver &slv, const var &r, const lin &cost, flaw &eff) : slv(slv), rho(r), cost(cost), effect(eff) {}
resolver::resolver(solver &slv, const lin &cost, flaw &eff) : resolver(slv, slv.sat_cr.new_var(), cost, eff) {}
resolver::~resolver() {}

double resolver::get_cost() const { return slv.la_th.value(cost) + est_cost; }
}