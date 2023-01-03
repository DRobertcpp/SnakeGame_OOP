#pragma once
class Point
{
protected:
	int xCoordinate, yCoordinate;
public:
	Point();
	Point(int xyCoordinate);
	Point(int xCoordinate, int yCoordinate);
	Point(const Point& anotherPoint);
	~Point();
	const int GetX() { return xCoordinate; }
	const int GetY() { return yCoordinate; }
	void SetX(int xCoordinate) { this->xCoordinate=xCoordinate; }
	void SetY(int yCoordinate) { this->yCoordinate = yCoordinate; }
	bool operator == (Point const& obj);
};
