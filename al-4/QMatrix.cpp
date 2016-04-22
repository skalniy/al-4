#include "QMatrix.h"



QMatrix::QMatrix(unsigned int m, unsigned int n)
{
	if ((m == 0) || (n == 0)) throw ZeroSizeOfMatrix();
	rows = m;
	columns = n;
	element = new Q*[getRows()]; // поля m и n спокойно можно использовать внутри своих же методов
	for (unsigned int i = 0; i < getRows(); i++) {
		element[i] = new Q[getColumns()]();
		for (unsigned int j = 0; j < getColumns(); j++)
			element[i][j] = Q();
	}
}


QMatrix::QMatrix(QMatrix&& oth) {
	*this = move(oth); // тут move лишний: тип oth и так QMatrix&&
	// T&& move<T>(T& a) только делает return static_cast<T&&>(a);
}


QMatrix::~QMatrix()
{
	if (element == nullptr) return;
	for (unsigned int i = 0; i < getRows(); i++)
		delete element[i];
	delete element;
}


QMatrix QMatrix::transposition() const {
	QMatrix result = QMatrix(getColumns(), getRows()); // m, n

	for (unsigned int i = 0; i < getRows(); i++)
		for (unsigned int j = 0; j < getColumns(); j++)
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

	for (unsigned int i = 0; i < result.getRows(); i++)
		for (unsigned int j = 0; j < result.getColumns(); j++)
			result(i, j) = lhs(i, j) + rhs(i, j);

	return result;
}


istream& operator>>(istream& ins, QMatrix& mat) {
	for (unsigned int i = 0; i < mat.getRows(); i++)
		for (unsigned int j = 0; j < mat.getColumns(); j++) {
			ins >> mat.element[i][j];
		}

	return ins;
}


ostream& operator<<(ostream& out, const QMatrix& mat) {
	out << mat.getRows() << " " << mat.getColumns() << endl;
	for (unsigned int i = 0; i < mat.getRows(); i++) {
		for (unsigned int j = 0; j < mat.getColumns(); j++)
			out << mat(i, j) << "\t";
		out << endl;
	}

	return out;
}


Q& QMatrix::operator()(unsigned int i, unsigned int j) const { return element[i][j]; }