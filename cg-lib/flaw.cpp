#include "flaw.h"
#include "resolver.h"
#include "solver.h"
#include <limits>
#include <cassert>

namespace cg
{

flaw::flaw(solver &slv, const std::vector<resolver *> &causes, const bool &exclusive, const bool &structural) : slv(slv), exclusive(exclusive), structural(structural), causes(causes.begin(), causes.end()), supports(causes.begin(), causes.end())
{
    for (const auto &r : causes)
        r->preconditions.push_back(this);
}

flaw::~flaw() {}

double flaw::get_cost() const
{
    double min_cost = std::numeric_limits<double>::infinity();
    for (const auto &r : resolvers)
        if (r->get_cost() < min_cost)
            min_cost = r->get_cost();
    return min_cost;
}

void flaw::init()
{
    assert(!expanded);

    if (causes.empty())
        // the flaw is necessarily active..
        phi = TRUE_var;
    else
    {
        // we create a new variable..
        std::vector<lit> cs;
        for (const auto &c : causes)
            cs.push_back(c->rho);

        // the flaw is active if the conjunction of its causes is active..
        phi = slv.sat_cr.new_conj(cs);
    }

    if (slv.sat_cr.value(phi) == True)
        // we have a top-level (a landmark) flaw..
        slv.flaws.insert(this);
    else
    {
        // we listen for the flaw to become active..
        slv.phis[phi].push_back(this);
        slv.bind(phi);
    }
}

void flaw::expand()
{
    assert(!expanded);

    // we compute the resolvers..
    compute_resolvers();
    expanded = true;

    // we add causal relations between the flaw and its resolvers (i.e., if the flaw is phi exactly one of its resolvers should be in plan)..
    if (resolvers.empty())
    {
        // there is no way for solving this flaw..
        if (!slv.sat_cr.new_clause({lit(phi, false)}))
            throw unsolvable_exception();
    }
    else
    {
        // we need to take a decision for solving this flaw..
        std::vector<lit> r_chs;
        for (const auto &r : resolvers)
            r_chs.push_back(r->rho);
        if (!slv.sat_cr.new_clause({lit(phi, false), exclusive ? slv.sat_cr.new_exct_one(r_chs) : slv.sat_cr.new_disj(r_chs)}))
            throw unsolvable_exception();
    }
}

void flaw::add_resolver(resolver &r)
{
    resolvers.push_back(&r);
    slv.new_resolver(r);
}
}