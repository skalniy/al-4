#include "al-4.h"



using namespace std;


int main()
try {

	ifstream ist("in.txt");
	if (!ist) throw FileNotFound();
	ofstream ost("out.txt");
	if (!ost) throw FileNotFound();
	int m, n;

	ist >> m >> n;
	QMatrix a = QMatrix(m, n);
	ist >> a;

	ist >> m >> n;
	QMatrix c = QMatrix(m, n);
	ist >> c;

	QMatrix b = a + c;
	ost << b;

	ist.close();
	ost.close();

	system("pause");
	return 0;
} 
catch (...) {
	cout << "Run-time error. See error stream for details." << endl;
	return -1;
}