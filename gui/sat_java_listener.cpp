#include "sat_java_listener.h"
#include "java_gui.h"

namespace gui
{
sat_java_listener::sat_java_listener(java_gui &gui, smt::sat_core &s) : gui(gui), sat_listener(s) {}
sat_java_listener::~sat_java_listener() {}

void sat_java_listener::new_var(const smt::var &v) { gui.env->CallVoidMethod(gui.sat_object, gui.n_var, v); }

void sat_java_listener::new_value(const smt::var &v)
{
    switch (sat.value(v))
    {
    case smt::True:
        gui.env->CallVoidMethod(gui.sat_object, gui.n_value, v, gui.true_obj);
        break;
    case smt::False:
        gui.env->CallVoidMethod(gui.sat_object, gui.n_value, v, gui.false_obj);
        break;
    case smt::Undefined:
        gui.env->CallVoidMethod(gui.sat_object, gui.n_value, v, gui.undefined_obj);
        break;
    }
}

void sat_java_listener::new_clause(const smt::clause &c, const std::vector<smt::lit> &ls)
{
    jobjectArray lits_array = gui.env->NewObjectArray(ls.size(), gui.lit_cls, NULL);
    for (size_t i = 0; i < ls.size(); i++)
    {
        jobject c_l = gui.env->NewObject(gui.lit_cls, gui.lit_cstr, ls[i].v, ls[i].sign);
        gui.env->SetObjectArrayElement(lits_array, i, c_l);
    }
    gui.env->CallVoidMethod(gui.sat_object, gui.n_clause, reinterpret_cast<jlong>(&c), lits_array);
}
}