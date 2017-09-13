#pragma once

#include "la_theory.h"

namespace smt
{

class la_listener
{
  friend class la_theory;

public:
  la_listener(la_theory &s) : th(s) {}
  la_listener(const la_listener &that) = delete;

  virtual ~la_listener()
  {
    for (const auto &v : la_vars)
      th.forget(v, this);
  }

protected:
  void listen_la(var v)
  {
    th.listen(v, this);
    la_vars.push_back(v);
  }

private:
  virtual void new_la_var(const var &v) {}
  virtual void la_value_change(const var &v) {}

private:
  la_theory &th;
  std::vector<var> la_vars;
};
}