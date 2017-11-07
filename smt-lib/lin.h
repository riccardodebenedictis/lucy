#pragma once

#include "inf_rational.h"
#include <map>

namespace smt
{

typedef size_t var;

class lin
{
public:
  lin();
  lin(const inf_rational &known_term);
  lin(const var v, const inf_rational &c);

public:
  lin operator+(const lin &right) const;
  lin operator+(const inf_rational &right) const;
  friend lin operator+(const inf_rational &lhs, const lin &rhs);

  lin operator-(const lin &right) const;
  lin operator-(const inf_rational &right) const;
  friend lin operator-(const inf_rational &lhs, const lin &rhs);

  lin operator*(const inf_rational &right) const;
  friend lin operator*(const inf_rational &lhs, const lin &rhs);

  lin operator/(const inf_rational &right) const;

  lin operator+=(const lin &right);
  lin operator+=(const std::pair<var, inf_rational> &term);
  lin operator+=(const inf_rational &right);

  lin operator-=(const lin &right);
  lin operator-=(const std::pair<var, inf_rational> &term);
  lin operator-=(const inf_rational &right);

  lin operator*=(const inf_rational &right);

  lin operator/=(const inf_rational &right);

  lin operator-() const;

  std::string to_string() const;

public:
  std::map<const var, inf_rational> vars;
  inf_rational known_term;
};
}