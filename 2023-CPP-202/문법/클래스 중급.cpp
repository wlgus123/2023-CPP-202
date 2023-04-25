#include <iostream>
#include <string.h>

using namespace std;

class MString {
public:
	MString(const char* str)
	{
		unsigned int l = strlen(str);
		c_str_ = new char[l+1];		// '\0'(널문자)가 들어갈 공간 +1
		strcpy(c_str_, str);
		size_ = l;
	}

	// 소멸자(destructor)
	~MString()
	{
		// 소멸자로 생성자에서 동적할당한 메모리 해제
		delete[] c_str_;
	}
	unsigned int size(void) { return size_; }
	char* c_str(void) { return c_str_; }
private:
	unsigned int size_;		// 문자열의 길이
	char* c_str_;			// 문자열의 시작주소
};

int main(void)
{
	// 생성자가 호출되면서 "I will be back"(문자열) 만큼의 동적할당이 이뤄짐
	MString* str = new MString("I will be back");
	cout << str->c_str() << endl;

	// 객체 str만 삭제. 동적할당으로 생성된 문자열은 그대로 남아있음(메모리 누수)
	// TODO : 소멸자(destructor)를 이용하여 동적할당된 메모리도 해제하자
	delete str;
	return 0;
}