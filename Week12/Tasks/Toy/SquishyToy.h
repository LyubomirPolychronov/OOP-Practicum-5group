#pragma once
#include "Toy.h"
class SquishyToy : public Toy
{
public:
	SquishyToy(const std::string& name, const std::string& manufacturer, const Condition& con, double price) : Toy(name, manufacturer, con, price) {}
	void makeSound() const override { std::cout << "Squish, squish"; }
	
};

