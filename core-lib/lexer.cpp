#include "lexer.h"

namespace lucy
{

lexer::lexer(std::istream &is) : is(is) {}

lexer::~lexer() {}

token lexer::next()
{
    return {symbol::EOF_Symbol, 0, 0};
}
}