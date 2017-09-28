#include "causal_graph.h"
#include "enum_flaw.h"
#include "atom_flaw.h"
#include "disjunction_flaw.h"
#include "smart_type.h"
#include "state_variable.h"
#include "reusable_resource.h"
#ifdef BUILD_GUI
#include "causal_graph_listener.h"
#endif
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
    read(std::vector<std::string>({"init.rddl"}));
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
    var_expr c_e = core::new_enum(tp, allowed_vals);
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

    if (&atm.tp.get_scope() != this)
    {
        std::queue<type *> q;
        q.push(static_cast<type *>(&atm.tp.get_scope()));
        while (!q.empty())
        {
            if (smart_type *st = dynamic_cast<smart_type *>(q.front()))
                st->new_fact(*af);
            for (const auto &st : q.front()->get_supertypes())
                q.push(st);
            q.pop();
        }
    }
}

void causal_graph::new_goal(atom &atm)
{
    // we create a new atom flaw representing a goal..
    atom_flaw *af = new atom_flaw(*this, atm, false);
    reason.insert({&atm, af});
    new_flaw(*af);

    if (&atm.tp.get_scope() != this)
    {
        std::queue<type *> q;
        q.push(static_cast<type *>(&atm.tp.get_scope()));
        while (!q.empty())
        {
            if (smart_type *st = dynamic_cast<smart_type *>(q.front()))
                st->new_goal(*af);
            for (const auto &st : q.front()->get_supertypes())
                q.push(st);
            q.pop();
        }
    }
}

void causal_graph::new_disjunction(context &d_ctx, const disjunction &disj)
{
    // we create a new disjunction flaw..
    disjunction_flaw *df = new disjunction_flaw(*this, d_ctx, disj);
    new_flaw(*df);
}

void causal_graph::solve()
{
    // we build the causal graph..
    build();

    // we create a new graph var..
    graph_var = core::sat.new_var();
#ifndef NDEBUG
    std::cout << "graph var is: γ" << std::to_string(graph_var) << std::endl;
#endif
    // we use the new graph var to allow search within the current graph..
    bool a_gv = core::sat.assume(graph_var) && core::sat.check();
    assert(a_gv);

    while (true)
    {
        // this is the next flaw to be solved..
        flaw *f_next = select_flaw();

        if (f_next)
        {
#ifndef NDEBUG
            std::cout << "(" << std::to_string(trail.size()) << "): " << f_next->get_label();
#endif
            assert(f_next->cost < std::numeric_limits<double>::infinity());
            if (!f_next->structural || !has_inconsistencies()) // we run out of inconsistencies, thus, we renew them..
            {
                // this is the next resolver to be rho..
                res = &select_resolver(*f_next);
#ifndef NDEBUG
                std::cout << " " << res->get_label() << std::endl;
#endif
                if (f_next->structural)
                    resolvers.push_back(res);

                // we apply the resolver..
                if (!core::sat.assume(res->rho) || !core::sat.check())
                    throw unsolvable_exception();

                res = nullptr;
                if (core::sat.root_level())
                    if (core::sat.value(graph_var) == Undefined)
                    {
                        // we have learnt a unit clause! thus, we reassume the graph var..
                        a_gv = core::sat.assume(graph_var);
                        assert(a_gv);
                        if (!core::sat.check())
                            throw unsolvable_exception();
                    }
                    else
                    {
                        assert(core::sat.value(graph_var) == False);
                        // we have exhausted the search within the graph: we extend the graph..
                        add_layer();

                        // we create a new graph var..
                        graph_var = core::sat.new_var();
#ifndef NDEBUG
                        std::cout << "graph var is: γ" << std::to_string(graph_var) << std::endl;
#endif
                        // we use the new graph var to allow search within the new graph..
                        a_gv = core::sat.assume(graph_var) && core::sat.check();
                        assert(a_gv);
                    }
            }
        }
        else if (!has_inconsistencies()) // we run out of flaws, we check for inconsistencies one last time..
            // Hurray!! we have found a solution..
            return;
    }
}

void causal_graph::new_flaw(flaw &f)
{
    f.init();
    flaw_q.push(&f);

#ifdef BUILD_GUI
    // we notify the listeners that a new flaw has arised..
    for (const auto &l : listeners)
        l->new_flaw(f);
#endif
}

void causal_graph::new_resolver(resolver &r)
{
#ifdef BUILD_GUI
    // we notify the listeners that a new resolver has arised..
    for (const auto &l : listeners)
        l->new_resolver(r);
#endif
}

void causal_graph::new_causal_link(flaw &f, resolver &r)
{
    r.preconditions.push_back(&f);
    f.supports.push_back(&r);
    bool new_clause = core::sat.new_clause({lit(r.rho, false), f.phi});
    assert(new_clause);

#ifdef BUILD_GUI
    // we notify the listeners that a new causal link has been created..
    for (const auto &l : listeners)
        l->causal_link_added(f, r);
#endif
}

bool causal_graph::propagate(const lit &p, std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    if (!building_graph)
    {
        if (phis.find(p.v) != phis.end()) // a decision has been taken about the presence of some flaws within the current partial solution..
            for (const auto &f : phis.at(p.v))
                if (p.sign) // this flaw has been added to the current partial solution..
                {
                    flaws.insert(f);
                    if (!trail.empty())
                        trail.back().new_flaws.insert(f);
#ifdef BUILD_GUI
                    // we notify the listeners that the state of the flaw has changed..
                    for (const auto &l : listeners)
                        l->flaw_state_changed(*f);
#endif
                }
                else // this flaw has been removed from the current partial solution..
                {
                    set_cost(*f, std::numeric_limits<double>::infinity());
#ifdef BUILD_GUI
                    // we notify the listeners that the state of the flaw has changed..
                    for (const auto &l : listeners)
                        l->flaw_state_changed(*f);
#endif
                }

        if (rhos.find(p.v) != rhos.end())
        {
            // a decision has been taken about the presence of some resolvers within the current partial solution..
            for (const auto &r : rhos.at(p.v))
                flaw_costs_q.push(&r->effect);
            propagate_costs();
        }

        if (std::any_of(flaws.begin(), flaws.end(), [&](flaw *f) { return f->cost == std::numeric_limits<double>::infinity(); })) // we have made the heuristic blind..
        {
            for (const auto &r : rhos)
                if (core::sat.value(r.first) == False)
                    cnfl.push_back(r.first);
            cnfl.push_back(lit(graph_var, false));
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

    // we erase the new flaws..
    for (const auto &f : trail.back().new_flaws)
        flaws.erase(f);

    // we restore the flaw costs..
    for (const auto &c : trail.back().old_costs)
        c.first->cost = c.second;

#ifdef BUILD_GUI
    // we notify the listeners that the cost of some flaws has been restored..
    for (const auto &l : listeners)
        for (const auto &c : trail.back().old_costs)
            l->flaw_cost_changed(*c.first);
#endif

    // we manage structural flaws..
    if (!resolvers.empty() && resolvers.back() == trail.back().r)
        resolvers.pop_back();

    trail.pop_back();
}

void causal_graph::build()
{
#ifndef NDEBUG
    std::cout << "building the causal graph.." << std::endl;
#endif
    assert(!building_graph);
    assert(core::sat.root_level());

    building_graph = true;
    while (std::any_of(flaws.begin(), flaws.end(), [&](flaw *f) { return f->cost == std::numeric_limits<double>::infinity(); }))
    {
        if (flaw_q.empty())
        {
            building_graph = false;
            throw unsolvable_exception();
        }
        assert(!flaw_q.front()->expanded);
        if (core::sat.value(flaw_q.front()->phi) != False)
        {
            if (is_deferrable(*flaw_q.front())) // we postpone the expansion..
                flaw_q.push(flaw_q.front());
            else
            {
                flaw_q.front()->expand();
                if (!core::sat.check())
                {
                    building_graph = false;
                    throw unsolvable_exception();
                }

                for (const auto &r : flaw_q.front()->resolvers)
                {
                    resolvers.push_front(r);
                    set_var(r->rho);
                    try
                    {
                        r->apply();
                    }
                    catch (const inconsistency_exception &)
                    {
                        if (!core::sat.new_clause({lit(r->rho, false)}))
                        {
                            building_graph = false;
                            throw unsolvable_exception();
                        }
                    }

                    if (!core::sat.check())
                    {
                        building_graph = false;
                        throw unsolvable_exception();
                    }

                    restore_var();
                    if (r->preconditions.empty() && core::sat.value(r->rho) != False)
                    {
                        // there are no requirements for this resolver..
                        set_cost(*flaw_q.front(), std::min(flaw_q.front()->cost, la_th.value(r->cost)));
                        if (core::sat.value(r->rho) != True)
                        {
                            // making this resolver false might make the heuristic blind..
                            rhos[r->rho].push_back(r);
                            bind(r->rho);
                        }
                    }
                    resolvers.pop_front();
                }
            }
        }
        flaw_q.pop();
    }
    building_graph = false;
}

void causal_graph::add_layer()
{
#ifndef NDEBUG
    std::cout << "adding a layer to the causal graph.." << std::endl;
#endif
    assert(!building_graph);
    assert(core::sat.root_level());

    building_graph = true;
    std::vector<flaw *> fs;
    while (!flaw_q.empty())
    {
        fs.push_back(flaw_q.front());
        flaw_q.pop();
    }
    for (const auto &f : fs)
        flaw_q.push(f);

    while (std::all_of(fs.begin(), fs.end(), [&](flaw *f) { return f->cost == std::numeric_limits<double>::infinity(); }))
    {
        if (flaw_q.empty())
        {
            building_graph = false;
            throw unsolvable_exception();
        }
        assert(!flaw_q.front()->expanded);
        if (core::sat.value(flaw_q.front()->phi) != False)
        {
            flaw_q.front()->expand();
            if (!core::sat.check())
            {
                building_graph = false;
                throw unsolvable_exception();
            }

            for (const auto &r : flaw_q.front()->resolvers)
            {
                resolvers.push_front(r);
                set_var(r->rho);
                try
                {
                    r->apply();
                }
                catch (const inconsistency_exception &)
                {
                    if (!core::sat.new_clause({lit(r->rho, false)}))
                    {
                        building_graph = false;
                        throw unsolvable_exception();
                    }
                }

                if (!core::sat.check())
                {
                    building_graph = false;
                    throw unsolvable_exception();
                }

                restore_var();
                if (r->preconditions.empty() && core::sat.value(r->rho) != False)
                {
                    // there are no requirements for this resolver..
                    set_cost(*flaw_q.front(), std::min(flaw_q.front()->cost, la_th.value(r->cost)));
                    if (core::sat.value(r->rho) != True)
                    {
                        // making this resolver false might make the heuristic blind..
                        rhos[r->rho].push_back(r);
                        bind(r->rho);
                    }
                }
                resolvers.pop_front();
            }
        }
        flaw_q.pop();
    }
    building_graph = false;
}

bool causal_graph::is_deferrable(flaw &f)
{
    std::queue<flaw *> q;
    q.push(&f);
    while (!q.empty())
    {
        if (core::sat.value(q.front()->phi) == False) // it is not possible to solve this flaw with current assignments.. thus we defer..
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

#ifdef BUILD_GUI
        // we notify the listeners that a flaw cost has changed..
        for (const auto &l : listeners)
            l->flaw_cost_changed(f);
#endif

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

#ifdef BUILD_GUI
            // we notify the listeners that a flaw cost has changed..
            for (const auto &l : listeners)
                l->flaw_cost_changed(*flaw_costs_q.front());
#endif

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
        {
            f->init();

#ifdef BUILD_GUI
            // we notify the listeners that a new flaw has arised..
            for (const auto &l : listeners)
                l->new_flaw(*f);
#endif

            // we expand the flaw..
            f->expand();
            if (!core::sat.check())
                throw unsolvable_exception();

            for (const auto &r : f->resolvers)
            {
                resolvers.push_front(r);
                set_var(r->rho);
                r->apply();

                if (!core::sat.check())
                    throw unsolvable_exception();

                restore_var();
                if (r->preconditions.empty())
                {
                    // there are no requirements for this resolver..
                    set_cost(*f, std::min(f->cost, la_th.value(r->cost)));
                    assert(core::sat.value(r->rho) != False);
                    if (core::sat.value(r->rho) != True)
                    {
                        // making this resolver false might make the heuristic blind..
                        rhos[r->rho].push_back(r);
                        bind(r->rho);
                    }
                }
                resolvers.pop_front();
            }
        }

        if (std::any_of(incs.begin(), incs.end(), [&](flaw *f) { return f->structural; }))
            build();

        // we re-assume the current graph var to allow search within the current graph..
        bool a_gv = core::sat.assume(lit(graph_var, true));
        assert(a_gv);
        return true;
    }
    else
        return false;
}

flaw *causal_graph::select_flaw()
{
    assert(std::all_of(flaws.begin(), flaws.end(), [&](flaw *const f) { return f->expanded && core::sat.value(f->phi) == True; }));
    // this is the next flaw to be solved (i.e., the most expensive one)..
    flaw *f_next = nullptr;
    for (auto it = flaws.begin(); it != flaws.end();)
    {
        if (std::any_of((*it)->resolvers.begin(), (*it)->resolvers.end(), [&](resolver *r) { return core::sat.value(r->rho) == True; }))
        {
            // we have either a trivial (i.e. has only one resolver) or an already solved flaw..
            assert(core::sat.value((*std::find_if((*it)->resolvers.begin(), (*it)->resolvers.end(), [&](resolver *r) { return core::sat.value(r->rho) != False; }))->rho) == True);
            // we remove the flaw from the current flaws..
            if (!trail.empty())
                trail.back().solved_flaws.insert((*it));
            flaws.erase(it++);
        }
        else
        {
            // the flaw not trivial nor already solved: let's see if it's better than the previous one..
            if (!f_next) // this is the first flaw we see..
                f_next = *it;
            else if (f_next->structural && !(*it)->structural) // we prefere non-structural flaws (i.e., inconsistencies) to structural ones..
                f_next = *it;
            else if (f_next->structural == (*it)->structural && f_next->cost < (*it)->cost) // this flaw is actually better than the previous one..
                f_next = *it;
            ++it;
        }
    }

#ifdef BUILD_GUI
    if (f_next) // we notify the listeners that we have rho a flaw..
        for (const auto &l : listeners)
            l->current_flaw(*f_next);
#endif

    return f_next;
}

resolver &causal_graph::select_resolver(flaw &f)
{
    double r_cost = std::numeric_limits<double>::infinity();
    resolver *r_next = nullptr; // this is the next resolver to be rho (i.e., the cheapest one)..
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
    // we notify the listeners that we have rho a resolver..
    for (const auto &l : listeners)
        l->current_resolver(*r_next);
#endif

    return *r_next;
}
}