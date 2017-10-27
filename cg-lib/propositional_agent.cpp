#include "propositional_agent.h"
#include "predicate.h"
#include "atom_flaw.h"

namespace cg
{

propositional_agent::propositional_agent(solver &s) : smart_type(s, s, PROPOSITIONAL_AGENT_NAME) { constructors.push_back(new agnt_constructor(*this)); }

propositional_agent::~propositional_agent() {}

std::vector<flaw *> propositional_agent::get_flaws()
{
    std::vector<flaw *> flaws;
    if (to_check.empty()) // nothing has changed since last inconsistency check..
        return flaws;
    else
        return flaws;
}

void propositional_agent::new_fact(atom_flaw &) { throw std::logic_error("it is not possible to define facts on propositional agents.."); }

void propositional_agent::new_goal(atom_flaw &f)
{
    atom &atm = f.get_atom();
    atoms.push_back({&atm, new agnt_atom_listener(*this, atm)});
    to_check.insert(&atm);
}

propositional_agent::agnt_atom_listener::agnt_atom_listener(propositional_agent &agnt, atom &atm) : atom_listener(atm), agnt(agnt) {}
propositional_agent::agnt_atom_listener::~agnt_atom_listener() {}
void propositional_agent::agnt_atom_listener::something_changed() { agnt.to_check.insert(&atm); }

propositional_agent::agnt_flaw::agnt_flaw(solver &s, const std::set<atom *> &overlapping_atoms) : flaw(s, smart_type::get_resolvers(s, overlapping_atoms)), overlapping_atoms(overlapping_atoms) {}
propositional_agent::agnt_flaw::~agnt_flaw() {}
void propositional_agent::agnt_flaw::compute_resolvers() {}

propositional_agent::agnt_resolver::agnt_resolver(solver &g, const lin &cost, agnt_flaw &f, const atom &before, const atom &after, const lit &to_do) : resolver(g, cost, f), before(before), after(after), to_do(to_do) {}
propositional_agent::agnt_resolver::~agnt_resolver() {}
void propositional_agent::agnt_resolver::apply() { slv.sat_cr.new_clause({lit(rho, false), to_do}); }
}