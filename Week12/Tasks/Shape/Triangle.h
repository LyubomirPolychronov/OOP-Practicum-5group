#pragma once
#include "Shape.h"
class Triangle : public Shape
{
private:
	double a, b, c;
public:
	Triangle(const std::string& name, double a, double b, double c): Shape(name), a(a), b(b), c(c){}
	double getPerimeter() const override { return a + b + c; }
	double getArea() const override {
		double p = getPerimeter() / 2.0;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	//bool isPointInside(const Point& p) const override{}
};

