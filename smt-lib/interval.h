#pragma once

#include "inf_rational.h"
#include <string>

namespace smt
{

class interval
{
public:
  interval();
  interval(const inf_rational &value);
  interval(const inf_rational &lb, const inf_rational &ub);

  bool consistent() const;
  bool constant() const;
  bool intersecting(const interval &i) const;
  bool contains(const interval &i) const;

  bool operator!=(const interval &right) const;
  bool operator<(const interval &right) const;
  bool operator<=(const interval &right) const;
  bool operator==(const interval &right) const;
  bool operator>=(const interval &right) const;
  bool operator>(const interval &right) const;

  bool operator!=(const inf_rational &right) const;
  bool operator<(const inf_rational &right) const;
  bool operator<=(const inf_rational &right) const;
  bool operator==(const inf_rational &right) const;
  bool operator>=(const inf_rational &right) const;
  bool operator>(const inf_rational &right) const;

  interval operator&&(const interval &rhs) const;

  interval operator+(const interval &rhs) const;
  interval operator-(const interval &rhs) const;
  interval operator*(const interval &rhs) const;
  interval operator/(const interval &rhs) const;

  interval operator+(const inf_rational &rhs) const;
  interval operator-(const inf_rational &rhs) const;
  interval operator*(const inf_rational &rhs) const;
  interval operator/(const inf_rational &rhs) const;

  interval &operator+=(const interval &right);
  interval &operator-=(const interval &right);
  interval &operator*=(const interval &right);
  interval &operator/=(const interval &right);

  interval &operator+=(const inf_rational &right);
  interval &operator-=(const inf_rational &right);
  interval &operator*=(const inf_rational &right);
  interval &operator/=(const inf_rational &right);

  interval operator-() const;

  friend interval operator+(const inf_rational &lhs, const interval &rhs);
  friend interval operator-(const inf_rational &lhs, const interval &rhs);
  friend interval operator*(const inf_rational &lhs, const interval &rhs);
  friend interval operator/(const inf_rational &lhs, const interval &rhs);

  std::string to_string() const;

public:
  inf_rational lb;
  inf_rational ub;
};
}
