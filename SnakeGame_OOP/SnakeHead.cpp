#include "SnakeHead.h"
#include "Point.h"
#include <iostream>
using namespace std;
SnakeHead::SnakeHead() : Point() {}
SnakeHead::SnakeHead(int xyCoordinate) : Point( xyCoordinate) {}
SnakeHead::SnakeHead(int xCoordinate, int yCoordinate) : Point(xCoordinate, yCoordinate) {}
SnakeHead::SnakeHead(const SnakeHead& anotherPoint) : Point( anotherPoint) {}
void SnakeHead::Print() { cout << icon; }
char SnakeHead::icon = '@';
string SnakeHead::dir = "STOP";
