#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	// 전통적인 배열은 크기가 고정되어 있으나,
	// 벡터는 크기가 자유롭게 변할 수 있는 동적배열이다.
	vector<int> arr;
	arr.reserve(4);		// 크기를 4로
	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);

	// 꽉찬 공간에 새로운 데이터를 넣어보자
	arr.push_back(50);

	vector<int>::iterator iter;
	// 반복자(iterator)를 활용하여 모든 원소를 출력
	for (iter=arr.begin(); iter!=arr.end(); iter++)
		cout << *iter << " ";

	return 0;
}