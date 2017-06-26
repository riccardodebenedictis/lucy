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
    bool solved = false;
    std::unordered_set<set_item *> a_state = graph.set_th.value(atm.state);
    assert(!a_state.empty());
    if (a_state.find(graph.unified) != a_state.end())
    {
        for (const auto &i : atm.tp.get_instances())
        {
            if (&*i == &atm)
            {
                continue;
            }

            atom *c_a = static_cast<atom *>(&*i);
            if (!graph.reason.at(c_a)->is_expanded())
            {
                continue;
            }
            std::unordered_set<set_item *> c_state = graph.set_th.value(c_a->state);
            assert(!c_state.empty());
            if (c_state.find(graph.active) == c_state.end() || !atm.equates(*c_a))
            {
                continue;
            }
            // atom c_a is a good candidate for unification..
            std::vector<lit> unif_lits;
            std::unordered_set<flaw *> seen;
            std::queue<flaw *> q;
            q.push(graph.reason.at(&atm));
            q.push(graph.reason.at(c_a));
            while (!q.empty())
            {
                assert(graph.core::sat.value(q.front()->get_in_plan()) != False);
                if (seen.find(q.front()) != seen.end())
                {
                    // we do not allow cyclic causality..
                    break;
                }
                seen.insert(q.front());
                for (const auto &cause : q.front()->get_causes())
                {
                    assert(graph.core::sat.value(cause->get_chosen()) != False);
                    if (graph.core::sat.value(cause->get_chosen()) != True)
                    {
                        unif_lits.push_back(lit(cause->get_chosen(), true));
                        q.push(&cause->get_effect());
                    }
                }
                q.pop();
            }
            if (!q.empty())
            {
                continue;
            }
            if (a_state.size() > 1)
            {
                assert(graph.core::sat.value(graph.set_th.allows(atm.state, *graph.unified)) != False);
                unif_lits.push_back(lit(graph.set_th.allows(atm.state, *graph.unified), true));
            }
            if (c_state.size() > 1)
            {
                assert(graph.core::sat.value(graph.set_th.allows(c_a->state, *graph.active)) != False);
                unif_lits.push_back(lit(graph.set_th.allows(c_a->state, *graph.active), true));
            }
            var eq_v = atm.eq(*c_a);
            if (graph.core::sat.value(eq_v) == False)
            {
                continue;
            }
            if (graph.core::sat.value(eq_v) != True)
            {
                unif_lits.push_back(lit(atm.eq(*c_a), true));
            }
            if (unif_lits.empty() || graph.core::sat.check(unif_lits))
            {
                // unification is actually possible!
                unify_atom *u_res = new unify_atom(graph, *this, atm, *c_a, unif_lits);
                add_resolver(*u_res);
                graph.new_causal_link(*graph.reason.at(c_a), *u_res);
                graph.set_cost(*this, graph.reason.at(c_a)->get_cost());
                // making this resolver false might make the heuristic blind..
                graph.chosen.insert({u_res->get_chosen(), u_res});
                graph.bind(u_res->get_chosen());
                solved = true;
            }
        }
    }
    if (!solved)
    {
        // we remove unification from atom state..
        bool not_unify = graph.core::sat.new_clause({lit(graph.set_th.allows(atm.state, *graph.unified), false)});
        assert(not_unify);
    }
    if (is_fact)
    {
        add_resolver(*new add_fact(graph, *this, atm));
    }
    else
    {
        add_resolver(*new expand_goal(graph, *this, atm));
    }
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
    {
        graph.core::sat.new_clause({lit(chosen, false), v});
    }
}
}