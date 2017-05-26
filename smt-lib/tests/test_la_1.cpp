#include "sat_core.h"
#include "la_theory.h"
#include <cassert>

using namespace smt;

int main()
{
    sat_core sat;
    la_theory la_th(sat);

    var b0 = sat.new_var();
    var x0 = la_th.new_var();

    var b5 = la_th.new_geq(lin(x0, 1), lin(10));
    var b6 = la_th.new_leq(lin(x0, 1), lin(0));

    bool cs;
    cs = sat.new_clause({lit(b0, false), lit(b5, true)});
    assert(cs);
    cs = sat.new_clause({lit(b5, false), lit(b6, true)});
    assert(cs);

    bool p = sat.check();
    assert(p);

    bool a;
    a = sat.assume(lit(b0, true)) && sat.check();
    assert(a);
}