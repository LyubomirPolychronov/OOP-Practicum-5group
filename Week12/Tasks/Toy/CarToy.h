#pragma once
#include "Toy.h"
class CarToy : public Toy
{
public:
	CarToy(const std::string& name, const std::string& manufacturer, const Condition& con, double price) : Toy(name, manufacturer, con, price) {}
	void makeSound() const override { std::cout << "Vrum, vrum"; }

};

