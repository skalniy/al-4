#include "QMatrix.h"



QMatrix::QMatrix(unsigned int m, unsigned int n)
{
	if ((m == 0) || (n == 0)) throw ZeroSizeOfMatrix();
	rows = m;
	columns = n;
	element = new Q*[rows]; // поля m и n спокойно можно использовать внутри своих же методов
	for (unsigned int i = 0; i < rows; i++) {
		element[i] = new Q[columns]();
		for (unsigned int j = 0; j < columns; j++)
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
	for (unsigned int i = 0; i < rows_count(); i++)
		delete element[i];
	delete element;
}


QMatrix QMatrix::transposition() const {
	QMatrix result = QMatrix(columns_count(), rows_count()); // m, n

	for (unsigned int i = 0; i < rows_count(); i++)
		for (unsigned int j = 0; j < columns_count(); j++)
			result.element[j][i] = element[i][j];

	return result;
}


QMatrix operator* (const QMatrix& lhs, const QMatrix& rhs) {
	if (lhs.columns_count() != rhs.rows_count()) throw BadSizeOfMatrix();
	QMatrix result = QMatrix(lhs.rows_count(), rhs.columns_count());

	for (unsigned int i = 0; i < lhs.rows_count(); i++)
		for (unsigned int j = 0; j < rhs.columns_count(); j++)
			for (unsigned int k = 0; k < lhs.columns_count(); k++)
				result.element[i][j] = result.element[i][j] + lhs.element[i][k] * rhs.element[k][j];

	return result;
}


QMatrix operator+ (const QMatrix& lhs, const QMatrix& rhs) {
	QMatrix result = QMatrix(lhs.rows_count(), rhs.columns_count());

	for (unsigned int i = 0; i < result.rows_count(); i++)
		for (unsigned int j = 0; j < result.columns_count(); j++)
			result(i, j) = lhs(i, j) + rhs(i, j);

	return result;
}


istream& operator>>(istream& ins, QMatrix& mat) {
	for (unsigned int i = 0; i < mat.rows_count(); i++)
		for (unsigned int j = 0; j < mat.columns_count(); j++) {
			ins >> mat.element[i][j];
		}

	return ins;
}


ostream& operator<<(ostream& out, const QMatrix& mat) {
	out << mat.rows_count() << " " << mat.columns_count() << endl;
	for (unsigned int i = 0; i < mat.rows_count(); i++) {
		for (unsigned int j = 0; j < mat.columns_count(); j++)
			out << mat(i, j) << "\t";
		out << endl;
	}

	return out;
}


Q& QMatrix::operator()(unsigned int i, unsigned int j) const { return element[i][j]; }