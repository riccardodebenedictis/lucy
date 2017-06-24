#include "declaration.h"

namespace lucy
{

namespace ast
{

declaration::declaration() {}
declaration::~declaration() {}

type_declaration::type_declaration(const std::string &n) : name(n) {}
type_declaration::~type_declaration() {}

typedef_declaration::typedef_declaration(const std::string &n, const std::string &pt, const expression *const e) : type_declaration(n), primitive_type(pt), xpr(e) {}
typedef_declaration::~typedef_declaration() {}

enum_declaration::enum_declaration(const std::string &n, const std::vector<std::string> &es, const std::vector<std::vector<std::string>> &trs) : type_declaration(n), enums(es), type_refs(trs) {}
enum_declaration::~enum_declaration() {}

variable_declaration::variable_declaration(const std::string &n, const expression *const e) : name(n), xpr(e) {}
variable_declaration::~variable_declaration() {}

field_declaration::field_declaration(const std::vector<std::string> &tp, const std::vector<variable_declaration *> &ds) : type(tp), declarations(ds) {}
field_declaration::~field_declaration() {}

constructor_declaration::constructor_declaration(const std::vector<std::pair<std::vector<std::string>, std::string>> &pars, const std::vector<std::pair<std::string, std::vector<expression *>>> &il, const std::vector<statement *> &stmnts) : parameters(pars), init_list(il), statements(stmnts) {}
constructor_declaration::~constructor_declaration() {}

method_declaration::method_declaration(const std::vector<std::string> &rt, const std::string &n, const std::vector<std::pair<std::vector<std::string>, std::string>> &pars, const std::vector<statement *> &stmnts) : return_type(rt), name(n), parameters(pars), statements(stmnts) {}
method_declaration::~method_declaration() {}

predicate_declaration::predicate_declaration(const std::string &n, const std::vector<std::pair<std::vector<std::string>, std::string>> &pars, const std::vector<std::vector<std::string>> &pl, const std::vector<statement *> &stmnts) : name(n), parameters(pars), predicate_list(pl), statements(stmnts) {}
predicate_declaration::~predicate_declaration() {}

class_declaration::class_declaration(const std::string &n, const std::vector<std::vector<std::string>> &bcs, const std::vector<field_declaration *> &fs, const std::vector<constructor_declaration *> &cs, const std::vector<method_declaration *> &ms, const std::vector<predicate_declaration *> &ps, const std::vector<type_declaration *> &ts) : type_declaration(n), base_classes(bcs), fields(fs), constructors(cs), methods(ms), predicates(ps), types(ts) {}
class_declaration::~class_declaration() {}
}
}