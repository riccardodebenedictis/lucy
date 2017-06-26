#pragma once

#include "flaw.h"
#include "context.h"
#include "disjunction.h"
#include "resolver.h"

using namespace lucy;

namespace cg
{

class disjunction_flaw : public flaw
{
public:
  disjunction_flaw(causal_graph &graph, const context &ctx, const disjunction &disj);
  disjunction_flaw(const disjunction_flaw &orig) = delete;
  virtual ~disjunction_flaw();

  std::string get_label() const override { return "disj"; }

private:
  void compute_resolvers() override;

  class choose_conjunction : public resolver
  {
  public:
    choose_conjunction(causal_graph &graph, disjunction_flaw &disj_flaw, const context &ctx, const conjunction &conj);
    choose_conjunction(const choose_conjunction &that) = delete;
    virtual ~choose_conjunction();

    std::string get_label() const override { return "conj"; }

  private:
    bool apply() override;

  private:
    context ctx;
    const conjunction &conj;
  };

private:
  context ctx;
  const disjunction &disj;
};
}