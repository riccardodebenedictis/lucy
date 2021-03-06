#include "reusable_resource.h"
#include "combinations.h"
#include "statement.h"
#include "expression.h"

namespace cg
{

reusable_resource::reusable_resource(cg::solver &g) : smart_type(g, g, REUSABLE_RESOURCE_NAME)
{
    add_field(*this, *new field(g.get_type("real"), REUSABLE_RESOURCE_CAPACITY));
    constructors.push_back(new rr_constructor(*this));
    predicates.insert({REUSABLE_RESOURCE_USE_PREDICATE_NAME, new use_predicate(*this)});
}

reusable_resource::~reusable_resource() {}

std::vector<flaw *> reusable_resource::get_flaws()
{
    std::vector<flaw *> flaws;
    if (to_check.empty()) // nothing has changed since last inconsistency check..
        return flaws;
    else
    {
        // we collect atoms for each state variable..
        std::unordered_map<item *, std::vector<atom *>> rr_instances;
        for (const auto &a : atoms)
            if (slv.sat_cr.value(a.first->sigma) == True) // we filter out those which are not strictly active..
            {
                expr c_scope = a.first->get(TAU);
                if (var_item *enum_scope = dynamic_cast<var_item *>(&*c_scope))
                {
                    for (const auto &val : slv.ov_th.value(enum_scope->ev))
                        if (to_check.find(static_cast<item *>(val)) != to_check.end())
                            rr_instances[static_cast<item *>(val)].push_back(a.first);
                }
                else
                    rr_instances[static_cast<item *>(&*c_scope)].push_back(a.first);
            }

        for (const auto &rr : rr_instances)
        {
            // for each pulse, the atoms starting at that pulse..
            std::map<inf_rational, std::set<atom *>> starting_atoms;
            // for each pulse, the atoms ending at that pulse..
            std::map<inf_rational, std::set<atom *>> ending_atoms;
            // all the pulses of the timeline..
            std::set<inf_rational> pulses;
            // the resource capacity..
            arith_expr capacity = rr.first->get(REUSABLE_RESOURCE_CAPACITY);

            for (const auto &a : rr.second)
            {
                arith_expr s_expr = a->get("start");
                arith_expr e_expr = a->get("end");
                inf_rational start = slv.la_th.value(s_expr->l);
                inf_rational end = slv.la_th.value(e_expr->l);
                starting_atoms[start].insert(a);
                ending_atoms[end].insert(a);
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
                lin resource_usage;
                for (const auto &a : overlapping_atoms)
                {
                    arith_expr amount = a->get(REUSABLE_RESOURCE_USE_AMOUNT_NAME);
                    resource_usage += amount->l;
                }

                if (slv.la_th.value(resource_usage) > slv.la_th.value(capacity->l)) // we have a peak..
                    flaws.push_back(new rr_flaw(slv, overlapping_atoms));
            }
        }

        to_check.clear();
        return flaws;
    }
}

void reusable_resource::new_fact(atom_flaw &f)
{
    // we apply interval-predicate if the fact becomes active..
    atom &atm = f.get_atom();
    set_var(atm.sigma);
    static_cast<predicate &>(get_predicate(REUSABLE_RESOURCE_USE_PREDICATE_NAME)).apply_rule(atm);
    restore_var();

    // we avoid unification..
    if (!slv.sat_cr.new_clause({lit(f.get_phi(), false), atm.sigma}))
        throw unsolvable_exception();

    atoms.push_back({&atm, new rr_atom_listener(*this, atm)});
    expr c_scope = atm.get(TAU);
    if (var_item *enum_scope = dynamic_cast<var_item *>(&*c_scope))
        for (const auto &val : slv.ov_th.value(enum_scope->ev))
            to_check.insert(static_cast<item *>(val));
    else
        to_check.insert(&*c_scope);
}

void reusable_resource::new_goal(atom_flaw &) { throw std::logic_error("it is not possible to define goals on a reusable resource.."); }

reusable_resource::rr_constructor::rr_constructor(reusable_resource &rr) : constructor(rr.slv, rr, {new field(rr.slv.get_type(REAL_KEYWORD), REUSABLE_RESOURCE_CAPACITY)}, {{REUSABLE_RESOURCE_CAPACITY, {new ast::id_expression({REUSABLE_RESOURCE_CAPACITY})}}}, {new ast::expression_statement(new ast::geq_expression(new ast::id_expression({REUSABLE_RESOURCE_CAPACITY}), new ast::real_literal_expression(0)))}) {}
reusable_resource::rr_constructor::~rr_constructor() {}

reusable_resource::use_predicate::use_predicate(reusable_resource &rr) : predicate(rr.slv, rr, REUSABLE_RESOURCE_USE_PREDICATE_NAME, {new field(rr.slv.get_type(REAL_KEYWORD), REUSABLE_RESOURCE_USE_AMOUNT_NAME), new field(rr, TAU)}, {new ast::expression_statement(new ast::geq_expression(new ast::id_expression({REUSABLE_RESOURCE_USE_AMOUNT_NAME}), new ast::real_literal_expression(0)))}) { supertypes.push_back(&rr.slv.get_predicate("IntervalPredicate")); }
reusable_resource::use_predicate::~use_predicate() {}

reusable_resource::rr_atom_listener::rr_atom_listener(reusable_resource &rr, atom &atm) : atom_listener(atm), rr(rr) {}
reusable_resource::rr_atom_listener::~rr_atom_listener() {}

void reusable_resource::rr_atom_listener::something_changed()
{
    expr c_scope = atm.get(TAU);
    if (var_item *enum_scope = dynamic_cast<var_item *>(&*c_scope))
        for (const auto &val : atm.get_core().ov_th.value(enum_scope->ev))
            rr.to_check.insert(static_cast<item *>(val));
    else
        rr.to_check.insert(&*c_scope);
}

reusable_resource::rr_flaw::rr_flaw(solver &slv, const std::set<atom *> &atms) : flaw(slv, smart_type::get_resolvers(slv, atms)), overlapping_atoms(atms) {}
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
        if (var_item *enum_scope = dynamic_cast<var_item *>(&*a1_scope))
        {
            std::unordered_set<var_value *> a1_scopes = slv.ov_th.value(enum_scope->ev);
            if (a1_scopes.size() > 1)
                for (const auto &sc : a1_scopes)
                    add_resolver(*new displace_resolver(slv, lin(), *this, *as[1], *static_cast<item *>(sc), lit(slv.ov_th.allows(enum_scope->ev, *sc), false)));
        }
    }
}

reusable_resource::rr_resolver::rr_resolver(solver &slv, const lin &cost, rr_flaw &f, const lit &to_do) : resolver(slv, cost, f), to_do(to_do) {}
reusable_resource::rr_resolver::~rr_resolver() {}
void reusable_resource::rr_resolver::apply() { slv.sat_cr.new_clause({lit(rho, false), to_do}); }

reusable_resource::order_resolver::order_resolver(solver &slv, const lin &cost, rr_flaw &f, const atom &before, const atom &after, const lit &to_do) : rr_resolver(slv, cost, f, to_do), before(before), after(after) {}
reusable_resource::order_resolver::~order_resolver() {}

reusable_resource::displace_resolver::displace_resolver(solver &slv, const lin &cost, rr_flaw &f, const atom &a, const item &i, const lit &to_do) : rr_resolver(slv, cost, f, to_do), a(a), i(i) {}
reusable_resource::displace_resolver::~displace_resolver() {}
}