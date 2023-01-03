#include<iostream>
using namespace std;
#include "Point.h"
#include "Fruit.h"
#include "Snake.h"
#include "Game.h"
#include <list>
#include<windows.h> //For Sleep() method
int main()
{
	Game newGame;
	while (!newGame.IsGameOver())
	{
		newGame.Draw();
		newGame.Input();
		newGame.Logic();
		Sleep(130);
	}
	newGame.Draw();
	newGame.Input();
	return 0;
}