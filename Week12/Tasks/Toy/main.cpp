// Toy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DogToy.h"
#include "TrainToy.h"
#include "SquishyToy.h"
#include "CarToy.h"
int main()
{
	DogToy dt("roshko", "bosch", Condition::New, 20.99);
	TrainToy tt("train", "bosch", Condition::New, 24.66);
	SquishyToy st("squishko", "bosch", Condition::Used, 25.56);
	CarToy ct("car", "bosch", Condition::Used, 27.99);
	dt.printInfo();
	tt.printInfo();
	st.printInfo();
	ct.printInfo();


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
