#pragma once
#include "Shape.h"
class Circle : public Shape
{
private:
	double r;
public:
	Circle(const std::string& name, double r): Shape(name), r(r) {}
	double getPerimeter() const override { return 2 * PI * r; }
	double getArea() const override { return PI * r * r; }
	//bool isPointInside(const Point& p) const override {}
};

