#pragma once
#include "Toy.h"
class TrainToy : public Toy
{
public:
	TrainToy(const std::string& name, const std::string& manufacturer, const Condition& con, double price) : Toy(name, manufacturer, con, price) {}
	void makeSound() const override { std::cout << "Tuu tu"; }
};

