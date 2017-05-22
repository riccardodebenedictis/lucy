#include "core.h"
#include "predicate.h"
#include "atom.h"
#include "method.h"
#include "field.h"
#include <iostream>
#include <cassert>

namespace lucy {

	core::core() : scope(*this, *this), env(*this, this), sat(), la(sat), set(sat) {
		types.insert({ BOOL_KEYWORD, new bool_type(*this) });
		types.insert({ INT_KEYWORD, new int_type(*this) });
		types.insert({ REAL_KEYWORD, new real_type(*this) });
		types.insert({ STRING_KEYWORD, new string_type(*this) });
	}

	core::~core() {
		/*for (const auto& p : parsers) {
			delete p;
		}*/
		for (const auto& p : predicates) {
			delete p.second;
		}
		for (const auto& t : types) {
			delete t.second;
		}
		for (const auto& ms : methods) {
			for (const auto& m : ms.second) {
				delete m;
			}
		}
	}

	bool core::read(const std::string & script) {
		return false;
	}

	bool core::read(const std::vector<std::string>& files) {
		return false;
	}

	bool_expr core::new_bool() {
		return new bool_item(*this, smt::lit(sat.new_var(), true));
	}

	bool_expr core::new_bool(const bool& val) {
		return new bool_item(*this, smt::lit(val, true));
	}

	arith_expr core::new_int() {
		std::cerr << "[warning] replacing an integer variable with a real variable.." << std::endl;
		return new arith_item(*this, *types.at(REAL_KEYWORD), smt::lin(la.new_var(), 1));
	}

	arith_expr core::new_int(const long& val) {
		return new arith_item(*this, *types.at(REAL_KEYWORD), smt::lin(val));
	}

	arith_expr core::new_real() {
		return new arith_item(*this, *types.at(REAL_KEYWORD), smt::lin(la.new_var(), 1));
	}

	arith_expr core::new_real(const double& val) {
		return new arith_item(*this, *types.at(REAL_KEYWORD), smt::lin(val));
	}

	string_expr core::new_string() {
		return new string_item(*this, "");
	}

	string_expr core::new_string(const std::string& val) {
		return new string_item(*this, val);
	}

	expr core::new_enum(const type& t, const std::unordered_set<item*>& allowed_vals) {
		std::unordered_set<smt::set_item*> vals(allowed_vals.begin(), allowed_vals.end());
		if (t.name.compare(BOOL_KEYWORD) == 0) {
			bool_expr b = new_bool();
			std::vector<smt::lit> eqs;
			for (const auto& v : allowed_vals) {
				eqs.push_back(smt::lit(sat.new_eq(b->l, dynamic_cast<bool_item*> (v)->l), true));
			}
			bool nc = sat.new_clause(eqs);
			assert(nc);
			return b;
		}
		else if (t.name.compare(INT_KEYWORD) == 0) {
			arith_expr i = new_int();
			std::vector<smt::lit> eqs;
			for (const auto& v : allowed_vals) {
				smt::var leq_v = la.new_leq(i->l, dynamic_cast<arith_item*> (v)->l);
				smt::var geq_v = la.new_geq(i->l, dynamic_cast<arith_item*> (v)->l);
				smt::var eq_v = sat.new_conj({ smt::lit(leq_v, true), smt::lit(geq_v, true) });
				eqs.push_back(smt::lit(eq_v, true));
			}
			bool nc = sat.new_clause(eqs);
			assert(nc);
			return i;
		}
		else if (t.name.compare(REAL_KEYWORD) == 0) {
			arith_expr r = new_real();
			std::vector<smt::lit> eqs;
			for (const auto& v : allowed_vals) {
				smt::var leq_v = la.new_leq(r->l, dynamic_cast<arith_item*> (v)->l);
				smt::var geq_v = la.new_geq(r->l, dynamic_cast<arith_item*> (v)->l);
				smt::var eq_v = sat.new_conj({ smt::lit(leq_v, true), smt::lit(geq_v, true) });
				eqs.push_back(smt::lit(eq_v, true));
			}
			bool nc = sat.new_clause(eqs);
			assert(nc);
			return r;
		}
		else {
			return new enum_item(*this, t, set.new_var(vals));
		}
	}

	bool_expr core::negate(bool_expr var) {
		return new bool_item(*this, !var->l);
	}

	bool_expr core::eq(bool_expr left, bool_expr right) {
		return new bool_item(*this, smt::lit(sat.new_eq(left->l, right->l), true));
	}

	bool_expr core::conj(const std::vector<bool_expr>& exprs) {
		std::vector<smt::lit> lits;
		for (const auto& bex : exprs) {
			lits.push_back(bex->l);
		}
		return new bool_item(*this, smt::lit(sat.new_conj(lits), true));
	}

	bool_expr core::disj(const std::vector<bool_expr>& exprs) {
		std::vector<smt::lit> lits;
		for (const auto& bex : exprs) {
			lits.push_back(bex->l);
		}
		return new bool_item(*this, smt::lit(sat.new_disj(lits), true));
	}

	bool_expr core::exct_one(const std::vector<bool_expr>& exprs) {
		std::vector<smt::lit> lits;
		for (const auto& bex : exprs) {
			lits.push_back(bex->l);
		}
		return new bool_item(*this, smt::lit(sat.new_exct_one(lits), true));
	}

	arith_expr core::add(const std::vector<arith_expr>& exprs) {
		smt::lin l;
		for (const auto& aex : exprs) {
			l += aex->l;
		}
		return new arith_item(*this, *types.at(REAL_KEYWORD), l);
	}

	arith_expr core::sub(const std::vector<arith_expr>& exprs) {
		smt::lin l;
		for (std::vector<arith_expr>::const_iterator it = exprs.begin(); it != exprs.end(); ++it) {
			if (it == exprs.begin()) {
				l += (*it)->l;
			}
			else {
				l -= (*it)->l;
			}
		}
		return new arith_item(*this, *types.at(REAL_KEYWORD), l);
	}

	arith_expr core::mult(const std::vector<arith_expr>& exprs) {
		arith_expr ae = *std::find_if(exprs.begin(), exprs.end(), [&](arith_expr ae) { return la.bounds(ae->l).constant(); });
		smt::lin l = ae->l;
		for (const auto& aex : exprs) {
			if (aex != ae) {
				assert(la.bounds(aex->l).constant() && "non-linear expression..");
				l *= la.value(aex->l);
			}
		}
		return new arith_item(*this, *types.at(REAL_KEYWORD), l);
	}

	arith_expr core::div(arith_expr left, arith_expr right) {
		assert(la.bounds(right->l).constant() && "non-linear expression..");
		return new arith_item(*this, *types.at(REAL_KEYWORD), left->l / la.value(right->l));
	}

	arith_expr core::minus(arith_expr ex) {
		return new arith_item(*this, *types.at(REAL_KEYWORD), -ex->l);
	}

	bool_expr core::lt(arith_expr left, arith_expr right) {
		std::cerr << "[warning] replacing strict inequality (<) with non-strict inequality (<=).." << std::endl;
		return new bool_item(*this, smt::lit(la.new_leq(left->l, right->l), true));
	}

	bool_expr core::leq(arith_expr left, arith_expr right) {
		return new bool_item(*this, smt::lit(la.new_leq(left->l, right->l), true));
	}

	bool_expr core::eq(arith_expr left, arith_expr right) {
		return new bool_item(*this, smt::lit(sat.new_conj({ smt::lit(la.new_leq(left->l, right->l), true), smt::lit(la.new_geq(left->l, right->l), true) }), true));
	}

	bool_expr core::geq(arith_expr left, arith_expr right) {
		return new bool_item(*this, smt::lit(la.new_geq(left->l, right->l), true));
	}

	bool_expr core::gt(arith_expr left, arith_expr right) {
		std::cerr << "[warning] replacing strict inequality (>) with non-strict inequality (>=).." << std::endl;
		return new bool_item(*this, smt::lit(la.new_geq(left->l, right->l), true));
	}

	bool_expr core::eq(expr left, expr right) {
		return new bool_item(*this, smt::lit(left->eq(*right), true));
	}

	bool core::assert_facts(const std::vector<smt::lit>& facts) {
		for (const auto& f : facts) {
			if (!sat.new_clause({ smt::lit(ctr_var, false), f })) {
				return false;
			}
		}
		return true;
	}

	field& core::get_field(const std::string& name) const {
		if (fields.find(name) != fields.end()) {
			return *fields.at(name);
		}

		// not found
		throw std::out_of_range(name);
	}

	method& core::get_method(const std::string& name, const std::vector<const type*>& ts) const {
		if (methods.find(name) != methods.end()) {
			bool found = false;
			for (const auto& mthd : methods.at(name)) {
				if (mthd->args.size() == ts.size()) {
					found = true;
					for (size_t i = 0; i < ts.size(); i++) {
						if (!mthd->args[i]->tp.is_assignable_from(*ts[i])) {
							found = false;
							break;
						}
					}
					if (found) {
						return *mthd;
					}
				}
			}
		}

		// not found
		throw std::out_of_range(name);
	}

	predicate& core::get_predicate(const std::string& name) const {
		if (predicates.find(name) != predicates.end()) {
			return *predicates.at(name);
		}

		// not found
		throw std::out_of_range(name);
	}

	type& core::get_type(const std::string& name) const {
		if (types.find(name) != types.end()) {
			return *types.at(name);
		}

		// not found
		throw std::out_of_range(name);
	}

	expr core::get(const std::string& name) const {
		if (items.find(name) != items.end()) {
			return items.at(name);
		}

		throw std::out_of_range(name);
	}

	smt::lbool core::bool_value(const bool_expr& var) const noexcept { return sat.value(var->l); }

	smt::interval core::arith_bounds(const arith_expr& var) const noexcept { return la.bounds(var->l); }

	double core::arith_value(const arith_expr& var) const noexcept { return la.value(var->l); }

	std::unordered_set<smt::set_item*> core::enum_value(const enum_expr& var) const noexcept { return set.value(var->ev); }

}