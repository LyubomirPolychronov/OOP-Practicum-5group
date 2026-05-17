#include "ChromeSticker.h"
int ChromeSticker::nextSerialNum = 672348;
ChromeSticker::ChromeSticker(const std::string& name) : Sticker(name), serialNum(nextSerialNum++)
{
}

void ChromeSticker::printInfo() const
{
	std::cout << "Name: " << this->name << " ,normal number: " << this->number << " ,and serial number " << this->serialNum << std::endl;
}
