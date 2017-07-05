#include "field.h"

namespace lucy
{

field::field(const type &tp, const std::string &name, const ast::expression *const e, bool synthetic) : tp(tp), name(name), xpr(e), synthetic(synthetic) {}
field::~field() {}
}