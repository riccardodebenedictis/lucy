#include "interval.h"

#include <limits>
#include <algorithm>

namespace smt
{

interval::interval() : lb(-std::numeric_limits<double>::infinity()), ub(std::numeric_limits<double>::infinity()) {}
interval::interval(double value) : lb(value), ub(value) {}
interval::interval(double lb, double ub) : lb(lb), ub(ub) {}

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

interval interval::operator&&(const interval &rhs) const { return interval(std::max(lb, rhs.lb), std::min(ub, rhs.ub)); }

interval interval::operator+(const interval &rhs) const { return interval(lb + rhs.lb, ub + rhs.ub); }
interval interval::operator-(const interval &rhs) const { return interval(lb - rhs.ub, ub - rhs.lb); }
interval interval::operator*(const interval &rhs) const
{
    interval result(std::numeric_limits<double>::infinity(), -std::numeric_limits<double>::infinity());
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
        interval result(std::numeric_limits<double>::infinity(), -std::numeric_limits<double>::infinity());
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

interval interval::operator+(const double &rhs) const { return interval(lb + rhs, ub + rhs); }
interval interval::operator-(const double &rhs) const { return interval(lb - rhs, ub - rhs); }
interval interval::operator*(const double &rhs) const
{
    if (rhs >= 0)
        return interval(lb * rhs, ub * rhs);
    else
        return interval(ub * rhs, lb * rhs);
}
interval interval::operator/(const double &rhs) const
{
    if (rhs >= 0)
        return interval(lb / rhs, ub / rhs);
    else
        return interval(ub / rhs, lb / rhs);
}

interval operator+(const double &lhs, const interval &rhs) { return interval(lhs + rhs.lb, lhs + rhs.ub); }
interval operator-(const double &lhs, const interval &rhs) { return interval(lhs - rhs.ub, lhs - rhs.lb); }
interval operator*(const double &lhs, const interval &rhs)
{
    if (lhs >= 0)
        return interval(rhs.lb * lhs, rhs.ub * lhs);
    else
        return interval(rhs.ub * lhs, rhs.lb * lhs);
}
interval operator/(const double &lhs, const interval &rhs)
{
    if (rhs.lb <= 0 && rhs.ub >= 0) // 0 appears in the denominator..
        return interval();
    else
    {
        interval result(std::numeric_limits<double>::infinity(), -std::numeric_limits<double>::infinity());
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
    double c_lb = std::numeric_limits<double>::infinity();
    double c_ub = -std::numeric_limits<double>::infinity();
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
        lb = -std::numeric_limits<double>::infinity();
        ub = std::numeric_limits<double>::infinity();
    }
    else
    {
        double c_lb = std::numeric_limits<double>::infinity();
        double c_ub = -std::numeric_limits<double>::infinity();
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

interval &interval::operator+=(const double &right)
{
    lb += right;
    ub += right;
    return *this;
}
interval &interval::operator-=(const double &right)
{
    lb -= right;
    ub -= right;
    return *this;
}
interval &interval::operator*=(const double &right)
{
    if (right >= 0)
    {
        lb *= right;
        ub *= right;
    }
    else
    {
        double c_lb = lb;
        lb = ub * right;
        ub = c_lb * right;
    }
    return *this;
}
interval &interval::operator/=(const double &right)
{
    if (right >= 0)
    {
        lb /= right;
        ub /= right;
    }
    else
    {
        double c_lb = lb;
        lb = ub / right;
        ub = c_lb / right;
    }
    return *this;
}

interval interval::operator-() const { return (-ub, -lb); }

std::string interval::to_string() const { return "[" + std::to_string(lb) + ", " + std::to_string(ub) + "]"; }
}
