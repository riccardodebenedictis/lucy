#include "cg_listener.h"
#include "solver.h"
#include "flaw.h"
#include "resolver.h"
#include <algorithm>

namespace cg
{

cg_listener::cg_listener(solver &slv) : slv(slv)
{
    slv.listeners.push_back(this);
}

cg_listener::~cg_listener() { slv.listeners.erase(std::find(slv.listeners.begin(), slv.listeners.end(), this)); }

void cg_listener::new_flaw(const flaw &f)
{
    flaw_listeners.insert({&f, new flaw_listener(*this, f)});
    flaw_created(f);
}

void cg_listener::flaw_created(const flaw &) {}
void cg_listener::flaw_state_changed(const flaw &) {}
void cg_listener::current_flaw(const flaw &) {}

void cg_listener::new_resolver(const resolver &r)
{
    resolver_listeners.insert({&r, new resolver_listener(*this, r)});
    resolver_created(r);
}

void cg_listener::resolver_created(const resolver &) {}
void cg_listener::resolver_state_changed(const resolver &) {}
void cg_listener::resolver_cost_changed(const resolver &) {}
void cg_listener::current_resolver(const resolver &) {}

void cg_listener::causal_link_added(const flaw &, const resolver &) {}

std::string cg_listener::to_string() const
{
    std::string g;
    g += "{ ";
    if (!flaw_listeners.empty())
    {
        g += "\"flaws\" : [";
        for (std::unordered_map<const flaw *, cg_listener::flaw_listener *>::const_iterator fs_it = flaw_listeners.begin(); fs_it != flaw_listeners.end(); ++fs_it)
        {
            if (fs_it != flaw_listeners.begin())
                g += ", ";
            g += "{ \"id\" : \"" + std::to_string(reinterpret_cast<uintptr_t>(fs_it->first)) + "\", \"label\" : \"" + fs_it->first->get_label() + "\", \"phi_var\" : \"b" + std::to_string(fs_it->first->get_phi()) + "\", \"phi_val\" : ";
            switch (slv.sat_cr.value(fs_it->first->get_phi()))
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
            if (!fs_it->first->get_cost().is_positive_infinite())
                g += ", \"cost\" : " + fs_it->first->get_cost().to_string();
            g += " }";
        }
        g += "]";
    }
    if (!resolver_listeners.empty())
    {
        if (!flaw_listeners.empty())
            g += ", ";
        g += "\"resolvers\" : [";
        for (std::unordered_map<const resolver *, cg_listener::resolver_listener *>::const_iterator rs_it = resolver_listeners.begin(); rs_it != resolver_listeners.end(); ++rs_it)
        {
            if (rs_it != resolver_listeners.begin())
                g += ", ";
            g += "{ \"id\" : \"" + std::to_string(reinterpret_cast<uintptr_t>(rs_it->first)) + "\", \"label\" : \"" + rs_it->first->get_label() + "\", \"rho_var\" : \"b" + std::to_string(rs_it->first->get_rho()) + "\", \"rho_val\" : ";
            switch (slv.sat_cr.value(rs_it->first->get_rho()))
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
            if (!rs_it->first->get_cost().is_positive_infinite())
                g += ", \"cost\" : " + rs_it->first->get_cost().to_string();
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

cg_listener::flaw_listener::flaw_listener(cg_listener &listener, const flaw &f) : sat_value_listener(listener.slv.sat_cr), listener(listener), f(f) { listen_sat(f.get_phi()); }
cg_listener::flaw_listener::~flaw_listener() {}
void cg_listener::flaw_listener::sat_value_change(const var &) { listener.flaw_state_changed(f); }

cg_listener::resolver_listener::resolver_listener(cg_listener &listener, const resolver &r) : sat_value_listener(listener.slv.sat_cr), listener(listener), r(r) { listen_sat(r.get_rho()); }
cg_listener::resolver_listener::~resolver_listener() {}
void cg_listener::resolver_listener::sat_value_change(const var &) { listener.resolver_state_changed(r); }
}