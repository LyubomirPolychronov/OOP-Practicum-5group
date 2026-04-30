#pragma once
#include "Shape.h"
class Triangle : public Shape
{
private:
	double a, b, c;
public:
	Triangle(const std::string& color, double a, double b, double c) : Shape(color), a(a), b(b), c(c){}
	double getArea() const;
};

