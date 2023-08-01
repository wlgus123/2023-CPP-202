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

	~Entity() {}

	void move(float x, float y)
	{
		sprite_->move(x, y);
	}

	// getter
	int get_life(void) { return life_; }
	int get_speed(void) { return speed_; }
	RectangleShape get_sprite(void) { return *sprite_; }

	// setter
	void set_life(int val) { life_ = val; }
	void set_speed(int val) { speed_ = val; }
	void set_sprite(RectangleShape* val) { sprite_ = val; }

private:
	int life_;
	int speed_;
	RectangleShape* sprite_;
};

int main(void)
{
	RenderWindow window(VideoMode(1000, 800), "Sangsok");
	window.setFramerateLimit(60);

	RectangleShape p;
	p.setFillColor(Color::White);
	p.setPosition(100, 300);
	p.setSize(Vector2f(50, 50));
	
	Entity* player = new Entity(3, 5, &p);


	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			// 윈도우의 x를 눌렀을 때 창이 닫아지도록
			if (e.type == Event::Closed)
				window.close();
		}

		int p_speed = player->get_speed();
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			player->move(p_speed, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			player->move(-p_speed, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			player->move(0, -p_speed);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			player->move(0, p_speed);
		}


		window.clear();

		window.draw(player->get_sprite());

		window.display();
	}

	return 0;
}