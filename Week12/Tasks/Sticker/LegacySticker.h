#pragma once
#include "Sticker.h"
class LegacySticker : public Sticker
{
private:
	std::string team;
	int matches;
public:
	LegacySticker(const std::string& name, const std::string& team, int matches);
	void printInfo() const override;
};

