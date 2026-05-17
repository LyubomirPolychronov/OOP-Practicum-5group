#include "Sticker.h"
int Sticker::nextNumber = 13453;
Sticker::Sticker(const std::string& name) : number(nextNumber++), name(name)
{
}

void Sticker::printInfo() const
{
	std::cout << "Name: " << this->name << " and number: " << this->number << std::endl;
}

int Sticker::getNum() const
{
	return this->number;
}

const std::string& Sticker::getName() const
{
	return this->name;
}
