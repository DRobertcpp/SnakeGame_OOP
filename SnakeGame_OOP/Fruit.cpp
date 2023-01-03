#include "Fruit.h"
#include "Point.h"
#include <iostream>
using namespace std;
Fruit::Fruit() : Point() {}
Fruit::Fruit(int xCoordinate, int yCoordinate) : Point( xCoordinate,  yCoordinate) {}
Fruit::Fruit(const Fruit& anotherPoint) : Point( anotherPoint) {}
void Fruit::Print() { cout << icon; }
char Fruit::icon = '$';



