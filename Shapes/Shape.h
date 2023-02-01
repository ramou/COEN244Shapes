#pragma once
#include "Point.h"
#include <string>
class Shape {
public:
	virtual void draw() = 0;
	virtual float getArea() = 0;
	virtual Point getCenter() = 0;
	virtual std::string getName() = 0;

private:


};

