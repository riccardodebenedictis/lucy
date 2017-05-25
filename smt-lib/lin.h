#pragma once

#include "visibility.h"
#include <map>

namespace smt
{

typedef size_t var;

#pragma warning(disable : 4251)
class DLL_PUBLIC lin
{
public:
  lin();
  lin(double known_term);
  lin(var v, double c);

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
  std::map<var, double> vars;
  double known_term;
};
}