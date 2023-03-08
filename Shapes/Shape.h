#pragma once
#include "Point.h"
#include <string>
#include <iostream>
class Shape {
public:
	virtual void draw() {
		using namespace std;
		cout << "This is a Shape." << endl;
	};
	virtual float getArea() = 0;
	virtual Point getCenter() = 0;
	virtual std::string getName() = 0;
	virtual int getId() { return 1; };

	int foo() { return 2; }


private:


};

