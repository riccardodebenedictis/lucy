#pragma once
#include <numeric>
#include <string>

namespace smt
{

typedef long I;

class rational
{
public:
  rational();
  rational(I n);
  rational(I n, I d);

public:
  I numerator() const { return num; }
  I denominator() const { return den; }

  bool is_positive() const { return num > 0; }
  bool is_negative() const { return num < 0; }
  bool is_infinite() const { return den == 0; }
  bool is_positive_infinite() const { return is_positive() && is_infinite(); }
  bool is_negative_infinite() const { return is_negative() && is_infinite(); }

  virtual bool operator!=(const rational &rhs) const;
  virtual bool operator<(const rational &rhs) const;
  virtual bool operator<=(const rational &rhs) const;
  virtual bool operator==(const rational &rhs) const;
  virtual bool operator>=(const rational &rhs) const;
  virtual bool operator>(const rational &rhs) const;

  virtual bool operator!=(const I &rhs) const;
  virtual bool operator<(const I &rhs) const;
  virtual bool operator<=(const I &rhs) const;
  virtual bool operator==(const I &rhs) const;
  virtual bool operator>=(const I &rhs) const;
  virtual bool operator>(const I &rhs) const;

  virtual rational operator+(const rational &rhs) const;
  virtual rational operator-(const rational &rhs) const;
  virtual rational operator*(const rational &rhs) const;
  virtual rational operator/(const rational &rhs) const;

  virtual rational operator+(const I &rhs) const;
  virtual rational operator-(const I &rhs) const;
  virtual rational operator*(const I &rhs) const;
  virtual rational operator/(const I &rhs) const;

  virtual rational &operator+=(const rational &rhs);
  virtual rational &operator-=(const rational &rhs);
  virtual rational &operator*=(const rational &rhs);
  virtual rational &operator/=(const rational &rhs);

  virtual rational &operator+=(const I &rhs);
  virtual rational &operator-=(const I &rhs);
  virtual rational &operator*=(const I &rhs);
  virtual rational &operator/=(const I &rhs);

  friend rational operator+(const I &lhs, const rational &rhs);
  friend rational operator-(const I &lhs, const rational &rhs);
  friend rational operator*(const I &lhs, const rational &rhs);
  friend rational operator/(const I &lhs, const rational &rhs);

  virtual rational operator-() const;

  virtual std::string to_string() const;

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

  static I gcd(I u, I v) // computes the greatest common divisor..
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