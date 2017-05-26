#include "reusable_resource.h"
#include "combinations.h"

namespace cg
{

reusable_resource::reusable_resource(cg::causal_graph &g) : smart_type(g, g, REUSABLE_RESOURCE_NAME)
{
    fields.insert({REUSABLE_RESOURCE_CAPACITY, new field(g.get_type("real"), REUSABLE_RESOURCE_CAPACITY)});
    constructors.push_back(new rr_constructor(*this));
    predicates.insert({REUSABLE_RESOURCE_USE_PREDICATE_NAME, new use_predicate(*this)});
}

reusable_resource::~reusable_resource() {}

std::vector<flaw *> reusable_resource::get_flaws()
{
    std::vector<flaw *> flaws;
    if (to_check.empty())
    {
        // nothing has changed since last inconsistency check..
        return flaws;
    }
    else
    {
        // we collect atoms for each state variable..
        std::unordered_map<item *, std::vector<atom *>> instances;
        for (const auto &a : atoms)
        {
            // we filter out those which are not strictly active..
            if (graph.core::sat.value(graph.set_th.allows(a.first->state, *atom::active)) == True)
            {
                enum_expr c_scope = a.first->get("scope");
                for (const auto &i : graph.set_th.value(c_scope->ev))
                {
                    if (to_check.find(static_cast<item *>(i)) != to_check.end())
                    {
                        instances[static_cast<item *>(i)].push_back(a.first);
                        break;
                    }
                }
            }
        }

        for (const auto &rr : instances)
        {
            // for each pulse, the atoms starting at that pulse..
            std::map<double, std::set<atom *>> starting_atoms;
            // for each pulse, the atoms ending at that pulse..
            std::map<double, std::set<atom *>> ending_atoms;
            // all the pulses of the timeline..
            std::set<double> pulses;
            // the resource capacity..
            arith_expr capacity = rr.first->get(REUSABLE_RESOURCE_CAPACITY);

            for (const auto &a : rr.second)
            {
                arith_expr s_expr = a->get("start");
                arith_expr e_expr = a->get("end");
                double start = graph.la_th.value(s_expr->l);
                double end = graph.la_th.value(e_expr->l);
                starting_atoms[start].insert(a);
                ending_atoms[end].insert(a);
                pulses.insert(start);
                pulses.insert(end);
            }

            std::set<atom *> overlapping_atoms;
            for (const auto &p : pulses)
            {
                if (starting_atoms.find(p) != starting_atoms.end())
                {
                    for (const auto &a : starting_atoms.at(p))
                    {
                        overlapping_atoms.insert(a);
                    }
                }
                if (ending_atoms.find(p) != ending_atoms.end())
                {
                    for (const auto &a : ending_atoms.at(p))
                    {
                        overlapping_atoms.erase(a);
                    }
                }
                lin resource_usage;
                for (const auto &a : overlapping_atoms)
                {
                    arith_expr amount = a->get(REUSABLE_RESOURCE_USE_AMOUNT_NAME);
                    resource_usage += amount->l;
                }
                if (graph.la_th.value(resource_usage) > graph.la_th.value(capacity->l))
                {
                    // we have a peak..
                    flaws.push_back(new rr_flaw(graph, overlapping_atoms));
                }
            }
        }

        to_check.clear();
        return flaws;
    }
}

void reusable_resource::new_predicate(predicate &p)
{
    throw std::logic_error("it is not possible to define predicates on a reusable resource..");
}

bool reusable_resource::new_fact(atom &a)
{
    // we apply interval-predicate if the fact becomes active..
    set_var(graph.set_th.allows(a.state, *atom::active));
    if (!static_cast<predicate &>(graph.get_predicate("IntervalPredicate")).apply_rule(a))
    {
        return false;
    }
    restore_var();

    // reusable resource facts cannot unify..
    if (!graph.core::sat.new_clause({lit(graph.set_th.allows(a.state, *atom::unified), false)}))
    {
        return false;
    }

    atoms.push_back({&a, new rr_atom_listener(*this, a)});
    enum_expr c_scope = a.get("scope");
    for (const auto &val : graph.set_th.value(c_scope->ev))
    {
        to_check.insert(static_cast<item *>(val));
    }
    return true;
}

bool reusable_resource::new_goal(atom &a)
{
    throw std::logic_error("it is not possible to define goals on a reusable resource..");
}

reusable_resource::use_predicate::use_predicate(reusable_resource &rr) : predicate(rr.graph, rr, REUSABLE_RESOURCE_USE_PREDICATE_NAME, {new field(rr.graph.get_type("real"), REUSABLE_RESOURCE_USE_AMOUNT_NAME)})
{
    supertypes.push_back(&rr.graph.get_predicate("IntervalPredicate"));
}

reusable_resource::use_predicate::~use_predicate() {}

bool reusable_resource::use_predicate::apply_rule(atom &a) const
{
    return true;
}

reusable_resource::rr_atom_listener::rr_atom_listener(reusable_resource &rr, atom &atm) : atom_listener(atm), rr(rr) {}

reusable_resource::rr_atom_listener::~rr_atom_listener() {}

void reusable_resource::rr_atom_listener::something_changed()
{
    enum_expr c_scope = atm.get("scope");
    for (const auto &val : atm.get_core().set_th.value(c_scope->ev))
    {
        rr.to_check.insert(static_cast<item *>(val));
    }
}

reusable_resource::rr_flaw::rr_flaw(causal_graph &graph, const std::set<atom *> &overlapping_atoms) : flaw(graph), overlapping_atoms(overlapping_atoms) {}

reusable_resource::rr_flaw::~rr_flaw() {}

void reusable_resource::rr_flaw::compute_resolvers()
{
    std::vector<std::vector<atom *>> cs = combinations(std::vector<atom *>(overlapping_atoms.begin(), overlapping_atoms.end()), 2);
    for (const auto &as : cs)
    {
        arith_expr a0_start = as[0]->get("start");
        arith_expr a0_end = as[0]->get("end");
        arith_expr a1_start = as[1]->get("start");
        arith_expr a1_end = as[1]->get("end");

        bool_expr a0_before_a1 = graph.leq(a0_end, a1_start);
        if (graph.core::sat.value(a0_before_a1->l) != False)
        {
            add_resolver(*new order_resolver(graph, lin(0.0), *this, *as[0], *as[1], a0_before_a1->l));
        }
        bool_expr a1_before_a0 = graph.leq(a1_end, a0_start);
        if (graph.core::sat.value(a1_before_a0->l) != False)
        {
            add_resolver(*new order_resolver(graph, lin(0.0), *this, *as[1], *as[0], a1_before_a0->l));
        }

        enum_expr a0_scope = as[0]->get("scope");
        std::unordered_set<set_item *> a0_scopes = graph.set_th.value(a0_scope->ev);
        if (a0_scopes.size() > 1)
        {
            for (const auto &sc : a0_scopes)
            {
                add_resolver(*new displace_resolver(graph, lin(0.0), *this, *as[0], *static_cast<item *>(sc), lit(graph.set_th.allows(a0_scope->ev, *sc), false)));
            }
        }

        enum_expr a1_scope = as[1]->get("scope");
        std::unordered_set<set_item *> a1_scopes = graph.set_th.value(a1_scope->ev);
        if (a1_scopes.size() > 1)
        {
            for (const auto &sc : a1_scopes)
            {
                add_resolver(*new displace_resolver(graph, lin(0.0), *this, *as[1], *static_cast<item *>(sc), lit(graph.set_th.allows(a1_scope->ev, *sc), false)));
            }
        }
    }
}

reusable_resource::rr_resolver::rr_resolver(causal_graph &graph, const lin &cost, rr_flaw &f, const lit &to_do) : resolver(graph, cost, f), to_do(to_do) {}

reusable_resource::rr_resolver::~rr_resolver() {}

bool reusable_resource::rr_resolver::apply() { return graph.core::sat.new_clause({lit(chosen, false), to_do}); }

reusable_resource::order_resolver::order_resolver(causal_graph &graph, const lin &cost, rr_flaw &f, const atom &before, const atom &after, const lit &to_do) : rr_resolver(graph, cost, f, to_do), before(before), after(after) {}

reusable_resource::order_resolver::~order_resolver() {}

reusable_resource::displace_resolver::displace_resolver(causal_graph &graph, const lin &cost, rr_flaw &f, const atom &a, const item &i, const lit &to_do) : rr_resolver(graph, cost, f, to_do), a(a), i(i) {}

reusable_resource::displace_resolver::~displace_resolver() {}
}