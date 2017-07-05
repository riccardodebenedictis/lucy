#include "scope.h"
#include "env.h"
#include "field.h"

namespace lucy
{

scope::scope(core &cr, scope &scp) : cr(cr), scp(scp) {}

scope::~scope()
{
	for (const auto &f : fields)
		delete f.second;
}

field &scope::get_field(const std::string &name) const
{
	if (fields.find(name) != fields.end())
		return *fields.at(name);

	// if not here, check any enclosing scope
	return scp.get_field(name);
}

std::unordered_map<std::string, field *> scope::get_fields() const noexcept { return fields; }

method &scope::get_method(const std::string &name, const std::vector<const type *> &ts) const { return scp.get_method(name, ts); }
std::vector<method *> scope::get_methods() const noexcept { return scp.get_methods(); }

type &scope::get_type(const std::string &name) const { return scp.get_type(name); }
std::unordered_map<std::string, type *> scope::get_types() const noexcept { return scp.get_types(); }

predicate &scope::get_predicate(const std::string &name) const { return scp.get_predicate(name); }
std::unordered_map<std::string, predicate *> scope::get_predicates() const noexcept { return scp.get_predicates(); }
}