#pragma once

#include "lit.h"
#include "lin.h"
#include <vector>

namespace smt
{

enum op
{
  leq,
  geq
};

class assertion
{
  friend class la_theory;
  friend class row;

public:
  assertion(la_theory &th, op o, var b, var x, double v);
  assertion(const assertion &orig) = delete;
  virtual ~assertion();

  std::string to_string() const;

private:
  bool propagate_lb(var x, std::vector<lit> &cnfl);
  bool propagate_ub(var x, std::vector<lit> &cnfl);

private:
  la_theory &th;
  op o;
  var b;
  var x;
  double v;
};

class row
{
  friend class la_theory;

public:
  row(la_theory &th, var x, lin l);
  row(const assertion &orig) = delete;
  virtual ~row();

  std::string to_string() const;

private:
  bool propagate_lb(var x, std::vector<lit> &cnfl);
  bool propagate_ub(var x, std::vector<lit> &cnfl);

private:
  la_theory &th;
  var x;
  lin l;
};
}