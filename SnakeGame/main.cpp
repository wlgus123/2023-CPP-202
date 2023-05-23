#include <SFML/Graphics.hpp>

using namespace sf;

int main(void)
{
	RenderWindow window(VideoMode(640, 480), "Snake Game");
	
	// 컴퓨터가 1초 동안 처리하는 횟수를 60으로 제한한다
	// Frame Per Second를 60으로 조절
	window.setFramerateLimit(60);

	RectangleShape snake;
	snake.setFillColor(Color::White);
	snake.setPosition(100, 300);
	snake.setSize(Vector2f(50, 50));

	RectangleShape apple;
	apple.setFillColor(Color::Red);
	apple.setPosition(200, 400);
	apple.setSize(Vector2f(50, 50));

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
			snake.move(5, 0);
		if (Keyboard::isKeyPressed(Keyboard::Left))
			snake.move(-5, 0);
		if (Keyboard::isKeyPressed(Keyboard::Up))
			snake.move(0, -5);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			snake.move(0, 5);


		window.clear();

		window.draw(snake);
		window.draw(apple);	// draw를 늦게 할 수록 더 위에 있다

		window.display();
	}

	return 0;
}