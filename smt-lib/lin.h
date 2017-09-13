#pragma once

#include <map>

namespace smt
{

typedef size_t var;

class lin
{
public:
  lin();
  lin(const double known_term);
  lin(const var v, const double c);

public:
  lin operator+(const lin &right) const;
  lin operator+(const double &right) const;
  friend lin operator+(const double &lhs, const lin &rhs);

  lin operator-(const lin &right) const;
  lin operator-(const double &right) const;
  friend lin operator-(const double &lhs, const lin &rhs);

  lin operator*(const double &right) const;
  friend lin operator*(const double &lhs, const lin &rhs);

  lin operator/(const double &right) const;

  lin operator+=(const lin &right);
  lin operator+=(const std::pair<var, double> &term);
  lin operator+=(const double &right);

  lin operator-=(const lin &right);
  lin operator-=(const std::pair<var, double> &term);
  lin operator-=(const double &right);

  lin operator*=(const double &right);

  lin operator/=(const double &right);

  lin operator-() const;

  std::string to_string() const;

public:
  std::map<const var, double> vars;
  double known_term;
};
}