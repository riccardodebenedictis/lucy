#pragma once

#include <jni.h>

namespace gui
{

class sat_java_listener;
class cg_java_listener;

class java_gui
{

  friend class sat_java_listener;
  friend class cg_java_listener;

public:
  java_gui();
  java_gui(const java_gui &orig) = delete;
  virtual ~java_gui();

private:
  JavaVM *jvm; // denotes a Java VM..
  JNIEnv *env; // pointer to native method interface..

  jobject false_obj;
  jobject true_obj;
  jobject undefined_obj;

  jclass lit_cls;
  jmethodID lit_cstr;

  jobject sat_object; // the SATCore Java object..
  jmethodID n_var;    // the new variable method..
  jmethodID n_value;  // the value changed method..
  jmethodID n_clause; // the new clause method..

  jobject cg_object;         // the CausalGraph Java object..
  jmethodID f_created;       // the new flaw method..
  jmethodID f_state_changed; // the flaw state changed method..
  jmethodID f_cost_changed;  // the flaw cost changed method..
  jmethodID c_flaw;          // the current flow changed method..
  jmethodID r_created;       // the new resolver method..
  jmethodID r_state_changed; // the resolver state changed method..
  jmethodID c_resolver;      // the current resolver changed method..
  jmethodID c_link_added;    // the causal link added method..
};
}