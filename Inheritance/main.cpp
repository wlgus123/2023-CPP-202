#include <SFML/Graphics.hpp>

using namespace sf;

class Entity {
public:

	// 왠만하면 클래스를 매개변수로 할 때 99.99%는 주소값으로 넘기자
	// 메모리 용량을 줄일 수 있다. call by value를 피하기 위해
	Entity(int life, int speed, RectangleShape* sprite)
		: life_(life), speed_(speed), sprite_(sprite)
	{
	}

private:
	int life_;
	int speed_;
	RectangleShape* sprite_;
};

int main(void)
{
	RenderWindow window(VideoMode(1000, 800), "Sangsok");

	RectangleShape p;
	p.setFillColor(Color::White);
	p.setPosition(100, 300);
	p.setSize(Vector2f(50, 50));


	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			// 윈도우의 x를 눌렀을 때 창이 닫아지도록
			if (e.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
			p.move(1, 0);
		if (Keyboard::isKeyPressed(Keyboard::Left))
			p.move(-1, 0);
		if (Keyboard::isKeyPressed(Keyboard::Up))
			p.move(0, -1);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			p.move(0, 1);


		window.clear();

		window.draw(p);

		window.display();
	}

	return 0;
}