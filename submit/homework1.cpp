#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	unsigned int sum=0; // result of summation or factorial must be positive
	int i;
	double stir;
// Summation 1 to 100
	for(i=0;i<100;i++) sum += (1+i);   // sum: summation 1 to 100

	cout << "Summation of 1 to 100: " << sum << endl;

	sum = 1;

// Calculate 100 factorial (straightforward)
	for(i=0;i<100;i++){
		sum *= (i+1);  // sum = sum * (i+1)
//		cout << "Value of " << (i+1) << "!: " << sum << endl;   //output to check overflow
	}
	cout << "Value of 100!(straightforward): " << sum << endl;
// Calculate 100 Factorial (Stirling Approx.)
	stir = exp(100 * log(100) - 100);
	cout << "Value of 100!(Stirling Approx.): " << stir << endl;
	
}
