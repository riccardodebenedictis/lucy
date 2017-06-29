#include "causal_graph_listener.h"
#include "causal_graph.h"
#include "flaw.h"
#include "resolver.h"
#include "log.h"
#include <algorithm>

#define GRAPH_FILE "graph.json"

namespace cg
{

causal_graph_listener::causal_graph_listener(causal_graph &graph) : graph(graph)
{
    graph.listeners.push_back(this);
    WRITE(GRAPH_FILE, to_string());
#ifndef NDEBUG
    JavaVMInitArgs vm_args;
    JavaVMOption *options = new JavaVMOption[1];
    options[0].optionString = "-Djava.class.path=.";
    vm_args.version = JNI_VERSION_1_6;
    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = false;
    JNI_CreateJavaVM(&jvm, (void **)&env, &vm_args);
#endif
}

causal_graph_listener::~causal_graph_listener() { graph.listeners.erase(std::find(graph.listeners.begin(), graph.listeners.end(), this)); }

void causal_graph_listener::new_flaw(const flaw &f)
{
    flaw_listeners.insert({&f, new flaw_listener(*this, f)});
    flaw_created(f);
}

void causal_graph_listener::flaw_created(const flaw &f) { WRITE(GRAPH_FILE, to_string()); }
void causal_graph_listener::flaw_state_changed(const flaw &f) { WRITE(GRAPH_FILE, to_string()); }
void causal_graph_listener::flaw_cost_changed(const flaw &f) { WRITE(GRAPH_FILE, to_string()); }
void causal_graph_listener::current_flaw(const flaw &f) { WRITE(GRAPH_FILE, to_string()); }

void causal_graph_listener::new_resolver(const resolver &r)
{
    resolver_listeners.insert({&r, new resolver_listener(*this, r)});
    resolver_created(r);
}

void causal_graph_listener::resolver_created(const resolver &r) { WRITE(GRAPH_FILE, to_string()); }
void causal_graph_listener::resolver_state_changed(const resolver &r) { WRITE(GRAPH_FILE, to_string()); }
void causal_graph_listener::current_resolver(const resolver &r) { WRITE(GRAPH_FILE, to_string()); }

void causal_graph_listener::causal_link_added(const flaw &f, const resolver &r) { WRITE(GRAPH_FILE, to_string()); }

std::string causal_graph_listener::to_string()
{
    std::string g;
    g += "{ ";
    if (!flaw_listeners.empty())
    {
        g += "\"flaws\" : [";
        for (std::unordered_map<const flaw *, causal_graph_listener::flaw_listener *>::const_iterator fs_it = flaw_listeners.begin(); fs_it != flaw_listeners.end(); ++fs_it)
        {
            if (fs_it != flaw_listeners.begin())
                g += ", ";
            g += "{ \"id\" : \"" + std::to_string(reinterpret_cast<uintptr_t>(fs_it->first)) + "\", \"label\" : \"" + fs_it->first->get_label() + "\", \"in_plan_var\" : \"b" + std::to_string(fs_it->first->get_in_plan()) + "\", \"in_plan_val\" : ";
            switch (graph.core::sat.value(fs_it->first->get_in_plan()))
            {
            case True:
                g += "\"True\"";
                break;
            case False:
                g += "\"False\"";
                break;
            case Undefined:
                g += "\"Undefined\"";
                break;
            }
            if (fs_it->first->get_cost() < std::numeric_limits<double>::infinity())
                g += ", \"cost\" : " + std::to_string(fs_it->first->get_cost());
            g += " }";
        }
        g += "]";
    }
    if (!resolver_listeners.empty())
    {
        if (!flaw_listeners.empty())
            g += ", ";
        g += "\"resolvers\" : [";
        for (std::unordered_map<const resolver *, causal_graph_listener::resolver_listener *>::const_iterator rs_it = resolver_listeners.begin(); rs_it != resolver_listeners.end(); ++rs_it)
        {
            if (rs_it != resolver_listeners.begin())
                g += ", ";
            g += "{ \"id\" : \"" + std::to_string(reinterpret_cast<uintptr_t>(rs_it->first)) + "\", \"label\" : \"" + rs_it->first->get_label() + "\", \"chosen_var\" : \"b" + std::to_string(rs_it->first->get_chosen()) + "\", \"chosen_val\" : ";
            switch (graph.core::sat.value(rs_it->first->get_chosen()))
            {
            case True:
                g += "\"True\"";
                break;
            case False:
                g += "\"False\"";
                break;
            case Undefined:
                g += "\"Undefined\"";
                break;
            }
            if (rs_it->first->get_cost() < std::numeric_limits<double>::infinity())
                g += ", \"cost\" : " + std::to_string(rs_it->first->get_cost());
            g += ", \"solves\" : \"" + std::to_string(reinterpret_cast<uintptr_t>(&rs_it->first->get_effect())) + "\"";
            std::vector<flaw *> pres = rs_it->first->get_preconditions();
            if (!pres.empty())
            {
                g += ", \"preconditions\" : [";
                for (std::vector<flaw *>::const_iterator cs_it = pres.begin(); cs_it != pres.end(); ++cs_it)
                {
                    if (cs_it != pres.begin())
                        g += ", ";
                    g += "\"" + std::to_string(reinterpret_cast<uintptr_t>(*cs_it)) + "\"";
                }
                g += "]";
            }
            g += " }";
        }
        g += "]";
    }
    g += " }";
    return g;
}

causal_graph_listener::flaw_listener::flaw_listener(causal_graph_listener &listener, const flaw &f) : sat_value_listener(listener.get_graph().core::sat), listener(listener), f(f) {}
causal_graph_listener::flaw_listener::~flaw_listener() {}
void causal_graph_listener::flaw_listener::sat_value_change(var v) { listener.flaw_state_changed(f); }

causal_graph_listener::resolver_listener::resolver_listener(causal_graph_listener &listener, const resolver &r) : sat_value_listener(listener.get_graph().core::sat), listener(listener), r(r) {}
causal_graph_listener::resolver_listener::~resolver_listener() {}
void causal_graph_listener::resolver_listener::sat_value_change(var v) { listener.resolver_state_changed(r); }
}