// Shape.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
int main()
{
	std::cout << "Area | Perimeter\n";
	Triangle t("t", 3, 4, 5);
	std::cout << t.getArea() << "    |   " << t.getPerimeter() << std::endl;

	Rectangle r("r", 3, 4);
	std::cout << r.getArea() << "   |   " << r.getPerimeter() << std::endl;

	Square s("s",5);
	std::cout << s.getArea() <<  "   |   "  << s.getPerimeter() << std::endl;

	Circle c("c1", 5);
	std::cout << c.getArea() << " | " << c.getPerimeter() << std::endl;


	// Version with points

	/*Point a(0, 0);
	Point b(1, 0);
	Point c(1,1);
	Point d(0, 1);
	Point i(1, 0);
	Rectangle r("r1",a,b,c,d);
	std::cout << r.getArea() << " " << r.getPerimeter() << " ,is point inside: " << r.isPointInside(i) << std::endl;*/
}
