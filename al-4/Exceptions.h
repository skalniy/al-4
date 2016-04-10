#pragma once
#include "al-4.h"


class ZeroDenominatorException {
public:
	ZeroDenominatorException() {
		std::cerr << "Zero denominator in rational number.";
		terminate();
	}
};