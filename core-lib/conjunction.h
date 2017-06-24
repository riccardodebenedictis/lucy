#pragma once

#include "scope.h"
#include "la_theory.h"
#include "statement.h"

using namespace smt;

namespace lucy
{

namespace ast
{
class statement;
}

class context;

class DLL_PUBLIC conjunction : public scope
{
public:
  conjunction(core &cr, scope &scp, const lin &cst, const std::vector<ast::statement *> &stmnts);
  conjunction(const conjunction &that) = delete;
  virtual ~conjunction();

  lin get_cost() const
  {
    return cost;
  }

  bool apply(context &ctx) const;

private:
  const lin cost;
  const std::vector<ast::statement *> statements;
};
}