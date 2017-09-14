#pragma once

#include "sat_core.h"
#include <algorithm>

namespace smt
{

class sat_listener
{
  friend class sat_core;

public:
  sat_listener(sat_core &s) : sat(s) { s.listeners.push_back(this); }
  sat_listener(const sat_listener &that) = delete;
  virtual ~sat_listener() { sat.listeners.erase(std::find(sat.listeners.begin(), sat.listeners.end(), this)); }

private:
  virtual void new_var(const var &v) {}
  virtual void new_value(const var &v) {}
  virtual void new_clause(const clause &c) {}

protected:
  sat_core &sat;
};
}