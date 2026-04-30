#include "SortedLegoCatalog.h"

void SortedLegoCatalog::sort()
{
	std::sort(sets.begin(), sets.end(), [](const std::unique_ptr<LegoSet>& a, const std::unique_ptr<LegoSet>& b) {
		if (!a || !b)
		{
			return false;
		}
		return *a < *b;
		});
}
