#pragma once

#include "scope.h"
#include "la_theory.h"

using namespace smt;

namespace lucy
{

class context;

class DLL_PUBLIC conjunction : public scope
{
public:
  conjunction(core &cr, scope &scp, const lin &cst);
  conjunction(const conjunction &that) = delete;
  virtual ~conjunction();

  lin get_cost() const
  {
    return cost;
  }

  virtual bool apply(context &ctx) const = 0;

private:
  lin cost;
};
}