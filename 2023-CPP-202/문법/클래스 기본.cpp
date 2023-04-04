#include <iostream>
#include <string>

using namespace std;

// 여러 data들을 하나의 의미있는 구조체로 묶어서 관리
// 구조체, 클래스는 일반적으로 단어의 첫 글자로 대문자로 합시다
// class는 디폴트가 private (stucrt는 디폴트가 public)
class Student {
public:
	// 생성자(constructor) : 객체가 생성될 때 호출되는 함수
	// 생성자를 정의하지 않으면 default로 매개변수가 없는 생성자가 정의된다
	Student()
	{
		hakbun = 2200;
		name = "박남길";
		tel = "010-0000-0000";
		department = "뉴미디어소프트웨어";
		address = "서울시 관악구";
	}

	// class 멤버 함수를 가질 수 있다
	void print(void)
	{
		cout << "학번 : " << hakbun << endl;
		cout << "이름 : " << name << endl;
		cout << "전화번호 : " << tel << endl;
		cout << "학과 : " << department << endl;
		cout << "주소 : " << address << endl;
	}

private:
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
	// 자료형 : Student(class 생략 가능)
	Student stu1;
	

	stu1.print();

	return 0;
}