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
 * File:   lit.h
 * Author: Riccardo De Benedictis <riccardo.debenedictis@istc.cnr.it>
 *
 * Created on April 10, 2017, 11:41 AM
 */

#ifndef LIT_H
#define LIT_H

#include <iostream>

namespace smt
{

typedef size_t var;

class lit
{
  public:
    lit(var v, bool sign);

    lit operator!() const
    {
        return lit(v, !sign);
    }

    bool operator==(const lit &rhs) const
    {
        return v == rhs.v && sign == rhs.sign;
    }

    bool operator!=(const lit &rhs) const
    {
        return !operator==(rhs);
    }

    std::string to_string() const;

    friend std::ostream &operator<<(std::ostream &os, const lit &obj);

  public:
    var v;
    bool sign;
};
}

#endif /* LIT_H */