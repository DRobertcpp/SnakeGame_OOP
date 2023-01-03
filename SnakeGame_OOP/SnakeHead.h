#pragma once
#include "Point.h"
#include<string>
using namespace std;
class SnakeHead: public Point
{
private:
	static char icon;
	static string dir;
public: 
	SnakeHead();
	SnakeHead(int xyCoordinate);
	SnakeHead(int xCoordinate, int yCoordinate);
	SnakeHead(const SnakeHead& anotherPoint);
	void Print();
	char GetSymbol() { return icon; }
	Point GetPosition() { return *this; }
	static string GetDir() { return dir; }
	static void SetDir(string direction) { SnakeHead::dir = direction; }
};

