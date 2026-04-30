#pragma once
#include <iostream>
#include <string>

enum class Connectivity {
	wired,
	wireless,
};

class Computer_Peripheral
{
private:
	std::string model;
	std::string manufacturer;
	double price;

public:
	Computer_Peripheral(const std::string& name, const std::string& manufacturer, double price) : model(name), manufacturer(manufacturer), price(price){}
	void setPrice(double newPrice) { this->price = newPrice; }
	double getPrice() const;
	const std::string& getModel() const;
	const std::string& getManufacturer() const;

};

