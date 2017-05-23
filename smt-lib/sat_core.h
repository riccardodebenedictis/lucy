#pragma once

#include "visibility.h"
#include "lit.h"
#include <vector>
#include <queue>
#include <unordered_map>

namespace smt {

	static const var FALSE = 0;
	static const var TRUE = 1;

	enum lbool {
		True, False, Undefined
	};

#pragma warning( disable : 4251 )
	class DLL_PUBLIC sat_core {
		friend class clause;
		friend class theory;
		friend class sat_value_listener;
	public:
		sat_core();
		sat_core(const sat_core& orig) = delete;
		virtual ~sat_core();

		var new_var();
		bool new_clause(const std::vector<lit>& lits);

		var new_eq(const lit& left, const lit& right);
		var new_conj(const std::vector<lit>& ls);
		var new_disj(const std::vector<lit>& ls);
		var new_exct_one(const std::vector<lit>& ls);

		bool eq(const lit& left, const lit& right) {
			return new_clause({ !left, right }) && new_clause({ left, !right });
		}

		bool exct_one(const std::vector<lit>& lits) {
			// the at-least-one clause..
			std::vector<lit> ls;
			for (size_t i = 0; i < lits.size(); i++) {
				for (size_t j = i + 1; j < lits.size(); j++) {
					// the at-most-one clauses..
					if (!new_clause({ !lits[i], !lits[j] })) {
						return false;
					}
				}
				ls.push_back(lits[i]);
			}
			return new_clause(ls);
		}

		bool assume(const lit& p);
		void pop();

		lbool value(var x) const {
			return assigns[x];
		}

		lbool value(const lit& p) const {
			switch (value(p.v)) {
			case True:
				return p.sign ? True : False;
			case False:
				return p.sign ? False : True;
			case Undefined:
				return Undefined;
			default:
				throw std::logic_error("invalid value..");
			}
		}

		bool root_level() { return trail_lim.empty(); }

		bool check();
		bool check(const std::vector<lit>& lits);

	private:
		bool propagate(std::vector<lit>& cnfl);
		void analyze(const std::vector<lit>& cnfl, std::vector<lit>& out_learnt, size_t& out_btlevel);
		void record(const std::vector<lit>& lits);

		bool enqueue(const lit& p, clause* const c = nullptr);
		void pop_one();

		size_t index(const lit& p) const { return p.sign ? p.v << 1 : (p.v << 1) ^ 1; }

		void add_theory(theory& th);
		void remove_theory(theory& th);
		void bind(var v, theory& th);
		void unbind(var v, theory& th);

		void listen(var v, sat_value_listener* const l);
		void forget(var v, sat_value_listener* const l);

	private:
		// collection of problem constraints..
		std::vector<clause*> constrs;
		// for each variable v, a list of constraints watching v..
		std::vector<std::vector<clause*>> watches;
		// propagation queue..
		std::queue<lit> prop_q;
		// the current assignments..
		std::vector<lbool> assigns;
		// the list of assignment in chronological order..
		std::vector<lit> trail;
		// separator literals for different decision levels in 'trail'..
		std::vector<lit> trail_lim;
		// for each variable, the constraint that implied its value..
		std::vector<clause*> reason;
		// for each variable, the decision level it was assigned..
		std::vector<size_t> level;
		// the already existing expressions (string to bool variable)..
		std::unordered_map<std::string, var> exprs;

		// all the theories..
		std::vector<theory*> theories;
		std::unordered_map<var, std::list<theory*>> bounds;
		std::unordered_map<var, std::list<sat_value_listener*>> listening;
	};
}