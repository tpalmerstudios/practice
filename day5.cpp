#include <iostream>

using namespace std;

void swap (int x, int y);

int main ()
{
	int x=5, y=10;

	cout << "Main. Before Swap, X: " << x << ", Y: " << y << endl;
	swap (x, y);
	cout << "Main. After Swap, X: " << x << ", Y: " << y << endl;
	return 0;
}

void swap (int x, int y)
{
	int temp;
	cout << "Swap. Before Swap, X: " << x << ", Y: " << y << endl;

	temp = x;
	x = y;
	y = temp;

	cout << "Swap. After Swap, X: " << x << ", Y: " << y << endl;
}

