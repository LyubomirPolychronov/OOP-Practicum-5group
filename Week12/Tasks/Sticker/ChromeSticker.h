#pragma once
#include "Sticker.h"
class ChromeSticker : public Sticker
{
private:
	int serialNum;
	static int nextSerialNum;
public:
	ChromeSticker(const std::string& name);
	void printInfo() const override;
};

