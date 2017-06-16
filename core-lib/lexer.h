#pragma once

#include <istream>

namespace lucy
{

enum symbol
{
  BOOL,           // 'bool'
  INT,            // 'int'
  REAL,           // 'real'
  STRING,         // 'string'
  TYPE_DEF,       // 'type_def'
  ENUM,           // 'enum'
  CLASS,          // 'class'
  GOAL,           // 'goal'
  FACT,           // 'fact'
  PREDICATE,      // 'predicate'
  NEW,            // 'new'
  OR,             // 'or'
  THIS,           // 'this'
  VOID,           // 'void'
  TRUE,           // 'true'
  FALSE,          // 'false'
  RETURN,         // 'return'
  DOT,            // '.'
  COMMA,          // ','
  COLON,          // ':'
  SEMICOLON,      // ';'
  LPAREN,         // '('
  RPAREN,         // ')'
  LBRACKET,       // '['
  RBRACKET,       // ']'
  LBRACE,         // '{'
  RBRACE,         // '}'
  PLUS,           // '+'
  MINUS,          // '-'
  STAR,           // '*'
  SLASH,          // '/'
  AMP,            // '&'
  BAR,            // '|'
  EQUAL,          // '='
  GT,             // '>'
  LT,             // '<'
  BANG,           // '!'
  EQEQ,           // '=='
  LTEQ,           // '<='
  GTEQ,           // '>='
  BANGEQ,         // '!='
  IMPLICATION,    // '->'
  CARET,          // '^'
  ID,             // ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*
  NumericLiteral, // [0-9]+ ('.' [0-9]+)? | '.' [0-9]+
  StringLiteral,  // '" . . ."'
  EOF_Symbol
};

struct token
{
  symbol sym;
  int pos;
  int line;
};

class lexer
{
public:
  lexer(std::istream &is);
  lexer(const lexer &orig) = delete;
  virtual ~lexer();

  token next();

private:
  std::istream &is;
};
}