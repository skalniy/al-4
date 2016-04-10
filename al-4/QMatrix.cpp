#include "QMatrix.h"



QMatrix::QMatrix(unsigned int m, unsigned int n)
{
	if ((m == 0) || (n == 0)) throw ZeroSizeOfMatrix();
	rows = m;
	columns = n;
	element = new Q*[rows];
	for (unsigned int i = 0; i < getRows(); i++)
		element[i] = new Q[getColumns()]();
}


QMatrix::~QMatrix()
{
	for (unsigned int i = 0; i < getRows(); i++)
		delete[] element[i];
	delete[] element;
}


QMatrix operator* (const QMatrix& lhs, const QMatrix& rhs) {
	if (lhs.getColumns() != rhs.getRows()) throw BadSizeOfMatrix();
	QMatrix result = QMatrix(lhs.getRows(), rhs.getColumns());

	for (unsigned int i = 0; i < lhs.getRows(); i++)
		for (unsigned int j = 0; j < rhs.getColumns(); j++)
			for (unsigned int k = 0; k < lhs.getColumns(); k++)
				result.element[i][j] = result.element[i][j] + lhs.element[i][k] * rhs.element[k][j];

	return result;
}
