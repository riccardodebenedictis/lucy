#pragma once

#include <string>

namespace smt
{

class interval
{
public:
  interval();
  interval(double value);
  interval(double lb, double ub);

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

  interval operator&&(const interval &rhs) const;

  interval operator+(const interval &rhs) const;
  interval operator-(const interval &rhs) const;
  interval operator*(const interval &rhs) const;
  interval operator/(const interval &rhs) const;

  interval operator+(const double &rhs) const;
  interval operator-(const double &rhs) const;
  interval operator*(const double &rhs) const;
  interval operator/(const double &rhs) const;

  interval &operator+=(const interval &right);
  interval &operator-=(const interval &right);
  interval &operator*=(const interval &right);
  interval &operator/=(const interval &right);

  interval &operator+=(const double &right);
  interval &operator-=(const double &right);
  interval &operator*=(const double &right);
  interval &operator/=(const double &right);

  interval operator-() const;

  friend interval operator+(const double &lhs, const interval &rhs);
  friend interval operator-(const double &lhs, const interval &rhs);
  friend interval operator*(const double &lhs, const interval &rhs);
  friend interval operator/(const double &lhs, const interval &rhs);

  std::string to_string() const;

public:
  double lb;
  double ub;
};
}
