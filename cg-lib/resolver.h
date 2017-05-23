#pragma once

#include "la_theory.h"

using namespace smt;

namespace cg {

	class resolver {
		friend class causal_graph;
		friend class flaw;
	public:
		resolver(causal_graph& graph, const lin& cost, flaw& eff);
		resolver(const resolver& orig) = delete;
		virtual ~resolver();

		virtual bool apply() = 0;

		smt::var get_chosen() const { return chosen; }
		flaw& get_effect() const { return effect; }
		std::vector<flaw*> get_preconditions() const { return preconditions; }
		double get_cost() const;

		virtual std::string get_label() const;

	protected:
		causal_graph& graph;
		var chosen;
		lin cost;
		// the preconditions of this resolver..
		std::vector<flaw*> preconditions;
		// the flaw solved by this resolver..
		flaw& effect;
	};
}