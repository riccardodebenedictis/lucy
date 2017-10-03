#include "solver.h"
#include "enum_flaw.h"
#include "disjunction_flaw.h"
#include "atom_flaw.h"
#ifdef BUILD_GUI
#include "cg_listener.h"
#endif
#include <algorithm>
#include <cassert>

namespace cg
{

solver::solver() : core(), theory(sat_cr) { read(std::vector<std::string>({"init.rddl"})); }

solver::~solver() {}

expr solver::new_enum(const type &tp, const std::unordered_set<item *> &allowed_vals) { return nullptr; }

void solver::new_fact(atom &atm) {}

void solver::new_goal(atom &atm) {}

void solver::new_disjunction(context &d_ctx, const disjunction &disj) {}

void solver::solve() {}

void solver::new_flaw(flaw &f)
{
    f.init(); // flaws' initialization requires being at root-level..
    flaw_q.push(&f);

    assert(sat_cr.value(f.phi) != False);
    if (sat_cr.value(f.phi) == True)
        // we have a top-level (a landmark) flaw..
        flaws.insert(&f);
    else
    {
        // we listen for the flaw to become active..
        phis[f.phi].push_back(&f);
        bind(f.phi);
    }

#ifdef BUILD_GUI
    // we notify the listeners that a new flaw has arised..
    for (const auto &l : listeners)
        l->new_flaw(f);
#endif
}

void solver::new_resolver(resolver &r)
{
    assert(sat_cr.value(r.rho) != False);
    if (sat_cr.value(r.rho) != True) // we do not have a top-level (a landmark) resolver..
    {
        // we listen for the resolver to become active..
        rhos[r.rho].push_back(&r);
        bind(r.rho);
    }

#ifdef BUILD_GUI
    // we notify the listeners that a new resolver has arised..
    for (const auto &l : listeners)
        l->new_resolver(r);
#endif
}

void solver::new_causal_link(flaw &f, resolver &r)
{
    r.preconditions.push_back(&f);
    f.supports.push_back(&r);
    bool new_clause = sat_cr.new_clause({lit(r.rho, false), f.phi});
    assert(new_clause);

#ifdef BUILD_GUI
    // we notify the listeners that a new causal link has been created..
    for (const auto &l : listeners)
        l->causal_link_added(f, r);
#endif
}

void solver::set_cost(resolver &r, double cst)
{
    if (r.est_cost != cst)
    {
        double f_cost = r.effect.get_cost(); // this is the current effect's estimated cost..
        if (!trail.empty())
            trail.back().old_costs.insert({&r, r.est_cost});
        r.est_cost = cst;

#ifdef BUILD_GUI
        // we notify the listeners that a flaw cost has changed..
        for (const auto &l : listeners)
            l->resolver_cost_changed(r);
#endif

        if (f_cost != r.effect.get_cost()) // the effect's estimated cost has changed..
            for (const auto &supp : r.effect.supports)
                resolver_q.push(supp);

        propagate_costs();
    }
}

void solver::propagate_costs()
{
    while (!resolver_q.empty())
    {
        resolver &c_res = *resolver_q.front(); // the current resolver whose cost has been updated..
        double r_cost = -std::numeric_limits<double>::infinity();
        for (const auto &f : c_res.preconditions)
        {
            double c = f->get_cost();
            if (c < r_cost)
                r_cost = c;
        }
        if (c_res.est_cost != r_cost)
        {
            if (!trail.empty())
                trail.back().old_costs.insert({&c_res, c_res.est_cost});
            c_res.est_cost = r_cost;

#ifdef BUILD_GUI
            // we notify the listeners that a flaw cost has changed..
            for (const auto &l : listeners)
                l->resolver_cost_changed(c_res);
#endif

            for (const auto &supp : c_res.effect.supports)
                resolver_q.push(supp);
        }
        resolver_q.pop();
    }
}

flaw &solver::select_flaw()
{
    assert(!flaws.empty());
    assert(std::all_of(flaws.begin(), flaws.end(), [&](flaw *const f) { return f->expanded && sat_cr.value(f->phi) == True; }));
    // this is the next flaw to be solved (i.e., the most expensive one)..
    flaw *f_next = nullptr;
    for (auto it = flaws.begin(); it != flaws.end();)
        if (std::any_of((*it)->resolvers.begin(), (*it)->resolvers.end(), [&](resolver *r) { return sat_cr.value(r->rho) == True; }))
        {
            // we have either a trivial (i.e. has only one resolver) or an already solved flaw..
            assert(sat_cr.value((*std::find_if((*it)->resolvers.begin(), (*it)->resolvers.end(), [&](resolver *r) { return sat_cr.value(r->rho) != False; }))->rho) == True);
            // we remove the flaw from the current flaws..
            if (!trail.empty())
                trail.back().solved_flaws.insert((*it));
            flaws.erase(it++);
        }
        else
        {
            // the current flaw is not trivial nor already solved: let's see if it's better than the previous one..
            if (!f_next) // this is the first flaw we see..
                f_next = *it;
            else if (f_next->structural && !(*it)->structural) // we prefere non-structural flaws (i.e., inconsistencies) to structural ones..
                f_next = *it;
            else if (f_next->structural == (*it)->structural && f_next->get_cost() < (*it)->get_cost()) // this flaw is actually better than the previous one..
                f_next = *it;
            ++it;
        }

#ifdef BUILD_GUI
    if (f_next) // we notify the listeners that we have selected a flaw..
        for (const auto &l : listeners)
            l->current_flaw(*f_next);
#endif

    return *f_next;
}

resolver &solver::select_resolver(flaw &f)
{
    double r_cost = std::numeric_limits<double>::infinity();
    resolver *r_next = nullptr; // this is the next resolver to be selected (i.e., the cheapest one)..
    for (const auto &r : f.resolvers)
    {
        double c_cost = r->get_cost();
        if (c_cost < r_cost)
        {
            r_cost = c_cost;
            r_next = r;
        }
    }

#ifdef BUILD_GUI
    // we notify the listeners that we have selected a resolver..
    for (const auto &l : listeners)
        l->current_resolver(*r_next);
#endif

    return *r_next;
}

bool solver::propagate(const lit &p, std::vector<lit> &cnfl) { return false; }

bool solver::check(std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    return true;
}

void solver::push()
{
    trail.push_back(layer(res));
    if (res)
    {
        // we just solved the resolver's effect..
        trail.back().solved_flaws.insert(&res->effect);
        flaws.erase(&res->effect);
    }
}

void solver::pop()
{
    // we reintroduce the solved flaw..
    for (const auto &f : trail.back().solved_flaws)
        flaws.insert(f);

    // we erase the new flaws..
    for (const auto &f : trail.back().new_flaws)
        flaws.erase(f);

    // we restore the resolvers' estimated costs..
    for (const auto &r : trail.back().old_costs)
        r.first->est_cost = r.second;

#ifdef BUILD_GUI
    // we notify the listeners that the cost of some flaws has been restored..
    for (const auto &l : listeners)
        for (const auto &c : trail.back().old_costs)
            l->resolver_cost_changed(*c.first);
#endif

    trail.pop_back();
}
}