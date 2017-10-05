#include "cg_java_listener.h"
#include "java_gui.h"
#include "solver.h"
#include "flaw.h"
#include "resolver.h"

namespace gui
{
cg_java_listener::cg_java_listener(cg::solver &slv, java_gui &gui) : cg_listener(slv), gui(gui) {}
cg_java_listener::~cg_java_listener() {}

void cg_java_listener::flaw_created(const cg::flaw &f)
{
    std::vector<cg::resolver *> causes = f.get_causes();
    jlongArray causes_array = gui.env->NewLongArray(causes.size());
    jlong *cause = gui.env->GetLongArrayElements(causes_array, NULL);
    for (size_t i = 0; i < causes.size(); i++)
        cause[i] = reinterpret_cast<jlong>(causes[i]);
    gui.env->ReleaseLongArrayElements(causes_array, cause, 0);

    gui.env->CallVoidMethod(gui.cg_object, gui.f_created, reinterpret_cast<jlong>(&f), causes_array, gui.env->NewStringUTF(f.get_label().c_str()), slv.sat_cr.value(f.get_phi()));
}
void cg_java_listener::flaw_state_changed(const cg::flaw &f) { gui.env->CallVoidMethod(gui.cg_object, gui.f_state_changed, reinterpret_cast<jlong>(&f), slv.sat_cr.value(f.get_phi())); }
void cg_java_listener::current_flaw(const cg::flaw &f) { gui.env->CallVoidMethod(gui.cg_object, gui.c_flaw, reinterpret_cast<jlong>(&f)); }

void cg_java_listener::resolver_created(const cg::resolver &r) { gui.env->CallVoidMethod(gui.cg_object, gui.r_created, reinterpret_cast<jlong>(&r), reinterpret_cast<jlong>(&r.get_effect()), gui.env->NewStringUTF(r.get_label().c_str()), r.get_cost(), slv.sat_cr.value(r.get_rho())); }
void cg_java_listener::resolver_state_changed(const cg::resolver &r) { gui.env->CallVoidMethod(gui.cg_object, gui.r_state_changed, reinterpret_cast<jlong>(&r), slv.sat_cr.value(r.get_rho())); }
void cg_java_listener::resolver_cost_changed(const cg::resolver &r) { gui.env->CallVoidMethod(gui.cg_object, gui.r_cost_changed, reinterpret_cast<jlong>(&r), r.get_cost()); }
void cg_java_listener::current_resolver(const cg::resolver &r) { gui.env->CallVoidMethod(gui.cg_object, gui.c_resolver, reinterpret_cast<jlong>(&r)); }

void cg_java_listener::causal_link_added(const cg::flaw &f, const cg::resolver &r) { gui.env->CallVoidMethod(gui.cg_object, gui.c_link_added, reinterpret_cast<jlong>(&f), reinterpret_cast<jlong>(&r)); }
}