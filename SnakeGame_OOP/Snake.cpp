#include "Snake.h"
#include "SnakeHead.h"
#include "Point.h"
Snake::Snake(SnakeHead head) 
{
	this->head = head;
}
Snake::Snake(Snake& otherSnake)
{
	this->head = otherSnake.head;
	this->body = otherSnake.body;
}
char Snake::bodyIcon = '*';