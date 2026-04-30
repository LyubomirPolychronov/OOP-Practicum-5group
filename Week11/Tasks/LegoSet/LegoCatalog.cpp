#include "LegoCatalog.h"
LegoCatalog::LegoCatalog(int size)
{
	sets.reserve(size);
}

void LegoCatalog::add(const LegoSet& set)
{
	sets.push_back(std::make_unique<LegoSet>(set));
}

void LegoCatalog::remove(const std::string& name)
{
	sets.erase(std::remove_if(sets.begin(), sets.end(), [&name](const std::unique_ptr<LegoSet>& s) {
		return s && s->getName() == name;
		}), sets.end());
}

std::ostream& operator<<(std::ostream& os, const LegoCatalog& catalog)
{
	os << " Lego Catalog:\n";
	for (const auto& setPtr : catalog.sets) {
		if (setPtr)
		{
			os << *setPtr;
		}
	}
	return os;
}
