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

void theory::bind(const var &v)
{
    if (listening_on.find(v) == listening_on.end())
    {
        listening_on.insert(v);
        sat.bind(v, *this);
    }
}

void theory::unbind(const var &v)
{
    assert(listening_on.find(v) != listening_on.end());
    listening_on.erase(v);
    sat.unbind(v, *this);
}

void theory::record(const std::vector<lit> &cls) { sat.record(cls); }
}