#pragma once

#include "visibility.h"
#include <string>

namespace smt {

	class DLL_PUBLIC interval {
	public:
		interval();
		interval(double value);
		interval(double lb, double ub);

		bool consistent() const;
		bool constant() const;
		bool intersecting(const interval& i) const;
		bool contains(const interval& i) const;

		bool operator!=(const interval& right) const;
		bool operator<(const interval& right) const;
		bool operator<=(const interval& right) const;
		bool operator==(const interval& right) const;
		bool operator>=(const interval& right) const;
		bool operator>(const interval& right) const;

		interval operator&&(const interval& rhs);

		interval operator+(const interval& rhs);
		interval operator+(const double& rhs);
		friend interval operator+(const double& lhs, const interval& rhs);

		interval operator-(const interval& rhs);
		interval operator-(const double& rhs);
		friend interval operator-(const double& lhs, const interval& rhs);

		interval operator*(const interval& rhs);
		interval operator*(const double& rhs);
		friend interval operator*(const double& lhs, const interval& rhs);

		interval operator/(const interval& rhs);
		interval operator/(const double& rhs);
		friend interval operator/(const double& lhs, const interval& rhs);

		interval operator+=(const interval& right);
		interval operator+=(const double& right);

		interval operator-=(const interval& right);
		interval operator-=(const double& right);

		interval operator*=(const interval& right);
		interval operator*=(const double& right);

		interval operator/=(const interval& right);
		interval operator/=(const double& right);

		interval operator-() const;

		std::string to_string() const;

	public:
		double lb;
		double ub;
	};
}
