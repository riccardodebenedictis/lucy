#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cg;

namespace test {
	TEST_CLASS(smt_test) {
public:
	TEST_METHOD(TestCG0) {
		causal_graph g;
		gui::vtk_graph vtk_g(g);
	}

	};
}