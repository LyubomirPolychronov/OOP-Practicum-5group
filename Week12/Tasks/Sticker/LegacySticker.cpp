#include "LegacySticker.h"

LegacySticker::LegacySticker(const std::string& name, const std::string& team, int matches) : Sticker(name), team(team), matches(matches)
{
}

void LegacySticker::printInfo() const
{
	std::cout << "Name: " << this->name << " ,number: " << this->number << " ,team: " << this->team << " ,and mathces: " << this->matches << std::endl;
}
