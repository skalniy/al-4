#include "Q.h"



Q operator* (const Q& lhs, const Q& rhs) {

	return Q(lhs.m * rhs.m, lhs.n * rhs.n);
}