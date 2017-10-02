#pragma once

#include "flaw.h"
#include "item.h"
#include "resolver.h"

using namespace lucy;

namespace cg
{

class enum_flaw : public flaw
{
public:
  enum_flaw(solver &slv, resolver *const cause, var_item &e_itm);
  enum_flaw(const enum_flaw &orig) = delete;
  virtual ~enum_flaw();

  std::string get_label() const override { return "φ" + std::to_string(get_phi()) + " enum"; }

private:
  void compute_resolvers() override;

  class choose_value : public resolver
  {
  public:
    choose_value(solver &slv, enum_flaw &enm_flaw, var_value &val);
    choose_value(const choose_value &that) = delete;
    virtual ~choose_value();

    std::string get_label() const override { return "ρ" + std::to_string(rho) + " val"; }

  private:
    void apply() override;

  private:
    var v;
    var_value &val;
  };

private:
  var_item &e_itm;
};
}