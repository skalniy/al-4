#pragma once
#include "al-4.h"



using namespace std;


class Q
{
public:
	Q(int m = 0, unsigned int n = 1);

	int m;
	unsigned int n;

	friend Q operator*(const Q& lhs, const Q& rhs);
	friend Q operator+(const Q& lhs, const Q& rhs);
	friend std::istream& operator>>(std::istream& in, Q& q);
	friend std::ostream& operator<<(std::ostream& out, const Q& q);
};

