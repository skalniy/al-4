#pragma once
#include "al-4.h"
using namespace std;

class ZeroDenominatorException {
public:
	ZeroDenominatorException() {
		std::cerr << "Zero denominator in rational number." << endl; // стоит оставить ответственность за вывод вызывающему коду
		// Предлагаю возвращать строку в методе what()
	}
};


class ZeroSizeOfMatrix {
public:
	ZeroSizeOfMatrix() {
		std::cerr << "Zero size of matrix." << endl;
	}
};


class BadSizeOfMatrix {
public:
	BadSizeOfMatrix() {
		std::cerr << "Bad size of matrix." << endl;
	}
};


class FileNotFound {
public:
	FileNotFound() {
		std::cerr << "File not found." << endl;
	}
};