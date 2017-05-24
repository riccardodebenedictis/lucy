#pragma once

#include "causal_graph_listener.h"

namespace cg {

	namespace gui {

		class vtk_graph : public causal_graph_listener {
		public:
			vtk_graph(causal_graph& graph);
			virtual ~vtk_graph();

		private:
			void flaw_created(const flaw& f) override;
			void flaw_state_changed(const flaw& f) override;
			void flaw_cost_changed(const flaw& f) override;
			void current_flaw(const flaw& f) override;

			void resolver_created(const resolver& r) override;
			void resolver_state_changed(const resolver& r) override;
			void current_resolver(const resolver& r) override;

			void causal_link_added(const flaw& f, const resolver& r) override;
		};
	}
}