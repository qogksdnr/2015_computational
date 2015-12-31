#include <iostream>

using namespace std;

int main()
{
	char name[100], num[100], addr[100];
	cout << "Name: ";
	cin >> name;
	cout << "Number: ";
	cin >> num;
	cout << "Address: ";
	cin >> addr;

	cout << "Name: " << name << endl << "Number: " << num << endl << "Address: " << addr << endl;
	return 0;
}
