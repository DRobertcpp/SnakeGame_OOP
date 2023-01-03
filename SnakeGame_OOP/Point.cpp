#include "Point.h"
using namespace std;
#include<iostream>
Point::Point()
{
	xCoordinate = yCoordinate =0;
}
 
Point::~Point()
{
}

Point::Point(int xyCoordinate)
{
	xCoordinate = yCoordinate = xyCoordinate;
}

Point::Point(int xCoordinate, int yCoordinate)
{
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;	
}

Point::Point(const Point& anotherPoint)
{
	this->xCoordinate = anotherPoint.xCoordinate;
	this->yCoordinate = anotherPoint.yCoordinate;
}

bool Point::operator == (Point const& obj) {
	bool result = true;
	if (this->xCoordinate != obj.xCoordinate || this->yCoordinate != obj.yCoordinate)
		result = false;
	return result;
}


