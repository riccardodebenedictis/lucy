#include "atom_flaw.h"
#include "causal_graph.h"
#include "predicate.h"
#include <cassert>

namespace cg
{

atom_flaw::atom_flaw(causal_graph &graph, atom &atm, bool is_fact) : flaw(graph, true), atm(atm), is_fact(is_fact) {}
atom_flaw::~atom_flaw() {}

void atom_flaw::compute_resolvers()
{
    assert(graph.core::sat.value(get_in_plan()) != False);
    bool unifiable = false; // becomes true if this flaw can be solved through unification..
    // this is the state of the atom associated to this flaw..
    std::unordered_set<set_item *> a_state = graph.set_th.value(atm.state);
    assert(!a_state.empty());
    if (a_state.find(graph.unified) != a_state.end())
    {
        // we the ancestors of this flaw, so as to avoid cyclic causality..
        std::unordered_set<flaw *> ancestors;
        std::queue<flaw *> q;
        q.push(this);
        while (!q.empty())
        {
            if (ancestors.find(q.front()) == ancestors.end())
            {
                ancestors.insert(q.front());
                for (const auto &supp : q.front()->get_supports())
                    if (graph.core::sat.value(supp->get_chosen()) != False) // if false, the edge is broken..
                        q.push(&supp->get_effect());                        // we push its effect..
            }
            q.pop();
        }

        for (const auto &i : atm.tp.get_instances())
        {
            if (&*i == &atm) // the current atom cannot unify with itself..
                continue;

            // this is the atom we are checking for unification..
            atom *c_a = static_cast<atom *>(&*i);
            // this is the target flaw (i.e. the one we are checking for unification) and cannot be in the current flaw's causes' effects..
            flaw *target = graph.reason.at(c_a);

            if (!target->is_expanded())
                continue;

            if (ancestors.find(target) != ancestors.end()) // unifying with the target atom would introduce cyclic causality..
                continue;

            // this is the state of the atom we are checking for unification..
            std::unordered_set<set_item *> c_state = graph.set_th.value(c_a->state);
            assert(!c_state.empty());

            if (c_state.find(graph.active) == c_state.end() || !atm.equates(*c_a))
                continue;

            // atom c_a is a good candidate for unification..

            // we build the unification literals..
            std::vector<lit> unif_lits;
            q.push(this);
            q.push(target);
            while (!q.empty())
            {
                for (const auto &cause : q.front()->get_causes())
                    if (graph.core::sat.value(cause->get_chosen()) != True)
                        unif_lits.push_back(lit(cause->get_chosen(), true)); // we push its effect..
                q.pop();
            }

            if (a_state.size() > 1)                                                             // if the state can be either 'unified' or something else..
                unif_lits.push_back(lit(graph.set_th.allows(atm.state, *graph.unified), true)); // we force the state to be 'unified' within the unification literals..
            if (c_state.size() > 1)                                                             // if the state can be either 'active' or something else..
                unif_lits.push_back(lit(graph.set_th.allows(c_a->state, *graph.active), true)); // we force the state to be 'active' within the unification literals..

            // the equality propositional variable..
            var eq_v = atm.eq(*c_a);

            if (graph.core::sat.value(eq_v) == False) // the two atoms cannot unify, hence, we skip this instance..
                continue;

            if (graph.core::sat.value(eq_v) != True)
                unif_lits.push_back(lit(atm.eq(*c_a), true));

            if (unif_lits.empty() || graph.core::sat.check(unif_lits))
            {
                // unification is actually possible!
                unify_atom *u_res = new unify_atom(graph, *this, atm, *c_a, unif_lits);
                add_resolver(*u_res);
                graph.new_causal_link(*target, *u_res);
                graph.set_cost(*this, target->get_cost());
                // making this resolver false might make the heuristic blind..
                graph.chosen.insert({u_res->get_chosen(), u_res});
                graph.bind(u_res->get_chosen());
                unifiable = true;
            }
        }
    }
    if (!unifiable)
    {
        // we remove unification from atom state..
        if (!graph.core::sat.new_clause({lit(graph.set_th.allows(atm.state, *graph.unified), false)}))
            throw unsolvable_exception();
    }

    if (is_fact)
        add_resolver(*new add_fact(graph, *this, atm));
    else
        add_resolver(*new expand_goal(graph, *this, atm));
}

atom_flaw::add_fact::add_fact(causal_graph &graph, atom_flaw &atm_flaw, atom &atm) : resolver(graph, lin(0), atm_flaw), atm(atm) {}
atom_flaw::add_fact::~add_fact() {}

void atom_flaw::add_fact::apply() { graph.core::sat.new_clause({lit(chosen, false), lit(graph.set_th.allows(atm.state, *graph.active), true)}); }

atom_flaw::expand_goal::expand_goal(causal_graph &graph, atom_flaw &atm_flaw, atom &atm) : resolver(graph, lin(1), atm_flaw), atm(atm) {}
atom_flaw::expand_goal::~expand_goal() {}

void atom_flaw::expand_goal::apply()
{
    graph.core::sat.new_clause({lit(chosen, false), lit(graph.set_th.allows(atm.state, *graph.active), true)});
    static_cast<const predicate *>(&atm.tp)->apply_rule(atm);
}

atom_flaw::unify_atom::unify_atom(causal_graph &graph, atom_flaw &atm_flaw, atom &atm, atom &with, const std::vector<lit> &unif_lits) : resolver(graph, lin(0), atm_flaw), atm(atm), with(with), unif_lits(unif_lits) {}
atom_flaw::unify_atom::~unify_atom() {}

void atom_flaw::unify_atom::apply()
{
    for (const auto &v : unif_lits)
        graph.core::sat.new_clause({lit(chosen, false), v});
}
}