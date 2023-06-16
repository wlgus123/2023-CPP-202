#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	Animal(int age, string name) : age_(age), name_(name)
	{ 
		cout << "동물 생성자" << endl;
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
	}
	~Crane() { cout << "두루미 소멸자" << endl; }

	void Bark()
	{
		cout << "두루두루" << endl;
	}

private:
	int leg_length_;
};

int main(void)
{
	Animal* animal = new Animal(18, "동물이");
	animal->Bark();		// 동물 짖는다
	delete animal;

	animal = new Crane(3, "지우", 108);
	animal->Bark();		// 동물 짖는다(정적 바인딩으로 인해 부모의 멤버함수를 호출)
	delete animal;

	return 0;
}