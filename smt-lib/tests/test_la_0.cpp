#include "sat_core.h"
#include "la_theory.h"
#include <iostream>
#include <cassert>

using namespace smt;

int main()
{
    sat_core sat;
    la_theory la_th(sat);

    var x0 = la_th.new_var();
    var x1 = la_th.new_var();

    var leq_0 = la_th.new_leq(lin(x0, 1), lin(-4));
    var geq_0 = la_th.new_geq(lin(x0, 1), lin(-8));
    var leq_1 = la_th.new_leq(lin(x0, -1) + lin(x1, 1), lin(1));
    var geq_1 = la_th.new_geq(lin(x0, 1) + lin(x1, 1), lin(-3));

    bool a;
    a = sat.assume(lit(leq_0, true)) && sat.check();
    assert(a);
    a = sat.assume(lit(geq_0, true)) && sat.check();
    assert(a);
    a = sat.assume(lit(leq_1, true)) && sat.check();
    assert(a);
    a = sat.assume(lit(geq_1, true)) && sat.check();
    assert(a);
}