#include <iostream>
using namespace std;
int main ()
{
	int a, b, c;
	cout << "Enter three numbers.\n";
	cout << "A:		";
	cin >>  a;
	cout << "\nB:		";
	cin >> b;
	cout << "\nC:		";
	cin >> c;

	if (c = (a-b))
	{
		cout << "A:		";
		cout << a;
		cout << " minus B:		";
		cout << b;
		cout << " equals C:		";
		cout << c << endl;
	}

	else
		cout << "A-B is not equal to C.\n";
	return 0;
}
