#pragma once
#include "Computer_Peripheral.h"
class Mouse : public Computer_Peripheral
{
private:
	Connectivity c;

public:
	Mouse(const std::string& model, const std::string& manufacturer, double price, const Connectivity& connection) : Computer_Peripheral(model, manufacturer, price) { c = connection; }
};

