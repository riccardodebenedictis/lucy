#include "lit.h"

namespace smt
{

lit::lit(var v, bool sign) : v(v), sign(sign) {}

lit::~lit() {}

std::string lit::to_string() const
{
	if (sign)
	{
		return "{ \"var\" : \"b" + std::to_string(v) + "\", \"sign\" : true }";
	}
	else
	{
		return "{ \"var\" : \"b" + std::to_string(v) + "\", \"sign\" : false }";
	}
}
}