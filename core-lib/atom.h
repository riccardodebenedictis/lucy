#pragma once

#include "item.h"

namespace lucy
{

class predicate;

class DLL_PUBLIC atom_state : public set_item
{
    friend class atom;

  private:
    atom_state() {}
    atom_state(const atom_state &that) = delete;
    virtual ~atom_state() {}
};

class DLL_PUBLIC atom : public item
{
  public:
    static atom_state *const active;
    static atom_state *const inactive;
    static atom_state *const unified;

  public:
    atom(core &cr, const context ctx, const predicate &pred);
    atom(const atom &orig) = delete;
    virtual ~atom();

  public:
    const var state;
};

__declspec(selectany) atom_state *const atom::active = new atom_state();
__declspec(selectany) atom_state *const atom::inactive = new atom_state();
__declspec(selectany) atom_state *const atom::unified = new atom_state();
}