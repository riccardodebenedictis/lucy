#pragma once

namespace lucy
{

class lexer;
class core;

class parser
{
public:
  parser(core &c);
  parser(const parser &orig) = delete;
  virtual ~parser();

private:
  core &c;
};
}