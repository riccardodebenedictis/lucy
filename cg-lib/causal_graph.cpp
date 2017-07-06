#include "causal_graph.h"
#include "enum_flaw.h"
#include "atom_flaw.h"
#include "disjunction_flaw.h"
#include "smart_type.h"
#include "state_variable.h"
#include "reusable_resource.h"
#include "causal_graph_listener.h"
#include "propositional_state.h"
#include "propositional_agent.h"
#include <algorithm>
#ifndef NDEBUG
#include <iostream>
#endif
#include <cassert>

namespace cg
{

causal_graph::causal_graph() : core(), theory(core::sat)
{
    bool r = read(std::vector<std::string>({"init.rddl"}));
    assert(r);
    types.insert({STATE_VARIABLE_NAME, new state_variable(*this)});
    types.insert({REUSABLE_RESOURCE_NAME, new reusable_resource(*this)});
    types.insert({PROPOSITIONAL_STATE_NAME, new propositional_state(*this)});
    types.insert({PROPOSITIONAL_AGENT_NAME, new propositional_agent(*this)});
}

causal_graph::~causal_graph() {}

expr causal_graph::new_enum(const type &tp, const std::unordered_set<item *> &allowed_vals)
{
    assert(!allowed_vals.empty());
    // we create a new enum expression..
    enum_expr c_e = core::new_enum(tp, allowed_vals);
    if (allowed_vals.size() > 1)
    {
        // we create a new enum flaw..
        enum_flaw *ef = new enum_flaw(*this, *c_e);
        new_flaw(*ef);
    }
    return c_e;
}

void causal_graph::new_fact(atom &atm)
{
    // we create a new atom flaw representing a fact..
    atom_flaw *af = new atom_flaw(*this, atm, true);
    reason.insert({&atm, af});
    new_flaw(*af);

    // we link the state of the atom to the state of the flaw..
    if (!core::sat.new_clause({lit(set_th.allows(atm.state, *active), false), lit(af->in_plan, true)}))
        throw unsolvable_exception();
    if (!core::sat.new_clause({lit(set_th.allows(atm.state, *unified), false), lit(af->in_plan, true)}))
        throw unsolvable_exception();
    if (!core::sat.new_clause({lit(set_th.allows(atm.state, *inactive), false), lit(af->in_plan, false)}))
        throw unsolvable_exception();

    core::new_fact(atm);
}

void causal_graph::new_goal(atom &atm)
{
    // we create a new atom flaw representing a goal..
    atom_flaw *af = new atom_flaw(*this, atm, false);
    reason.insert({&atm, af});
    new_flaw(*af);

    // we link the state of the atom to the state of the flaw..
    if (!core::sat.new_clause({lit(set_th.allows(atm.state, *active), false), lit(af->in_plan, true)}))
        throw unsolvable_exception();
    if (!core::sat.new_clause({lit(set_th.allows(atm.state, *unified), false), lit(af->in_plan, true)}))
        throw unsolvable_exception();
    if (!core::sat.new_clause({lit(set_th.allows(atm.state, *inactive), false), lit(af->in_plan, false)}))
        throw unsolvable_exception();

    core::new_goal(atm);
}

void causal_graph::new_disjunction(context &d_ctx, const disjunction &disj)
{
    // we create a new disjunction flaw..
    disjunction_flaw *df = new disjunction_flaw(*this, d_ctx, disj);
    new_flaw(*df);
}

bool causal_graph::solve()
{
main_loop:
    res = nullptr;

    if (!flaw_q.empty())
    {
        // we build the planning graph..
        try
        {
            build();
        }
        catch (const unsolvable_exception &)
        {
            return false;
        }
    }

#ifndef NDEBUG
    std::cout << "searching.." << std::endl;
#endif

    // we create a new graph var..
    graph_var = core::sat.new_var();
    // we use the current graph var to allow search within the current graph..
    bool a_gv = core::sat.assume(lit(graph_var, true));
    assert(a_gv);

    // this is the next flaw to be solved..
    flaw *f_next = select_flaw();
    while (f_next)
    {
        assert(f_next->cost < std::numeric_limits<double>::infinity());
        if (f_next->has_subgoals())
        {
            // we run out of inconsistencies, thus, we renew them..
            if (has_inconsistencies())
                goto main_loop;
        }

        // this is the next resolver to be chosen..
        resolver &r_next = select_resolver(*f_next);
        res = &r_next;
        if (f_next->has_subgoals())
            resolvers.push_back(&r_next);

        // we apply the resolver..
        if (!core::sat.assume(lit(r_next.chosen, true)) || !core::sat.check())
            return false;

        while (!has_solution())
        {
            // we search within the graph..
            std::vector<lit> look_elsewhere;
            for (std::vector<layer>::reverse_iterator trail_it = trail.rbegin(); trail_it != trail.rend(); ++trail_it)
                if (trail_it->r)
                    look_elsewhere.push_back(lit(trail_it->r->chosen, false));
            look_elsewhere.push_back(lit(graph_var, false));

            // we backtrack..
            while (core::sat.value(look_elsewhere[0].v) != Undefined)
                core::sat.pop();

            if (core::sat.root_level())
            {
                // we have exhausted the search within the graph: we extend the graph..
                try
                {
                    add_layer();
                }
                catch (const unsolvable_exception &)
                {
                    return false;
                }

                // we create a new graph var..
                graph_var = core::sat.new_var();
                // we use the current graph var to allow search within the current graph..
                a_gv = core::sat.assume(lit(graph_var, true));
                assert(a_gv);
            }
            else
            {
                record(look_elsewhere);
                if (!core::sat.check())
                    return false;
            }
        }

        // we select a new flaw..
        f_next = select_flaw();
    }

    // we run out of flaws, we check for inconsistencies one last time..
    if (has_inconsistencies())
        goto main_loop;

    // we have found a solution..
    return true;
}

void causal_graph::new_flaw(flaw &f)
{
    f.init();
    flaw_q.push(&f);
    if (core::sat.value(f.in_plan) == True) // we have a top-level (landmark) flaw..
        flaws.insert(&f);
    else
    {
        // we listen for the flaw to become in_plan..
        in_plan[f.in_plan].push_back(&f);
        bind(f.in_plan);
    }

    // we notify the listeners that a new flaw has arised..
    for (const auto &l : listeners)
        l->new_flaw(f);
}

void causal_graph::new_resolver(resolver &r)
{
    // we notify the listeners that a new resolver has arised..
    for (const auto &l : listeners)
        l->new_resolver(r);
}

void causal_graph::new_causal_link(flaw &f, resolver &r)
{
    r.preconditions.push_back(&f);
    f.supports.push_back(&r);
    bool new_clause = core::sat.new_clause({lit(r.chosen, false), lit(f.in_plan, true)});
    assert(new_clause);

    // we notify the listeners that a new causal link has been created..
    for (const auto &l : listeners)
        l->causal_link_added(f, r);
}

bool causal_graph::propagate(const lit &p, std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    if (in_plan.find(p.v) != in_plan.end()) // a decision has been taken about the presence of some flaws within the current partial solution..
    {
        if (p.sign)
        {
            // these flaws have been added to the current partial solution..
            for (const auto &f : in_plan.at(p.v))
            {
                flaws.insert(f);
                if (!trail.empty())
                    trail.back().new_flaws.insert(f);
                // we notify the listeners that the state of the flaw has changed..
                for (const auto &l : listeners)
                    l->flaw_state_changed(*f);
            }
        }
        else
        {
            // these flaws have been removed from the current partial solution..
            for (const auto &f : in_plan.at(p.v))
            {
                set_cost(*f, std::numeric_limits<double>::infinity());
                // we notify the listeners that the state of the flaw has changed..
                for (const auto &l : listeners)
                    l->flaw_state_changed(*f);
            }
        }
    }
    else // a decision has been taken about the presence of a resolver within the current partial solution..
    {
        flaw_costs_q.push(&chosen.at(p.v)->effect);
        propagate_costs();
    }

    if (flaw_q.empty())
    {
        // we can use standard search techniques..
        if (!has_solution())
        {
            // we have made the heuristic blind..
            cnfl.push_back(p);
            for (std::vector<layer>::reverse_iterator trail_it = trail.rbegin(); trail_it != trail.rend(); ++trail_it)
                if (trail_it->r) // this resolver is null if we are calling the check from the sat core! Not bad: shorter conflict..
                    cnfl.push_back(lit(trail_it->r->chosen, false));
            return false;
        }
    }

    return true;
}

bool causal_graph::check(std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    return true;
}

void causal_graph::push()
{
    trail.push_back(layer(res));
    if (res)
    {
        // we just solved the resolver's effect..
        trail.back().solved_flaws.insert(&res->effect);
        flaws.erase(&res->effect);
    }
}

void causal_graph::pop()
{
    // we reintroduce the solved flaw..
    for (const auto &f : trail.back().solved_flaws)
        flaws.insert(f);

    // we erase new flaws..
    for (const auto &f : trail.back().new_flaws)
        flaws.erase(f);

    assert(std::all_of(flaws.begin(), flaws.end(), [&](flaw *const f) { return core::sat.value(f->in_plan) == True; }));

    // we restore flaw costs..
    for (const auto &c : trail.back().old_costs)
        c.first->cost = c.second;

    // we notify the listeners that the cost of some flaws has been restored..
    for (const auto &l : listeners)
        for (const auto &c : trail.back().old_costs)
            l->flaw_cost_changed(*c.first);

    // we manage structural flaws..
    if (!resolvers.empty() && resolvers.back() == trail.back().r)
        resolvers.pop_back();

    trail.pop_back();
}

void causal_graph::build()
{
#ifndef NDEBUG
    std::cout << "building the planning graph.." << std::endl;
#endif
    assert(core::sat.root_level());
    assert(!flaw_q.empty());

    while (!has_solution() && !flaw_q.empty())
    {
        assert(flaw_q.front()->initialized);
        assert(!flaw_q.front()->expanded);
        if (is_deferrable(*flaw_q.front())) // we postpone the expansion..
            flaw_q.push(flaw_q.front());
        else
        {
            flaw_q.front()->expand();
            if (!core::sat.check())
                throw unsolvable_exception();

            for (const auto &r : flaw_q.front()->resolvers)
            {
                resolvers.push_front(r);
                set_var(r->chosen);
                r->apply();

                if (!core::sat.check())
                    throw unsolvable_exception();

                restore_var();
                if (r->preconditions.empty())
                {
                    // there are no requirements for this resolver..
                    set_cost(*flaw_q.front(), std::min(flaw_q.front()->cost, la_th.value(r->cost)));
                    // making this resolver false might make the heuristic blind..
                    chosen.insert({r->chosen, r});
                    bind(r->chosen);
                }
                resolvers.pop_front();
            }
        }
        flaw_q.pop();
    }
}

void causal_graph::add_layer()
{
#ifndef NDEBUG
    std::cout << "adding a layer the planning graph.." << std::endl;
#endif
    assert(core::sat.root_level());

    std::vector<flaw *> fs;
    while (!flaw_q.empty())
    {
        fs.push_back(flaw_q.front());
        flaw_q.pop();
    }

    for (const auto &f : fs)
    {
        assert(f->initialized);
        assert(!f->expanded);
        f->expand();

        if (!core::sat.check())
            throw unsolvable_exception();

        for (const auto &r : f->resolvers)
        {
            resolvers.push_front(r);
            set_var(r->chosen);
            r->apply();

            if (!core::sat.check())
                throw unsolvable_exception();

            restore_var();
            if (r->preconditions.empty())
            {
                // there are no requirements for this resolver..
                set_cost(*f, std::min(f->cost, la_th.value(r->cost)));
                // making this resolver false might make the heuristic blind..
                chosen.insert({r->chosen, r});
                bind(r->chosen);
            }
            resolvers.pop_front();
        }
    }
}

bool causal_graph::has_solution()
{
    for (const auto &f : flaws)
        if (f->cost == std::numeric_limits<double>::infinity())
            return false;
    return true;
}

bool causal_graph::is_deferrable(flaw &f)
{
    std::queue<flaw *> q;
    q.push(&f);
    while (!q.empty())
    {
        if (!q.front()->exclusive) // we cannot defer this flaw..
            return false;
        else if (core::sat.value(q.front()->in_plan) == False) // it is not possible to solve this flaw with current assignments.. thus we defer..
            return true;
        else if (q.front()->cost < std::numeric_limits<double>::infinity()) // we already have a possible solution for this flaw.. thus we defer..
            return true;
        for (const auto &r : q.front()->causes)
            q.push(&r->effect);
        q.pop();
    }
    // we cannot defer this flaw..
    return false;
}

void causal_graph::set_cost(flaw &f, double cost)
{
    if (f.cost != cost)
    {
        if (!trail.empty())
            trail.back().old_costs.insert({&f, f.cost});
        f.cost = cost;

        // we notify the listeners that a flaw cost has changed..
        for (const auto &l : listeners)
            l->flaw_cost_changed(f);

        for (const auto &supp : f.supports)
            flaw_costs_q.push(&supp->effect);

        propagate_costs();
    }
}

void causal_graph::propagate_costs()
{
    while (!flaw_costs_q.empty())
    {
        double f_cost = std::numeric_limits<double>::infinity();
        for (const auto &r : flaw_costs_q.front()->resolvers)
        {
            double c = r->get_cost();
            if (c < f_cost)
                f_cost = c;
        }
        if (flaw_costs_q.front()->cost != f_cost)
        {
            if (!trail.empty())
                trail.back().old_costs.insert({flaw_costs_q.front(), flaw_costs_q.front()->cost});
            flaw_costs_q.front()->cost = f_cost;

            // we notify the listeners that a flaw cost has changed..
            for (const auto &l : listeners)
                l->flaw_cost_changed(*flaw_costs_q.front());

            for (const auto &supp : flaw_costs_q.front()->supports)
                flaw_costs_q.push(&supp->effect);
        }
        flaw_costs_q.pop();
    }
}

bool causal_graph::has_inconsistencies()
{
#ifndef NDEBUG
    std::cout << "checking for inconsistencies.." << std::endl;
#endif
    std::vector<flaw *> incs;
    std::queue<type *> q;
    for (const auto &t : get_types())
        if (!t.second->primitive)
            q.push(t.second);

    while (!q.empty())
    {
        if (smart_type *st = dynamic_cast<smart_type *>(q.front()))
        {
            std::vector<flaw *> c_incs = st->get_flaws();
            incs.insert(incs.end(), c_incs.begin(), c_incs.end());
        }
        for (const auto &st : q.front()->get_types())
            q.push(st.second);
        q.pop();
    }

    if (!incs.empty())
    {
        // we go back to root level..
        while (!core::sat.root_level())
            core::sat.pop();

        // we initialize the new flaws..
        for (const auto &f : incs)
            new_flaw(*f);

        return true;
    }
    else
        return false;
}

flaw *causal_graph::select_flaw()
{
    // this is the next flaw to be solved (i.e., the most expensive one)..
    flaw *f_next = nullptr;
    for (auto it = flaws.begin(); it != flaws.end();)
    {
        assert((*it)->expanded);
        assert(core::sat.value((*it)->in_plan) == True);
        if (std::count_if((*it)->resolvers.begin(), (*it)->resolvers.end(), [&](resolver *r) { return core::sat.value(r->chosen) != False; }) == 1)
        {
            // we have a trivial flaw..
            assert(core::sat.value((*std::find_if((*it)->resolvers.begin(), (*it)->resolvers.end(), [&](resolver *r) { return core::sat.value(r->chosen) != False; }))->chosen) == True);
            // we remove the trivial flaw from the current flaws..
            if (!trail.empty())
                trail.back().solved_flaws.insert((*it));
            flaws.erase(it++);
        }
        else
        {
            // the flaw is not trivial: let's see if it's better than the previous one..
            if (!f_next) // this is the first flaw we see..
                f_next = *it;
            else if (f_next->has_subgoals() && !(*it)->has_subgoals()) // we prefere non-structural flaws (i.e., inconsistencies) to structural ones..
                f_next = *it;
            else if (f_next->has_subgoals() == (*it)->has_subgoals() && f_next->cost < (*it)->cost) // this flaw is actually better than the previous one..
                f_next = *it;
            ++it;
        }
    }

    if (f_next) // we notify the listeners that we have chosen a flaw..
        for (const auto &l : listeners)
            l->current_flaw(*f_next);

    return f_next;
}

resolver &causal_graph::select_resolver(flaw &f)
{
    double r_cost = std::numeric_limits<double>::infinity();
    resolver *r_next = nullptr; // this is the next resolver to be chosen (i.e., the cheapest one)..
    for (const auto &r : f.resolvers)
    {
        double c_cost = r->get_cost();
        if (c_cost < r_cost)
        {
            r_cost = c_cost;
            r_next = r;
        }
    }

    // we notify the listeners that we have chosen a resolver..
    for (const auto &l : listeners)
        l->current_resolver(*r_next);

    return *r_next;
}
}