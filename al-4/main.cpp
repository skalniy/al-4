#include "al-4.h"



using namespace std;


int main() {
	ifstream ist("in.txt");
	if (!ist) throw FileNotFound();
	ofstream ost("out.txt");
	if (!ost) throw FileNotFound();
	int m, n;

	cout << "size: ";
	cin >> m >> n;
	QMatrix a = QMatrix(m, n);
	cin >> a;

	QMatrix b = a.transposition();
	cout << b;
	
	ist.close();
	ost.close();

	system("pause");
	return 0;
}