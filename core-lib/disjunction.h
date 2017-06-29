#pragma once

#include "scope.h"
#include "la_theory.h"

using namespace smt;

namespace lucy
{

namespace ast
{
class statement;
}

class context;

class conjunction : public scope
{
public:
  conjunction(core &cr, scope &scp, const lin &cst, const std::vector<const ast::statement *> &stmnts);
  conjunction(const conjunction &that) = delete;
  virtual ~conjunction();

  lin get_cost() const { return cost; }

  void apply(context &ctx) const;

private:
  const lin cost;
  const std::vector<const ast::statement *> statements;
};

class disjunction : public scope
{
public:
  disjunction(core &cr, scope &scp, const std::vector<const conjunction *> &conjs);
  disjunction(const disjunction &orig) = delete;
  virtual ~disjunction();

  const std::vector<const conjunction *> get_conjunctions() const { return conjunctions; }

private:
  const std::vector<const conjunction *> conjunctions;
};
}