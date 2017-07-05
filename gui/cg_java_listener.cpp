#include "cg_java_listener.h"
#include "causal_graph.h"
#include "flaw.h"
#include "resolver.h"

namespace gui
{
cg_java_listener::cg_java_listener(cg::causal_graph &graph) : causal_graph_listener(graph)
{
    JavaVMInitArgs vm_args;
    JavaVMOption *options = new JavaVMOption[1];
#ifdef _WIN32
    options[0].optionString = (char *)"-Djava.class.path=./lucy_gui.jar;./prefuse.jar";
#else
    options[0].optionString = (char *)"-Djava.class.path=./lucy_gui.jar:./prefuse.jar";
#endif
    options[1].optionString = (char *)"-ea";
    vm_args.version = JNI_VERSION_1_8;
    vm_args.nOptions = 2;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = false;
    JNI_CreateJavaVM(&jvm, (void **)&env, &vm_args);
    jclass cls = env->FindClass("CausalGraph");
    jmethodID cstr = env->GetMethodID(cls, "<init>", "()V");
    cg_object = env->NewObject(cls, cstr);
    f_created = env->GetMethodID(cls, "flaw_created", "(J[JLjava/lang/String;DI)V");
    f_state_changed = env->GetMethodID(cls, "flaw_state_changed", "(JI)V");
    f_cost_changed = env->GetMethodID(cls, "flaw_cost_changed", "(JD)V");
    c_flaw = env->GetMethodID(cls, "current_flaw", "(J)V");
    r_created = env->GetMethodID(cls, "resolver_created", "(JJLjava/lang/String;I)V");
    r_state_changed = env->GetMethodID(cls, "resolver_state_changed", "(JI)V");
    c_resolver = env->GetMethodID(cls, "current_resolver", "(J)V");
    c_link_added = env->GetMethodID(cls, "causal_link_added", "(JJ)V");
}

cg_java_listener::~cg_java_listener() { jvm->DestroyJavaVM(); }

void cg_java_listener::flaw_created(const cg::flaw &f)
{
    std::vector<cg::resolver *> causes = f.get_causes();
    jlongArray causes_array = env->NewLongArray(causes.size());
    jlong *cause = env->GetLongArrayElements(causes_array, NULL);
    for (size_t i = 0; i < causes.size(); i++)
        cause[i] = reinterpret_cast<jlong>(causes[i]);
    env->ReleaseLongArrayElements(causes_array, cause, 0);

    env->CallVoidMethod(cg_object, f_created, reinterpret_cast<jlong>(&f), causes_array, env->NewStringUTF(f.get_label().c_str()), f.get_cost(), graph.core::sat.value(f.get_in_plan()));
}
void cg_java_listener::flaw_state_changed(const cg::flaw &f) { env->CallVoidMethod(cg_object, f_state_changed, reinterpret_cast<jlong>(&f), graph.core::sat.value(f.get_in_plan())); }
void cg_java_listener::flaw_cost_changed(const cg::flaw &f) { env->CallVoidMethod(cg_object, f_cost_changed, reinterpret_cast<jlong>(&f), f.get_cost()); }
void cg_java_listener::current_flaw(const cg::flaw &f) { env->CallVoidMethod(cg_object, c_flaw, reinterpret_cast<jlong>(&f)); }

void cg_java_listener::resolver_created(const cg::resolver &r) { env->CallVoidMethod(cg_object, r_created, reinterpret_cast<jlong>(&r), reinterpret_cast<jlong>(&r.get_effect()), env->NewStringUTF(r.get_label().c_str()), graph.core::sat.value(r.get_chosen())); }
void cg_java_listener::resolver_state_changed(const cg::resolver &r) { env->CallVoidMethod(cg_object, r_state_changed, reinterpret_cast<jlong>(&r), graph.core::sat.value(r.get_chosen())); }
void cg_java_listener::current_resolver(const cg::resolver &r) { env->CallVoidMethod(cg_object, c_resolver, reinterpret_cast<jlong>(&r)); }

void cg_java_listener::causal_link_added(const cg::flaw &f, const cg::resolver &r) { env->CallVoidMethod(cg_object, c_link_added, reinterpret_cast<jlong>(&f), reinterpret_cast<jlong>(&r)); }
}