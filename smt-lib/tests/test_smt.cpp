#include "sat_core.h"
#include "la_theory.h"
#include <iostream>
#include <cassert>

using namespace smt;

void test_sat_0()
{
    sat_core sat;

    var b0 = sat.new_var();
    var b1 = sat.new_var();
    var b2 = sat.new_var();
    var b3 = sat.new_var();
    var b4 = sat.new_var();
    var b5 = sat.new_var();
    var b6 = sat.new_var();
    var b7 = sat.new_var();
    var b8 = sat.new_var();

    bool cs;
    cs = sat.new_clause({lit(b0, true), lit(b1, true)});
    assert(cs);
    cs = sat.new_clause({lit(b0, true), lit(b2, true), lit(b6, true)});
    assert(cs);
    cs = sat.new_clause({lit(b1, false), lit(b2, false), lit(b3, true)});
    assert(cs);
    cs = sat.new_clause({lit(b3, false), lit(b4, true), lit(b7, true)});
    assert(cs);
    cs = sat.new_clause({lit(b3, false), lit(b5, true), lit(b8, true)});
    assert(cs);
    cs = sat.new_clause({lit(b4, false), lit(b5, false)});
    assert(cs);

    bool a;
    a = sat.assume(lit(b6, false)) && sat.check();
    assert(a);
    a = sat.assume(lit(b7, false)) && sat.check();
    assert(a);
    a = sat.assume(lit(b8, false)) && sat.check();
    assert(a);
    a = sat.assume(lit(b0, false)) && sat.check();
    assert(a);
}

void test_la_0()
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

void test_la_1()
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

void test_theory_propagation()
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

int main()
{
    std::cout << "[smt-lib] testing sat core.." << std::endl;
    test_sat_0();

    std::cout << "[smt-lib] testing linear arithmetic theory 0.." << std::endl;
    test_la_0();

    std::cout << "[smt-lib] testing linear arithmetic theory 1.." << std::endl;
    test_la_1();

    std::cout << "[smt-lib] testing theory propagation.." << std::endl;
    test_theory_propagation();
}