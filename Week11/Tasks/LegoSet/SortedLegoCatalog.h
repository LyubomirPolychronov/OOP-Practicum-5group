#pragma once
#include "LegoCatalog.h"
class SortedLegoCatalog : public LegoCatalog
{
public:
	SortedLegoCatalog(int size) : LegoCatalog(size){}
	void sort();
};

