#include "java_gui.h"

#include "cg_java_listener.h"
#include "causal_graph.h"
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

    jclass lbool_class = env->FindClass("SATCore$LBool");
    false_obj = env->GetStaticObjectField(lbool_class, env->GetStaticFieldID(lbool_class, "False", "LSATCore$LBool;"));
    true_obj = env->GetStaticObjectField(lbool_class, env->GetStaticFieldID(lbool_class, "True", "LSATCore$LBool;"));
    undefined_obj = env->GetStaticObjectField(lbool_class, env->GetStaticFieldID(lbool_class, "Undefined", "LSATCore$LBool;"));

    lit_cls = static_cast<jclass>(env->NewGlobalRef(env->FindClass("SATCore$Lit")));
    lit_cstr = env->GetMethodID(lit_cls, "<init>", "(JZ)V");

    jclass sat_cls = env->FindClass("SATCore");
    jmethodID sat_cstr = env->GetMethodID(sat_cls, "<init>", "()V");
    sat_object = env->NewObject(sat_cls, sat_cstr);
    n_var = env->GetMethodID(sat_cls, "new_var", "(J)V");
    n_value = env->GetMethodID(sat_cls, "new_value", "(JLSATCore$LBool;)V");
    n_clause = env->GetMethodID(sat_cls, "new_clause", "(J[LSATCore$Lit;)V");

    jclass cg_cls = env->FindClass("CausalGraph");
    jmethodID cg_cstr = env->GetMethodID(cg_cls, "<init>", "()V");
    cg_object = env->NewObject(cg_cls, cg_cstr);
    f_created = env->GetMethodID(cg_cls, "flaw_created", "(J[JLjava/lang/String;DI)V");
    f_state_changed = env->GetMethodID(cg_cls, "flaw_state_changed", "(JI)V");
    f_cost_changed = env->GetMethodID(cg_cls, "flaw_cost_changed", "(JD)V");
    c_flaw = env->GetMethodID(cg_cls, "current_flaw", "(J)V");
    r_created = env->GetMethodID(cg_cls, "resolver_created", "(JJLjava/lang/String;I)V");
    r_state_changed = env->GetMethodID(cg_cls, "resolver_state_changed", "(JI)V");
    c_resolver = env->GetMethodID(cg_cls, "current_resolver", "(J)V");
    c_link_added = env->GetMethodID(cg_cls, "causal_link_added", "(JJ)V");
}

java_gui::~java_gui() { jvm->DestroyJavaVM(); }
}