#pragma once
#include "Computer_Peripheral.h"
class Headphones : public Computer_Peripheral
{
private:
	Connectivity c;
	bool hasMic;
public:
	Headphones(const std::string& model, const std::string& manufacturer, double price, const Connectivity& connection, bool hasMic) : Computer_Peripheral(model, manufacturer, price) {
		this->c = connection;
		this->hasMic = hasMic;
	}
};

