#include "sat_core.h"
#include <cassert>

using namespace smt;

int main()
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