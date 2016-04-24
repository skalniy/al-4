#pragma once
#include "al-4.h"
using namespace std;

class ZeroDenominatorException : runtime_error {
public:
	ZeroDenominatorException() : runtime_error("Zero denominator in rational number.") {}
};


class ZeroSizeOfMatrix : runtime_error {
public:
	ZeroSizeOfMatrix() : runtime_error("Zero size of matrix.") {}
};


class BadSizeOfMatrix : runtime_error {
public:
	BadSizeOfMatrix() : runtime_error("Bad size of matrix.") {}
};


class FileNotFound : runtime_error {
public:
	FileNotFound() : runtime_error("File not found.") {}
};