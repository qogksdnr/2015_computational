#include <iostream>

using namespace std;

int sumofelements(int [2][2]);   // 행렬들의 모든 원소들의 합을 구하는 함수
void summationoftwo(int [2][2], int [2][2],int [2][2]); // 인수로 받은 2차 두 정사각행렬 a,b의 합 a+b를 구한 후 r에 되돌려주는 함수
void subtractoftwo(int [2][2], int [2][2], int[2][2]); // 인수로 받은 2차 두 정사각행렬 a,b의 차 a-b를 구한 후 r에 되돌려주는 함수
void reversearr(int *, int);   // 인수로 받은 1차원 행렬을 뒤집는다

int main()
{
	// 2x2 Matirx summation of each elements, substract, sum (using function)
	// 1~10 1-dimsion array, 
	int r[2][2];   // 1번 문제. 한 행렬의 각 요소의 합과 두 행렬의 뺄셈, 덧셈을 하는 함수를 작성하세요 단, 행렬은 모두 2차 정사각 행렬입니다.
	int i,j;
	int suma = 0, sumb = 0;
	int a[2][2] = {{1,2},{3,4}}; // a의 행렬 정의
	int b[2][2] = {{5,6},{7,8}}; // b의 행렬 정의

	cout << "Summation of each element of matrix A: " << sumofelements(a) << endl; // 행렬 a의 모든 원소들의 합을 계산 후 출력
	cout << "Summation of each element of matrix B: " << sumofelements(b) << endl; // b도 마찬가지

	summationoftwo(a,b,r);       // 2차 정사각행렬로 정의된  지역 변수 a,b의 합을 구한 후 r에 넣는다
	cout << "(A) + (B) : " << endl;
	cout << "----------------" << endl;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++) cout << r[i][j] << " " ;   // 행렬답게 표시하기 위하여 반복문을 이용하여 출력
		cout << endl;
	}

	subtractoftwo(a,b,r);        // 2차 정사각행렬로 정의된 지역 변수 a,b의 차 a-b를 구한 후에 r에 넣는다
	cout << "(A) - (B) : " << endl;
	cout << "----------------" << endl;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++) cout << r[i][j] << " " ; // 역시 행렬스럽게 표시하기 위해 반복문을 이용
		cout << endl;
	}

	int two[10] = {1,2,3,4,5,6,7,8,9,10};    // 2번 문제. 오름차순으로 정렬된 1~10 까지의 행렬 요소들을 내림차순으로 정렬하는 함수를 작성하세요.

	cout << "two: ";
	for(i = 0;i < 10; i++) cout << two[i] << " ";
	cout << endl;
	reversearr(two,sizeof(two));   // 내림차순으로 바꿀 행렬과 그 행렬 전체의 크기를 주고 호출
	cout << "two: ";
	for(i = 0;i < 10; i++) cout << two[i] << " ";
	cout << endl;
}

void reversearr(int *a,int size)
{
	int i,c,temp;                       // 인수로 받은 1차원 행렬 a는 이미 오름차순으로 정렬되어 있으므로 단순히 행렬을 뒤집는것만으로 내림차순으로 정렬 가능
	c = size/sizeof(int)-1;             // 반복 횟수 결정(받은 행렬의 최대 첨자 확인)
	for(i=0;i<(c/2);i++){
		temp = a[i];    // 스왑
		a[i] = a[c-i];
		a[c-i]=temp;
	}
}

int sumofelements(int a[][2])
{
	int i, j, sum=0;                 // sum을 0으로 초기화(중요)
	for(i = 0;i < 2; i++){
		for(j = 0;j < 2; j++){
			sum+=a[i][j];   // 각 행렬의 합을 sum변수에 집어넣음
		}
	}
	return sum;
}
void summationoftwo(int a[2][2], int b[2][2], int r[2][2])
{
	int i,j;
	for(i = 0; i < 2; i++) for(j = 0; j < 2; j++) r[i][j] = a[i][j] + b[i][j]; // 두 행렬 원소들의 합을 인수로 받은 행렬 r에다가 저장
}
void subtractoftwo(int a[2][2], int b[2][2], int r[2][2])
{
	int i,j;
	for(i = 0; i < 2; i++) for(j = 0; j < 2; j++) r[i][j] = a[i][j] - b[i][j];  // 두 행렬 원소들의 차를 인수로 받은 행렬 r에다가 저장
}
