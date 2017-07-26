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
    assert(graph.core::sat.value(atm.state) != False);
    if (graph.core::sat.value(atm.state) == Undefined) // we check if the atom can unify..
    {
        // we collect the ancestors of this flaw, so as to avoid cyclic causality..
        std::unordered_set<const flaw *> ancestors;
        std::queue<const flaw *> q;
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

            if (graph.core::sat.value(c_a->state) != True || !atm.equates(*c_a))
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

            unif_lits.push_back(lit(atm.state, false)); // we force the state of this atom to be 'unified' within the unification literals..
            unif_lits.push_back(lit(c_a->state, true)); // we force the state of the target atom to be 'active' within the unification literals..

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
            }
        }
    }

    if (is_fact)
        add_resolver(*new add_fact(graph, *this, atm));
    else
        add_resolver(*new expand_goal(graph, *this, atm));
}

atom_flaw::add_fact::add_fact(causal_graph &graph, atom_flaw &atm_flaw, atom &atm) : resolver(graph, lin(0), atm_flaw), atm(atm) {}
atom_flaw::add_fact::~add_fact() {}

void atom_flaw::add_fact::apply() { graph.core::sat.new_clause({lit(chosen, false), lit(atm.state, true)}); }

atom_flaw::expand_goal::expand_goal(causal_graph &graph, atom_flaw &atm_flaw, atom &atm) : resolver(graph, lin(1), atm_flaw), atm(atm) {}
atom_flaw::expand_goal::~expand_goal() {}

void atom_flaw::expand_goal::apply()
{
    graph.core::sat.new_clause({lit(chosen, false), lit(atm.state, true)});
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