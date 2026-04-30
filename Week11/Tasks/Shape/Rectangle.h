#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
private:
	double width, length;
public:
	Rectangle(const std::string& color, double width, double length) : Shape(color), width(width), length(length){}
	double getArea() const;
};

