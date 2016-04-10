#include "Q.h"



Q::Q(int _m, unsigned int _n) {
	if (n == 0) throw ZeroDenominatorException();
	m = _m;
	n = _n;
}


Q operator*(const Q& lhs, const Q& rhs) {

	return Q(lhs.m * rhs.m, lhs.n * rhs.n);
}


Q operator+(const Q& lhs, const Q& rhs) {

	return Q(lhs.m * rhs.n + lhs.n * rhs.m, lhs.n * rhs.n);
}


istream& operator>>(istream& in, Q& q) {
	unsigned int m, n;

	cin >> m;
	cin >> n;

	q = Q(m, n);

	return in;
}


ostream& operator<<(ostream& out, const Q& q) {
	cout << q.m << "/" << q.n << " ";

	return out;
}