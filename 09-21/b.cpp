#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double a=0, b=0, c=10, x=0, y=0;
	a = 10, b = 3;
	y = pow(a,b);
	cout << y << endl;

	cout << "b = " << b << endl;
	b += c;
	cout << "b(test) = " << b << endl;

	double pi = 3.1415926535;
	x = sin(pi/2);
	cout << "(sin(pi/2) = " << x << endl;
	return 0;
}

