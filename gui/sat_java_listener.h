#pragma once

#include "sat_listener.h"

namespace gui
{

class java_gui;

class sat_java_listener : public smt::sat_listener
{

public:
  sat_java_listener(java_gui &gui, smt::sat_core &s);
  sat_java_listener(const sat_java_listener &orig) = delete;
  virtual ~sat_java_listener();

private:
  virtual void new_var(const smt::var &v) override;
  virtual void new_value(const smt::var &v) override;
  virtual void new_clause(const smt::clause &c) override;

private:
  java_gui &gui;
};
}