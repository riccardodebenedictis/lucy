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
    var b2 = la_th.new_geq(lin(x0, 1), lin(1));
    var b3 = la_th.new_geq(lin(x0, 1), lin(0));
    var b4 = la_th.new_leq(lin(x0, 1), lin(-1));

    bool a;
    a = sat.assume(lit(b2, true)) && sat.check();
    assert(a);
    assert(sat.value(b3) == True);
    assert(sat.value(b4) == False);

    var x1 = la_th.new_var();
    var b5 = la_th.new_leq(lin(x1, 1), lin(-1));
    var b6 = la_th.new_leq(lin(x1, 1), lin(0));
    var b7 = la_th.new_geq(lin(x1, 1), lin(1));

    a = sat.assume(lit(b5, true)) && sat.check();
    assert(a);
    assert(sat.value(b6) == True);
    assert(sat.value(b7) == False);
}