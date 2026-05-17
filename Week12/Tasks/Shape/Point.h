#pragma once
#include <iostream>
#include <algorithm>
class Point
{
private:
	double x, y;
public:
	
	Point(double x, double y) : x(x), y(y){}
	Point(const Point& p) { this->x = p.x; this->y = p.y; }
	bool operator<(const Point& p1) const {
		return (this->x < p1.x) || (this->x == p1.x && this->y < p1.y);
	}
	bool operator>(const Point& p1) const {
		return (this->x > p1.x) || (this->x == p1.x && this->y > p1.y);
	}
	double getX() const { return x; }
	double getY() const { return y; }
};

