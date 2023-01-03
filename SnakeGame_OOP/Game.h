#pragma once
#include "Snake.h"
#include "Fruit.h"
#include "SnakeHead.h"
class Game
{
private:
	static const int width = 39;
	static const int height = 15;
	bool gameOver;
	int score;
	Snake snake;
	Fruit fruit;
public:
	Game();
	Game(bool gameOver, int score,Snake snake, Fruit fruit);
	void Draw();
	void Input();
	void Logic();
	void MoveBody();
	void MoveHead();
	void PassingThroughWalls();
	void CheckCollisions();
	void CheckEatingFruit();
	bool IsGameOver() { return gameOver; }
};
