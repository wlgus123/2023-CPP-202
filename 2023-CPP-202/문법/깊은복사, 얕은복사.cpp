#include <iostream>

using namespace std;

int main(void)
{
	// int 3개짜리 공간을 동적할당 한 후 ptr1이 가리킨다
	int* ptr1 = new int[3];
	ptr1[0] = 0, ptr1[1] = 10, ptr1[2] = 20;

	// 별도의 공간을 만들지 않고, ptr1의 주소값만 복사함(얕은복사, shallow copy)
	int* ptr2 = ptr1;
	
	// 얕은 복사를 하면 원본데이터가 손실될 수 있다.
	ptr2[1] = 100;
	for (int i = 0; i < 3; i++)
	{
		cout << ptr1[i] << " " << ptr2[i] << endl;
	}

	delete[] ptr1;
	// 이미 해제된 공간을 또 해제하려고 하니 에러가 발생함
	delete[] ptr2;
	return 0;
}

