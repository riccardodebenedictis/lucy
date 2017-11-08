#include "state_variable.h"
#include "predicate.h"
#include "combinations.h"

namespace cg
{

state_variable::state_variable(cg::solver &g) : smart_type(g, g, STATE_VARIABLE_NAME) { constructors.push_back(new sv_constructor(*this)); }

state_variable::~state_variable()
{
    // we clear the atom listeners..
    for (const auto &a : atoms)
        delete a.second;
}

std::vector<flaw *> state_variable::get_flaws()
{
    std::vector<flaw *> flaws;
    if (to_check.empty()) // nothing has changed since last inconsistency check..
        return flaws;
    else
    {
        // we collect atoms for each state variable..
        std::unordered_map<item *, std::vector<atom *>> sv_instances;
        for (const auto &atm : atoms)
            if (slv.sat_cr.value(atm.first->sigma) == True) // we filter out those which are not strictly active..
            {
                expr c_scope = atm.first->get(TAU);
                if (var_item *enum_scope = dynamic_cast<var_item *>(&*c_scope))
                {
                    for (const auto &val : slv.ov_th.value(enum_scope->ev))
                        if (to_check.find(static_cast<item *>(val)) != to_check.end())
                            sv_instances[static_cast<item *>(val)].push_back(atm.first);
                }
                else
                    sv_instances[static_cast<item *>(&*c_scope)].push_back(atm.first);
            }

        for (const auto &sv : sv_instances)
        {
            // for each pulse, the atoms starting at that pulse..
            std::map<inf_rational, std::set<atom *>> starting_atoms;
            // for each pulse, the atoms ending at that pulse..
            std::map<inf_rational, std::set<atom *>> ending_atoms;
            // all the pulses of the timeline..
            std::set<inf_rational> pulses;

            for (const auto &atm : sv.second)
            {
                arith_expr s_expr = atm->get("start");
                arith_expr e_expr = atm->get("end");
                inf_rational start = slv.la_th.value(s_expr->l);
                inf_rational end = slv.la_th.value(e_expr->l);
                starting_atoms[start].insert(atm);
                ending_atoms[end].insert(atm);
                pulses.insert(start);
                pulses.insert(end);
            }

            std::set<atom *> overlapping_atoms;
            for (const auto &p : pulses)
            {
                const auto at_start_p = starting_atoms.find(p);
                if (at_start_p != starting_atoms.end())
                    overlapping_atoms.insert(at_start_p->second.begin(), at_start_p->second.end());
                const auto at_end_p = ending_atoms.find(p);
                if (at_end_p != ending_atoms.end())
                    for (const auto &a : at_end_p->second)
                        overlapping_atoms.erase(a);

                if (overlapping_atoms.size() > 1) // we have a peak..
                    flaws.push_back(new sv_flaw(slv, overlapping_atoms));
            }
        }

        to_check.clear();
        return flaws;
    }
}

void state_variable::new_predicate(predicate &pred)
{
    inherit(static_cast<predicate &>(slv.get_predicate("IntervalPredicate")), pred);
    add_field(pred, *new field(static_cast<type &>(pred.get_scope()), TAU));
}

void state_variable::new_fact(atom_flaw &f)
{
    // we apply interval-predicate if the fact becomes active..
    atom &atm = f.get_atom();
    set_var(atm.sigma);
    static_cast<predicate &>(slv.get_predicate("IntervalPredicate")).apply_rule(atm);
    restore_var();

    atoms.push_back({&atm, new sv_atom_listener(*this, atm)});
    expr c_scope = atm.get(TAU);
    if (var_item *enum_scope = dynamic_cast<var_item *>(&*c_scope))
        for (const auto &val : slv.ov_th.value(enum_scope->ev))
            to_check.insert(static_cast<item *>(val));
    else
        to_check.insert(&*c_scope);
}

void state_variable::new_goal(atom_flaw &f)
{
    atom &atm = f.get_atom();
    atoms.push_back({&atm, new sv_atom_listener(*this, atm)});
    expr c_scope = atm.get(TAU);
    if (var_item *multi_scope = dynamic_cast<var_item *>(&*c_scope))
        for (const auto &val : slv.ov_th.value(multi_scope->ev))
            to_check.insert(static_cast<item *>(val));
    else
        to_check.insert(&*c_scope);
}

state_variable::sv_atom_listener::sv_atom_listener(state_variable &sv, atom &atm) : atom_listener(atm), sv(sv) {}
state_variable::sv_atom_listener::~sv_atom_listener() {}

void state_variable::sv_atom_listener::something_changed()
{
    expr c_scope = atm.get(TAU);
    if (var_item *enum_scope = dynamic_cast<var_item *>(&*c_scope))
        for (const auto &val : atm.get_core().ov_th.value(enum_scope->ev))
            sv.to_check.insert(static_cast<item *>(val));
    else
        sv.to_check.insert(&*c_scope);
}

state_variable::sv_flaw::sv_flaw(solver &slv, const std::set<atom *> &atms) : flaw(slv, smart_type::get_resolvers(slv, atms)), overlapping_atoms(atms) {}
state_variable::sv_flaw::~sv_flaw() {}

void state_variable::sv_flaw::compute_resolvers()
{
    std::vector<std::vector<atom *>> cs = combinations(std::vector<atom *>(overlapping_atoms.begin(), overlapping_atoms.end()), 2);
    for (const auto &as : cs)
    {
        arith_expr a0_start = as[0]->get("start");
        arith_expr a0_end = as[0]->get("end");
        arith_expr a1_start = as[1]->get("start");
        arith_expr a1_end = as[1]->get("end");

        bool_expr a0_before_a1 = slv.leq(a0_end, a1_start);
        if (slv.sat_cr.value(a0_before_a1->l) != False)
            add_resolver(*new order_resolver(slv, lin(), *this, *as[0], *as[1], a0_before_a1->l));
        bool_expr a1_before_a0 = slv.leq(a1_end, a0_start);
        if (slv.sat_cr.value(a1_before_a0->l) != False)
            add_resolver(*new order_resolver(slv, lin(), *this, *as[1], *as[0], a1_before_a0->l));

        expr a0_scope = as[0]->get(TAU);
        if (var_item *enum_scope = dynamic_cast<var_item *>(&*a0_scope))
        {
            std::unordered_set<var_value *> a0_scopes = slv.ov_th.value(enum_scope->ev);
            if (a0_scopes.size() > 1)
                for (const auto &sc : a0_scopes)
                    add_resolver(*new displace_resolver(slv, lin(), *this, *as[0], *static_cast<item *>(sc), lit(slv.ov_th.allows(enum_scope->ev, *sc), false)));
        }

        expr a1_scope = as[1]->get(TAU);
        if (var_item *enum_scope = dynamic_cast<var_item *>(&*a0_scope))
        {
            std::unordered_set<var_value *> a1_scopes = slv.ov_th.value(enum_scope->ev);
            if (a1_scopes.size() > 1)
                for (const auto &sc : a1_scopes)
                    add_resolver(*new displace_resolver(slv, lin(), *this, *as[1], *static_cast<item *>(sc), lit(slv.ov_th.allows(enum_scope->ev, *sc), false)));
        }
    }
}

state_variable::sv_resolver::sv_resolver(solver &slv, const lin &cost, sv_flaw &f, const lit &to_do) : resolver(slv, cost, f), to_do(to_do) {}
state_variable::sv_resolver::~sv_resolver() {}
void state_variable::sv_resolver::apply() { slv.sat_cr.new_clause({lit(rho, false), to_do}); }

state_variable::order_resolver::order_resolver(solver &slv, const lin &cost, sv_flaw &f, const atom &before, const atom &after, const lit &to_do) : sv_resolver(slv, cost, f, to_do), before(before), after(after) {}
state_variable::order_resolver::~order_resolver() {}

state_variable::displace_resolver::displace_resolver(solver &slv, const lin &cost, sv_flaw &f, const atom &a, const item &i, const lit &to_do) : sv_resolver(slv, cost, f, to_do), a(a), i(i) {}
state_variable::displace_resolver::~displace_resolver() {}
}