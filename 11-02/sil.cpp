#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	double erra, errb;
	double a,b;
	a = 389; 
	b = 993;
	erra = 9;
	errb = 32;
	cout << "a: ";
	cout << setprecision(3) << a << "+-" << setprecision(2) << erra << endl;
	cout << "b: ";
	cout << setprecision(3) << b << "+-" << setprecision(2) << errb << endl;

	cout << "a+b: ";
	cout << setprecision(3) << a+b << "+-" << setprecision(2) << sqrt(erra*erra+errb*errb) << endl;

	cout << "a*b: ";
	cout << setprecision(3) << a*b << "+-" << setprecision(2) << a*b*sqrt((erra*erra)/(a*a)+(errb*errb)/(b*b)) << endl;

	cout << "a/b: ";
	cout << setprecision(3) << a/b << "+-" << setprecision(2) << sqrt((erra*erra)/(a*a) + (errb*errb)/(b*b)) << endl;
	
}
