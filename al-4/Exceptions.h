#pragma once
#include "al-4.h"


class ZeroDenominatorException {
public:
	ZeroDenominatorException() {
		std::cerr << "Zero denominator in rational number.";
	}
};


class ZeroSizeOfMatrix {
public:
	ZeroSizeOfMatrix() {
		std::cerr << "Zero size of matrix.";
	}
};


class BadSizeOfMatrix {
public:
	BadSizeOfMatrix() {
		std::cerr << "Bad size of matrix.";
	}
};