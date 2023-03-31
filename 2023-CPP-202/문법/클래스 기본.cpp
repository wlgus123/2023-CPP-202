#include <iostream>
#include <string>

using namespace std;

// 여러 data들을 하나의 의미있는 구조체로 묶어서 관리
// 구조체, 클래스는 일반적으로 단어의 첫 글자로 대문자로 합시다
struct Student {
	// 성능때문에 hakbun을 문자열로 하지 않음
	// 일반적으로 문자열은 정수형 데이터보다 많은 메모리 공간을 요구하며
	// 정수는 비교연산을 한번에 할 수 있으나, 문자열은 글자수 만큼 반복하여 비교해야함
	int hakbun;
	string name;
	string tel;
	string department;
	string address;
};

int main(void)
{
	// 자료형 : struct Student(C++에서는 Student만 써도 가능)
	struct Student stu1;
	stu1.hakbun = 2200;
	stu1.name = "박남길";
	stu1.tel = "010-0000-0000";
	stu1.department = "뉴미디어소프트웨어";
	stu1.address = "서울시 관악구";

	cout << "학번 : " << stu1.hakbun << endl;
	cout << "이름 : " << stu1.name << endl;
	cout << "전화번호 : " << stu1.tel << endl;
	cout << "학과 : " << stu1.department << endl;
	cout << "주소 : " << stu1.address << endl;

	return 0;
}