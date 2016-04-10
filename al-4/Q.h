#pragma once
class Q
{

public:
	Q(int m = 0, unsigned int n = 1) : n(n), m(m) { }

	int m;
	unsigned int n;

	friend Q operator* (const Q& lhs, const Q& rhs);
};

