#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	Animal(int age, string name) : age_(age), name_(name)
	{ 
		cout << "동물 생성자" << endl;
		cout << "나이 " << age_ << endl;
		cout << "이름 " << name_ << endl;
	}

	~Animal() { cout << "동물 소멸자" << endl; }
	void Bark(void) { cout << "동물 짖는다" << endl; }
	void Eat(void) { cout << "동물 먹는다" << endl; }
	void Hunt(void) { cout << "동물 사냥한다" << endl; }

private:
	int age_;
	string name_;
};

// 두루미
class Crane : public Animal
{
public:
	
	Crane(int age, string name, int leg_length) : Animal(age, name)
	{ 
		cout << "두루미 생성자" << endl;
		leg_length_ = leg_length;
		cout << "다리길이 " << leg_length_ << endl;
	}
	~Crane() { cout << "두루미 소멸자" << endl; }

private:
	int leg_length_;
};

int main(void)
{
	Crane* crane = new Crane(3, "지우", 108);	// 부모의 멤버변수를 사용
	crane->Eat();	// 부모의 멤버함수를 사용

	delete crane;
	return 0;
}