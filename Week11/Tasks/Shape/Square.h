#pragma once
#include "Rectangle.h"
class Square : public Rectangle
{	
public:
	Square(const std::string& color, double side) :  Rectangle(color, side,side){}
};

