#pragma once

#include "visibility.h"
#include "la_theory.h"

namespace smt
{

class DLL_PUBLIC la_value_listener
{
    friend class la_theory;

  public:
    la_value_listener(la_theory &s) : th(s) {}
    la_value_listener(const la_value_listener &that) = delete;

    virtual ~la_value_listener()
    {
        for (const auto &v : la_vars)
        {
            th.forget(v, this);
        }
    }

  protected:
    void listen_la(var v)
    {
        th.listen(v, this);
        la_vars.push_back(v);
    }

    virtual void la_value_change(var v) {}

  private:
    la_theory &th;
    std::vector<var> la_vars;
};
}