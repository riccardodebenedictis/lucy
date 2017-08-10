#include "resolver.h"
#include "causal_graph.h"
#include "flaw.h"
#include <cassert>

namespace cg
{

resolver::resolver(causal_graph &graph, const var &ch, const lin &cost, flaw &eff) : graph(graph), chosen(ch), cost(cost), effect(eff) {}
resolver::resolver(causal_graph &graph, const lin &cost, flaw &eff) : resolver(graph, graph.core::sat.new_var(), cost, eff) {}
resolver::~resolver() {}

double resolver::get_cost() const
{
    if (graph.core::sat.value(chosen) == False) // the resolver cannot be chosen..
        return std::numeric_limits<double>::infinity();
    else
    {
        // the cost of the resolver is given by the cost of its most expensive precondition plus the cost of the resolver itself..
        double r_cost = preconditions.empty() ? 0.0 : -std::numeric_limits<double>::infinity();
        for (const auto &f : preconditions)
            if (f->cost > r_cost)
                r_cost = f->cost;
        r_cost += graph.la_th.value(cost);
        return r_cost;
    }
}

std::string resolver::get_label() const
{
    std::string lbl = "ρ" + std::to_string(chosen);
    switch (graph.core::sat.value(chosen))
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
    return lbl;
}
}