#pragma once
#include "rational.h"

namespace smt
{

class inf_rational : public rational
{
public:
  inf_rational() : inf(0) {}
  inf_rational(rational rat) : rational(rat), inf(0) {}
  inf_rational(I nun, I den) : rational(nun, den), inf(0) {}
  inf_rational(rational rat, I inf) : rational(rat), inf(inf) {}
  inf_rational(rational rat, rational inf) : rational(rat), inf(inf) {}

public:
  rational infinitesimal() const { return inf; }

  bool operator!=(const inf_rational &rhs) const { return rational::operator!=(rhs) && inf != rhs.inf; };
  bool operator<(const inf_rational &rhs) const { return rational::operator<(rhs) || (rational::operator==(rhs) && inf < rhs.inf); };
  bool operator<=(const inf_rational &rhs) const { return rational::operator<=(rhs) || (rational::operator==(rhs) && inf <= rhs.inf); };
  bool operator==(const inf_rational &rhs) const { return rational::operator==(rhs) && inf == rhs.inf; };
  bool operator>=(const inf_rational &rhs) const { return rational::operator>=(rhs) || (rational::operator==(rhs) && inf >= rhs.inf); };
  bool operator>(const inf_rational &rhs) const { return rational::operator>(rhs) || (rational::operator==(rhs) && inf > rhs.inf); };

  bool operator!=(const rational &rhs) const override { return rational::operator!=(rhs) || inf.numerator() != 0; };
  bool operator<(const rational &rhs) const override { return rational::operator<(rhs) || (rational::operator==(rhs) && inf.numerator() < 0); };
  bool operator<=(const rational &rhs) const override { return rational::operator<=(rhs) || (rational::operator==(rhs) && inf.numerator() <= 0); };
  bool operator==(const rational &rhs) const override { return rational::operator==(rhs) && inf.numerator() == 0; };
  bool operator>=(const rational &rhs) const override { return rational::operator>=(rhs) || (rational::operator==(rhs) && inf.numerator() >= 0); };
  bool operator>(const rational &rhs) const override { return rational::operator>(rhs) || (rational::operator==(rhs) && inf.numerator() > 0); };

  bool operator!=(const I &rhs) const override { return rational::operator!=(rhs) || inf.numerator() != 0; };
  bool operator<(const I &rhs) const override { return rational::operator<(rhs) || (rational::operator==(rhs) && inf.numerator() < 0); };
  bool operator<=(const I &rhs) const override { return rational::operator<=(rhs) || (rational::operator==(rhs) && inf.numerator() <= 0); };
  bool operator==(const I &rhs) const override { return rational::operator==(rhs) && inf.numerator() == 0; };
  bool operator>=(const I &rhs) const override { return rational::operator>=(rhs) || (rational::operator==(rhs) && inf.numerator() >= 0); };
  bool operator>(const I &rhs) const override { return rational::operator>(rhs) || (rational::operator==(rhs) && inf.numerator() > 0); };

  rational operator+(const inf_rational &rhs) const
  {
    rational c_inf = inf + rhs.inf;
    return c_inf == 0 ? rational::operator+(rhs) : inf_rational(rational::operator+(rhs), c_inf);
  };
  rational operator-(const inf_rational &rhs) const
  {
    rational c_inf = inf - rhs.inf;
    return c_inf == 0 ? rational::operator-(rhs) : inf_rational(rational::operator-(rhs), c_inf);
  };

  rational operator+(const rational &rhs) const override { return inf_rational(rational::operator+(rhs), inf); };
  rational operator-(const rational &rhs) const override { return inf_rational(rational::operator-(rhs), inf); };
  rational operator*(const rational &rhs) const override
  {
    rational c_inf = inf * rhs;
    return c_inf == 0 ? rational::operator*(rhs) : inf_rational(rational::operator*(rhs), c_inf);
  };
  rational operator/(const rational &rhs) const override
  {
    rational c_inf = inf / rhs;
    return c_inf == 0 ? rational::operator/(rhs) : inf_rational(rational::operator/(rhs), c_inf);
  };

  rational operator+(const I &rhs) const override { return inf_rational(rational::operator+(rhs), inf); };
  rational operator-(const I &rhs) const override { return inf_rational(rational::operator-(rhs), inf); };
  rational operator*(const I &rhs) const override
  {
    rational c_inf = inf * rhs;
    return c_inf == 0 ? rational::operator*(rhs) : inf_rational(rational::operator*(rhs), c_inf);
  };
  rational operator/(const I &rhs) const override
  {
    rational c_inf = inf / rhs;
    return c_inf == 0 ? rational::operator/(rhs) : inf_rational(rational::operator/(rhs), c_inf);
  };

  rational &operator+=(const inf_rational &rhs)
  {
    rational::operator+=(rhs);
    inf += rhs.inf;
    return *this;
  }
  rational &operator-=(const inf_rational &rhs)
  {
    rational::operator-=(rhs);
    inf -= rhs.inf;
    return *this;
  }

  rational &operator+=(const rational &rhs) override { return rational::operator+=(rhs); }
  rational &operator-=(const rational &rhs) override { return rational::operator-=(rhs); }
  rational &operator*=(const rational &rhs) override
  {
    rational::operator*=(rhs);
    inf *= rhs;
    return *this;
  }
  rational &operator/=(const rational &rhs) override
  {
    rational::operator/=(rhs);
    inf /= rhs;
    return *this;
  }

  rational &operator+=(const I &rhs) override { return rational::operator+=(rhs); }
  rational &operator-=(const I &rhs) override { return rational::operator-=(rhs); }
  rational &operator*=(const I &rhs) override
  {
    rational::operator*=(rhs);
    inf *= rhs;
    return *this;
  }
  rational &operator/=(const I &rhs) override
  {
    rational::operator/=(rhs);
    inf /= rhs;
    return *this;
  }

  rational operator-() const override { return inf_rational(rational::operator-(), -inf); }

  std::string to_string() const override { return rational::to_string() + (inf != 0 ? (" + " + inf.to_string() + "ε") : ""); };

private:
  rational inf; // the infinitesimal part..
};
}