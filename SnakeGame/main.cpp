#include <SFML/Graphics.hpp>
#include <stdlib.h>		// srand(), rand()
#include <time.h>		// time()
#include <stdio.h>

#define DIR_UP		0
#define DIR_DOWN	1
#define DIR_RIGHT	2
#define DIR_LEFT	3

using namespace sf;

class Snake {

private:
	int dir_;
	int x_;
	int y_;
	RectangleShape sprite_;
};

int main(void)
{
	const int WIDTH = 1000;							// 픽셀 너비
	const int HEIGHT = 800;							// 픽셀 높이
	const int BLOCK_SIZE = 50;						// 한 칸이 가지고 있는 픽셀
	const int G_WIDTH = WIDTH / BLOCK_SIZE;			// 그리드의 너비
	const int G_HEIGHT = HEIGHT / BLOCK_SIZE;		// 그리드의 높이

	srand(time(NULL));
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Snake Game");
	
	// 컴퓨터가 1초 동안 처리하는 횟수를 60으로 제한한다
	// Frame Per Second를 60으로 조절
	window.setFramerateLimit(15);

	RectangleShape snake;
	int snake_x = 1, snake_y = 2;		// 뱀의 그리드 좌표
	int snake_dir = DIR_DOWN;			// 뱀이 이동하는 방향
	snake.setFillColor(Color::White);
	snake.setPosition(snake_x*BLOCK_SIZE, snake_y*BLOCK_SIZE);
	snake.setSize(Vector2f(BLOCK_SIZE, BLOCK_SIZE));

	RectangleShape apple;
	int apple_x = rand() % G_WIDTH, apple_y = rand() % G_HEIGHT;
	apple.setFillColor(Color::Red);
	apple.setPosition(apple_x*BLOCK_SIZE, apple_y*BLOCK_SIZE);
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
		// input
		// 방향키가 동시에 눌러지지 않도록 else 처리
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			snake_dir = DIR_RIGHT;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			snake_dir = DIR_LEFT;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up)) {
			snake_dir = DIR_UP;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			snake_dir = DIR_DOWN;
		}

		// update
		if (snake_dir == DIR_UP) {
			snake_y--;
		}
		else if (snake_dir == DIR_DOWN) {
			snake_y++;
		}
		else if (snake_dir == DIR_RIGHT) {
			snake_x++;
		}
		else if (snake_dir == DIR_LEFT) {
			snake_x--;
		}
		snake.setPosition(snake_x * BLOCK_SIZE, snake_y * BLOCK_SIZE);

		// 뱀이 사과를 먹었을 때,
		if (snake_x==apple_x && snake_y==apple_y) {
			apple_x = rand() % G_WIDTH, apple_y = rand() % G_HEIGHT;
			apple.setPosition(apple_x * BLOCK_SIZE, apple_y * BLOCK_SIZE);
		}


		// render
		window.clear();

		window.draw(snake);
		window.draw(apple);	// draw를 늦게 할 수록 더 위에 있다

		window.display();
	}

	return 0;
}