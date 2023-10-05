#include <SFML/Graphics.hpp>
#include <stdlib.h>		//srand(), rand()
#include <time.h>		//time()
#include <stdio.h>

#define DIR_UP		0
#define DIR_DOWN	1
#define DIR_RIGHT	2
#define DIR_LEFT	3

#define BODY_MAX    20

using namespace sf;

const int BLOCK_SIZE = 50;					//한 칸이 가지고 있는 픽셀
const int WIDTH = 1000;						//픽셀 너비
const int HEIGHT = 800;						//픽셀 높이
const int G_WIDTH = WIDTH / BLOCK_SIZE;     //그리드의 너비
const int G_HEIGHT = HEIGHT / BLOCK_SIZE;	 //그리드의 높이

class Object {
public:
	int x_;
	int y_;
	RectangleShape sprite_;
};

class Snake {

public:
	Snake(int dir, int length, int score=0) : dir_(dir), length_(length), score_(score)
	{}

	int GetDir() { return dir_; }
	int GetLength() { return length_; }
	int GetScore() { return score_; }
	Object* GetBody() { return body_; }


	void SetDir(int dir) { dir_ = dir; }
	void SetLength(int length) { length_ = length; }
	void SetScore(int score) { score_ = score; }
	
	void IncLength(void) { length_++; }
	void IncScore(int val) { score_ += val; }

	// body 초기화
	void InitBody(void)
	{
		for (int i = 0; i < BODY_MAX; i++) {
			body_[i].x_ = 50, body_[i].y_ = 2;	//뱀의 그리드 좌표
			body_[i].sprite_.setFillColor(Color(0, 128, 0));
			body_[i].sprite_.setOutlineThickness(5.f);
			body_[i].sprite_.setFillColor(Color::Green);
			body_[i].sprite_.setPosition(body_[i].x_ * BLOCK_SIZE, body_[i].y_ * BLOCK_SIZE);
			body_[i].sprite_.setSize(Vector2f(BLOCK_SIZE, BLOCK_SIZE));
		}
		body_[0].x_ = 3, body_[0].y_ = 3;
	}
	 
	// 머리 이외의 몸통
	void UpdateBody(void)
	{
		for (int i = GetLength() - 1; i > 0; i--) {
			body_[i].x_ = body_[i - 1].x_;
			body_[i].y_ = body_[i - 1].y_;
			body_[i].sprite_.setPosition(body_[i].x_ * BLOCK_SIZE, body_[i].y_ * BLOCK_SIZE);
		}
	}
	
	// 머리
	void UpdateHead(void)
	{
		//머리
		if (GetDir() == DIR_UP && body_[0].y_ > 0) {
			body_[0].y_--;
		}
		else if (GetDir() == DIR_DOWN && body_[0].y_ < G_HEIGHT - 1) {
			body_[0].y_++;
		}
		else if (GetDir() == DIR_RIGHT && body_[0].x_ < G_WIDTH - 1) {
			body_[0].x_++;
		}
		else if (GetDir() == DIR_LEFT && body_[0].x_ > 0) {
			body_[0].x_--;
		}
		body_[0].sprite_.setPosition(body_[0].x_ * BLOCK_SIZE, body_[0].y_ * BLOCK_SIZE);
	}

private:
	int dir_;
	int length_;
	int score_;
	Object body_[BODY_MAX];
};

class Apple {

public:
	int x_;
	int y_;
	RectangleShape sprite_;
};

int main(void)
{

	srand(time(NULL));
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Snake Game");

	//컴퓨터가 1초 동안 처리하는 횟수를 60으로 제한한다
	//Frame Per Second를 60으로 조절
	window.setFramerateLimit(15);

	Font font;
	// 한글이 지원되는 폰트로 변경
	if (!font.loadFromFile("C:\\Windows\\Fonts\\H2GSRB.ttf"))
	{
		printf("폰트 불러오기 실패");
		return -1;
	}

	Text t_info;
	t_info.setFont(font);
	t_info.setFillColor(Color::Magenta);
	t_info.setCharacterSize(50);
	t_info.setPosition(0, 0);

	// 유니코드(한글)를 호환하기 위한 자료형으로 변경
	wchar_t t_info_buf[100];

	Snake snake = Snake(DIR_DOWN, 1);
	snake.InitBody();

	Apple apple;
	apple.x_ = rand() % G_WIDTH, apple.y_ = rand() % G_HEIGHT;
	apple.sprite_.setFillColor(Color::Red);
	apple.sprite_.setPosition(apple.x_ * BLOCK_SIZE, apple.y_ * BLOCK_SIZE);
	apple.sprite_.setSize(Vector2f(BLOCK_SIZE, BLOCK_SIZE));

	

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			//윈도우의 x를 눌렀을 때 창이 닫아지도록
			if (e.type == Event::Closed)
				window.close();
		}

		// 방향키가 동시에 눌러지지 않도록 else 처리
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			snake.SetDir(DIR_RIGHT);
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			snake.SetDir(DIR_LEFT);
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			snake.SetDir(DIR_UP);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			snake.SetDir(DIR_DOWN);
		}

		// update
		
		swprintf(t_info_buf, L"점수 : %d \n", snake.GetScore());
		t_info.setString(t_info_buf);

		snake.UpdateBody();
		snake.UpdateHead();


		// TODO : GetBody() 멤버접근 방법 바꿔보기
		//뱀이 사과를 먹었을 때, 
		if (snake.GetBody()[0].x_ == apple.x_ && snake.GetBody()[0].y_ == apple.y_)
		{
			//사과 위치전환
			apple.x_ = rand() % G_WIDTH, apple.y_ = rand() % G_HEIGHT;
			apple.sprite_.setPosition(apple.x_ * BLOCK_SIZE, apple.y_ * BLOCK_SIZE);


			snake.IncScore(5);

			//뱀의 길이를 변화
			if (snake.GetLength() < 20)
				snake.IncLength();
		}

		//render
		window.clear();

		for (int i = 0; i < snake.GetLength(); i++)
			window.draw(snake.GetBody()[i].sprite_);
		window.draw(apple.sprite_);  //draw를 늦게 할 수록 더 위에 있다
		window.draw(t_info);

		window.display();
	}

	return 0;
}