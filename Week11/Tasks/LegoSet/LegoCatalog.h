#pragma once
#include <vector>
#include <memory>
#include "LegoSet.h"
#include <algorithm>
class LegoCatalog
{
protected:
	std::vector<std::unique_ptr<LegoSet>> sets;
public:
	LegoCatalog(int size);
	void add(const LegoSet& set);
	void remove(const std::string& name);
	friend std::ostream& operator<<(std::ostream& os, const LegoCatalog& catalog);
};

