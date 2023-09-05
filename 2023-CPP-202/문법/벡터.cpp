#include <iostream>

using namespace std;

int main(void)
{
	int* arr = new int[4];
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;

	// 꽉찬 공간에 새로운 데이터를 넣어보자
		// 크기가 확장된 새로운 공간을 만든다.
	int* temp = new int[6];
		// 기존의 값을 복사한다.
	for (int i = 0; i < 4; i++)
		temp[i] = arr[i];
		// 기존 공간 삭제
	delete[] arr;
		// arr이 새로운 공간을 가리킴
	arr = temp;
		// 새로운 값을 넣어줌
	arr[4] = 50;


	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";


	delete[] arr;
	return 0;
}