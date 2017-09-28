#pragma once

#include "type.h"
#include "causal_graph.h"
#include "atom.h"
#include "field.h"

using namespace lucy;

namespace cg
{

class flaw;

class smart_type : public type
{
  friend class causal_graph;

public:
  smart_type(causal_graph &graph, scope &scp, const std::string &name) : type(graph, scp, name, false), graph(graph) {}
  smart_type(const smart_type &that) = delete;

  virtual ~smart_type() {}

private:
  virtual std::vector<flaw *> get_flaws() = 0;
  virtual void new_fact(atom_flaw &) {}
  virtual void new_goal(atom_flaw &) {}

protected:
  causal_graph &graph;
};

class atom_listener : public sat_value_listener, public la_value_listener, public set_value_listener
{
public:
  atom_listener(atom &atm) : sat_value_listener(atm.get_core().sat), la_value_listener(atm.get_core().la_th), set_value_listener(atm.get_core().ov_th), atm(atm)
  {
    std::queue<const type *> q;
    q.push(&atm.tp);
    while (!q.empty())
    {
      for (const auto &f : q.front()->get_fields())
        if (!f.second->synthetic)
        {
          item *i = &*atm.get(f.first);
          if (bool_item *be = dynamic_cast<bool_item *>(i))
            listen_sat(be->l.v);
          else if (arith_item *ae = dynamic_cast<arith_item *>(i))
            for (const auto &term : ae->l.vars)
              listen_la(term.first);
          else if (var_item *ee = dynamic_cast<var_item *>(i))
            listen_set(ee->ev);
        }

      for (const auto &st : q.front()->get_supertypes())
        q.push(st);
      q.pop();
    }
  }
  atom_listener(const atom_listener &that) = delete;

  virtual ~atom_listener() {}

protected:
  atom &atm;
};
}