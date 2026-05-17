#pragma once
#include "Shape.h"
#include <algorithm>
#include <vector>
class Rectangle : public Shape
{
protected:
	double a, b;
public:
	Rectangle(const std::string& name, double a,double b): Shape(name), a(a),b(b){}
	double getPerimeter() const override { return 2 * (a + b); }
	double getArea() const override {
		return a*b;
	}
	//bool isPointInside(const Point& p) const override{}



	// Version with points

//protected:
//	Point a, b, c, d;
//public:
//	Rectangle(const std::string& name, const Point& a, const Point& b, const Point& c, const Point& d) : Shape(name), a(a), b(b), c(c),d(d) {}
//
//	double getPerimeter() const override { 
//		return 2 * (getSide(a,b) + getSide(b,c));
//	}
//	double getArea() const override { return getSide(a,b) * getSide(b,c); }
//	bool isPointInside(const Point& p) const override {
//		Point bottomLeft = std::min({ a,b,c,d });
//		Point topRight = std::max({ a,b,c,d });
//		if ((p.getX() >= bottomLeft.getX() && p.getX() <= topRight.getX()) && (p.getY() >= bottomLeft.getY() && p.getY() <= topRight.getY()))
//		{
//			return true;
//		}
//		return false;
//	}
};

