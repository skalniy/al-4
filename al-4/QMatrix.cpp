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


istream& operator>>(istream& in, QMatrix& mat) {
	unsigned int m, n;
	cin >> m;
	cin >> n;

	mat = QMatrix(m, n);
	for (int i = 0; i < mat.getRows(); i++)
		for (int j = 0; j < mat.getColumns(); j++)
			cin >> mat.element[i][j];

	return in;
}


ostream& operator<<(ostream& out, const QMatrix& mat) {
	for (int i = 0; i < mat.getRows(); i++) {
		for (int j = 0; j < mat.getColumns(); j++)
			cout << mat.element[i][j];
		cout << endl;
	}

	return out;
}
