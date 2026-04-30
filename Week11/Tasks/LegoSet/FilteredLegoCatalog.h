#pragma once
#include "LegoCatalog.h"
class FilteredLegoCatalog : public LegoCatalog
{
public:
	FilteredLegoCatalog(int size) : LegoCatalog(size){}
	void filterByName(const std::string& name);
	void filterByTheme(const std::string& theme);
	void filterByPieces(int count);
	void limit(int n);
};

