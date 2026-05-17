#pragma once
#include "Repository.hpp"
#include "Sticker.h"
#include <functional>
class StickerRepository : public Repository<Sticker>
{
public:
	bool findByNum(int num);
	std::vector<Sticker>& trade(int num);
};

