#pragma once

#include "causal_graph_listener.h"
#include <jni.h>

namespace gui
{
class cg_java_listener : public cg::causal_graph_listener
{

public:
  cg_java_listener(cg::causal_graph &graph);
  cg_java_listener(const cg_java_listener &orig) = delete;
  virtual ~cg_java_listener();

  void attach();
  void detach();

private:
  void flaw_created(const cg::flaw &f) override;
  void flaw_state_changed(const cg::flaw &f) override;
  void flaw_cost_changed(const cg::flaw &f) override;
  void current_flaw(const cg::flaw &f) override;

  void resolver_created(const cg::resolver &r) override;
  void resolver_state_changed(const cg::resolver &r) override;
  void current_resolver(const cg::resolver &r) override;

  void causal_link_added(const cg::flaw &f, const cg::resolver &r) override;

private:
  JavaVM *jvm;               // denotes a Java VM..
  JNIEnv *env;               // pointer to native method interface..
  jobject cg_object;         // the Java object..
  jmethodID f_created;       // a new flaw method..
  jmethodID f_state_changed; // flaw state changed method..
  jmethodID f_cost_changed;  // a flaw cost changed method..
};
}