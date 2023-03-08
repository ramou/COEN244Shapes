#pragma once
#include "Shape.h"
#include <vector>
#include <algorithm>

class MultiShape : public Shape {
public:
	virtual void draw() {
		using namespace std;

		std::for_each(
			shapes.begin(),
			shapes.end(), [](Shape* s) {
				s->draw();
			});
	};
	virtual float getArea() {
		return 0;
	}
	virtual Point getCenter() {
		Point p = { 0,0 };
		return p;
	}
	virtual std::string getName() {
		return "MultiShape";
	}

	void add(Shape& s) {
		shapes.push_back(&s);
	}

	MultiShape& operator<<(Shape& s) {
		this->add(s);
		return *this;
	}

	MultiShape& operator+(Shape& s) {
		this->add(s);
		return *this;
	}

	MultiShape& operator+(MultiShape m) {
		std::for_each(
			m.shapes.begin(),
			m.shapes.end(), [this](Shape* s) {
				this->add(*s);
			});
		return *this;
	}
	friend MultiShape operator+(Shape& s1, MultiShape m);

private:
	std::vector<Shape*> shapes;
};

MultiShape operator+(Shape& s1, Shape& s2);

MultiShape operator+(Shape& s1, MultiShape s2);




