#pragma once
#include "al-4.h"


class Q;

class QMatrix
{
private:
	unsigned int rows, columns;

public:
	QMatrix(unsigned int m = 1, unsigned int n = 1);
	~QMatrix();

	unsigned int getRows (void) const { return rows; }
	unsigned int getColumns(void) const { return columns; }

	Q** element;

	//Q operator() const (unsigned int i, unsigned int j) { return element[i][j]; }
	friend istream& operator>>(istream& in, QMatrix& mat);
	friend ostream& operator<<(ostream& out, const QMatrix& mat);
	friend QMatrix operator* (const QMatrix& lhs, const QMatrix& rhs);
	friend QMatrix operator+ (const QMatrix& lhs, const QMatrix& rhs);
	QMatrix transposition() const;
};

