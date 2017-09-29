#pragma once

#include "sat_core.h"

using namespace smt;

namespace cg
{

class solver;
class flaw;
class resolver;
class flaw_listener;
class resolver_listener;

class cg_listener
{
  friend class solver;
  friend class flaw_listener;
  friend class resolver_listener;

public:
  cg_listener(solver &s);
  cg_listener(const cg_listener &orig) = delete;
  virtual ~cg_listener();

private:
  void new_flaw(const flaw &f);

  virtual void flaw_created(const flaw &f);
  virtual void flaw_state_changed(const flaw &f);
  virtual void flaw_cost_changed(const flaw &f);
  virtual void current_flaw(const flaw &f);

  void new_resolver(const resolver &r);

  virtual void resolver_created(const resolver &r);
  virtual void resolver_state_changed(const resolver &r);
  virtual void current_resolver(const resolver &r);

  virtual void causal_link_added(const flaw &f, const resolver &r);

  std::string to_string() const;

  class flaw_listener : public sat_value_listener
  {
  public:
    flaw_listener(cg_listener &l, const flaw &f);
    flaw_listener(const flaw_listener &orig) = delete;
    virtual ~flaw_listener();

  private:
    void sat_value_change(const var &v) override;

  protected:
    cg_listener &listener;
    const flaw &f;
  };

  class resolver_listener : public sat_value_listener
  {
  public:
    resolver_listener(cg_listener &l, const resolver &r);
    resolver_listener(const resolver_listener &orig) = delete;
    virtual ~resolver_listener();

  private:
    void sat_value_change(const var &v) override;

  protected:
    cg_listener &listener;
    const resolver &r;
  };

protected:
  solver &slv;

private:
  std::unordered_map<const flaw *, flaw_listener *> flaw_listeners;
  std::unordered_map<const resolver *, resolver_listener *> resolver_listeners;
};
}