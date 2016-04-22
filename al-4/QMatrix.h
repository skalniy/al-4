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


	unsigned int getRows (void) const { return rows; } // честно говоря, get в названии метода не слишком и нужен.
	unsigned int getColumns(void) const { return columns; } // Метод columns() был бы неплох, нет?

	Q** element; // public?

	Q& operator()(unsigned int i, unsigned int j) const; // const operator, имхо, лучше бы возвращал const reference
	// можно сделать еще неконстантный, вот он вернет неконстантную ссылку

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

