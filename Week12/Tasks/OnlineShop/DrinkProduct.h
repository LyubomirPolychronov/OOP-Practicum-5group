#pragma once
#include "Product.h"
class DrinkProduct : public Product
{
private:
	int ml;
public:
	DrinkProduct(const std::string& name, const std::string& manufacturer, double price, int stockCount, int ml) : Product(name, manufacturer, price, stockCount), ml(ml){}

	void getSize() const override { std::cout << ml << " ml"; }

	std::unique_ptr<Product> clone() const override {
		return std::make_unique<DrinkProduct>(*this);
	}

	int getMl() const { return ml; }
};

