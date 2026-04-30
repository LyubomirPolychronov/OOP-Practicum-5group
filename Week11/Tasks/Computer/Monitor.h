#pragma once
#include "Computer_Peripheral.h"
class Monitor : public Computer_Peripheral
{
private:
	int refreshRate;
	int size;
public:
	Monitor(const std::string& model, const std::string& manufacturer, double price, int refreshRate, int size ) : Computer_Peripheral(model, manufacturer, price) {
		this->refreshRate = refreshRate;
		this->size = size;
	}
};

