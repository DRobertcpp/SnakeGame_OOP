#pragma once
#include "Point.h"
#include "SnakeHead.h"
#include <list>
using std::list;
class Snake
{
public:
	SnakeHead head;
	list<Point> body;
	static char bodyIcon;
public:
	Snake() { head = NULL; body.push_back(Point()); }
	Snake(SnakeHead head);
	Snake(Snake& snake);
	string  GetHeadDirection() { return head.GetDir(); }
	char GetBodySymbol() { return bodyIcon; }
};