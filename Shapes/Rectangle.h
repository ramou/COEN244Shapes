#pragma once
#include "Shape.h"
#include <iostream>
class Rectangle : public Shape {
public:
	Rectangle(Point p, int w, int h) : bottomLeft(p), width(w), height(h) {}
	virtual void draw();
	virtual float getArea();
	virtual Point getCenter();
	virtual std::string getName();

	virtual int getWidth() { return width; }
	virtual int getHeight() { return height; }
	virtual Point getBL() { return bottomLeft; }

private:
	Point bottomLeft;
	int width;
	int height;



};

