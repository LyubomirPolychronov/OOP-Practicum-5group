#pragma once
#include <iostream>
#include <string>
#include <cmath>
class Shape
{
private:
	std::string color;
public:
	Shape(const std::string& color) : color(color) {}
	const std::string& getColor() const;
};

