/*
 * Copyright (C) 2017 Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   utils.h
 * Author: Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 *
 * Created on April 10, 2017, 5:49 PM
 */

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

namespace smt
{

template <typename T>
std::vector<std::vector<T>> combinations(const std::vector<T> &v, int n)
{
    std::vector<std::vector<T>> combs;
    std::string bitmask(n, 1);   // K leading 1's
    bitmask.resize(v.size(), 0); // N-K trailing 0's

    // print integers and permute bitmask
    do
    {
        std::vector<T> c_comb;
        c_comb.reserve(n);
        // [0..N-1] integers
        for (size_t i = 0; i < v.size(); ++i)
        {
            if (bitmask[i])
                c_comb.push_back(v[i]);
        }
        combs.push_back(c_comb);
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
    return combs;
}

template <typename T, typename Q>
std::vector<T> get_keys(const std::map<T, Q> &m)
{
    std::vector<T> keys;
    for (const auto &p : m)
    {
        keys.push_back(p.first);
    }
    return keys;
}

template <typename T, typename Q>
std::vector<T> get_keys(const std::unordered_map<T, Q> &m)
{
    std::vector<T> keys;
    for (const auto &p : m)
    {
        keys.push_back(p.first);
    }
    return keys;
}
}

#endif /* UTILS_H */