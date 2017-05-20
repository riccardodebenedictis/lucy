#include "lit.h"

namespace smt {

	lit::lit(var v, bool sign) : v(v), sign(sign) {}

	lit::~lit() {}

	std::string lit::to_string() const {
		if (sign) {
			return "b" + std::to_string(v);
		}
		else {
			return"!b" + std::to_string(v);
		}
	}
}