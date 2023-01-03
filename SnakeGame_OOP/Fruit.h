#pragma once
#include "Point.h"
class Fruit :public Point
{
private:
	static char icon;
public: 
	Fruit();
	Fruit(int xCoordinate, int yCoordinate);
	Fruit(const Fruit& anotherPoint);
	void Print();
	char GetSymbol() { return icon; }
	Point GetPosition() { return *this; }
};
