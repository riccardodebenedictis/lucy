#pragma once

#include "sat_core.h"

namespace smt
{

class sat_value_listener
{
  friend class sat_core;

public:
  sat_value_listener(sat_core &s) : sat(s) {}
  sat_value_listener(const sat_value_listener &that) = delete;

  virtual ~sat_value_listener()
  {
    for (const auto &v : sat_vars)
      sat.forget(v, this);
  }

protected:
  void listen_sat(var v)
  {
    sat.listen(v, this);
    sat_vars.push_back(v);
  }

private:
  virtual void sat_value_change(const var &v) {}

private:
  sat_core &sat;
  std::vector<var> sat_vars;
};
}