#pragma once

#include "flaw.h"
#include "resolver.h"

namespace cg
{

class super_flaw : public flaw
{
public:
  super_flaw(solver &slv, resolver *const cause, const std::vector<flaw *> &fs);
  super_flaw(const super_flaw &orig) = delete;
  virtual ~super_flaw();

  std::string get_label() const override
  {
    std::string f_str = "φ" + std::to_string(get_phi()) + " {";
    for (std::vector<flaw *>::const_iterator f_it = flaws.begin(); f_it != flaws.end(); ++f_it)
    {
      if (f_it != flaws.begin())
        f_str += ", ";
      f_str += (*f_it)->get_label();
    }
    f_str += "}";
    return f_str;
  }

private:
  void compute_resolvers() override;

  class super_resolver : public resolver
  {
  public:
    super_resolver(solver &slv, super_flaw &s_flaw, const var &app_r, const lin &c, const std::vector<resolver *> &rs);
    super_resolver(const super_resolver &that) = delete;
    virtual ~super_resolver();

    std::string get_label() const override
    {
      std::string r_str = "ρ" + std::to_string(rho) + " {";
      for (std::vector<resolver *>::const_iterator r_it = resolvers.begin(); r_it != resolvers.end(); ++r_it)
      {
        if (r_it != resolvers.begin())
          r_str += ", ";
        r_str += (*r_it)->get_label();
      }
      r_str += "}";
      return r_str;
    }

  private:
    void apply() override;

  private:
    const std::vector<resolver *> resolvers;
  };

private:
  const std::vector<flaw *> flaws;
};
}