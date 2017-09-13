#include "sat_java_listener.h"

namespace gui
{
sat_java_listener::sat_java_listener(smt::sat_core &s) : sat_listener(s)
{
    JavaVMInitArgs vm_args;
    JavaVMOption *options = new JavaVMOption[1];
#ifdef _WIN32
    options[0].optionString = (char *)"-Djava.class.path=./lucy_gui.jar";
#else
    options[0].optionString = (char *)"-Djava.class.path=./lucy_gui.jar";
#endif
    options[1].optionString = (char *)"-ea";
    vm_args.version = JNI_VERSION_1_8;
    vm_args.nOptions = 2;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = false;
    JNI_CreateJavaVM(&jvm, (void **)&env, &vm_args);
    jclass cls = env->FindClass("SATCore");
    jmethodID cstr = env->GetMethodID(cls, "<init>", "()V");
    sat_object = env->NewObject(cls, cstr);
    n_var = env->GetMethodID(cls, "new_var", "(J)V");
    n_value = env->GetMethodID(cls, "new_value", "(JLSATCore$LBool;)V");
    n_clause = env->GetMethodID(cls, "new_clause", "(Ljava/util/List;)V");
}

sat_java_listener::~sat_java_listener() { jvm->DestroyJavaVM(); }

void sat_java_listener::new_var(const smt::var &v) { env->CallVoidMethod(sat_object, n_var, v); }

void sat_java_listener::new_value(const smt::var &v)
{
    jclass val_class = env->FindClass("SATCore$LBool");
    switch (sat.value(v))
    {
    case smt::True:
        env->CallVoidMethod(sat_object, n_value, v, env->GetStaticObjectField(val_class, env->GetStaticFieldID(val_class, "True", "LSATCore$LBool;")));
        break;
    case smt::False:
        env->CallVoidMethod(sat_object, n_value, v, env->GetStaticObjectField(val_class, env->GetStaticFieldID(val_class, "False", "LSATCore$LBool;")));
        break;
    case smt::Undefined:
        env->CallVoidMethod(sat_object, n_value, v, env->GetStaticObjectField(val_class, env->GetStaticFieldID(val_class, "Undefined", "LSATCore$LBool;")));
        break;
    }
}

void sat_java_listener::new_clause(const smt::clause &c, const std::vector<smt::lit> &ls)
{
    jclass cls = static_cast<jclass>(env->NewGlobalRef(env->FindClass("java/util/ArrayList")));
    jmethodID cstr = env->GetMethodID(cls, "<init>", "(I)V");
    jobject lits = env->NewObject(cls, cstr, ls.size());
    jmethodID add = env->GetMethodID(cls, "add", "(Ljava/lang/Object;)Z");

    jclass lit_cls = static_cast<jclass>(env->NewGlobalRef(env->FindClass("SATCore$Lit")));
    jmethodID lit_cstr = env->GetMethodID(lit_cls, "<init>", "(JZ)V");
    for (const auto &l : ls)
    {
        jobject c_l = env->NewObject(lit_cls, lit_cstr, l.v, l.sign);
        env->CallBooleanMethod(lits, add, c_l);
        env->DeleteLocalRef(c_l);
    }
    env->CallVoidMethod(sat_object, n_clause, reinterpret_cast<jlong>(&c), lits);
}
}