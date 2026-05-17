#pragma once
#include <string>
#include <iostream>
class Sticker
{
protected:
	int number;
	static int nextNumber;
	std::string name;
public:
	Sticker(const std::string& name);
	
	virtual ~Sticker() {};
	virtual void printInfo() const;

	int getNum() const;
	const std::string& getName() const;
};

