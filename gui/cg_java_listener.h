#pragma once

#include "cg_listener.h"

namespace gui
{

class java_gui;

class cg_java_listener : public cg::cg_listener
{

public:
  cg_java_listener(cg::solver &slv, java_gui &gui);
  cg_java_listener(const cg_java_listener &orig) = delete;
  virtual ~cg_java_listener();

private:
  void flaw_created(const cg::flaw &f) override;
  void flaw_state_changed(const cg::flaw &f) override;
  void current_flaw(const cg::flaw &f) override;

  void resolver_created(const cg::resolver &r) override;
  void resolver_state_changed(const cg::resolver &r) override;
  void resolver_cost_changed(const cg::resolver &r) override;
  void current_resolver(const cg::resolver &r) override;

  void causal_link_added(const cg::flaw &f, const cg::resolver &r) override;

private:
  java_gui &gui;
};
}