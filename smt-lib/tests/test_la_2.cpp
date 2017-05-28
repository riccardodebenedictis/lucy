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

    bool leq0 = la_th.new_leq(lin(x0, 1), lin(x1, 1));
    bool geq0 = la_th.new_geq(lin(x0, 1), lin(10));
    bool leq1 = la_th.new_leq(lin(x0, 1) + lin(x1, 1), lin(20));

    bool a = sat.assume(lit(leq0, true));
    assert(a);
    a = sat.assume(lit(geq0, true));
    assert(a);
    a = sat.assume(lit(leq1, true));
    assert(a);
}