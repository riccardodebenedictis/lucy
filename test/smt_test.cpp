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

	TEST_METHOD(TestLA0) {
		sat_core c;
		la_theory la(c);

		var x0 = la.new_var();
		var x1 = la.new_var();

		var leq_0 = la.new_leq(lin(x0, 1), lin(-4));
		var geq_0 = la.new_geq(lin(x0, 1), lin(-8));
		var leq_1 = la.new_leq(lin(x0, -1) + lin(x1, 1), lin(1));
		var geq_1 = la.new_geq(lin(x0, 1) + lin(x1, 1), lin(-3));

		bool a;
		a = c.assume(lit(leq_0, true)) && c.check();
		Assert::IsTrue(a);
		a = c.assume(lit(geq_0, true)) && c.check();
		Assert::IsTrue(a);
		a = c.assume(lit(leq_1, true)) && c.check();
		Assert::IsTrue(a);
		a = c.assume(lit(geq_1, true)) && c.check();
		Assert::IsTrue(a);
	}

	TEST_METHOD(testLA1) {
		sat_core c;
		la_theory la(c);

		var b0 = c.new_var();
		var x0 = la.new_var();

		var b5 = la.new_geq(lin(x0, 1), lin(10));
		var b6 = la.new_leq(lin(x0, 1), lin(0));

		bool cs;
		cs = c.new_clause({ lit(b0, false), lit(b5, true) });
		Assert::IsTrue(cs);
		cs = c.new_clause({ lit(b5, false), lit(b6, true) });
		Assert::IsTrue(cs);

		bool p = c.check();
		Assert::IsTrue(p);

		bool a;
		a = c.assume(lit(b0, true)) && c.check();
		Assert::IsTrue(a);
	}

	TEST_METHOD(testTheoryPropagation) {
		sat_core c;
		la_theory la(c);

		var x0 = la.new_var();
		var b2 = la.new_geq(lin(x0, 1), lin(1));
		var b3 = la.new_geq(lin(x0, 1), lin(0));
		var b4 = la.new_leq(lin(x0, 1), lin(-1));

		bool a;
		a = c.assume(lit(b2, true)) && c.check();
		Assert::IsTrue(a);
		Assert::IsTrue(True == c.value(b3));
		Assert::IsTrue(False == c.value(b4));

		var x1 = la.new_var();
		var b5 = la.new_leq(lin(x1, 1), lin(-1));
		var b6 = la.new_leq(lin(x1, 1), lin(0));
		var b7 = la.new_geq(lin(x1, 1), lin(1));

		a = c.assume(lit(b5, true)) && c.check();
		Assert::IsTrue(a);
		Assert::IsTrue(True == c.value(b6));
		Assert::IsTrue(False == c.value(b7));
	}

	};
}