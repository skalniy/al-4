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


	unsigned int rows_count (void) const { return rows; } // честно говоря, get в названии метода не слишком и нужен.
	unsigned int columns_count(void) const { return columns; } // Метод columns() был бы неплох, нет?

	Q** element; // public?

	Q& operator()(unsigned int i, unsigned int j) const; // const operator, имхо, лучше бы возвращал const reference
	// можно сделать еще неконстантный, вот он вернет неконстантную ссылку

	QMatrix transposition() const;

	QMatrix& operator=(QMatrix&& oth) {
		rows = oth.rows_count();
		columns = oth.columns_count();
		element = oth.element;

		oth.element = nullptr;

		return *this;
	}

	friend istream& operator>>(istream& in, QMatrix& mat);
	friend ostream& operator<<(ostream& out, const QMatrix& mat);
	friend QMatrix operator* (const QMatrix& lhs, const QMatrix& rhs);
	friend QMatrix operator+ (const QMatrix& lhs, const QMatrix& rhs);
};

