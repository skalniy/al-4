#pragma once
#include "Q.h"
#include "al-4.h"


class Q;

class QMatrix
{
private:
	unsigned int rows, columns;

public:
	QMatrix(unsigned int m = 1, unsigned int n = 1);
	~QMatrix();
	QMatrix(QMatrix&& oth);


	unsigned int getRows (void) const { return rows; }
	unsigned int getColumns(void) const { return columns; }

	Q** element;

	Q& operator()(unsigned int i, unsigned int j) const;

	QMatrix transposition() const;

	QMatrix& operator=(QMatrix&& oth) {
		rows = oth.getRows();
		columns = oth.getColumns();
		element = oth.element;

		oth.element = nullptr;

		return *this;
	}

	friend istream& operator>>(istream& in, QMatrix& mat);
	friend ostream& operator<<(ostream& out, const QMatrix& mat);
	friend QMatrix operator* (const QMatrix& lhs, const QMatrix& rhs);
	friend QMatrix operator+ (const QMatrix& lhs, const QMatrix& rhs);
};

