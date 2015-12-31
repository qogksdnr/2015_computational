#include <iostream>

using namespace std;

int main()
{
	int x = 0;
	int input = 0;

	cout << "10보다 작은 값 입력: ";
	cin >> input;
	if(input < 10){
		x = input;
		cout <<"x에 10보다 작은 값인 " << x << "가 입력되었습니다." << endl <<"x = "<< x << endl;
	}
	else cout << "입력하신 값은 10보다 큽니다. x에 대입하지 않겠습니다." << endl<<"x = " << x << endl;
	return 0;
}
