// Sticker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sticker.h"
#include "LegacySticker.h"
#include "ChromeSticker.h"
#include "StickerRepository.h"
int main()
{
	Sticker s("Messi");
//	s.printInfo();
	ChromeSticker cs("Ronaldo");
	ChromeSticker cs2("Ronaldo");
//	cs.printInfo();
//	cs2.printInfo();
	LegacySticker ls("Suarez", "Barca", 258);
	LegacySticker ls2("Bale", "Real Madrid", 190);
//	ls.printInfo();
//	ls2.printInfo();
	StickerRepository sp;
	std::vector<Sticker> deck;
	deck.push_back(s);
	deck.push_back(cs);
	deck.push_back(cs2);
	deck.push_back(ls);
	deck.push_back(ls2);
	sp.addAll(deck);
	for (size_t i = 0; i < sp.getSize(); i++)
	{
		sp[i].printInfo();
	}
	//sp.findByNum(13453);

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
