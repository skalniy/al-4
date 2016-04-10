#include "QMatrix.h"



QMatrix::QMatrix(unsigned int m, unsigned int n)
{
	if ((m == 0) || (n == 0)) throw ZeroSizeOfMatrix();
	rows = m;
	columns = n;
	element = new Q*[getRows()];
	for (unsigned int i = 0; i < getRows(); i++) {
		element[i] = new Q[getColumns()]();
		for (unsigned int j = 0; j < getColumns(); j++)
			element[i][j] = Q();
	}
}


QMatrix::~QMatrix()
{
	for (unsigned int i = 0; i < getRows(); i++)
		delete element[i];
	delete element;
}


QMatrix QMatrix::transposition() const {
	QMatrix result = QMatrix(getColumns(), getRows());

	for (int i = 0; i < getRows(); i++)
		for (int j = 0; j < getColumns(); j++)
			result.element[j][i] = element[i][j];

	return result;
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


QMatrix operator+ (const QMatrix& lhs, const QMatrix& rhs) {
	QMatrix result = QMatrix(lhs.getRows(), rhs.getColumns());

	for (int i = 0; i < result.getRows(); i++)
		for (int j = 0; j < result.getColumns(); j++)
			result.element[i][j] = lhs.element[i][j] + rhs.element[i][j];

	return result;
}


istream& operator>>(istream& in, QMatrix& mat) {
	for (int i = 0; i < mat.getRows(); i++)
		for (int j = 0; j < mat.getColumns(); j++) {
			cout << "[" << i << "," << j << "]";
			cin >> mat.element[i][j];
		}

	return in;
}


ostream& operator<<(ostream& out, const QMatrix& mat) {
	for (int i = 0; i < mat.getRows(); i++) {
		for (int j = 0; j < mat.getColumns(); j++)
			cout << mat.element[i][j] << "\t";
		cout << endl;
	}

	return out;
}
