#pragma once
#include "rational.h"

namespace smt
{

typedef long I;

class inf_rational
{
  public:
    inf_rational() : rat(0), inf(0) {}
    inf_rational(rational f) : rat(f), inf(0) {}
    inf_rational(I n, I d) : rat(rational(n, d)), inf(0) {}
    inf_rational(rational f, I inf) : rat(f), inf(inf) {}

  public:
    rational get_rational() const { return rat; }
    rational get_infinitesimal() const { return inf; }

    bool operator!=(const inf_rational &rhs) const;
    bool operator<(const inf_rational &rhs) const;
    bool operator<=(const inf_rational &rhs) const;
    bool operator==(const inf_rational &rhs) const;
    bool operator>=(const inf_rational &rhs) const;
    bool operator>(const inf_rational &rhs) const;

    bool operator!=(const rational &rhs) const;
    bool operator<(const rational &rhs) const;
    bool operator<=(const rational &rhs) const;
    bool operator==(const rational &rhs) const;
    bool operator>=(const rational &rhs) const;
    bool operator>(const rational &rhs) const;

    bool operator!=(const I &rhs) const;
    bool operator<(const I &rhs) const;
    bool operator<=(const I &rhs) const;
    bool operator==(const I &rhs) const;
    bool operator>=(const I &rhs) const;
    bool operator>(const I &rhs) const;

    rational operator+(const inf_rational &rhs) const;
    rational operator-(const inf_rational &rhs) const;
    rational operator*(const inf_rational &rhs) const;
    rational operator/(const inf_rational &rhs) const;

    rational operator+(const rational &rhs) const;
    rational operator-(const rational &rhs) const;
    rational operator*(const rational &rhs) const;
    rational operator/(const rational &rhs) const;

    rational operator+(const I &rhs) const;
    rational operator-(const I &rhs) const;
    rational operator*(const I &rhs) const;
    rational operator/(const I &rhs) const;

    rational &operator+=(const inf_rational &rhs);
    rational &operator-=(const inf_rational &rhs);
    rational &operator*=(const inf_rational &rhs);
    rational &operator/=(const inf_rational &rhs);

    rational &operator+=(const rational &rhs);
    rational &operator-=(const rational &rhs);
    rational &operator*=(const rational &rhs);
    rational &operator/=(const rational &rhs);

    rational &operator+=(const I &rhs);
    rational &operator-=(const I &rhs);
    rational &operator*=(const I &rhs);
    rational &operator/=(const I &rhs);

  private:
    rational rat;
    rational inf;
};
}