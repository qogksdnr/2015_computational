#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	double error;
	cout << "Input n: ";
	cin >> n;
	error = 1./sqrt(n);
	cout << "Input n: " << n << endl << "error of n: " << error << endl;
}
