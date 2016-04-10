#include "Q.h"



Q::Q(int m, unsigned int n) {
	if (n == 0) throw ZeroDenominatorException();
	this->m = m;
	this->n = n;
}


Q operator* (const Q& lhs, const Q& rhs) {

	return Q(lhs.m * rhs.m, lhs.n * rhs.n);
}


Q operator+ (const Q& lhs, const Q& rhs) {

	return Q(lhs.m * rhs.n + lhs.n * rhs.m, lhs.n * rhs.n);
}