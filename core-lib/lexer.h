#pragma once

#include <istream>
#include <vector>
#include <string>

namespace lucy
{

enum symbol
{
  BOOL_ID,          // 'bool'
  INT_ID,           // 'int'
  REAL_ID,          // 'real'
  STRING_ID,        // 'string'
  TYPEDEF_ID,       // 'typedef'
  ENUM_ID,          // 'enum'
  CLASS_ID,         // 'class'
  GOAL_ID,          // 'goal'
  FACT_ID,          // 'fact'
  PREDICATE_ID,     // 'predicate'
  NEW_ID,           // 'new'
  OR_ID,            // 'or'
  THIS_ID,          // 'this'
  VOID_ID,          // 'void'
  TRUE_ID,          // 'true'
  FALSE_ID,         // 'false'
  RETURN_ID,        // 'return'
  DOT_ID,           // '.'
  COMMA_ID,         // ','
  COLON_ID,         // ':'
  SEMICOLON_ID,     // ';'
  LPAREN_ID,        // '('
  RPAREN_ID,        // ')'
  LBRACKET_ID,      // '['
  RBRACKET_ID,      // ']'
  LBRACE_ID,        // '{'
  RBRACE_ID,        // '}'
  PLUS_ID,          // '+'
  MINUS_ID,         // '-'
  STAR_ID,          // '*'
  SLASH_ID,         // '/'
  AMP_ID,           // '&'
  BAR_ID,           // '|'
  EQ_ID,            // '='
  GT_ID,            // '>'
  LT_ID,            // '<'
  BANG_ID,          // '!'
  EQEQ_ID,          // '=='
  LTEQ_ID,          // '<='
  GTEQ_ID,          // '>='
  BANGEQ_ID,        // '!='
  IMPLICATION_ID,   // '->'
  CARET_ID,         // '^'
  ID_ID,            // ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*
  IntLiteral_ID,    // [0-9]+
  RealLiteral_ID,   // [0-9]+ '.' [0-9]+)? | '.' [0-9]+
  StringLiteral_ID, // '" . . ."'
  EOF_ID
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
  id_token(const int &start_line, const int &start_pos, const int &end_line, const int &end_pos, const std::string &id) : token(ID_ID, start_line, start_pos, end_line, end_pos), id(id) {}
  virtual ~id_token() {}

public:
  const std::string id;
};

class int_token : public token
{
public:
  int_token(const int &start_line, const int &start_pos, const int &end_line, const int &end_pos, const long &val) : token(IntLiteral_ID, start_line, start_pos, end_line, end_pos), val(val) {}
  virtual ~int_token() {}

public:
  const long val;
};

class real_token : public token
{
public:
  real_token(const int &start_line, const int &start_pos, const int &end_line, const int &end_pos, const double &val) : token(RealLiteral_ID, start_line, start_pos, end_line, end_pos), val(val) {}
  virtual ~real_token() {}

public:
  const double val;
};

class string_token : public token
{
public:
  string_token(const int &start_line, const int &start_pos, const int &end_line, const int &end_pos, const std::string &str) : token(StringLiteral_ID, start_line, start_pos, end_line, end_pos), str(str) {}
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