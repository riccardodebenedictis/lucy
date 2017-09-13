#pragma once

#include "set_theory.h"

namespace smt
{

class set_listener
{
  friend class set_theory;

public:
  set_listener(set_theory &s) : th(s) {}
  set_listener(const set_listener &that) = delete;

  virtual ~set_listener()
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
  virtual void new_set_var(const var &v) {}
  virtual void set_value_change(const var &v) {}

private:
  set_theory &th;
  std::vector<var> la_vars;
};
}