#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace smt;

namespace test {
	TEST_CLASS(smt_test) {
public:
	TEST_METHOD(TestSAT0) {
		sat_core c;

		var b0 = c.new_var();
		var b1 = c.new_var();
		var b2 = c.new_var();
		var b3 = c.new_var();
		var b4 = c.new_var();
		var b5 = c.new_var();
		var b6 = c.new_var();
		var b7 = c.new_var();
		var b8 = c.new_var();

		bool cs;
		cs = c.new_clause({ lit(b0, true), lit(b1, true) });
		Assert::IsTrue(cs);
		cs = c.new_clause({ lit(b0, true), lit(b2, true), lit(b6, true) });
		Assert::IsTrue(cs);
		cs = c.new_clause({ lit(b1, false), lit(b2, false), lit(b3, true) });
		Assert::IsTrue(cs);
		cs = c.new_clause({ lit(b3, false), lit(b4, true), lit(b7, true) });
		Assert::IsTrue(cs);
		cs = c.new_clause({ lit(b3, false), lit(b5, true), lit(b8, true) });
		Assert::IsTrue(cs);
		cs = c.new_clause({ lit(b4, false), lit(b5, false) });
		Assert::IsTrue(cs);

		bool a;
		a = c.assume(lit(b6, false)) && c.check();
		Assert::IsTrue(a);
		a = c.assume(lit(b7, false)) && c.check();
		Assert::IsTrue(a);
		a = c.assume(lit(b8, false)) && c.check();
		Assert::IsTrue(a);
		a = c.assume(lit(b0, false)) && c.check();
		Assert::IsTrue(a);
	}

	};
}