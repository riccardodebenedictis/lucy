#pragma once

#include "visibility.h"
#include <unordered_map>
#include <vector>

#define THIS_KEYWORD "this"
#define RETURN_KEYWORD "return"

namespace lucy
{

class core;
class field;
class method;
class type;
class predicate;
class env;
class expr;

namespace ast
{
class field_declaration;
}

#pragma warning(disable : 4251)
class DLL_PUBLIC scope
{
	friend class ast::field_declaration;

  public:
	scope(core &cr, scope &scp);
	scope(const scope &orig) = delete;
	virtual ~scope();

	core &get_core() const { return cr; }
	scope &get_scope() const { return scp; }

	virtual field &get_field(const std::string &name) const;
	std::unordered_map<std::string, field *> get_fields() const noexcept;

	virtual method &get_method(const std::string &name, const std::vector<const type *> &ts) const;
	virtual std::vector<method *> get_methods() const noexcept;

	virtual type &get_type(const std::string &name) const;
	virtual std::unordered_map<std::string, type *> get_types() const noexcept;

	virtual predicate &get_predicate(const std::string &name) const;
	virtual std::unordered_map<std::string, predicate *> get_predicates() const noexcept;

  protected:
	core &cr;
	scope &scp;
	std::unordered_map<std::string, field *> fields;
};
}