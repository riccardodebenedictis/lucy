#include "sat_core.h"
#include "clause.h"
#include "theory.h"
#include "sat_value_listener.h"
#include <cassert>

namespace smt {

	sat_core::sat_core() {
		var c_false = new_var();
		var c_true = new_var();
		assert(c_false == FALSE);
		assert(c_true == TRUE);
		assigns[FALSE] = False;
		assigns[TRUE] = True;
		level[FALSE] = 0;
		level[TRUE] = 0;
	}

	sat_core::~sat_core() {
		for (const auto& c : constrs) {
			delete c;
		}
	}

	var sat_core::new_var() {
		var id = assigns.size();
		watches.push_back(std::vector<clause*>());
		watches.push_back(std::vector<clause*>());
		assigns.push_back(Undefined);
		exprs.insert({ "b" + std::to_string(id), id });
		level.push_back(0);
		reason.push_back(nullptr);
		return id;
	}

	bool sat_core::new_clause(const std::vector<lit>& lits) {
		assert(root_level());
		if (std::any_of(lits.begin(), lits.end(), [&](const lit& p) { return value(p) == True; })) {
			return true;
		}
		else if (std::all_of(lits.begin(), lits.end(), [&](const lit& p) { return value(p) == False; })) {
			return false;
		}
		else {
			std::vector<lit> c_lits;
			std::copy_if(lits.begin(), lits.end(), std::back_inserter(c_lits), [&](const lit& p) { return value(p) == Undefined; });
			if (c_lits.size() == 1) {
				enqueue(c_lits[0]);
			}
			else {
				constrs.push_back(new clause(*this, c_lits));
			}
			return true;
		}
	}

	var sat_core::new_eq(const lit& left, const lit& right) {
		assert(root_level());
		if (left == right) {
			return TRUE;
		}
		if (left.v > right.v) {
			return new_eq(right, left);
		}
		std::string s_expr = (left.sign ? "b" : "!b") + std::to_string(left.v) + " == " + (right.sign ? "b" : "!b") + std::to_string(right.v);
		if (exprs.find(s_expr) != exprs.end()) {
			// the expression already exists..
			return exprs.at(s_expr);
		}
		else {
			// we need to create a new variable..
			var e = new_var();
			bool nc;
			nc = new_clause({ lit(e, false), !left, right });
			assert(nc);
			nc = new_clause({ lit(e, false), left, !right });
			assert(nc);
			nc = new_clause({ lit(e, true), !left, !right });
			assert(nc);
			exprs.insert({ s_expr, e });
			return e;
		}
	}

	var sat_core::new_conj(const std::vector<lit>& ls) {
		assert(root_level());
		std::vector<lit> c_lits = ls;
		std::sort(c_lits.begin(), c_lits.end(), [](const lit& l0, const lit& l1) { return l0.v > l1.v; });
		std::string s_expr;
		for (std::vector<lit>::const_iterator it = c_lits.begin(); it != c_lits.end(); ++it) {
			if (it == c_lits.begin()) { s_expr += (it->sign ? "b" : "!b") + std::to_string(it->v); }
			else { s_expr += (" & " + it->sign ? "b" : "!b") + std::to_string(it->v); }
		}
		if (exprs.find(s_expr) != exprs.end()) {
			// the expression already exists..
			return exprs.at(s_expr);
		}
		else {
			// we need to create a new variable..
			var c = new_var();
			std::vector<lit> lits;
			lits.push_back(lit(c, true));
			bool nc;
			for (const auto& l : ls) {
				nc = new_clause({ lit(c, false), l });
				assert(nc);
				lits.push_back(!l);
			}
			nc = new_clause(lits);
			assert(nc);
			exprs.insert({ s_expr, c });
			return c;
		}
	}

	var sat_core::new_disj(const std::vector<lit>& ls) {
		std::vector<lit> c_lits = ls;
		std::sort(c_lits.begin(), c_lits.end(), [](const lit& l0, const lit& l1) { return l0.v > l1.v; });
		std::string s_expr;
		for (std::vector<lit>::const_iterator it = c_lits.begin(); it != c_lits.end(); ++it) {
			if (it == c_lits.begin()) { s_expr += (it->sign ? "b" : "!b") + std::to_string(it->v); }
			else { s_expr += (" | " + it->sign ? "b" : "!b") + std::to_string(it->v); }
		}
		if (exprs.find(s_expr) != exprs.end()) {
			// the expression already exists..
			return exprs.at(s_expr);
		}
		else {
			// we need to create a new variable..
			var d = new_var();
			std::vector<lit> lits;
			lits.push_back(lit(d, false));
			bool nc;
			for (const auto& l : ls) {
				nc = new_clause({ !l, lit(d, true) });
				assert(nc);
				lits.push_back(l);
			}
			nc = new_clause(lits);
			assert(nc);
			exprs.insert({ s_expr, d });
			return d;
		}
	}

	var sat_core::new_exct_one(const std::vector<lit>& ls) {
		std::vector<lit> c_lits = ls;
		std::sort(c_lits.begin(), c_lits.end(), [](const lit& l0, const lit & l1) { return l0.v > l1.v; });
		std::string s_expr;
		for (std::vector<lit>::const_iterator it = c_lits.begin(); it != c_lits.end(); ++it) {
			if (it == c_lits.begin()) { s_expr += (it->sign ? "b" : "!b") + std::to_string(it->v); }
			else { s_expr += (" ^ " + it->sign ? "b" : "!b") + std::to_string(it->v); }
		}
		if (exprs.find(s_expr) != exprs.end()) {
			// the expression already exists..
			return exprs.at(s_expr);
		}
		else {
			// we need to create a new variable..
			var eo = new_var();
			std::vector<lit> lits;
			lits.push_back(lit(eo, false));
			bool nc;
			for (size_t i = 0; i < ls.size(); i++) {
				for (size_t j = i + 1; j < ls.size(); j++) {
					nc = new_clause({ !ls[i], !ls[j], lit(eo, false) });
					assert(nc);
				}
				lits.push_back(ls[i]);
			}
			nc = new_clause(lits);
			assert(nc);
			exprs.insert({ s_expr, eo });
			return eo;
		}
	}

	bool sat_core::assume(const lit & p) {
		assert(assigns[p.v] == Undefined);
		trail_lim.push_back(p);
		for (const auto& th : theories) {
			th->push();
		}
		return enqueue(p);
	}

	void sat_core::pop() {
		while (trail_lim.back() != trail.back()) {
			pop_one();
		}
		pop_one();
		trail_lim.pop_back();
		for (const auto& th : theories) {
			th->pop();
		}
	}

	bool sat_core::check() {
		while (true) {
			std::vector<lit> cnfl;
			if (!propagate(cnfl)) {
				if (root_level()) {
					return false;
				}
				// we sort literals according to descending order of variable assignment..
				std::sort(cnfl.begin(), cnfl.end(), [&](lit& a, lit& b) { return level[a.v] > level[b.v]; });
				std::vector<lit> no_good;
				size_t bt_level;
				// we analyze the conflict..
				analyze(cnfl, no_good, bt_level);
				while (trail_lim.size() > bt_level) {
					pop();
				}
				// we record the no-good..
				record(no_good);
			}
			else {
				return true;
			}
		}
	}

	bool sat_core::check(const std::vector<lit>& lits) {
		size_t c_level = trail_lim.size();
		std::vector<lit> cnfl;
		for (const auto& p : lits) {
			if (!assume(p) || !propagate(cnfl)) {
				while (trail_lim.size() > c_level) {
					pop();
				}
				return false;
			}
		}
		while (trail_lim.size() > c_level) {
			pop();
		}
		return true;
	}

	bool sat_core::propagate(std::vector<lit>& cnfl) {
		while (!prop_q.empty()) {
			// we propagate sat constraints..
			std::vector<clause*> tmp = std::move(watches[index(prop_q.front())]);
			for (size_t i = 0; i < tmp.size(); i++) {
				if (!tmp[i]->propagate(prop_q.front())) {
					for (size_t j = i + 1; j < tmp.size(); j++) {
						watches[index(prop_q.front())].push_back(tmp[j]);
					}
					assert(std::count_if(tmp[i]->lits.begin(), tmp[i]->lits.end(), [&](const lit& p) { return std::find(watches[index(!p)].begin(), watches[index(!p)].end(), tmp[i]) != watches[index(!p)].end(); }) == 2);
					while (!prop_q.empty()) {
						prop_q.pop();
					}
					cnfl.insert(cnfl.begin(), tmp[i]->lits.begin(), tmp[i]->lits.end());
					return false;
				}
				assert(std::count_if(tmp[i]->lits.begin(), tmp[i]->lits.end(), [&](const lit& p) { return std::find(watches[index(!p)].begin(), watches[index(!p)].end(), tmp[i]) != watches[index(!p)].end(); }) == 2);
			}

			// we perform theory propagation..
			for (const auto& th : bounds[prop_q.front().v]) {
				if (!th->propagate(prop_q.front(), cnfl)) {
					assert(!cnfl.empty());
					while (!prop_q.empty()) {
						prop_q.pop();
					}
					return false;
				}
			}

			prop_q.pop();
		}

		// we check theories..
		for (const auto& th : theories) {
			if (!th->check(cnfl)) {
				assert(!cnfl.empty());
				return false;
			}
		}

		return true;
	}

	void sat_core::analyze(const std::vector<lit>& cnfl, std::vector<lit>& out_learnt, size_t& out_btlevel) {
		out_learnt.push_back(lit(0, false));
		out_btlevel = 0;
		lit p = trail_lim.back();
		if (trail_lim.back() == trail.back()) {
			// a theory generated the conflict as a direct consequence of last decision..
			for (const auto& q : cnfl) {
				if (p.v != q.v) {
					out_learnt.push_back(q);
					out_btlevel = std::max(out_btlevel, level[q.v]);
				}
			}
			out_learnt[0] = !p;
			return;
		}
		std::set<var> seen;
		std::vector<lit> p_reason = cnfl;
		int counter = 0;
		do {
			for (const auto& q : p_reason) {
				if (p.v != q.v && seen.find(q.v) == seen.end()) {
					seen.insert(q.v);
					if (level[q.v] == trail_lim.size()) {
						counter++;
					}
					else if (level[q.v] > 0) {
						out_learnt.push_back(q);
						out_btlevel = std::max(out_btlevel, level[q.v]);
					}
				}
			}
			do {
				p = trail.back();
				if (reason[p.v]) {
					p_reason = reason[p.v]->lits;
				}
				pop_one();
			} while (seen.find(p.v) == seen.end());
			counter--;
		} while (counter > 0);
		out_learnt[0] = !p;
	}

	void sat_core::record(const std::vector<lit>& lits) {
		assert(value(lits[0]) == Undefined);
		assert(std::count_if(lits.begin(), lits.end(), [&](const lit & p) { return value(p) == Undefined; }) == 1);
		assert(std::count_if(lits.begin(), lits.end(), [&](const lit & p) { return value(p) == False; }) == lits.size() - 1);
		if (lits.size() == 1) {
			assert(root_level());
			bool e = enqueue(lits[0]);
			assert(e);
		}
		else {
			constrs.push_back(new clause(*this, lits));
			bool e = enqueue(lits[0]);
			assert(e);
		}
	}

	bool sat_core::enqueue(const lit & p, clause * const c) {
		return false;
	}

	void sat_core::pop_one() {
		assigns[trail.back().v] = Undefined;
		reason[trail.back().v] = nullptr;
		level[trail.back().v] = 0;
		if (listening.find(trail.back().v) != listening.end()) {
			for (const auto& l : listening[trail.back().v]) {
				l->sat_value_change(trail.back().v);
			}
		}
		trail.pop_back();
	}

	void sat_core::add_theory(theory & th) {
		theories.push_back(&th);
	}

	void sat_core::remove_theory(theory & th) {
		const auto& it = std::find(theories.begin(), theories.end(), &th);
		if (it != theories.end()) {
			theories.erase(it);
			for (const auto& lo : th.listening_on) {
				unbind(lo, th);
			}
			th.listening_on.clear();
		}
	}

	void sat_core::bind(var v, theory & th) {
		bounds[v].push_back(&th);
	}

	void sat_core::unbind(var v, theory & th) {
		const auto& it = std::find(bounds[v].begin(), bounds[v].end(), &th);
		if (it != bounds[v].end()) {
			bounds[v].erase(it);
		}
	}

	void sat_core::listen(var v, sat_value_listener * const l) {
		listening[v].push_back(l);
	}

	void sat_core::forget(var v, sat_value_listener * const l) {
		listening.at(v).erase(std::find(listening.at(v).begin(), listening.at(v).end(), l));
		if (listening.at(v).empty()) {
			listening.erase(v);
		}
	}
}
