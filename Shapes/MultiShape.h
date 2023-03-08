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


	/*
	MultiShape m
	Rectangle r = { p, 5, 4 };
	m << r;
	
	This instance is on the right-hand side of the << operator and we evaluate to a reference to this instance after adding the shape.
	*/
	MultiShape& operator<<(Shape& s) {
		this->add(s);
		return *this;
	}


	/*
	MultiShape m
	Rectangle r = { p, 5, 4 };
	m + r;

	This instance is on the right-hand side of the + operator and we evaluate to a reference to this instance after adding the shape... 
	watch out if this is an rvalue, but I think the vector shapes is playing nice with the default copy constructor.
	*/
	MultiShape& operator+(Shape& s) {
		this->add(s);
		return *this;
	}

	/*
	MultiShape m
	Rectangle r = { p, 5, 4 };
	Rectangle r2 = { p, 3, 3 };
	m + (r + r2);

	This instance is on the right-hand side of the first + operator and we evaluate to a reference to this instance 
	after adding the rvalue multishape created in the parenthesese
	watch out if this is an rvalue, but I think the vector shapes is playing nice with the default copy constructor.
	*/
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

	/*
	MultiShape m
	Rectangle r = { p, 5, 4 };
	Rectangle r2 = { p, 3, 3 };

	m = (r + r2);

	r and r2 are both shapes, so this creates a new MultiShape and a copyconstructor should do the rest. 
	I think the vector shapes is playing nice with the default copy constructor.
	*/
MultiShape operator+(Shape& s1, Shape& s2);


	/*
	MultiShape m
	Rectangle r = { p, 5, 4 };
	Rectangle r2 = { p, 3, 3 };
	r + (r + r2);

 
	we are adding the rvalue multishape created in the parenthesese, which means a reference to a Shape is on the left
	and the Multishape rvalue is on the right. We want to preserve the implied order, I think I left an example of 
	delegation in a comment which was cool, but did not preserve the order so we replaced it.
	*/

MultiShape operator+(Shape& s1, MultiShape s2);




