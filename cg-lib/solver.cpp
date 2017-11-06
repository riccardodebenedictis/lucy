#include "solver.h"
#include "enum_flaw.h"
#include "disjunction_flaw.h"
#include "atom_flaw.h"
#include "smart_type.h"
#include "state_variable.h"
#include "reusable_resource.h"
#include "propositional_agent.h"
#include "propositional_state.h"
#ifdef BUILD_GUI
#include "cg_listener.h"
#endif
#ifndef NDEBUG
#include <iostream>
#endif
#include <algorithm>
#include <cassert>

namespace cg
{

solver::solver() : core(), theory(sat_cr) {}
solver::~solver() {}

void solver::init()
{
    read(std::vector<std::string>({"init.rddl"}));
    types.insert({STATE_VARIABLE_NAME, new state_variable(*this)});
    types.insert({REUSABLE_RESOURCE_NAME, new reusable_resource(*this)});
    types.insert({PROPOSITIONAL_AGENT_NAME, new propositional_agent(*this)});
    types.insert({PROPOSITIONAL_STATE_NAME, new propositional_state(*this)});
}

expr solver::new_enum(const type &tp, const std::unordered_set<item *> &allowed_vals)
{
    assert(!allowed_vals.empty());
    // we create a new enum expression..
    var_expr c_e = core::new_enum(tp, allowed_vals);
    if (allowed_vals.size() > 1)
    {
        // we create a new enum flaw..
        enum_flaw *ef = new enum_flaw(*this, res, *c_e);
        new_flaw(*ef);
    }
    return c_e;
}

void solver::new_fact(atom &atm)
{
    // we create a new atom flaw representing a fact..
    atom_flaw *af = new atom_flaw(*this, res, atm, true);
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

void solver::new_goal(atom &atm)
{
    // we create a new atom flaw representing a goal..
    atom_flaw *af = new atom_flaw(*this, res, atm, false);
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

void solver::new_disjunction(context &d_ctx, const disjunction &disj)
{
    // we create a new disjunction flaw..
    disjunction_flaw *df = new disjunction_flaw(*this, res, d_ctx, disj);
    new_flaw(*df);
}

void solver::solve()
{
    // we build the causal graph..
    build();

    while (sat_cr.root_level())
    {
        assert(sat_cr.value(gamma) == False);
        // we have exhausted the search within the graph: we extend the graph..
        add_layer();
    }

    while (true)
    {
        // this is the next flaw to be solved..
        flaw *f_next = select_flaw();

        if (f_next)
        {
#ifndef NDEBUG
            std::cout << "(" << std::to_string(trail.size()) << "): " << f_next->get_label();
#endif
            assert(f_next->get_cost() < std::numeric_limits<double>::infinity());
            if (!f_next->structural || !has_inconsistencies()) // we run out of inconsistencies, thus, we renew them..
            {
                // this is the next resolver to be assumed..
                res = &select_resolver(*f_next);
#ifndef NDEBUG
                std::cout << " " << res->get_label() << std::endl;
#endif

                // we apply the resolver..
                if (!sat_cr.assume(res->rho) || !sat_cr.check())
                    throw unsolvable_exception();

                res = nullptr;
                while (sat_cr.root_level())
                    if (sat_cr.value(gamma) == Undefined)
                    {
                        // we have learnt a unit clause! thus, we reassume the graph var..
                        if (!sat_cr.assume(gamma) || !sat_cr.check())
                            throw unsolvable_exception();
                    }
                    else
                    {
                        assert(sat_cr.value(gamma) == False);
                        // we have exhausted the search within the graph: we extend the graph..
                        add_layer();
                    }
            }
        }
        else if (!has_inconsistencies()) // we run out of flaws, we check for inconsistencies one last time..
            // Hurray!! we have found a solution..
            return;
    }
}

void solver::build()
{
#ifndef NDEBUG
    std::cout << "building the causal graph.." << std::endl;
#endif
    assert(sat_cr.root_level());

    while (std::any_of(flaws.begin(), flaws.end(), [&](flaw *f) { return f->get_cost() == std::numeric_limits<double>::infinity(); }))
    {
        if (flaw_q.empty())
            throw unsolvable_exception();
        assert(!flaw_q.front()->expanded);
        if (sat_cr.value(flaw_q.front()->phi) != False)
            if (is_deferrable(*flaw_q.front())) // we postpone the expansion..
                flaw_q.push_back(flaw_q.front());
            else // we expand the flaw..
                expand_flaw(*flaw_q.front());
        flaw_q.pop_front();
    }

    // we create a new graph var..
    gamma = sat_cr.new_var();
#ifndef NDEBUG
    std::cout << "graph var is: γ" << std::to_string(gamma) << std::endl;
#endif
    // these flaws have not been expanded, hence, cannot have a solution..
    for (const auto &f : flaw_q)
        sat_cr.new_clause({lit(gamma, false), lit(f->phi, false)});
    // we use the new graph var to allow search within the current graph..
    if (!sat_cr.assume(gamma) || !sat_cr.check())
        throw unsolvable_exception();
}

bool solver::is_deferrable(flaw &f)
{
    std::queue<flaw *> q;
    q.push(&f);
    while (!q.empty())
    {
        assert(sat_cr.value(q.front()->phi) != False);
        if (q.front()->get_cost() < std::numeric_limits<double>::infinity()) // we already have a possible solution for this flaw, thus we defer..
            return true;
        for (const auto &r : q.front()->causes)
            q.push(&r->effect);
        q.pop();
    }
    // we cannot defer this flaw..
    return false;
}

void solver::add_layer()
{
#ifndef NDEBUG
    std::cout << "adding a layer to the causal graph.." << std::endl;
#endif
    assert(sat_cr.root_level());

    std::list<flaw *> f_q(flaw_q);
    while (std::all_of(f_q.begin(), f_q.end(), [&](flaw *f) { return f->get_cost() == std::numeric_limits<double>::infinity(); }))
    {
        if (flaw_q.empty())
            throw unsolvable_exception();
        std::list<flaw *> c_q = std::move(flaw_q);
        for (const auto &f : c_q)
        {
            assert(!f->expanded);
            if (sat_cr.value(f->phi) != False) // we expand the flaw..
                expand_flaw(*f);
        }
    }

    // we create a new graph var..
    gamma = sat_cr.new_var();
#ifndef NDEBUG
    std::cout << "graph var is: γ" << std::to_string(gamma) << std::endl;
#endif
    // these flaws have not been expanded, hence, cannot have a solution..
    for (const auto &f : flaw_q)
        sat_cr.new_clause({lit(gamma, false), lit(f->phi, false)});
    // we use the new graph var to allow search within the new graph..
    if (!sat_cr.assume(gamma) || !sat_cr.check())
        throw unsolvable_exception();
}

bool solver::has_inconsistencies()
{
#ifndef NDEBUG
    std::cout << " (checking for inconsistencies..)";
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

    assert(std::none_of(incs.begin(), incs.end(), [&](flaw *f) { return f->structural; }));
    if (!incs.empty())
    {
        // we go back to root level..
        while (!sat_cr.root_level())
            sat_cr.pop();

        // we initialize the new flaws..
        for (const auto &f : incs)
        {
            f->init();
#ifdef BUILD_GUI
            // we notify the listeners that a new flaw has arised..
            for (const auto &l : listeners)
                l->new_flaw(*f);
#endif
            expand_flaw(*f);
        }

        // we re-assume the current graph var to allow search within the current graph..
        if (!sat_cr.assume(gamma) || !sat_cr.check())
            throw unsolvable_exception();
#ifndef NDEBUG
        std::cout << ": " << std::to_string(incs.size()) << std::endl;
#endif
        return true;
    }
    else
        return false;
}

void solver::expand_flaw(flaw &f)
{
    building_graph = true;
    // we expand the flaw..
    f.expand();
    if (!sat_cr.check())
    {
        building_graph = false;
        throw unsolvable_exception();
    }

    for (const auto &r : f.resolvers)
    {
        res = r;
        set_var(r->rho);
        try
        {
            r->apply();
        }
        catch (const inconsistency_exception &)
        {
            if (!sat_cr.new_clause({lit(r->rho, false)}))
            {
                building_graph = false;
                throw unsolvable_exception();
            }
        }

        if (!sat_cr.check())
        {
            building_graph = false;
            throw unsolvable_exception();
        }

        restore_var();
        res = nullptr;
        if (r->preconditions.empty() && sat_cr.value(r->rho) != False) // there are no requirements for this resolver..
            set_est_cost(*r, 0);
    }
    building_graph = false;
}

void solver::new_flaw(flaw &f)
{
    f.init(); // flaws' initialization requires being at root-level..
    flaw_q.push_back(&f);
#ifdef BUILD_GUI
    // we notify the listeners that a new flaw has arised..
    for (const auto &l : listeners)
        l->new_flaw(f);
#endif
}

void solver::new_resolver(resolver &r)
{
    r.init();

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

void solver::set_est_cost(resolver &r, const double &cst)
{
    if (r.est_cost != cst)
    {
        if (!trail.empty())
            trail.back().old_costs.insert({&r, r.est_cost});
        // this is the current cost of the resolver's effect..
        double f_cost = r.effect.get_cost();
        // we update the resolver's estimated cost..
        r.est_cost = cst;

#ifdef BUILD_GUI
        // we notify the listeners that a flaw cost has changed..
        for (const auto &l : listeners)
            l->resolver_cost_changed(r);
#endif

        if (f_cost != r.effect.get_cost()) // the cost of the resolver's effect has changed as a consequence of the resolver's cost update,hence, we propagate the update to all the supports of the resolver's effect..
        {
            // the resolver costs queue (for resolver cost propagation)..
            std::queue<resolver *> resolver_q;
            for (const auto &c_r : r.effect.supports)
                resolver_q.push(c_r);

            while (!resolver_q.empty())
            {
                resolver &c_res = *resolver_q.front(); // the current resolver whose cost might require an update..
                double r_cost = -std::numeric_limits<double>::infinity();
                for (const auto &f : c_res.preconditions)
                {
                    double c = f->get_cost();
                    if (c > r_cost)
                        r_cost = c;
                }
                if (c_res.est_cost != r_cost)
                {
                    if (!trail.empty())
                        trail.back().old_costs.insert({&c_res, c_res.est_cost});
                    // this is the current cost of the resolver's effect..
                    f_cost = c_res.effect.get_cost();
                    // we update the resolver's estimated cost..
                    c_res.est_cost = r_cost;

#ifdef BUILD_GUI
                    // we notify the listeners that a flaw cost has changed..
                    for (const auto &l : listeners)
                        l->resolver_cost_changed(c_res);
#endif

                    if (f_cost != c_res.effect.get_cost())            // the cost of the resolver's effect has changed as a consequence of the resolver's cost update..
                        for (const auto &c_r : c_res.effect.supports) // hence, we propagate the update to all the supports of the resolver's effect..
                            resolver_q.push(c_r);
                }
                resolver_q.pop();
            }
        }
    }
}

flaw *solver::select_flaw()
{
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

    return f_next;
}

resolver &solver::select_resolver(flaw &f)
{
    inf_rational r_cost(1, 0);
    resolver *r_next = nullptr; // this is the next resolver to be selected (i.e., the cheapest one)..
    for (const auto &r : f.resolvers)
    {
        inf_rational c_cost = r->get_cost();
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

bool solver::propagate(const lit &p, std::vector<lit> &cnfl)
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
                    assert(flaws.find(f) == flaws.end());

        if (rhos.find(p.v) != rhos.end() && !p.sign) // a decision has been taken about the removal of some resolvers within the current partial solution..
            for (const auto &r : rhos.at(p.v))
                set_est_cost(*r, std::numeric_limits<double>::infinity());
    }

    return true;
}

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