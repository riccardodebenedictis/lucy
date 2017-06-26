#pragma once

#include <istream>
#include <vector>
#include <string>

namespace lucy
{

enum symbol
{
  BOOL,          // 'bool'
  INT,           // 'int'
  REAL,          // 'real'
  STRING,        // 'string'
  TYPEDEF,       // 'typedef'
  ENUM,          // 'enum'
  CLASS,         // 'class'
  GOAL,          // 'goal'
  FACT,          // 'fact'
  PREDICATE,     // 'predicate'
  NEW,           // 'new'
  OR,            // 'or'
  THIS,          // 'this'
  VOID,          // 'void'
  TRUE,          // 'true'
  FALSE,         // 'false'
  RETURN,        // 'return'
  DOT,           // '.'
  COMMA,         // ','
  COLON,         // ':'
  SEMICOLON,     // ';'
  LPAREN,        // '('
  RPAREN,        // ')'
  LBRACKET,      // '['
  RBRACKET,      // ']'
  LBRACE,        // '{'
  RBRACE,        // '}'
  PLUS,          // '+'
  MINUS,         // '-'
  STAR,          // '*'
  SLASH,         // '/'
  AMP,           // '&'
  BAR,           // '|'
  EQ,            // '='
  GT,            // '>'
  LT,            // '<'
  BANG,          // '!'
  EQEQ,          // '=='
  LTEQ,          // '<='
  GTEQ,          // '>='
  BANGEQ,        // '!='
  IMPLICATION,   // '->'
  CARET,         // '^'
  ID,            // ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*
  IntLiteral,    // [0-9]+
  RealLiteral,   // [0-9]+ '.' [0-9]+)? | '.' [0-9]+
  StringLiteral, // '" . . ."'
  COMMENT,
  EOF_Symbol
};

class token
{
public:
  token(const symbol &sym, const int &start_line, const int &start_pos, const int &end_line, const int &end_pos) : sym(sym), start_line(start_line), start_pos(start_pos), end_line(end_line), end_pos(end_pos) {}
  virtual ~token() {}

public:
  const symbol sym;
  const int start_line;
  const int start_pos;
  const int end_line;
  const int end_pos;
};

class id_token : public token
{
public:
  id_token(const int &start_line, const int &start_pos, const int &end_line, const int &end_pos, const std::string &id) : token(symbol::ID, start_line, start_pos, end_line, end_pos), id(id) {}
  virtual ~id_token() {}

public:
  const std::string id;
};

class int_token : public token
{
public:
  int_token(const int &start_line, const int &start_pos, const int &end_line, const int &end_pos, const long &val) : token(symbol::IntLiteral, start_line, start_pos, end_line, end_pos), val(val) {}
  virtual ~int_token() {}

public:
  const long val;
};

class real_token : public token
{
public:
  real_token(const int &start_line, const int &start_pos, const int &end_line, const int &end_pos, const double &val) : token(symbol::RealLiteral, start_line, start_pos, end_line, end_pos), val(val) {}
  virtual ~real_token() {}

public:
  const double val;
};

class string_token : public token
{
public:
  string_token(const int &start_line, const int &start_pos, const int &end_line, const int &end_pos, const std::string &str) : token(symbol::StringLiteral, start_line, start_pos, end_line, end_pos), str(str) {}
  virtual ~string_token() {}

public:
  const std::string str;
};

class lexer
{
public:
  lexer(std::istream &is);
  lexer(const lexer &orig) = delete;
  virtual ~lexer();

  token *next();

private:
  token *mk_token(const symbol &sym)
  {
    token *tk = new token(sym, start_line, start_pos, end_line, end_pos);
    start_line = end_line;
    start_pos = end_pos;
    return tk;
  }

  token *mk_id_token(const std::string &id)
  {
    id_token *tk = new id_token(start_line, start_pos, end_line, end_pos, id);
    start_line = end_line;
    start_pos = end_pos;
    return tk;
  }

  token *mk_numeric_token(const std::string &str)
  {
    token *tk = nullptr;
    if (str.find('.') == str.npos)
    {
      tk = new int_token(start_line, start_pos, end_line, end_pos, std::stol(str));
    }
    else
    {
      tk = new real_token(start_line, start_pos, end_line, end_pos, std::stod(str));
    }
    start_line = end_line;
    start_pos = end_pos;
    return tk;
  }

  token *mk_string_token(const std::string &str)
  {
    string_token *tk = new string_token(start_line, start_pos, end_line, end_pos, str);
    start_line = end_line;
    start_pos = end_pos;
    return tk;
  }

  token *finish_id(std::vector<char> &str);
  token *finish_whitespaces();

  void error(const std::string &err);

private:
  std::istream &is;
  char ch;
  int start_line = 0;
  int start_pos = 0;
  int end_line = 0;
  int end_pos = 0;
};
}