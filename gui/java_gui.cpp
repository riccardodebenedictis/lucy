#include "java_gui.h"

#include "cg_java_listener.h"
#include "solver.h"
#include "flaw.h"
#include "resolver.h"

namespace gui
{
java_gui::java_gui()
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

    jclass cg_cls = env->FindClass("CausalGraph");
    jmethodID cg_cstr = env->GetMethodID(cg_cls, "<init>", "()V");
    cg_object = env->NewObject(cg_cls, cg_cstr);
    f_created = env->GetMethodID(cg_cls, "flaw_created", "(J[JLjava/lang/String;I)V");
    f_state_changed = env->GetMethodID(cg_cls, "flaw_state_changed", "(JI)V");
    c_flaw = env->GetMethodID(cg_cls, "current_flaw", "(J)V");
    r_created = env->GetMethodID(cg_cls, "resolver_created", "(JJLjava/lang/String;DI)V");
    r_cost_changed = env->GetMethodID(cg_cls, "resolver_cost_changed", "(JD)V");
    r_state_changed = env->GetMethodID(cg_cls, "resolver_state_changed", "(JI)V");
    c_resolver = env->GetMethodID(cg_cls, "current_resolver", "(J)V");
    c_link_added = env->GetMethodID(cg_cls, "causal_link_added", "(JJ)V");
}

java_gui::~java_gui() { jvm->DestroyJavaVM(); }
}