// Shapes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Unrelated.h"
#include "MultiShape.h"

void foobar(Rectangle &r) {
    using namespace std;
    cout << r.bottomLeft.x << " " << r.bottomLeft.y << endl;
}

int main() {
    using namespace std;
    Point p = { 0,0 };
    Rectangle r = { p, 5, 4 };

    Rectangle r2 = { p, 3, 3 };
    foobar(r);

    MultiShape m;

    cout << m.getName() << endl;

    /*
    m.add(r);
    m.add(r2);
    */

    //m << r2 << r;
    
    m << r;
    m << r2;

    MultiShape m2 = (r2 + (r + r) + r2);

    m2.draw();


    Shape& s = (Shape&)r;


    /*
    cout << &s << endl;
    cout << &r << endl;

    cout << s.foo() << endl;
    cout << r.foo() << endl;
    //cout << ((Unrelated*)&r)->foo() << endl;

    //cout << ((Unrelated*)&r)->draw() << endl;

    //Triangle t = { p,p,p };


    //Square s = { p, 5 };

    r.draw();
    cout << "***************" << endl;
    s.draw();

    */



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
