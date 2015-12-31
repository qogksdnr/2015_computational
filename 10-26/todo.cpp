#include <iostream>

using namespace std;

int multier(int a,int b) { return a*b; }

int main()
{
	int i;
	int multi = 1;
	for(i=0;i<=10;i++){
		cout << "Now i: " << i << endl;
		if(i%2==1) multi = multier(multi,i);
	}
	cout << "Result of multiple: " << multi << endl;
	return 0;
}
