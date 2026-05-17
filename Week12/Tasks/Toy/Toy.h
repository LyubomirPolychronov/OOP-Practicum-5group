#pragma once
#include <string>
#include <iostream>
enum class Condition {
	Used, New,
};

class Toy
{
protected:
	double price;
	std::string name;
	std::string manufacturer;
	Condition condition;
public:
	Toy(const std::string& name, const std::string& manufacturer, const Condition& con, double price) : name(name), manufacturer(manufacturer), condition(con), price(price){}
	virtual ~Toy() {};
	virtual void makeSound() const {}
	const std::string& conditionToString(){
		if (condition == Condition::Used) {
			return "used";
		}
		else
		{
			return "new";
		}
	}
	void printInfo()  { 
		std::cout << "Name: " << name << " |Manufacturer: '" << manufacturer << "' |Condition: " << conditionToString() << " |Price: " << price;
		std::cout << " With sound: '";
		makeSound();
		std::cout << "'\n";
	}
	void operator~() { condition = Condition::Used; }
	void operator!() { condition = Condition::New; }
};

