#include "Rectangle.h"

void Rectangle::draw()
{
	using namespace std;
	cout << "This is a " << getName() << " with a width of "
		 << width << " and a height of " << height
		 << " and area of " << getArea()
		 << " located at point (" << bottomLeft.x << ", " 
		 << bottomLeft.y << ")" << endl;
}

float Rectangle::getArea()
{
	return width*height;
}

Point Rectangle::getCenter()
{
	return Point(0,0);
}

std::string Rectangle::getName()
{
	return std::string("Rectangle");
}
