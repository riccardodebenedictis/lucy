#pragma once

#include <string>

namespace smt
{

typedef size_t var;

class lit
{
public:
  lit(var v = -1, bool sign = true);
  virtual ~lit();

  lit operator!() const { return lit(v, !sign); }
  bool operator<(const lit &rhs) const { return v < rhs.v || (v == rhs.v && sign < rhs.sign); }
  bool operator==(const lit &rhs) const { return v == rhs.v && sign == rhs.sign; }
  bool operator!=(const lit &rhs) const { return !operator==(rhs); }

  std::string to_string() const;

public:
  var v;
  bool sign;
};
}