#include "sat_core.h"
#include <iostream>
#include <cassert>

using namespace smt;

int main()
{
    sat_core sat;

    var b0 = sat.new_var();
    var b1 = sat.new_var();

    bool cs;
    cs = sat.new_clause({lit(b0, true), lit(b1, true)});
    assert(cs);

    bool ch;
    ch = sat.check({lit(b0, false), lit(b1, false)});
    assert(!ch);
}