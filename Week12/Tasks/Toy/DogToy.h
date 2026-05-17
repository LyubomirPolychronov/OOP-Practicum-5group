#pragma once
#include "Toy.h"
class DogToy : public Toy
{
public:
	DogToy(const std::string& name, const std::string& manufacturer, const Condition& con, double price) : Toy(name, manufacturer, con, price) {}
	void makeSound() const override { std::cout << "Bow, bow"; }
};

