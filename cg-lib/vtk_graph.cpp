#include "vtk_graph.h"
#include "vtkCylinderSource.h"

namespace cg {

	namespace gui {

		vtk_graph::vtk_graph(causal_graph& graph) : causal_graph_listener(graph) {
			vtkCylinderSource* cylinder = vtkCylinderSource::New();
		}

		vtk_graph::~vtk_graph() { }

		void vtk_graph::flaw_created(const flaw & f) {
		}

		void vtk_graph::flaw_state_changed(const flaw & f) {
		}

		void vtk_graph::flaw_cost_changed(const flaw & f) {
		}

		void vtk_graph::current_flaw(const flaw & f) {
		}

		void vtk_graph::resolver_created(const resolver & r) {
		}

		void vtk_graph::resolver_state_changed(const resolver & r) {
		}

		void vtk_graph::current_resolver(const resolver & r) {
		}

		void vtk_graph::causal_link_added(const flaw & f, const resolver & r) {
		}
	}
}