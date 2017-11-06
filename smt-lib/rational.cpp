#include "rational.h"
#include <cassert>

namespace smt
{

rational::rational() : num(0), den(1) {}
rational::rational(I n) : num(n), den(1) {}
rational::rational(I n, I d) : num(n), den(d) { normalize(); }

bool rational::operator!=(const rational &rhs) const { return num != rhs.num || den != rhs.den; }
bool rational::operator<(const rational &rhs) const { return num * rhs.den < den * rhs.num; }
bool rational::operator<=(const rational &rhs) const { return num * rhs.den <= den * rhs.num; }
bool rational::operator==(const rational &rhs) const { return num == rhs.num && den == rhs.den; }
bool rational::operator>=(const rational &rhs) const { return num * rhs.den >= den * rhs.num; }
bool rational::operator>(const rational &rhs) const { return num * rhs.den > den * rhs.num; }

bool rational::operator!=(const I &rhs) const { return num != rhs || den != 1; }
bool rational::operator<(const I &rhs) const { return num < den * rhs; }
bool rational::operator<=(const I &rhs) const { return num <= den * rhs; }
bool rational::operator==(const I &rhs) const { return num == rhs && den == 1; }
bool rational::operator>=(const I &rhs) const { return num >= den * rhs; }
bool rational::operator>(const I &rhs) const { return num > den * rhs; }

rational rational::operator+(const rational &rhs) const
{
    assert(den != 0 || rhs.den != 0 || num == rhs.num); // inf + -inf or -inf + inf..
    if (rhs.num == 0 || (den == 0 && den == rhs.den))
        return *this;
    if (den == 1 && rhs.den == 1)
        return num + rhs.num;

    rational res(*this);
    I r_num = rhs.num;
    I r_den = rhs.den;

    I g = gcd(den, r_den);
    res.den /= g;
    res.num = num * (r_den / g) + r_num * den;
    g = gcd(num, g);
    res.num /= g;
    res.den *= r_den / g;
    return res;
}

rational rational::operator-(const rational &rhs) const
{
    assert(den != 0 || rhs.den != 0 || num == rhs.num); // inf + -inf or -inf + inf..
    if (rhs.num == 0 || (den == 0 && den == rhs.den))
        return *this;
    if (den == 1 && rhs.den == 1)
        return num - rhs.num;

    rational res(*this);
    I r_num = rhs.num;
    I r_den = rhs.den;

    I g = gcd(den, r_den);
    res.den /= g;
    res.num = num * (r_den / g) - r_num * den;
    g = gcd(num, g);
    res.num /= g;
    res.den *= r_den / g;
    return res;
}

rational rational::operator*(const rational &rhs) const
{
    assert(num != 0 || rhs.den != 0); // 0*inf..
    assert(den != 0 || rhs.num != 0); // inf*0..
    if (rhs.num == 1 && rhs.den == 1)
        return *this;
    if (num == 1 && den == 1)
        return rhs;
    if (den == 0 || rhs.den == 0)
    {
        rational res;
        res.num = ((num >= 0 && rhs.num >= 0) || (num <= 0 && rhs.num <= 0)) ? 1 : -1;
        res.den = 0;
        return res;
    }

    I gcd1 = gcd(num, rhs.den);
    I gcd2 = gcd(rhs.num, den);
    rational res;
    res.num = (num / gcd1) * (rhs.num / gcd2);
    res.den = (den / gcd2) * (rhs.den / gcd1);
    return res;
}

rational rational::operator/(const rational &rhs) const
{
    assert(num != 0 || rhs.num != 0); // 0/0..
    assert(den != 0 || rhs.den != 0); // inf/inf..
    if (rhs.num == 1 && rhs.den == 1)
        return *this;
    if (num == 1 && den == 1)
    {
        rational res;
        res.num = rhs.den;
        res.den = rhs.num;
        return res;
    }
    if (den == 0 || rhs.num == 0)
    {
        rational res;
        res.num = ((num >= 0 && rhs.num >= 0) || (num <= 0 && rhs.num <= 0)) ? 1 : -1;
        res.den = 0;
        return res;
    }

    I gcd1 = gcd(num, rhs.num);
    I gcd2 = gcd(rhs.den, den);
    rational res;
    res.num = (num / gcd1) * (rhs.den / gcd2);
    res.den = (den / gcd2) * (rhs.num / gcd1);

    if (res.den < 0)
    {
        res.num = -num;
        res.den = -den;
    }
    return res;
}

rational rational::operator+(const I &rhs) const
{
    if (rhs == 0 || den == 0)
        return *this;
    if (den == 1)
        return num + rhs;

    rational res;
    res.num = num + rhs * den;
    res.den = den;
    return res;
}

rational rational::operator-(const I &rhs) const
{
    if (rhs == 0 || den == 0)
        return *this;
    if (den == 1)
        return num - rhs;

    rational res;
    res.num = num - rhs * den;
    res.den = den;
    return res;
}

rational rational::operator*(const I &rhs) const
{
    if (rhs == 1)
        return *this;
    if (den == 0)
    {
        assert(rhs != 0); // inf*0..
        rational res;
        res.num = rhs > 0 ? num : -num;
        res.den = den;
        return res;
    }
    if (den == 1)
        return num * rhs;

    return rational(num * rhs, den);
}

rational rational::operator/(const I &rhs) const
{
    assert(num != 0 || rhs != 0); // 0/0..
    if (rhs == 1)
        return *this;
    if (den == 0)
    {
        rational res;
        res.num = rhs > 0 ? num : -num;
        res.den = den;
        return res;
    }

    return rational(num, den * rhs);
}

rational &rational::operator+=(const rational &rhs)
{
    assert(den != 0 || rhs.den != 0 || num == rhs.num); // inf + -inf or -inf + inf..
    if (rhs.num == 0 || (den == 0 && den == rhs.den))
        return *this;
    if (den == 1 && rhs.den == 1)
    {
        num += rhs.num;
        return *this;
    }

    I r_num = rhs.num;
    I r_den = rhs.den;

    I g = gcd(den, r_den);
    den /= g;
    num = num * (r_den / g) + r_num * den;
    g = gcd(num, g);
    num /= g;
    den *= r_den / g;

    return *this;
}

rational &rational::operator-=(const rational &rhs)
{
    assert(den != 0 || rhs.den != 0 || num == rhs.num); // inf + -inf or -inf + inf..
    if (rhs.num == 0 || (den == 0 && den == rhs.den))
        return *this;
    if (den == 1 && rhs.den == 1)
    {
        num -= rhs.num;
        return *this;
    }

    I r_num = rhs.num;
    I r_den = rhs.den;

    I g = gcd(den, r_den);
    den /= g;
    num = num * (r_den / g) - r_num * den;
    g = gcd(num, g);
    num /= g;
    den *= r_den / g;

    return *this;
}

rational &rational::operator*=(const rational &rhs)
{
    assert(num != 0 || rhs.den != 0); // 0*inf..
    assert(den != 0 || rhs.num != 0); // inf*0..
    if (rhs.num == 1 && rhs.den == 1)
        return *this;
    if (num == 1 && den == 1)
    {
        num = rhs.num;
        den = rhs.den;
        return *this;
    }
    if (den == 0 || rhs.den == 0)
    {
        rational res;
        num = ((num >= 0 && rhs.num >= 0) || (num <= 0 && rhs.num <= 0)) ? 1 : -1;
        den = 0;
        return *this;
    }

    I gcd1 = gcd(num, rhs.den);
    I gcd2 = gcd(rhs.num, den);
    num = (num / gcd1) * (rhs.num / gcd2);
    den = (den / gcd2) * (rhs.den / gcd1);
    return *this;
}

rational &rational::operator/=(const rational &rhs)
{
    assert(num != 0 || rhs.num != 0); // 0/0..
    assert(den != 0 || rhs.den != 0); // inf/inf..
    if (rhs.num == 1 && rhs.den == 1)
        return *this;
    if (num == 1 && den == 1)
    {
        num = rhs.den;
        den = rhs.num;
        return *this;
    }
    if (den == 0 || rhs.num == 0)
    {
        rational res;
        num = ((num >= 0 && rhs.num >= 0) || (num <= 0 && rhs.num <= 0)) ? 1 : -1;
        den = 0;
        return *this;
    }

    I gcd1 = gcd(num, rhs.num);
    I gcd2 = gcd(rhs.den, den);
    num = (num / gcd1) * (rhs.den / gcd2);
    den = (den / gcd2) * (rhs.num / gcd1);

    if (den < 0)
    {
        num = -num;
        den = -den;
    }
    return *this;
}

rational &rational::operator+=(const I &rhs)
{
    if (rhs == 0 || den == 0)
        return *this;
    if (den == 1)
    {
        num += rhs;
        return *this;
    }

    num += rhs * den;
    return *this;
}

rational &rational::operator-=(const I &rhs)
{
    if (rhs == 0 || den == 0)
        return *this;
    if (den == 1)
    {
        num -= rhs;
        return *this;
    }

    num -= rhs * den;
    return *this;
}

rational &rational::operator*=(const I &rhs)
{
    if (rhs == 1)
        return *this;
    if (den == 0)
    {
        assert(rhs != 0); // inf*0..
        num = rhs > 0 ? num : -num;
        return *this;
    }
    num *= rhs;
    if (den != 1)
        normalize();

    return *this;
}

rational &rational::operator/=(const I &rhs)
{
    if (rhs == 1)
        return *this;
    if (den == 0)
    {
        if (rhs != 0)
            num = rhs > 0 ? num : -num;
        return *this;
    }
    den *= rhs;
    if (den != 1)
        normalize();

    return *this;
}

rational operator+(const I &lhs, const rational &rhs)
{
    if (lhs == 0 || rhs.den == 0)
        return rhs;
    if (rhs.den == 1)
        return rhs.num + lhs;

    rational res;
    res.num = rhs.num + lhs * rhs.den;
    res.den = rhs.den;
    return res;
}

rational operator-(const I &lhs, const rational &rhs)
{
    if (lhs == 0 || rhs.den == 0)
        return rhs;
    if (rhs.den == 1)
        return rhs.num - lhs;

    rational res;
    res.num = rhs.num - lhs * rhs.den;
    res.den = rhs.den;
    return res;
}

rational operator*(const I &lhs, const rational &rhs)
{
    if (lhs == 1)
        return rhs;
    if (rhs.den == 0)
    {
        assert(lhs != 0); // 0*inf..
        rational res;
        res.num = lhs > 0 ? rhs.num : -rhs.num;
        res.den = rhs.den;
        return res;
    }
    if (rhs.den == 1)
        return rhs.num * lhs;

    return rational(rhs.num * lhs, rhs.den);
}
rational operator/(const I &lhs, const rational &rhs)
{
    if (lhs == 1)
    {
        rational res;
        res.num = rhs.den;
        res.den = rhs.num;
        return res;
    }
    if (rhs.den == 0)
    {
        assert(lhs != 0); // 0/0..
        rational res;
        res.num = lhs > 0 ? rhs.num : -rhs.num;
        res.den = rhs.den;
        return res;
    }

    return rational(rhs.num, rhs.den * lhs);
}

rational rational::operator-() const { return rational(-num, den); }

std::string rational::to_string() const
{
    switch (den)
    {
    case 0:
        return num > 0 ? "+inf" : "-inf";
    case 1:
        return std::to_string(num);
    default:
        return std::to_string(num) + "/" + std::to_string(den);
    }
}
}