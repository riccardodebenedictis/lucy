#include "theory.h"
#include "sat_core.h"
#include <cassert>

namespace smt
{

theory::theory(sat_core &sat) : sat(sat) { sat.add_theory(*this); }

theory::~theory()
{
    for (const auto &lo : listening_on)
        sat.unbind(lo, *this);
    listening_on.clear();
    sat.remove_theory(*this);
}

void theory::bind(var var)
{
    if (listening_on.find(var) == listening_on.end())
    {
        listening_on.insert(var);
        sat.bind(var, *this);
    }
}

void theory::unbind(var var)
{
    assert(listening_on.find(var) != listening_on.end());
    listening_on.erase(var);
    sat.unbind(var, *this);
}

void theory::record(const std::vector<lit> &cls) { sat.record(cls); }
}