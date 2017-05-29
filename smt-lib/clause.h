#pragma once

#include "lit.h"
#include <vector>

namespace smt
{

class sat_core;

class clause
{
    friend class sat_core;

  private:
    clause(sat_core &s, const std::vector<lit> &lits);
    clause(const clause &orig) = delete;
    ~clause();

    bool propagate(const lit &p);
    std::string to_string() const;

  private:
    sat_core &s;
    std::vector<lit> lits;
};
}