#include <iostream>

// 09-21-extra.cpp : Calculate 100 Factorial using charactor array

using namespace std;

int main()
{
	short result[1000000];
	short tempres[1000000];
	int temp,i,j,k;
	const int goal = 100;
	//initialize short array
	for(i=0;i<1000000;i++) result[i] = tempres[i] = '\0';
	result[0] = '1';
	
	cout << "Calculating " << goal << "!..." << endl;
	for(i=1;i<=goal;i++){
		for(j=0;result[j]!='\0';j++){
			temp = (result[j]-'0')*i;
			k=j;
			do{
				if(tempres[k]) tempres[k]--;
				tempres[k] += temp%10 + 1;
				temp /= 10;
				k++;
			}while(temp!=0);
		}
		for(j=0;tempres[j] != 0;j++){
			if(tempres[j] > 10){
				if(!tempres[j+1]) tempres[j+1]++;
				tempres[j+1]++;
				tempres[j--] -= 10;
				continue;
			}
			result[j] = tempres[j] + '0' - 1;
			tempres[j] = 0;
		}
	/*	cout << i << "!: ";
		for(k=j;k>=0;k--) cout << result[k];
		cout << endl;*/
		if(i%100==0)cout << "Now i: " << i << endl;
	}
	cout << "Final result of " << goal << "!: ";
	for(k=j;k>=0;k--) cout << (char)result[k];
	cout << endl << "Order of result: " << j << endl;
}
