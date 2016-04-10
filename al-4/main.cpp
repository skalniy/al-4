#include "al-4.h"



using namespace std;


int main() {
	ifstream ist("in.txt");
	if (!ist) throw FileNotFound();
	ofstream ost("out.txt");
	if (!ost) throw FileNotFound();

	cout << "size: ";
	int m, n;
	cin >> m >> n;

	QMatrix a = QMatrix(m, n);
	cin >> a;

	cout << a;
	
	ist.close();
	ost.close();

	system("pause");
	return 0;
}