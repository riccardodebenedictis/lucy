#pragma once
#include <numeric>

namespace smt
{

typedef long I;

class rational
{
public:
  rational() : num(0), den(1) {}
  rational(I n) : num(n), den(1) {}
  rational(I n, I d) : num(n), den(d) { normalize(); }

  I numerator() const { return num; }
  I denominator() const { return den; }

private:
  void normalize()
  {
    if (den != 1)
    {
      I c_gcd = std::abs(gcd(num, den));
      if (den < 0)
        c_gcd = -c_gcd;
      num /= c_gcd;
      den /= c_gcd;
    }
  }

  static I gcd(I u, I v)
  {
    while (v != 0)
    {
      I r = u % v;
      u = v;
      v = r;
    }
    return u;
  }

private:
  I num; // the numerator of the rational..
  I den; // the denominator of the rational..
};

static const rational ZERO = 0;
static const rational ONE = 1;
}