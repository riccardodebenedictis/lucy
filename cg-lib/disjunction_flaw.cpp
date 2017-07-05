#include "disjunction_flaw.h"
#include "env.h"
#include "causal_graph.h"

namespace cg
{

disjunction_flaw::disjunction_flaw(causal_graph &graph, const context &ctx, const disjunction &disj) : flaw(graph, true), ctx(ctx), disj(disj) {}

disjunction_flaw::~disjunction_flaw() {}

void disjunction_flaw::compute_resolvers()
{
    for (const auto &cnj : disj.get_conjunctions())
    {
        context cnj_ctx(new env(graph, ctx));
        add_resolver(*new choose_conjunction(graph, *this, cnj_ctx, *cnj));
    }
}

disjunction_flaw::choose_conjunction::choose_conjunction(causal_graph &graph, disjunction_flaw &disj_flaw, const context &ctx, const conjunction &conj) : resolver(graph, conj.get_cost(), disj_flaw), ctx(ctx), conj(conj) {}

disjunction_flaw::choose_conjunction::~choose_conjunction() {}

void disjunction_flaw::choose_conjunction::apply() { conj.apply(ctx); }
}