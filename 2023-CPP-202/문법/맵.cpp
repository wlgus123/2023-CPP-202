#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{
	// key:문자열, value:정수
	map<string, int> moving;

	moving["번개맨"] = 1987;
	moving["장희수"] = 2000;
	moving["봉평"] = 1959;

	cout << moving["장희수"] << endl;

	map<string, int>::iterator iter;
	// 맵은 순서가 없어서 iterator로만 반복문을 사용한다.
	for (iter= moving.begin(); iter!= moving.end(); iter++)
		cout << iter->first << iter->second << " ";

	return 0;
}