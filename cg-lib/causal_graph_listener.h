#pragma once

#include "sat_value_listener.h"

using namespace smt;

namespace cg {

	class causal_graph;
	class flaw;
	class resolver;

	class causal_graph_listener {
		friend class causal_graph;
	public:
		causal_graph_listener(causal_graph& g);
		causal_graph_listener(const causal_graph_listener& orig) = delete;
		virtual ~causal_graph_listener();

		causal_graph& get_graph() const { return graph; }

	private:
		void new_flaw(const flaw& f);

		virtual void flaw_created(const flaw& f) {}
		virtual void flaw_state_changed(const flaw& f) {}
		virtual void flaw_cost_changed(const flaw& f) {}
		virtual void current_flaw(const flaw& f) {}

		void new_resolver(const resolver& r);

		virtual void resolver_created(const resolver& r) {}
		virtual void resolver_state_changed(const resolver& r) {}
		virtual void current_resolver(const resolver& r) {}

		virtual void causal_link_added(const flaw& f, const resolver& r) { }

		class flaw_listener : public sat_value_listener {
		public:
			flaw_listener(causal_graph_listener& l, const flaw& f);
			flaw_listener(const flaw_listener& orig) = delete;
			virtual ~flaw_listener();

		private:
			void sat_value_change(var v) override;

		protected:
			causal_graph_listener& listener;
			const flaw& f;
		};

		class resolver_listener : public sat_value_listener {
		public:
			resolver_listener(causal_graph_listener& l, const resolver& r);
			resolver_listener(const resolver_listener& orig) = delete;
			virtual ~resolver_listener();

		private:
			void sat_value_change(var v) override;

		protected:
			causal_graph_listener& listener;
			const resolver& r;
		};

	protected:
		causal_graph& graph;

	private:
		std::unordered_map<const flaw*, flaw_listener*> flaw_listeners;
		std::unordered_map<const resolver*, resolver_listener*> resolver_listeners;
	};
}