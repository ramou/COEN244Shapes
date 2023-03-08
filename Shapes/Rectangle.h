#pragma once
#include "Shape.h"
#include "Art.h"
#include <iostream>
class Rectangle : public Shape, public Art {
public:
	Rectangle(Point p, int w, int h) : bottomLeft(p), width(w), height(h) {
		std::cout << "The id is " << Art::getId() << std::endl;
	}
	virtual void draw();
	virtual float getArea();
	virtual Point getCenter();
	virtual std::string getName();

	virtual int getWidth() { return width; }
	virtual int getHeight() { return height; }
	virtual Point getBL() { return bottomLeft; }

private:
	friend void foobar(Rectangle &);
	Point bottomLeft;
	int width;
	int height;



};

