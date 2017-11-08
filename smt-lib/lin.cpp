#include "lin.h"
#include <string>

namespace smt
{

lin::lin() : known_term(0) {}
lin::lin(const rational &known_term) : known_term(known_term) {}
lin::lin(const var v, const rational &c) : known_term(0) { vars.insert({v, c}); }

lin lin::operator+(const lin &right) const
{
    lin res = *this;
    for (auto &term : right.vars)
        if (res.vars.find(term.first) == res.vars.end())
            res.vars.insert(term);
        else
            res.vars[term.first] += term.second;
    for (auto it = res.vars.begin(); it != res.vars.end();)
        if (it->second == rational::ZERO)
            it = res.vars.erase(it);
        else
            ++it;
    res.known_term += known_term;
    return res;
}

lin lin::operator+(const rational &right) const
{
    lin res = *this;
    res.known_term += right;
    return res;
}

lin operator+(const rational &lhs, const lin &rhs)
{
    lin res = rhs;
    res.known_term += lhs;
    return res;
}

lin lin::operator-(const lin &right) const
{
    lin res = *this;
    for (auto &term : right.vars)
        if (res.vars.find(term.first) == res.vars.end())
            res.vars.insert({term.first, -term.second});
        else
            res.vars[term.first] -= term.second;
    for (auto it = res.vars.begin(); it != res.vars.end();)
        if (it->second == rational::ZERO)
            it = res.vars.erase(it);
        else
            ++it;
    res.known_term -= right.known_term;
    return res;
}

lin lin::operator-(const rational &right) const
{
    lin res = *this;
    res.known_term -= right;
    return res;
}

lin operator-(const rational &lhs, const lin &rhs)
{
    lin res = -rhs;
    res.known_term += lhs;
    return res;
}

lin lin::operator*(const rational &right) const
{
    lin res = *this;
    for (auto &term : res.vars)
    {
        term.second *= right;
    }
    res.known_term *= right;
    return res;
}

lin operator*(const rational &lhs, const lin &rhs)
{
    lin res = rhs;
    for (auto &term : res.vars)
        term.second *= lhs;
    res.known_term *= lhs;
    return res;
}

lin lin::operator/(const rational &right) const
{
    lin res = *this;
    for (auto &term : res.vars)
        term.second /= right;
    res.known_term /= right;
    return res;
}

lin lin::operator+=(const lin &right)
{
    for (auto &term : right.vars)
        if (vars.find(term.first) == vars.end())
            vars.insert(term);
        else
            vars[term.first] += term.second;
    for (auto it = vars.begin(); it != vars.end();)
        if (it->second == rational::ZERO)
            it = vars.erase(it);
        else
            ++it;
    known_term += right.known_term;
    return *this;
}

lin lin::operator+=(const std::pair<var, rational> &term)
{
    if (vars.find(term.first) == vars.end())
        vars.insert({term.first, -term.second});
    else
        vars[term.first] += term.second;

    if (vars[term.first] == rational::ZERO)
        vars.erase(term.first);
    return *this;
}

lin lin::operator+=(const rational &right)
{
    known_term += right;
    return *this;
}

lin lin::operator-=(const lin &right)
{
    for (auto &term : right.vars)
        if (vars.find(term.first) == vars.end())
            vars.insert({term.first, -term.second});
        else
            vars[term.first] -= term.second;
    for (auto it = vars.begin(); it != vars.end();)
        if (it->second == rational::ZERO)
            it = vars.erase(it);
        else
            ++it;
    known_term -= right.known_term;
    return *this;
}

lin lin::operator-=(const std::pair<var, rational> &term)
{
    if (vars.find(term.first) == vars.end())
        vars.insert({term.first, -term.second});
    else
        vars[term.first] -= term.second;
    if (vars[term.first] == rational::ZERO)
        vars.erase(term.first);
    return *this;
}

lin lin::operator-=(const rational &right)
{
    known_term -= right;
    return *this;
}

lin lin::operator*=(const rational &right)
{
    for (auto &term : vars)
        term.second *= right;
    known_term *= right;
    for (auto it = vars.begin(); it != vars.end();)
        if (it->second == rational::ZERO)
            it = vars.erase(it);
        else
            ++it;
    return *this;
}

lin lin::operator/=(const rational &right)
{
    for (auto &term : vars)
        term.second /= right;
    known_term /= right;
    for (auto it = vars.begin(); it != vars.end();)
        if (it->second == rational::ZERO)
            it = vars.erase(it);
        else
            ++it;
    return *this;
}

lin lin::operator-() const
{
    lin res;
    for (auto &term : vars)
        res.vars[term.first] = -term.second;
    res.known_term = -known_term;
    return res;
}

std::string lin::to_string() const
{
    if (vars.empty())
        return known_term.to_string();

    std::string s;
    for (std::map<var, rational>::const_iterator it = vars.begin(); it != vars.end(); ++it)
    {
        if (it == vars.begin())
        {
            if (it->second == rational::ONE)
                s += "x" + std::to_string(it->first);
            else if (it->second == -rational::ONE)
                s += "-x" + std::to_string(it->first);
            else
                s += it->second.to_string() + "*x" + std::to_string(it->first);
        }
        else
        {
            if (it->second == rational::ONE)
                s += " + x" + std::to_string(it->first);
            else if (it->second == -rational::ONE)
                s += " - x" + std::to_string(it->first);
            else if (it->second.is_positive())
                s += " + " + it->second.to_string() + "*x" + std::to_string(it->first);
            else
                s += " - " + (-it->second).to_string() + "*x" + std::to_string(it->first);
        }
    }

    if (known_term.is_positive())
        s += " + " + known_term.to_string();
    if (known_term.is_negative())
        s += " - " + (-known_term).to_string();
    return s;
}
}
