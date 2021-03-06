#include "propositional_state.h"
#include "predicate.h"
#include "atom_flaw.h"

namespace cg
{

propositional_state::propositional_state(solver &s) : smart_type(s, s, PROPOSITIONAL_STATE_NAME)
{
    constructors.push_back(new ps_constructor(*this));
    predicates.insert({PROPOSITIONAL_STATE_PREDICATE_NAME, new ps_predicate(*this)});
}

propositional_state::~propositional_state()
{
    // we clear the atom listeners..
    for (const auto &a : atoms)
        delete a.second;
}

std::vector<flaw *> propositional_state::get_flaws()
{
    std::vector<flaw *> flaws;
    if (to_check.empty()) // nothing has changed since last inconsistency check..
        return flaws;
    else
        return flaws;
}

void propositional_state::new_predicate(predicate &pred)
{
    inherit(static_cast<predicate &>(get_predicate(PROPOSITIONAL_STATE_PREDICATE_NAME)), pred);
    add_field(pred, *new field(static_cast<type &>(pred.get_scope()), TAU));
}

void propositional_state::new_fact(atom_flaw &f)
{
    // we apply interval-predicate if the fact becomes active..
    atom &atm = f.get_atom();
    set_var(atm.sigma);
    static_cast<predicate &>(get_predicate(PROPOSITIONAL_STATE_PREDICATE_NAME)).apply_rule(atm);
    restore_var();

    atoms.push_back({&atm, new ps_atom_listener(*this, atm)});
    to_check.insert(&atm);
}

void propositional_state::new_goal(atom_flaw &f)
{
    atom &atm = f.get_atom();
    atoms.push_back({&atm, new ps_atom_listener(*this, atm)});
    to_check.insert(&atm);
}

propositional_state::ps_predicate::ps_predicate(propositional_state &ps) : predicate(ps.slv, ps, PROPOSITIONAL_STATE_PREDICATE_NAME, {new field(ps.slv.get_type("bool"), PROPOSITIONAL_STATE_POLARITY_NAME)}, {}) { supertypes.push_back(&ps.slv.get_predicate("IntervalPredicate")); }
propositional_state::ps_predicate::~ps_predicate() {}

propositional_state::ps_atom_listener::ps_atom_listener(propositional_state &ps, atom &atm) : atom_listener(atm), ps(ps) {}
propositional_state::ps_atom_listener::~ps_atom_listener() {}
void propositional_state::ps_atom_listener::something_changed() { ps.to_check.insert(&atm); }

propositional_state::ps_flaw::ps_flaw(solver &s, const std::set<atom *> &overlapping_atoms) : flaw(s, smart_type::get_resolvers(s, overlapping_atoms)), overlapping_atoms(overlapping_atoms) {}
propositional_state::ps_flaw::~ps_flaw() {}
void propositional_state::ps_flaw::compute_resolvers() {}

propositional_state::ps_resolver::ps_resolver(solver &s, const lin &cost, ps_flaw &f, const lit &to_do) : resolver(s, cost, f), to_do(to_do) {}
propositional_state::ps_resolver::~ps_resolver() {}
void propositional_state::ps_resolver::apply() { slv.sat_cr.new_clause({lit(rho, false), to_do}); }

propositional_state::order_resolver::order_resolver(solver &s, const lin &cost, ps_flaw &f, const atom &before, const atom &after, const lit &to_do) : ps_resolver(s, cost, f, to_do), before(before), after(after) {}
propositional_state::order_resolver::~order_resolver() {}

propositional_state::displace_resolver::displace_resolver(solver &s, const lin &cost, ps_flaw &f, const atom &a, const std::string &f_name, const item &i, const lit &to_do) : ps_resolver(s, cost, f, to_do), a(a), f_name(f_name), i(i) {}
propositional_state::displace_resolver::~displace_resolver() {}
}