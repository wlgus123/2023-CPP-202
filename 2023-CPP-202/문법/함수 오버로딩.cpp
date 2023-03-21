#include <iostream>

using namespace std;
// 함수 오버로딩을 하면 함수이름은 같게, 매개변수는 다르게
// 함수 오버로딩을 사용하여 함수 이름을 하나로 통일할 수 있게 됨
int sum(int a, int b) {
	return a + b;
}

float sum(float a, float b) {
	return a + b;
}

int main(void)
{
	cout << sum(1, 2) << endl;
	cout << sum(1.1f, 2.2f) << endl;
	return 0;
}