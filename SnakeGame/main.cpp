#include <SFML/Graphics.hpp>

using namespace sf;

int main(void)
{
	RenderWindow window(VideoMode(640, 480), "Snake Game");

	RectangleShape snake;
	snake.setFillColor(Color::White);
	snake.setPosition(100, 300);
	snake.setSize(Vector2f(50, 50));

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
			snake.move(1, 0);
		if (Keyboard::isKeyPressed(Keyboard::Left))
			snake.move(-1, 0);
		if (Keyboard::isKeyPressed(Keyboard::Up))
			snake.move(0, -1);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			snake.move(0, 1);


		window.clear();

		window.draw(snake);

		window.display();
	}

	return 0;
}