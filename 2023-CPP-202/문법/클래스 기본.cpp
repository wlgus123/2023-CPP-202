#include <iostream>
#include <string>

using namespace std;

// 여러 data들을 하나의 의미있는 구조체로 묶어서 관리
struct pizza {
	string brand;
	string menu;
};

int main(void)
{
	// 자료형 : struct pizza(C++에서는 pizza만 써도 가능)
	struct pizza 오늘먹을피자;
	오늘먹을피자.brand = "피자스쿨";
	오늘먹을피자.menu = "콤비네이션";
	
	cout << "브랜드 : " << 오늘먹을피자.brand << endl;
	cout << "메뉴 : " << 오늘먹을피자.menu << endl;

	return 0;
}