#include "cg_java_listener.h"

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
    vm_args.version = JNI_VERSION_1_8;
    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = false;
    JNI_CreateJavaVM(&jvm, (void **)&env, &vm_args);
    jclass cls = env->FindClass("CausalGraph");
    jmethodID cstr = env->GetMethodID(cls, "<init>", "()V");
    cg_object = env->NewObject(cls, cstr);
    env->CallVoidMethod(cg_object, env->GetMethodID(cls, "init", "()V"));
    f_created = env->GetMethodID(cls, "flaw_created", "(J)V");
    f_state_changed = env->GetMethodID(cls, "flaw_state_changed", "(J)V");
    f_cost_changed = env->GetMethodID(cls, "flaw_cost_changed", "(J)V");
}

cg_java_listener::~cg_java_listener() { jvm->DestroyJavaVM(); }

void cg_java_listener::attach() { jvm->AttachCurrentThread((void **)&env, NULL); }
void cg_java_listener::detach() { jvm->DetachCurrentThread(); }

void cg_java_listener::flaw_created(const cg::flaw &f)
{
    env->CallVoidMethod(cg_object, f_created, reinterpret_cast<jlong>(&f));
}
void cg_java_listener::flaw_state_changed(const cg::flaw &f) {}
void cg_java_listener::flaw_cost_changed(const cg::flaw &f) {}
void cg_java_listener::current_flaw(const cg::flaw &f) {}

void cg_java_listener::resolver_created(const cg::resolver &r) {}
void cg_java_listener::resolver_state_changed(const cg::resolver &r) {}
void cg_java_listener::current_resolver(const cg::resolver &r) {}

void cg_java_listener::causal_link_added(const cg::flaw &f, const cg::resolver &r) {}
}