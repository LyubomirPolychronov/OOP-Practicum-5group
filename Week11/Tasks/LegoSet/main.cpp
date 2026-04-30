// LegoSet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LegoSet.h"
#include "SortedLegoCatalog.h"
#include "FilteredLegoCatalog.h"
int main()
{
	/*SortedLegoCatalog myCatalog(3);

    myCatalog.add(LegoSet("X-Wing Starfighter", 474, Theme::Lego_Star_Wars));
    myCatalog.add(LegoSet("Ninjago City Markets", 6163, Theme::Lego_Ninjago));
    myCatalog.add(LegoSet("Millennium Falcon", 7541, Theme::Lego_Star_Wars));
    myCatalog.add(LegoSet("Kai's Mech Rider", 312, Theme::Lego_Ninjago));

    std::cout << "--- Original Catalog ---" << std::endl;
    std::cout << myCatalog << std::endl;

    myCatalog.sort();
    std::cout << "--- Sorted by Piece Count (Ascending) ---" << std::endl;
    std::cout << myCatalog << std::endl;*/

   /* FilteredLegoCatalog filtered(2);
    filtered.add(LegoSet("Death Star", 4016, Theme::Lego_Star_Wars));
    filtered.add(LegoSet("Lloyd's Dragon", 747, Theme::Lego_Ninjago));
    filtered.add(LegoSet("Tantive IV", 1768, Theme::Lego_Star_Wars));

    std::cout << "--- Filtered Catalog (Before Filter) ---" << std::endl;
    std::cout << filtered << std::endl;

    filtered.filterByTheme("Lego Star Wars");
    std::cout << "--- Only Lego Star Wars Sets ---" << std::endl;
    std::cout << filtered << std::endl;

    filtered.limit(1);
    std::cout << "--- Limited to 1 Set ---" << std::endl;
    std::cout << filtered << std::endl;*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
