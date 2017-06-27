#pragma once

#include "scope.h"
#include "sat_core.h"
#include <string>

using namespace smt;

namespace lucy
{

class constructor;
class context;
class atom;

namespace ast
{
class typedef_declaration;
class enum_declaration;
class class_declaration;
}

#pragma warning(disable : 4251)
class DLL_PUBLIC type : public scope
{
  friend class core;
  friend class ast::typedef_declaration;
  friend class ast::enum_declaration;
  friend class ast::class_declaration;

public:
  type(core &cr, scope &scp, const std::string &name, bool primitive = false);
  type(const type &orig) = delete;
  virtual ~type();

  std::vector<type *> get_supertypes() const noexcept { return supertypes; }

  bool is_assignable_from(const type &t) const noexcept;

  virtual expr new_instance(context &ctx);
  virtual expr new_existential();

  std::vector<expr> get_instances() const noexcept { return instances; }

  constructor &get_constructor(const std::vector<const type *> &ts) const;
  std::vector<constructor *> get_constructors() const noexcept { return constructors; }

  field &get_field(const std::string &name) const override;

  method &get_method(const std::string &name, const std::vector<const type *> &ts) const override;
  std::vector<method *> get_methods() const noexcept override
  {
    std::vector<method *> c_methods;
    for (const auto &ms : methods)
    {
      c_methods.insert(c_methods.begin(), ms.second.begin(), ms.second.end());
    }
    return c_methods;
  }

  predicate &get_predicate(const std::string &name) const override;
  std::unordered_map<std::string, predicate *> get_predicates() const noexcept override { return predicates; }

  type &get_type(const std::string &name) const override;
  std::unordered_map<std::string, type *> get_types() const noexcept override { return types; }

protected:
  static void inherit(predicate &base, predicate &derived);

  virtual void new_predicate(predicate &p) {}

  void set_var(var ctr_var);
  void restore_var();

private:
  virtual void new_fact(atom &a) {}
  virtual void new_goal(atom &a) {}

public:
  const std::string name;
  const bool primitive;

protected:
  std::vector<type *> supertypes;
  std::vector<constructor *> constructors;
  std::unordered_map<std::string, std::vector<method *>> methods;
  std::unordered_map<std::string, type *> types;
  std::unordered_map<std::string, predicate *> predicates;
  std::vector<expr> instances;
};

class DLL_PUBLIC bool_type : public type
{
public:
  bool_type(core &cr);
  bool_type(const bool_type &that) = delete;
  virtual ~bool_type();

  expr new_instance(context &ctx) override;
};

class DLL_PUBLIC int_type : public type
{
public:
  int_type(core &cr);
  int_type(const int_type &that) = delete;
  virtual ~int_type();

  expr new_instance(context &ctx) override;
};

class DLL_PUBLIC real_type : public type
{
public:
  real_type(core &cr);
  real_type(const real_type &that) = delete;
  virtual ~real_type();

  expr new_instance(context &ctx) override;
};

class DLL_PUBLIC string_type : public type
{
public:
  string_type(core &cr);
  string_type(const string_type &that) = delete;
  virtual ~string_type();

  expr new_instance(context &ctx) override;
};
}