#pragma once

#include "set_theory.h"

namespace smt
{

class set_value_listener
{
  friend class set_theory;

public:
  set_value_listener(set_theory &s) : th(s) {}
  set_value_listener(const set_value_listener &that) = delete;

  virtual ~set_value_listener()
  {
    for (const auto &v : la_vars)
      th.forget(v, this);
  }

protected:
  void listen_set(var v)
  {
    th.listen(v, this);
    la_vars.push_back(v);
  }

private:
  virtual void set_value_change(const var &v) {}

private:
  set_theory &th;
  std::vector<var> la_vars;
};
}