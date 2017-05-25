#include "vtk_graph.h"
#include "vtkGraphLayoutView.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkCircularLayoutStrategy.h"

namespace cg
{

namespace gui
{

vtk_graph::vtk_graph(causal_graph &graph) : causal_graph_listener(graph), g(vtkSmartPointer<vtkMutableDirectedGraph>::New())
{
    // Create 3 vertices
    vtkIdType v1 = g->AddVertex();
    vtkIdType v2 = g->AddVertex();
    vtkIdType v3 = g->AddVertex();
    vtkIdType v4 = g->AddVertex();

    // Create a fully connected graph
    vtkEdgeType e1 = g->AddEdge(v1, v2);
    vtkEdgeType e2 = g->AddEdge(v2, v3);
    vtkEdgeType e3 = g->AddEdge(v1, v3);

    vtkSmartPointer<vtkCircularLayoutStrategy> circularLayoutStrategy = vtkSmartPointer<vtkCircularLayoutStrategy>::New();

    vtkSmartPointer<vtkGraphLayoutView> graphLayoutView = vtkSmartPointer<vtkGraphLayoutView>::New();
    graphLayoutView->AddRepresentationFromInput(g);
    graphLayoutView->SetLayoutStrategy(circularLayoutStrategy);
    graphLayoutView->ResetCamera();
    graphLayoutView->Render();
    graphLayoutView->GetInteractor()->Start();
}

vtk_graph::~vtk_graph() {}

void vtk_graph::flaw_created(const flaw &f)
{
}

void vtk_graph::flaw_state_changed(const flaw &f)
{
}

void vtk_graph::flaw_cost_changed(const flaw &f)
{
}

void vtk_graph::current_flaw(const flaw &f)
{
}

void vtk_graph::resolver_created(const resolver &r)
{
}

void vtk_graph::resolver_state_changed(const resolver &r)
{
}

void vtk_graph::current_resolver(const resolver &r)
{
}

void vtk_graph::causal_link_added(const flaw &f, const resolver &r)
{
}
}
}