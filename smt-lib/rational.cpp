#include "rational.h"

namespace smt
{
const rational rational::ZERO(0);
const rational rational::ONE(1);
const rational rational::NaN(0, 0);
const rational rational::POSITIVE_INFINITY(1, 0);
const rational rational::NEGATIVE_INFINITY(-1, 0);

rational::rational() : num(0), den(1) {}
rational::rational(I n) : num(n), den(1) {}
rational::rational(I n, I d) : num(n), den(d) { normalize(); }

rational rational::operator+(const rational &rhs)
{
    if (&rhs == &ZERO)
        return *this;
    if (this == &ZERO)
        return rhs;
    if (den == rhs.den)
    {
        if (den == 0)
            return num == rhs.num ? *this : NaN;
        return (num + rhs.num, den);
    }

    I c_gcd = gcd(den, rhs.den);
    I denomgcd = den / c_gcd;
    I otherdenomgcd = rhs.den / c_gcd;
    I newdenom = denomgcd * rhs.den;
    I newnum = otherdenomgcd * num + denomgcd * rhs.num;
    return (newnum, newdenom);
}
rational operator+(const I &lhs, const rational &rhs)
{
    return 0;
}

rational rational::operator-(const rational &rhs)
{
    return 0;
}
rational operator-(const I &lhs, const rational &rhs)
{
    return 0;
}

rational rational::operator*(const rational &rhs)
{
    return 0;
}
rational operator*(const I &lhs, const rational &rhs)
{
    return 0;
}

rational rational::operator/(const rational &rhs)
{
    return 0;
}
rational operator/(const I &lhs, const rational &rhs)
{
    return 0;
}
}