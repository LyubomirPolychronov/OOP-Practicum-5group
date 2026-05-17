#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "Point.h"
const double PI = 3.14159;
class Shape
{
protected:
	std::string name;
public:
	Shape(const std::string& name): name(name){}
	virtual ~Shape() {};
	virtual double getPerimeter() const = 0;
	virtual double getArea() const = 0;
	double getSide(const Point& a, const Point& b) const {
		return sqrt(((b.getX() - a.getX()) * (b.getX() - a.getX())) + ((b.getY() - a.getY()) * (b.getY() - a.getY())));;
	}
	//virtual bool isPointInside(const Point& p) const = 0;
};

