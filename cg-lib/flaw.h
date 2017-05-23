#pragma once

#include "la_theory.h"

using namespace smt;

namespace cg {

	class flaw {
		friend class causal_graph;
		friend class resolver;
	public:
		flaw(causal_graph& graph, bool disjunctive = false);
		flaw(const flaw& orig) = delete;
		virtual ~flaw();

		bool is_expanded() const { return expanded; }
		bool is_initialized() const { return initialized; }
		smt::var get_in_plan() const { return in_plan; }
		std::vector<resolver*> get_causes() const { return causes; }
		double get_cost() const { return cost; }

		virtual std::string get_label() const;

	private:
		virtual void init();
		bool expand();
		virtual void compute_resolvers() = 0;
		bool has_subgoals();

	protected:
		void add_resolver(resolver& r);

	protected:
		causal_graph& graph;

	private:
		const bool exclusive;
		bool initialized = false;
		bool expanded = false;
		var in_plan;
		// the resolvers for this flaw..
		std::vector<resolver*> resolvers;
		// the causes for having this flaw..
		std::vector<resolver*> causes;
		// the resolvers supported by this flaw..
		std::vector<resolver*> supports;
		double cost = std::numeric_limits<double>::infinity();
	};
}