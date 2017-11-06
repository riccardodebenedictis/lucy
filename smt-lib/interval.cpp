#include "interval.h"

#include <algorithm>

namespace smt
{

interval::interval() : lb(inf_rational(-1, 0)), ub(inf_rational(1, 0)) {}
interval::interval(const inf_rational &value) : lb(value), ub(value) {}
interval::interval(const inf_rational &lb, const inf_rational &ub) : lb(lb), ub(ub) {}

bool interval::consistent() const { return lb <= ub; }
bool interval::constant() const { return lb == ub; }
bool interval::intersecting(const interval &i) const { return ub >= i.lb && lb <= i.ub; }
bool interval::contains(const interval &i) const { return lb <= i.lb && ub >= i.ub; }

bool interval::operator!=(const interval &right) const { return ub < right.lb || lb > right.ub; }
bool interval::operator<(const interval &right) const { return ub < right.lb; }
bool interval::operator<=(const interval &right) const { return ub <= right.lb; }
bool interval::operator==(const interval &right) const { return constant() && right.constant() && lb == right.lb; }
bool interval::operator>=(const interval &right) const { return lb >= right.ub; }
bool interval::operator>(const interval &right) const { return lb > right.ub; }

bool interval::operator!=(const inf_rational &right) const { return ub < right || lb > right; }
bool interval::operator<(const inf_rational &right) const { return ub < right; }
bool interval::operator<=(const inf_rational &right) const { return ub <= right; }
bool interval::operator==(const inf_rational &right) const { return constant() && lb == right; }
bool interval::operator>=(const inf_rational &right) const { return lb >= right; }
bool interval::operator>(const inf_rational &right) const { return lb > right; }

interval interval::operator&&(const interval &rhs) const { return interval(std::max(lb, rhs.lb), std::min(ub, rhs.ub)); }

interval interval::operator+(const interval &rhs) const { return interval(lb + rhs.lb, ub + rhs.ub); }
interval interval::operator-(const interval &rhs) const { return interval(lb - rhs.ub, ub - rhs.lb); }
interval interval::operator*(const interval &rhs) const
{
    interval result(inf_rational(1, 0), inf_rational(-1, 0));
    for (const auto &i : {lb * rhs.lb, lb * rhs.ub, ub * rhs.lb, ub * rhs.ub})
    {
        if (i < result.lb)
            result.lb = i;
        if (i > result.ub)
            result.ub = i;
    }
    return result;
}
interval interval::operator/(const interval &rhs) const
{
    if (rhs.lb <= 0 && rhs.ub >= 0) // 0 appears in the denominator..
        return interval();
    else
    {
        interval result(inf_rational(1, 0), inf_rational(-1, 0));
        for (const auto &i : {lb / rhs.lb, lb / rhs.ub, ub / rhs.lb, ub / rhs.ub})
        {
            if (i < result.lb)
                result.lb = i;
            if (i > result.ub)
                result.ub = i;
        }
        return result;
    }
}

interval interval::operator+(const inf_rational &rhs) const { return interval(lb + rhs, ub + rhs); }
interval interval::operator-(const inf_rational &rhs) const { return interval(lb - rhs, ub - rhs); }
interval interval::operator*(const inf_rational &rhs) const
{
    if (rhs >= 0)
        return interval(lb * rhs, ub * rhs);
    else
        return interval(ub * rhs, lb * rhs);
}
interval interval::operator/(const inf_rational &rhs) const
{
    if (rhs >= 0)
        return interval(lb / rhs, ub / rhs);
    else
        return interval(ub / rhs, lb / rhs);
}

interval operator+(const inf_rational &lhs, const interval &rhs) { return interval(lhs + rhs.lb, lhs + rhs.ub); }
interval operator-(const inf_rational &lhs, const interval &rhs) { return interval(lhs - rhs.ub, lhs - rhs.lb); }
interval operator*(const inf_rational &lhs, const interval &rhs)
{
    if (lhs >= 0)
        return interval(rhs.lb * lhs, rhs.ub * lhs);
    else
        return interval(rhs.ub * lhs, rhs.lb * lhs);
}
interval operator/(const inf_rational &lhs, const interval &rhs)
{
    if (rhs.lb <= 0 && rhs.ub >= 0) // 0 appears in the denominator..
        return interval();
    else
    {
        interval result(inf_rational(1, 0), inf_rational(-1, 0));
        for (const auto &i : {lhs / rhs.lb, lhs / rhs.ub})
        {
            if (i < result.lb)
                result.lb = i;
            if (i > result.ub)
                result.ub = i;
        }
        return result;
    }
}

interval &interval::operator+=(const interval &right)
{
    lb += right.lb;
    ub += right.ub;
    return *this;
}
interval &interval::operator-=(const interval &right)
{
    lb -= right.ub;
    ub -= right.lb;
    return *this;
}
interval &interval::operator*=(const interval &right)
{
    inf_rational c_lb(1, 0);
    inf_rational c_ub(-1, 0);
    for (const auto &i : {lb * right.lb, lb * right.ub, ub * right.lb, ub * right.ub})
    {
        if (i < c_lb)
            c_lb = i;
        if (i > c_ub)
            c_ub = i;
    }
    lb = c_lb;
    ub = c_ub;
    return *this;
}
interval &interval::operator/=(const interval &right)
{
    if (right.lb <= 0 && right.ub >= 0)
    {
        // 0 appears in the denominator..
        lb = inf_rational(-1, 0);
        ub = inf_rational(1, 0);
    }
    else
    {
        inf_rational c_lb(1, 0);
        inf_rational c_ub(-1, 0);
        for (const auto &i : {lb / right.lb, lb / right.ub, ub / right.lb, ub / right.ub})
        {
            if (i < c_lb)
                c_lb = i;
            if (i > c_ub)
                c_ub = i;
        }
        lb = c_lb;
        ub = c_ub;
    }
    return *this;
}

interval &interval::operator+=(const inf_rational &right)
{
    lb += right;
    ub += right;
    return *this;
}
interval &interval::operator-=(const inf_rational &right)
{
    lb -= right;
    ub -= right;
    return *this;
}
interval &interval::operator*=(const inf_rational &right)
{
    if (right >= 0)
    {
        lb *= right;
        ub *= right;
    }
    else
    {
        inf_rational c_lb = lb;
        lb = ub * right;
        ub = c_lb * right;
    }
    return *this;
}
interval &interval::operator/=(const inf_rational &right)
{
    if (right >= 0)
    {
        lb /= right;
        ub /= right;
    }
    else
    {
        inf_rational c_lb = lb;
        lb = ub / right;
        ub = c_lb / right;
    }
    return *this;
}

interval interval::operator-() const { return (-ub, -lb); }

std::string interval::to_string() const { return "[" + lb.to_string() + ", " + ub.to_string() + "]"; }
}
