#include "causal_graph.h"
#include "enum_flaw.h"
#include "atom_flaw.h"
#include "disjunction_flaw.h"
#include "smart_type.h"

namespace cg {

	causal_graph::causal_graph() : core(), theory(core::sat) {}

	causal_graph::~causal_graph() {
		for (const auto& f : in_plan) {
			delete f.second;
		}
	}

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
	main_loop:
		res = nullptr;

		// we build the planning graph..
		if (!build()) {
			// the problem is unsolvable..
			return false;
		}

		// we create a new graph var..
		graph_var = core::sat.new_var();
		// we use the current graph var to allow search within the current graph..
		bool a_gv = core::sat.assume(smt::lit(graph_var, true));
		assert(a_gv);

		// this is the next flaw to be solved..
		flaw* f_next = select_flaw();
		while (f_next) {
			assert(f_next->cost < std::numeric_limits<double>::infinity());
			if (f_next->has_subgoals()) {
				// we run out of inconsistencies, thus, we renew them..
				if (has_inconsistencies()) {
					// we go back to root level..
					while (!core::sat.root_level()) {
						core::sat.pop();
					}
					goto main_loop;
				}
			}

			// this is the next resolver to be chosen..
			resolver& r_next = select_resolver(*f_next);
			res = &r_next;
			if (f_next->has_subgoals()) {
				resolvers.push_back(&r_next);
			}

			// we apply the resolver..
			if (!core::sat.assume(smt::lit(r_next.chosen, true)) || !core::sat.check()) {
				return false;
			}

			while (!has_solution()) {
				// we search within the graph..
				std::vector<smt::lit> look_elsewhere;
				for (std::vector<layer>::reverse_iterator trail_it = trail.rbegin(); trail_it != trail.rend(); ++trail_it) {
					if (trail_it->r) {
						look_elsewhere.push_back(smt::lit(trail_it->r->chosen, false));
					}
				}
				look_elsewhere.push_back(smt::lit(graph_var, false));
				while (core::sat.value(look_elsewhere[0].v) != smt::Undefined) {
					// we backtrack..
					core::sat.pop();
				}
				if (core::sat.root_level()) {
					// we have exhausted the search within the graph: we extend the graph..
					if (!add_layer()) {
						return false;
					}

					// we create a new graph var..
					graph_var = core::sat.new_var();
					// we use the current graph var to allow search within the current graph..
					a_gv = core::sat.assume(smt::lit(graph_var, true));
					assert(a_gv);
				}
				else {
					record(look_elsewhere);
					if (!core::sat.check()) {
						return false;
					}
				}
			}

			// we select a new flaw..
			f_next = select_flaw();
		}

		// we run out of flaws, we check for inconsistencies one last time..
		if (has_inconsistencies()) {
			// we go back to root level..
			while (!core::sat.root_level()) {
				core::sat.pop();
			}
			goto main_loop;
		}

		// we have found a solution..
		return true;
	}

	void causal_graph::new_flaw(flaw& f) {
		f.init();
		flaw_q.push(&f);
		if (core::sat.value(f.in_plan) == smt::True) {
			// we have a top-level (landmark) flaw..
			flaws.insert(&f);
		}
		else {
			// we listen for the flaw to become in_plan..
			in_plan.insert({ f.in_plan, &f });
			bind(f.in_plan);
		}
	}

	void causal_graph::new_resolver(resolver& r) {
	}

	void causal_graph::new_causal_link(flaw& f, resolver& r) {
		r.preconditions.push_back(&f);
		f.supports.push_back(&r);
		bool new_clause = core::sat.new_clause({ smt::lit(r.chosen, false), smt::lit(f.in_plan, true) });
		assert(new_clause);
	}

	bool causal_graph::propagate(const lit& p, std::vector<lit>& cnfl) {
		assert(cnfl.empty());
		if (in_plan.find(p.v) != in_plan.end()) {
			// a decision has been taken about the presence of this flaw within the current partial solution..
			flaw* f = in_plan.at(p.v);
			if (p.sign) {
				// a flaw has been added to the current partial solution..
				flaws.insert(f);
				if (!trail.empty()) {
					trail.back().new_flaws.insert(f);
				}
			}
			else {
				// a flaw has been removed from the current partial solution..
				set_cost(*f, std::numeric_limits<double>::infinity());
			}
		}
		else {
			flaw_costs_q.push(&chosen.at(p.v)->effect);
			propagate_costs();
		}

		if (flaw_q.empty()) {
			// we can use standard search techniques..
			if (!has_solution()) {
				// we have made the heuristic blind..
				cnfl.push_back(p);
				for (std::vector<layer>::reverse_iterator trail_it = trail.rbegin(); trail_it != trail.rend(); ++trail_it) {
					if (trail_it->r) {
						// this resolver is null if we are calling the check from the sat core! Not bad: shorter conflict..
						cnfl.push_back(smt::lit(trail_it->r->chosen, false));
					}
				}
				return false;
			}
		}

		return true;
	}

	bool causal_graph::check(std::vector<lit>& cnfl) {
		assert(cnfl.empty());
		return true;
	}

	void causal_graph::push() {
		trail.push_back(layer(res));
		if (res) {
			// we just solved the resolver's effect..
			trail.back().solved_flaws.insert(&res->effect);
			flaws.erase(&res->effect);
		}
	}

	void causal_graph::pop() {
		// we erase new flaws..
		for (const auto& f : trail.back().new_flaws) {
			flaws.erase(f);
		}
		// we reintroduce the solved flaw..
		for (const auto& f : trail.back().solved_flaws) {
			flaws.insert(f);
		}
		// we restore flaw costs..
		for (const auto& c : trail.back().old_costs) {
			c.first->cost = c.second;
		}
		// we manage structural flaws..
		if (!resolvers.empty() && resolvers.back() == trail.back().r) {
			resolvers.pop_back();
		}
		trail.pop_back();
	}

	bool causal_graph::build() {
		assert(core::sat.root_level());
		if (flaw_q.empty()) {
			// there is nothing to reason on..
			return true;
		}

		while (!has_solution() && !flaw_q.empty()) {
			assert(flaw_q.front()->initialized);
			assert(!flaw_q.front()->expanded);
			if (is_deferrable(*flaw_q.front())) {
				// we postpone the expansion..
				flaw_q.push(flaw_q.front());
			}
			else {
				if (!flaw_q.front()->expand() || !core::sat.check()) {
					return false;
				}

				for (const auto& r : flaw_q.front()->resolvers) {
					resolvers.push_front(r);
					set_var(r->chosen);
					if (!r->apply() || !core::sat.check()) {
						return false;
					}
					restore_var();
					if (r->preconditions.empty()) {
						// there are no requirements for this resolver..
						set_cost(*flaw_q.front(), std::min(flaw_q.front()->cost, la.value(r->cost)));
						// making this resolver false might make the heuristic blind..
						chosen.insert({ r->chosen, r });
						bind(r->chosen);
					}
					resolvers.pop_front();
				}
			}
			flaw_q.pop();
		}

		return true;
	}

	bool causal_graph::add_layer() {
		assert(core::sat.root_level());

		std::vector<flaw*> fs;
		while (!flaw_q.empty()) {
			fs.push_back(flaw_q.front());
			flaw_q.pop();
		}

		for (const auto& f : fs) {
			assert(f->initialized);
			assert(!f->expanded);
			if (!f->expand() || !core::sat.check()) {
				return false;
			}

			for (const auto& r : f->resolvers) {
				resolvers.push_front(r);
				set_var(r->chosen);
				if (!r->apply() || !core::sat.check()) {
					return false;
				}
				restore_var();
				if (r->preconditions.empty()) {
					// there are no requirements for this resolver..
					set_cost(*f, std::min(f->cost, la.value(r->cost)));
					// making this resolver false might make the heuristic blind..
					chosen.insert({ r->chosen, r });
					bind(r->chosen);
				}
				resolvers.pop_front();
			}
		}

		return true;
	}

	bool causal_graph::has_solution() {
		for (const auto& f : flaws) {
			if (f->cost == std::numeric_limits<double>::infinity()) {
				return false;
			}
		}
		return true;
	}

	bool causal_graph::is_deferrable(flaw& f) {
		std::queue<flaw*> q;
		q.push(&f);
		while (!q.empty()) {
			if (!q.front()->exclusive) {
				// we cannot defer this flaw..
				return false;
			}
			else if (core::sat.value(q.front()->in_plan) == smt::False) {
				// it is not possible to solve this flaw with current assignments.. thus we defer..
				return true;
			}
			else if (q.front()->cost < std::numeric_limits<double>::infinity()) {
				// we already have a possible solution for this flaw.. thus we defer..
				return true;
			}
			for (const auto& r : q.front()->causes) {
				q.push(&r->effect);
			}
			q.pop();
		}
		// we cannot defer this flaw..
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
		while (!flaw_costs_q.empty()) {
			double f_cost = std::numeric_limits<double>::infinity();
			for (const auto& r : flaw_costs_q.front()->resolvers) {
				double c = r->get_cost();
				if (c < f_cost) {
					f_cost = c;
				}
			}
			if (flaw_costs_q.front()->cost != f_cost) {
				if (!trail.empty()) {
					trail.back().old_costs.insert({ flaw_costs_q.front(), flaw_costs_q.front()->cost });
				}
				flaw_costs_q.front()->cost = f_cost;
				for (const auto& supp : flaw_costs_q.front()->supports) {
					flaw_costs_q.push(&supp->effect);
				}
			}
			flaw_costs_q.pop();
		}
	}

	bool causal_graph::has_inconsistencies() {
		std::vector<flaw*> incs;
		std::queue<type*> q;
		for (const auto& t : get_types()) {
			if (!t.second->primitive) {
				q.push(t.second);
			}
		}
		while (!q.empty()) {
			if (smart_type * st = dynamic_cast<smart_type*> (q.front())) {
				std::vector<flaw*> c_incs = st->get_flaws();
				incs.insert(incs.end(), c_incs.begin(), c_incs.end());
			}
			for (const auto& st : q.front()->get_types()) {
				q.push(st.second);
			}
			q.pop();
		}

		// we initialize the new flaws..
		for (const auto& f : incs) {
			new_flaw(*f);
		}

		return !incs.empty();
	}

	flaw* causal_graph::select_flaw() {
		// this is the next flaw to be solved (i.e., the most expensive one)..
		flaw* f_next = nullptr;
		for (auto it = flaws.begin(); it != flaws.end();) {
			assert((*it)->expanded);
			assert(core::sat.value((*it)->in_plan) == smt::True);
			if (std::count_if((*it)->resolvers.begin(), (*it)->resolvers.end(), [&](resolver * r) { return core::sat.value(r->chosen) != smt::False; }) == 1) {
				// we have a trivial flaw..
				assert(core::sat.value((*std::find_if((*it)->resolvers.begin(), (*it)->resolvers.end(), [&](resolver * r) { return core::sat.value(r->chosen) != smt::False; }))->chosen) == smt::True);
				// we remove the trivial flaw from the current flaws..
				if (!trail.empty()) {
					trail.back().solved_flaws.insert((*it));
				}
				flaws.erase(it++);
			}
			else {
				// the flaw is not trivial: let's see if it's better than the previous one..
				if (!f_next) {
					// it's the first flaw we see..
					f_next = *it;
				}
				else if (f_next->has_subgoals() && !(*it)->has_subgoals()) {
					// we prefere non-structural flaws (i.e., inconsistencies) to structural ones..
					f_next = *it;
				}
				else if (f_next->has_subgoals() == (*it)->has_subgoals() && f_next->cost < (*it)->cost) {
					// this flaw is actually better than the previous one..
					f_next = *it;
				}
				++it;
			}
		}
		return f_next;
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