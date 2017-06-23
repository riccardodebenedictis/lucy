#pragma once

#include <vector>
#include <string>

namespace lucy
{

namespace ast
{

class expression;
class statement;

class declaration
{
public:
  declaration();
  declaration(const declaration &orig) = delete;
  virtual ~declaration();
};

class type_declaration : public declaration
{
public:
  type_declaration(const std::string &n);
  type_declaration(const type_declaration &orig) = delete;
  virtual ~type_declaration();

private:
  std::string name;
};

class typedef_declaration : public type_declaration
{
public:
  typedef_declaration(const std::string &n, const std::string &pt, expression *const e);
  typedef_declaration(const typedef_declaration &orig) = delete;
  virtual ~typedef_declaration();

private:
  std::string primitive_type;
  expression *const xpr;
};

class enum_declaration : public type_declaration
{
public:
  enum_declaration(const std::string &n, const std::vector<std::string> &es, const std::vector<std::vector<std::string>> &trs);
  enum_declaration(const enum_declaration &orig) = delete;
  virtual ~enum_declaration();

private:
  std::vector<std::string> enums;
  std::vector<std::vector<std::string>> type_refs;
};

class variable_declaration : public declaration
{
public:
  variable_declaration(const std::string &n, expression *const e = nullptr);
  variable_declaration(const variable_declaration &orig) = delete;
  virtual ~variable_declaration();

private:
  std::string name;
  expression *const xpr;
};

class field_declaration : public declaration
{
public:
  field_declaration(const std::vector<std::string> &tp, const std::vector<variable_declaration *> &ds);
  field_declaration(const field_declaration &orig) = delete;
  virtual ~field_declaration();

private:
  std::vector<std::string> type;
  std::vector<variable_declaration *> declarations;
};

class constructor_declaration : public declaration
{
public:
  constructor_declaration(const std::vector<std::pair<std::vector<std::string>, std::string>> &pars, const std::vector<std::pair<std::string, std::vector<expression *>>> &il, const std::vector<statement *> &stmnts);
  constructor_declaration(const constructor_declaration &orig) = delete;
  virtual ~constructor_declaration();

private:
  std::vector<std::pair<std::vector<std::string>, std::string>> parameters;
  std::vector<std::pair<std::string, std::vector<expression *>>> init_list;
  std::vector<statement *> statements;
};

class method_declaration : public declaration
{
public:
  method_declaration(const std::vector<std::string> &rt, const std::string &n, const std::vector<std::pair<std::vector<std::string>, std::string>> &pars, const std::vector<statement *> &stmnts);
  method_declaration(const method_declaration &orig) = delete;
  virtual ~method_declaration();

private:
  std::vector<std::string> return_type;
  std::string name;
  std::vector<std::pair<std::vector<std::string>, std::string>> parameters;
  std::vector<statement *> statements;
};

class predicate_declaration : public declaration
{
public:
  predicate_declaration(const std::string &n, const std::vector<std::pair<std::vector<std::string>, std::string>> &pars, const std::vector<std::vector<std::string>> &pl, const std::vector<statement *> &stmnts);
  predicate_declaration(const predicate_declaration &orig) = delete;
  virtual ~predicate_declaration();

private:
  std::string name;
  std::vector<std::pair<std::vector<std::string>, std::string>> parameters;
  std::vector<std::vector<std::string>> predicate_list;
  std::vector<statement *> statements;
};

class class_declaration : public type_declaration
{
public:
  class_declaration(const std::string &n, const std::vector<std::vector<std::string>> &bcs, const std::vector<field_declaration *> &fs, const std::vector<constructor_declaration *> &cs, const std::vector<method_declaration *> &ms, const std::vector<predicate_declaration *> &ps, const std::vector<type_declaration *> &ts);
  class_declaration(const class_declaration &orig) = delete;
  virtual ~class_declaration();

private:
  std::vector<std::vector<std::string>> base_classes;
  std::vector<field_declaration *> fields;
  std::vector<constructor_declaration *> constructors;
  std::vector<method_declaration *> methods;
  std::vector<predicate_declaration *> predicates;
  std::vector<type_declaration *> types;
};
}
}