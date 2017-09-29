#include "resolver.h"
#include "solver.h"

namespace cg
{
double resolver::get_cost() const { return slv.la_th.value(cost) + est_cost; }
}