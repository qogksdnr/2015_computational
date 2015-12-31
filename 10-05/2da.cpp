#include <iostream>

using namespace std;

int main()
{
	int array[3][3] = {{10, 20, 30}, {21, 21, 22}, {31, 32, 33}};
	int i;
	for (i = 0; i < 3; i++) cout << "array[" << i << "][0] : " << array[i][0] << endl;
}
