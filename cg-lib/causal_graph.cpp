#include "causal_graph.h"
#include "enum_flaw.h"
#include "atom_flaw.h"
#include "disjunction_flaw.h"

namespace cg {

	causal_graph::causal_graph() : core(), theory(core::sat) {}

	causal_graph::~causal_graph() {}

	expr causal_graph::new_enum(const type& tp, const std::unordered_set<item*>& allowed_vals) {
		assert(!allowed_vals.empty());
		// we create a new enum expression..
		enum_expr c_e = core::new_enum(tp, allowed_vals);
		if (allowed_vals.size() > 1) {
			// we creaste a new enum flaw..
			enum_flaw* ef = new enum_flaw(*this, *c_e);
			new_flaw(*ef);
		}
		return c_e;
	}

	bool causal_graph::new_fact(atom& atm) {
		// we creaste a new atom flaw..
		atom_flaw* af = new atom_flaw(*this, atm, true);
		reason.insert({ &atm, af });
		new_flaw(*af);
		return core::new_fact(atm);
	}

	bool causal_graph::new_goal(atom& atm) {
		// we creaste a new atom flaw..
		atom_flaw* af = new atom_flaw(*this, atm, false);
		reason.insert({ &atm, af });
		new_flaw(*af);
		return core::new_goal(atm);
	}

	void causal_graph::new_disjunction(context& ctx, disjunction& disj) {
		// we creaste a new disjunction flaw..
		disjunction_flaw* df = new disjunction_flaw(*this, ctx, disj);
		new_flaw(*df);
	}

	bool causal_graph::solve() {
		return false;
	}

	void causal_graph::new_flaw(flaw& f) {
	}

	void causal_graph::new_resolver(resolver& r) {
	}

	void causal_graph::new_causal_link(flaw& f, resolver& r) {
	}

	bool causal_graph::propagate(const lit& p, std::vector<lit>& cnfl) {
		return false;
	}

	bool causal_graph::check(std::vector<lit>& cnfl) {
		return false;
	}

	void causal_graph::push() {
	}

	void causal_graph::pop() {
	}

	bool causal_graph::build() {
		return false;
	}

	bool causal_graph::add_layer() {
		return false;
	}

	bool causal_graph::has_solution() {
		return false;
	}

	bool causal_graph::is_deferrable(flaw& f) {
		return false;
	}

	void causal_graph::set_cost(flaw& f, double cost) {
		if (f.cost != cost) {
			if (!trail.empty()) {
				trail.back().old_costs.insert({ &f, f.cost });
			}
			f.cost = cost;

			for (const auto& supp : f.supports) {
				flaw_costs_q.push(&supp->effect);
			}
			propagate_costs();
		}
	}

	void causal_graph::propagate_costs() {
	}

	bool causal_graph::has_inconsistencies() {
		return false;
	}

	flaw* causal_graph::select_flaw() {
		return nullptr;
	}

	resolver& causal_graph::select_resolver(flaw& f) {
		double r_cost = std::numeric_limits<double>::infinity();
		resolver* r_next = nullptr; // this is the next resolver to be chosen (i.e., the cheapest one)..
		for (const auto& r : f.resolvers) {
			double c_cost = r->get_cost();
			if (c_cost < r_cost) {
				r_cost = c_cost;
				r_next = r;
			}
		}
		return *r_next;
	}
}