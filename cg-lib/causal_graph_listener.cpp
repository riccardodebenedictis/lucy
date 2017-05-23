#include "causal_graph_listener.h"
#include "causal_graph.h"


namespace cg {

	causal_graph_listener::causal_graph_listener(causal_graph& graph) : graph(graph) {
		graph.listeners.push_back(this);
	}

	causal_graph_listener::~causal_graph_listener() {
		graph.listeners.erase(std::find(graph.listeners.begin(), graph.listeners.end(), this));
	}

	void causal_graph_listener::new_flaw(const flaw& f) {
		flaw_listeners.insert({ &f, new flaw_listener(*this, f) });
		flaw_created(f);
	}

	void causal_graph_listener::new_resolver(const resolver& r) {
		resolver_listeners.insert({ &r, new resolver_listener(*this, r) });
		resolver_created(r);
	}

	causal_graph_listener::flaw_listener::flaw_listener(causal_graph_listener& listener, const flaw& f) : sat_value_listener(listener.get_graph().core::sat), listener(listener), f(f) { }

	causal_graph_listener::flaw_listener::~flaw_listener() { }

	void causal_graph_listener::flaw_listener::sat_value_change(var v) { listener.flaw_state_changed(f); }

	causal_graph_listener::resolver_listener::resolver_listener(causal_graph_listener& listener, const resolver& r) : sat_value_listener(listener.get_graph().core::sat), listener(listener), r(r) { }

	causal_graph_listener::resolver_listener::~resolver_listener() { }

	void causal_graph_listener::resolver_listener::sat_value_change(var v) { listener.resolver_state_changed(r); }
}