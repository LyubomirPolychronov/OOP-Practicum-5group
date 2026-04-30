#pragma once
#include <iostream>
#include <string>
#include <compare>
enum class Theme {
	Lego_Star_Wars,
	Lego_Ninjago,
};

class LegoSet
{
private:
	std::string name;
	static int idCounter;
	int id;
	int pieceCount;
	Theme theme;

public:
	LegoSet(const std::string& name, int pieceCount, const Theme& t);

	std::strong_ordering operator<=>(const LegoSet& other) const;
	bool operator==(const LegoSet& other) const;
	
	int getPieceCount() const;
	const Theme& getTheme() const;
	const std::string& getName() const;
	
	friend std::ostream& operator<<(std::ostream& os, const LegoSet& set);
};
	std::string enumToString(const Theme& t);

