#include <iostream>

using namespace std;

int main()
{
	int nArray[8] = {1,2,3};
	int nCount = sizeof(nArray)/sizeof(int);
	int i;

	for(i = 0; i < nCount; i++){
		cout << nArray[i] << ", ";
		cout << &nArray[i] << endl;
	}
}
