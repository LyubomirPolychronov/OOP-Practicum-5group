// Repository.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Repository.hpp"
#include <iostream>

int main() {
    Repository<int> repo;
    repo.add(10);
    repo.add(15);
    repo.add(20);
    repo.add(25);
    repo.print();

    bool hasBigNumber = repo.contains([](const int& x) { return x > 18; }); 
    std::cout << hasBigNumber << std::endl;

    std::vector collection = { 12, 13, 4 };
    repo.addAll(collection);
    repo.print();
    std::vector<int> evenNumbers = repo.findAll([](const int& x) { return x % 2 == 0; }); 
    for (size_t i = 0; i < evenNumbers.size(); i++)
    {
        std::cout << evenNumbers[i] << " ";
    }
    std::cout << std::endl;
    repo.remove([](const int& x) { return x % 5 == 0; });
    repo.print();
    return 0;
}