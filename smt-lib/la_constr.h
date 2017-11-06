#pragma once

#include "lit.h"
#include "lin.h"
#include <vector>

namespace smt
{

class inf_rational;
class la_theory;

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
  assertion(la_theory &th, const op o, const var b, const var x, const inf_rational &v);
  assertion(const assertion &orig) = delete;
  virtual ~assertion();

  std::string to_string() const;

private:
  bool propagate_lb(const var &x, std::vector<lit> &cnfl);
  bool propagate_ub(const var &x, std::vector<lit> &cnfl);

private:
  la_theory &th;
  const op o;
  const var b;
  const var x;
  const inf_rational v;
};

class row
{
  friend class la_theory;

public:
  row(la_theory &th, const var x, lin l);
  row(const assertion &orig) = delete;
  virtual ~row();

  std::string to_string() const;

private:
  bool propagate_lb(const var &x, std::vector<lit> &cnfl);
  bool propagate_ub(const var &x, std::vector<lit> &cnfl);

private:
  la_theory &th;
  const var x;
  lin l;
};
}