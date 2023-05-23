#include <SFML/Graphics.hpp>
#include <stdlib.h>		// srand(), rand()
#include <time.h>		// time()

using namespace sf;

int main(void)
{
	const int WIDTH = 1000;
	const int HEIGHT = 800;
	const int BLOCK_SIZE = 50;

	srand(time(NULL));
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Snake Game");
	
	// 컴퓨터가 1초 동안 처리하는 횟수를 60으로 제한한다
	// Frame Per Second를 60으로 조절
	window.setFramerateLimit(60);

	RectangleShape snake;
	snake.setFillColor(Color::White);
	snake.setPosition(100, 300);
	snake.setSize(Vector2f(BLOCK_SIZE, BLOCK_SIZE));

	RectangleShape apple;
	apple.setFillColor(Color::Red);
	// 640에 50을 뺀 이유는 사과가 화면 밖에 벗어나지 않게 하기 위함
	apple.setPosition(rand()%(WIDTH- BLOCK_SIZE), rand()%(HEIGHT- BLOCK_SIZE));
	apple.setSize(Vector2f(BLOCK_SIZE, BLOCK_SIZE));

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			// 윈도우의 x를 눌렀을 때 창이 닫아지도록
			if (e.type == Event::Closed)
				window.close();
		}

		// 방향키가 동시에 눌러지지 않도록 else 처리
		if (Keyboard::isKeyPressed(Keyboard::Right))
			snake.move(5, 0);
		else if (Keyboard::isKeyPressed(Keyboard::Left))
			snake.move(-5, 0);
		else if (Keyboard::isKeyPressed(Keyboard::Up))
			snake.move(0, -5);
		else if (Keyboard::isKeyPressed(Keyboard::Down))
			snake.move(0, 5);

		// 뱀이 사과를 먹었을 때,
		if (snake.getGlobalBounds().intersects(apple.getGlobalBounds())) {
			apple.setPosition(rand() % (WIDTH - BLOCK_SIZE), rand() % (HEIGHT - BLOCK_SIZE));
		}


		window.clear();

		window.draw(snake);
		window.draw(apple);	// draw를 늦게 할 수록 더 위에 있다

		window.display();
	}

	return 0;
}