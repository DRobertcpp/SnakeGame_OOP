#include "Game.h"
#include "Snake.h"
#include "Fruit.h"
#include <iostream>
#include<conio.h> //For _kbhit() and _getch() methods
#include<string>
using namespace std;

Game::Game()
{ 
	gameOver = false;
	score = 0;
	SnakeHead head(width / 2, height / 2);
	Snake snakeCopy(head);
	snake = snakeCopy;
	Fruit fruitCopy(rand() % width, rand() % height);
	fruit = fruitCopy;
}

Game::Game(bool gameOver, int score, Snake snake, Fruit fruit)
{
	this->gameOver = gameOver;
	this->score = score;
	this->snake = snake;
	this->fruit = fruit;
}

void Game::Draw()
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
		cout << "#";					//Draw the UPPER border of the map
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";			//Draw LEFT border of the map
			if (i == this->snake.head.GetY() && j == this->snake.head.GetX())//Draw Snake's head
				cout << snake.head.GetSymbol();
			else if (i == this->fruit.GetY() && j == this->fruit.GetX())	 //Draw the fruit
				cout << fruit.GetSymbol();
			else
			{
				bool print = false;// Verifying if it needs to print one bodypiece, otherwise prints a blank space
				list<Point>::iterator iter;
				for (iter = snake.body.begin(); iter != snake.body.end(); iter++)
				{
					if ((*iter).GetX() == j && (*iter).GetY() == i)
					{
						cout << snake.GetBodySymbol();
						print = true;
						break;
					}
				}
				if (!print)
					cout << " ";
			}
			if (j == width - 1)
				cout << "#";			//Draw RIGHT border of the map
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++)
		cout << "#";					//Draw the LOWER border of the map
	cout << endl << "SCORE: " << score;
}

void Game::Input()
{
	if (_kbhit())
		switch (_getch())
		{
		case 'a':
			snake.head.SetDir("LEFT");
			break;
		case 'd':
			snake.head.SetDir("RIGHT");
			break;
		case 'w':
			snake.head.SetDir("UP");
			break;
		case 's':
			snake.head.SetDir("DOWN");
			break;
		case 'x':
			gameOver = true;
			break;
		}
}

void Game::MoveBody()
{
	//Moves snake's body
	Point Prev;
	Point Prev2;
	if (!snake.body.empty())
	{
		if (snake.body.size() == 1)
		{
			Prev = snake.head.GetPosition();
		}
		else
		{
			Prev = *snake.body.begin();
		}
		*(snake.body.begin()) = (Point)snake.head;
		list<Point>::iterator iter;
		for (iter = snake.body.begin(); iter != (snake.body.end()); iter++)
		{
			if (iter == snake.body.begin() && snake.body.size() != 1)
				continue;
			Prev2 = *iter;
			*iter = Prev;
			Prev = Prev2;
		}
	}
}

void Game::MoveHead()
{
	//Moves snake's head
	switch (snake.GetHeadDirection()[0])
	{
	case 83: //S  from (STOP) VALUE
		break;
	case 76: //L from (LEFT) VALUE
		snake.head.SetX((snake.head.GetX()) - 1);
		break;
	case 82: //R from RIGHT VALUE
		snake.head.SetX((snake.head.GetX()) + 1);
		break;
	case 85: //U from UP  VALUE
		snake.head.SetY((snake.head.GetY()) - 1);
		break;
	case 68: //D from DOWN  VALUE
		snake.head.SetY((snake.head.GetY()) + 1);
		break;
	default:
		break;
	}
}

void Game::PassingThroughWalls()
{
	//Going through walls
	if (snake.head.GetX() >= width)
		snake.head.SetX(0);
	else if (snake.head.GetX() < 0)
		snake.head.SetX(width - 1);
	if (snake.head.GetY() >= height)
		snake.head.SetY(0);
	else if (snake.head.GetY() < 0)
		snake.head.SetY(height - 1);
}

void Game::CheckCollisions() 
{
	//Check colisions with tail
	if (!snake.body.empty())
	{
		list<Point>::iterator iter;
		for (iter = snake.body.begin(); iter != (snake.body.end()); iter++)
		{
			if ((Point)*iter == (Point)snake.head)
				gameOver = true;
		}
	}
}

void Game::CheckEatingFruit()
{
	// Check eating the fruit
	if ((Point)snake.head == (Point)fruit)
	{
		score += 10;
		fruit.SetX(rand() % width);
		fruit.SetY(rand() % height);
		if (snake.body.empty())
		{
			Point a = snake.head;
			switch (snake.GetHeadDirection()[0])
			{
			case 76: //L from (LEFT) VALUE
				a.SetX(snake.head.GetX() + 1);
				snake.body.push_back(a);
				break;
			case 82: //R from RIGHT VALUE
				a.SetX(snake.head.GetX() - 1);
				snake.body.push_back(a);
				break;
			case 85: //U from UP  VALUE
				a.SetY(snake.head.GetY() + 1);
				snake.body.push_back(a);
				break;
			case 68: //D from DOWN  VALUE
				a.SetX(snake.head.GetY() - 1);
				snake.body.push_back(a);
				break;
			default:
				break;
			}
		}
		else
		{
			Point a((snake.body.back()).GetX(), (snake.body.back()).GetY());
			snake.body.push_back(a);
		}
	}
}

void Game::Logic()
{	
	MoveBody();
	MoveHead();
	PassingThroughWalls();
	CheckCollisions();
	CheckEatingFruit();
}
