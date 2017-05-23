#include "state_variable.h"
#include "predicate.h"
#include "combinations.h"

namespace cg {

	state_variable::state_variable(cg::causal_graph& g) : smart_type(g, g, STATE_VARIABLE_NAME) {
		constructors.push_back(new sv_constructor(*this));
	}

	state_variable::~state_variable() {
		// we clear the atom listeners..
		for (const auto& a : atoms) {
			delete a.second;
		}
	}

	std::vector<flaw*> state_variable::get_flaws() {
		std::vector<flaw*> flaws;
		if (to_check.empty()) {
			// nothing has changed since last inconsistency check..
			return flaws;
		}
		else {
			// we collect atoms for each state variable..
			std::unordered_map<item*, std::vector<atom*>> instances;
			for (const auto& atm : atoms) {
				// we filter out those which are not strictly active..
				if (graph.core::sat.value(graph.set.allows(atm.first->state, *atom::active)) == True) {
					enum_expr c_scope = atm.first->get("scope");
					for (const auto& i : graph.set.value(c_scope->ev)) {
						if (to_check.find(static_cast<item*> (i)) != to_check.end()) {
							instances[static_cast<item*> (i)].push_back(atm.first);
							break;
						}
					}
				}
			}

			for (const auto& sv : instances) {
				// for each pulse, the atoms starting at that pulse..
				std::map<double, std::set<atom*>> starting_atoms;
				// for each pulse, the atoms ending at that pulse..
				std::map<double, std::set<atom*>> ending_atoms;
				// all the pulses of the timeline..
				std::set<double> pulses;

				for (const auto& atm : sv.second) {
					arith_expr s_expr = atm->get("start");
					arith_expr e_expr = atm->get("end");
					double start = graph.la.value(s_expr->l);
					double end = graph.la.value(e_expr->l);
					starting_atoms[start].insert(atm);
					ending_atoms[end].insert(atm);
					pulses.insert(start);
					pulses.insert(end);
				}

				std::set<atom*> overlapping_atoms;
				for (const auto& p : pulses) {
					if (starting_atoms.find(p) != starting_atoms.end()) {
						for (const auto& a : starting_atoms.at(p)) {
							overlapping_atoms.insert(a);
						}
					}
					if (ending_atoms.find(p) != ending_atoms.end()) {
						for (const auto& a : ending_atoms.at(p)) {
							overlapping_atoms.erase(a);
						}
					}
					if (overlapping_atoms.size() > 1) {
						// we have a peak..
						flaws.push_back(new sv_flaw(graph, overlapping_atoms));
					}
				}
			}

			to_check.clear();
			return flaws;
		}
	}

	void state_variable::new_predicate(predicate& pred) {
		inherit(static_cast<predicate&> (graph.get_predicate("IntervalPredicate")), pred);
	}

	bool state_variable::new_fact(atom& atm) {
		// we apply interval-predicate if the fact becomes active..
		set_var(graph.set.allows(atm.state, *atom::active));
		if (!static_cast<predicate&> (graph.get_predicate("IntervalPredicate")).apply_rule(atm)) {
			return false;
		}
		restore_var();

		atoms.push_back({ &atm, new sv_atom_listener(*this, atm) });
		enum_expr c_scope = atm.get("scope");
		for (const auto& val : graph.set.value(c_scope->ev)) {
			to_check.insert(static_cast<item*> (val));
		}
		return true;
	}

	bool state_variable::new_goal(atom& atm) {
		atoms.push_back({ &atm, new sv_atom_listener(*this, atm) });
		enum_expr c_scope = atm.get("scope");
		for (const auto& val : graph.set.value(c_scope->ev)) {
			to_check.insert(static_cast<item*> (val));
		}
		return true;
	}

	state_variable::sv_atom_listener::sv_atom_listener(state_variable& sv, atom& atm) : atom_listener(atm), sv(sv) { }

	state_variable::sv_atom_listener::~sv_atom_listener() { }

	void state_variable::sv_atom_listener::something_changed() {
		enum_expr c_scope = atm.get("scope");
		for (const auto& val : atm.get_core().set.value(c_scope->ev)) {
			sv.to_check.insert(static_cast<item*> (val));
		}
	}

	state_variable::sv_flaw::sv_flaw(causal_graph& graph, const std::set<atom*>& overlapping_atoms) : flaw(graph), overlapping_atoms(overlapping_atoms) { }

	state_variable::sv_flaw::~sv_flaw() { }

	void state_variable::sv_flaw::compute_resolvers() {
		std::vector<std::vector < atom*>> cs = combinations(std::vector<atom*>(overlapping_atoms.begin(), overlapping_atoms.end()), 2);
		for (const auto& as : cs) {
			arith_expr a0_start = as[0]->get("start");
			arith_expr a0_end = as[0]->get("end");
			arith_expr a1_start = as[1]->get("start");
			arith_expr a1_end = as[1]->get("end");

			bool_expr a0_before_a1 = graph.leq(a0_end, a1_start);
			if (graph.core::sat.value(a0_before_a1->l) != False) {
				add_resolver(*new order_resolver(graph, lin(0.0), *this, *as[0], *as[1], a0_before_a1->l));
			}
			bool_expr a1_before_a0 = graph.leq(a1_end, a0_start);
			if (graph.core::sat.value(a1_before_a0->l) != False) {
				add_resolver(*new order_resolver(graph, lin(0.0), *this, *as[1], *as[0], a1_before_a0->l));
			}

			enum_expr a0_scope = as[0]->get("scope");
			std::unordered_set<set_item*> a0_scopes = graph.set.value(a0_scope->ev);
			if (a0_scopes.size() > 1) {
				for (const auto& sc : a0_scopes) {
					add_resolver(*new displace_resolver(graph, lin(0.0), *this, *as[0], *static_cast<item*> (sc), lit(graph.set.allows(a0_scope->ev, *sc), false)));
				}
			}

			enum_expr a1_scope = as[1]->get("scope");
			std::unordered_set<set_item*> a1_scopes = graph.set.value(a1_scope->ev);
			if (a1_scopes.size() > 1) {
				for (const auto& sc : a1_scopes) {
					add_resolver(*new displace_resolver(graph, lin(0.0), *this, *as[1], *static_cast<item*> (sc), lit(graph.set.allows(a1_scope->ev, *sc), false)));
				}
			}
		}
	}

	state_variable::sv_resolver::sv_resolver(causal_graph& graph, const lin& cost, sv_flaw& f, const lit& to_do) : resolver(graph, cost, f), to_do(to_do) { }

	state_variable::sv_resolver::~sv_resolver() { }

	bool state_variable::sv_resolver::apply() { return graph.core::sat.new_clause({ lit(chosen, false), to_do }); }

	state_variable::order_resolver::order_resolver(causal_graph& graph, const lin& cost, sv_flaw& f, const atom& before, const atom& after, const lit& to_do) : sv_resolver(graph, cost, f, to_do), before(before), after(after) { }

	state_variable::order_resolver::~order_resolver() { }

	state_variable::displace_resolver::displace_resolver(causal_graph& graph, const lin& cost, sv_flaw& f, const atom& a, const item& i, const lit& to_do) : sv_resolver(graph, cost, f, to_do), a(a), i(i) { }

	state_variable::displace_resolver::~displace_resolver() { }
}