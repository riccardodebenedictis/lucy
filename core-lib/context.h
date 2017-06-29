#pragma once

namespace lucy
{

class env;
class item;
class bool_item;
class arith_item;
class string_item;
class enum_item;

class expr;
class bool_expr;
class arith_expr;
class string_expr;
class enum_expr;

class context
{
public:
  context(env *const ptr);
  context(const context &orig);
  virtual ~context();

  env &operator*() const { return *ptr; }
  env *operator->() const { return ptr; }
  operator context() const { return context(ptr); }

  operator expr() const;
  operator bool_expr() const;
  operator arith_expr() const;
  operator string_expr() const;
  operator enum_expr() const;

  bool operator==(const context &right) const { return ptr == right.ptr; }
  bool operator!=(const context &right) const { return !(*this == right); }

protected:
  env *const ptr;
};

class expr : public context
{
public:
  expr(item *const ptr);
  expr(const expr &orig) : context(orig.ptr) {}
  virtual ~expr() {}

  item &operator*() const;
  item *operator->() const;
  operator expr() const;
};

class bool_expr : public expr
{
public:
  bool_expr(bool_item *const ptr);
  bool_expr(const bool_expr &orig);
  virtual ~bool_expr() {}

  bool_item &operator*() const;
  bool_item *operator->() const;
  operator bool_expr() const;
};

class arith_expr : public expr
{
public:
  arith_expr(arith_item *const ptr);
  arith_expr(const arith_expr &orig);
  virtual ~arith_expr() {}

  arith_item &operator*() const;
  arith_item *operator->() const;
  operator arith_expr() const;
};

class string_expr : public expr
{
public:
  string_expr(string_item *const ptr);
  string_expr(const string_expr &orig);
  virtual ~string_expr() {}

  string_item &operator*() const;
  string_item *operator->() const;
  operator string_expr() const;
};

class enum_expr : public expr
{
public:
  enum_expr(enum_item *const ptr);
  enum_expr(const enum_expr &orig);
  virtual ~enum_expr() {}

  enum_item &operator*() const;
  enum_item *operator->() const;
  operator enum_expr() const;
};
}