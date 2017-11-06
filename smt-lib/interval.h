#pragma once

#include "rational.h"
#include <string>

namespace smt
{

class interval
{
public:
  interval();
  interval(const rational &value);
  interval(const rational &lb, const rational &ub);

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

  bool operator!=(const rational &right) const;
  bool operator<(const rational &right) const;
  bool operator<=(const rational &right) const;
  bool operator==(const rational &right) const;
  bool operator>=(const rational &right) const;
  bool operator>(const rational &right) const;

  interval operator&&(const interval &rhs) const;

  interval operator+(const interval &rhs) const;
  interval operator-(const interval &rhs) const;
  interval operator*(const interval &rhs) const;
  interval operator/(const interval &rhs) const;

  interval operator+(const rational &rhs) const;
  interval operator-(const rational &rhs) const;
  interval operator*(const rational &rhs) const;
  interval operator/(const rational &rhs) const;

  interval &operator+=(const interval &right);
  interval &operator-=(const interval &right);
  interval &operator*=(const interval &right);
  interval &operator/=(const interval &right);

  interval &operator+=(const rational &right);
  interval &operator-=(const rational &right);
  interval &operator*=(const rational &right);
  interval &operator/=(const rational &right);

  interval operator-() const;

  friend interval operator+(const rational &lhs, const interval &rhs);
  friend interval operator-(const rational &lhs, const interval &rhs);
  friend interval operator*(const rational &lhs, const interval &rhs);
  friend interval operator/(const rational &lhs, const interval &rhs);

  std::string to_string() const;

public:
  rational lb;
  rational ub;
};
}
