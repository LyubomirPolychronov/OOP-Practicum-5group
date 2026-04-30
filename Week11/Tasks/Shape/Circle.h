#pragma once
#include "Shape.h"
class Circle : public Shape
{
private:
	double radius;
public:
	Circle(const std::string& color, double radius) : Shape(color), radius(radius){}
	double getArea() const;
};

