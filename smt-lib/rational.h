#pragma once
#include <numeric>

namespace smt
{

typedef long I;

class rational
{
public:
  rational();
  rational(I n);
  rational(I n, I d);

  rational &operator=(I n) { return assign(n, 1); }
  rational &assign(I n, I d)
  {
    num = n;
    den = d;
    normalize();
    return *this;
  }

  I numerator() const { return num; }
  I denominator() const { return den; }

  rational operator+(const rational &rhs);
  friend rational operator+(const I &lhs, const rational &rhs);

  rational operator-(const rational &rhs);
  friend rational operator-(const I &lhs, const rational &rhs);

  rational operator*(const rational &rhs);
  friend rational operator*(const I &lhs, const rational &rhs);

  rational operator/(const rational &rhs);
  friend rational operator/(const I &lhs, const rational &rhs);

  static const rational ZERO;
  static const rational ONE;
  static const rational NaN;
  static const rational POSITIVE_INFINITY;
  static const rational NEGATIVE_INFINITY;

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
}