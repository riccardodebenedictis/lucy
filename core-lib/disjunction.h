#pragma once

#include "scope.h"

namespace lucy
{

class conjunction;

class DLL_PUBLIC disjunction : public scope
{
public:
  disjunction(core &cr, scope &scp);
  disjunction(const disjunction &orig) = delete;
  virtual ~disjunction();

  std::vector<conjunction *> get_conjunctions() const
  {
    return conjunctions;
  }

private:
  std::vector<conjunction *> conjunctions;
};
}