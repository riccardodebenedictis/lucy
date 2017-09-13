#pragma once

#include "sat_listener.h"
#include <jni.h>

namespace gui
{
class sat_java_listener : public smt::sat_listener
{

public:
  sat_java_listener(smt::sat_core &s);
  sat_java_listener(const sat_java_listener &orig) = delete;
  virtual ~sat_java_listener();

private:
  virtual void new_var(const smt::var &v) override;
  virtual void new_value(const smt::var &v) override;
  virtual void new_clause(const smt::clause &c, const std::vector<smt::lit> &ls) override;

private:
  JavaVM *jvm;        // denotes a Java VM..
  JNIEnv *env;        // pointer to native method interface..
  jobject sat_object; // the Java object..
  jmethodID n_var;    // the new variable method..
  jmethodID n_value;  // the value changed method..
  jmethodID n_clause; // the new clause method..
};
}