#include "flaw.h"
#include "resolver.h"
#include "causal_graph.h"
#include <algorithm>
#include <cassert>

namespace cg
{

flaw::flaw(causal_graph &graph, const bool &exclusive) : graph(graph), exclusive(exclusive), supports(graph.resolvers.begin(), graph.resolvers.end())
{
    // the cuases for this flaw is the current resolvers of the causal graph..
    for (const auto &r : graph.resolvers)
    {
        causes.push_back(r);
        r->preconditions.push_back(this);
    }
}

flaw::~flaw() {}

std::string flaw::get_label() const
{
    std::string lbl = "b" + std::to_string(in_plan);
    switch (graph.core::sat.value(in_plan))
    {
    case True:
        lbl += "(T)";
        break;
    case False:
        lbl += "(F)";
        break;
    case Undefined:
        break;
    default:
        break;
    }
    lbl += " " + std::to_string(cost);
    return lbl;
}

void flaw::init()
{
    assert(!expanded);

    if (causes.empty())
        // the flaw is necessarily in_plan..
        in_plan = TRUE_var;
    else
    {
        // we create a new variable..
        std::vector<lit> cs;
        for (const auto &c : causes)
            cs.push_back(c->chosen);

        // the flaw is in_plan if the conjunction of its causes is in_plan..
        in_plan = graph.core::sat.new_conj(cs);
    }

    if (graph.core::sat.value(in_plan) == True)
        // we have a top-level (a landmark) flaw..
        graph.flaws.insert(this);
    else
    {
        // we listen for the flaw to become in_plan..
        graph.in_plan[in_plan].push_back(this);
        graph.bind(in_plan);
    }
}

void flaw::expand()
{
    assert(!expanded);

    // we compute the resolvers..
    compute_resolvers();
    expanded = true;

    // we add causal relations between the flaw and its resolvers (i.e., if the flaw is in_plan exactly one of its resolvers should be in plan)..
    if (resolvers.empty())
    {
        // there is no way for solving this flaw..
        if (!graph.core::sat.new_clause({lit(in_plan, false)}))
            throw unsolvable_exception();
    }
    else
    {
        // we need to take a decision for solving this flaw..
        std::vector<lit> r_chs;
        for (const auto &r : resolvers)
            r_chs.push_back(r->chosen);
        if (!graph.core::sat.new_clause({lit(in_plan, false), exclusive ? graph.core::sat.new_exct_one(r_chs) : graph.core::sat.new_disj(r_chs)}))
            throw unsolvable_exception();
    }
}

bool flaw::has_subgoals()
{
    return std::any_of(resolvers.begin(), resolvers.end(), [](const resolver *r) { return !r->preconditions.empty(); });
}

void flaw::add_resolver(resolver &r)
{
    resolvers.push_back(&r);
    graph.new_resolver(r);
}
}