#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	int nc,c;
	nc = c = 0;
	cout << " Count 10 " << endl;
	for(int i = 0;i<10;i++){
		if(rand()%100>=50) c++;
		else nc++;
	}
	cout << "nc: " << nc << endl << "c: " << c << endl;
	cout << "fraction: " << (double)c/10. << endl;

	nc = c = 0;
	cout << " Count 1000 " << endl;
	for(int i = 0;i<1000;i++){
		if(rand()%100>=50) c++;
		else nc++;
	}
	cout << "nc: " << nc << endl << "c: " << c << endl;
	cout << "fraction: " << (double)c/1000. << endl;
	cout << " Count 100000 " << endl;
	for(int i = 0;i<100000;i++){
		if(rand()%100>=50) c++;
		else nc++;
	}
	cout << "nc: " << nc << endl << "c: " << c << endl;
	cout << "fraction: " << (double)c/100000. << endl;
}
