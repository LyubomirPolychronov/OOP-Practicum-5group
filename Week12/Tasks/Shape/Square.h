#pragma once
#include "Rectangle.h"
class Square : public Rectangle
{
private:
	double a;
public:
	Square(const std::string& name, double a) : Rectangle(name,a,a), a(a) {}

};

