#pragma once
#include "Rectangle.h"
class Square : public Rectangle {
public:

	Square(Point p, int d) : Rectangle(p, d, d) {}
	//virtual void draw();
	virtual std::string getName() override;

private:
};