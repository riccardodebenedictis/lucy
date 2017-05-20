#include "field.h"

namespace lucy {

	field::field(const type& tp, const std::string& name, bool synthetic) : tp(tp), name(name), synthetic(synthetic) { }

	field::~field() { }
}