#pragma once
#include "al-4.h"


class Q;

class QMatrix
{
private:
	unsigned int rows, columns;

public:
	QMatrix(unsigned int m, unsigned int n);
	~QMatrix();

	unsigned int getRows (void) const { return rows; }
	unsigned int getColumns(void) const { return columns; }

	Q** element;

	//Q operator() const (unsigned int i, unsigned int j) { return element[i][j]; }
};

