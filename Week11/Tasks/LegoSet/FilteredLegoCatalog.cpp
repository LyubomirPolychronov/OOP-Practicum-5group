#include "FilteredLegoCatalog.h"

void FilteredLegoCatalog::filterByName(const std::string& name)
{
	sets.erase(std::remove_if(sets.begin(), sets.end(), [&name](const std::unique_ptr<LegoSet>& s) {
		return s && s->getName() != name;
		}), sets.end());
}

void FilteredLegoCatalog::filterByTheme(const std::string& theme)
{
	sets.erase(std::remove_if(sets.begin(), sets.end(), [&theme](const std::unique_ptr<LegoSet>& s) {
		return s && enumToString(s->getTheme()) != theme;
		}), sets.end());
}

void FilteredLegoCatalog::filterByPieces(int count)
{
	sets.erase(std::remove_if(sets.begin(), sets.end(), [&count](const std::unique_ptr<LegoSet>& s) {
		return s && s->getPieceCount() != count;
		}), sets.end());
}

void FilteredLegoCatalog::limit(int n)
{
	if (n >=0 && n< (int)sets.size())
	{
		this->sets.resize(n);
	}
}
