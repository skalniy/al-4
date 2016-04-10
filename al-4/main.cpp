#include "al-4.h"



using namespace std;


int main() {
	ifstream ist("in.txt");
	if (!ist) throw FileNotFound();
	ofstream ost("out.txt");
	if (!ost) throw FileNotFound();

	Q a, b;
	ist >> a;
	cin >> b;

	ost << b;
	cout << a;
	
	ist.close();
	ost.close();

	system("pause");
	return 0;
}