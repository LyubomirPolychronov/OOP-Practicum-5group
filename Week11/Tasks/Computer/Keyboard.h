#pragma once
#include <vector>
#include "Computer_Peripheral.h"

enum class Language {
	EN,
	BG,
	ES,
	FR,
	DE,
};

class Keyboard : public Computer_Peripheral
{
private:
	std::string color;
	std::vector<Language> language;

public:
	Keyboard(const std::string& model, const std::string& manufacturer, double price,const std::string& color, const std::vector<Language>& language) : Computer_Peripheral(model, manufacturer, price) , color(color), language(language) {
		if (this->language.size() > 2) {
			this->language.resize(2);
		}
	}
};

