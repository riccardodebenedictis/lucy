#pragma once

#include "flaw.h"
#include "item.h"
#include "resolver.h"

using namespace lucy;

namespace cg
{

class enum_flaw : public flaw
{
public:
	enum_flaw(causal_graph &graph, enum_item &e_itm);
	enum_flaw(const enum_flaw &orig) = delete;
	virtual ~enum_flaw();

	std::string get_label() const override { return "enum"; }

private:
	void compute_resolvers() override;

	class choose_value : public resolver
	{
	public:
		choose_value(causal_graph &graph, enum_flaw &enm_flaw, set_item &val);
		choose_value(const choose_value &that) = delete;
		virtual ~choose_value();

		std::string get_label() const override { return "val"; }

	private:
		bool apply() override;

	private:
		var v;
		set_item &val;
	};

private:
	enum_item &e_itm;
};
}