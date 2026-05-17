// OnlineShop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FoodMarket.h"
#include "FoodProduct.h"
#include "DrinkProduct.h"
#include "GoldUser.h"
#include "SilverUser.h"
#include "BronzeUser.h"
int main() {
    FoodMarket market;

    FoodProduct bread("White Bread", "Simid", 1.50, 3, 500); 
    DrinkProduct milk("Milk 3.6%", " there ", 2.80, 1, 1000); 

    market.addProduct(bread);
    market.addProduct(milk);

    GoldUser ivan("Ivan", "pass123", 25, 10.0);  
    BronzeUser petar("Petar", "qwert", 19, 3.0);     

    market.registerUser(ivan);   
    market.registerUser(petar);  
    market.printCatalog();

    std::cout << "\n--- Transactions ---" << std::endl;
    market.buyProduct(1, 1); 
    market.buyProduct(2, 2); 

    std::cout << std::endl;
    market.printCatalog();

    return 0;
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
