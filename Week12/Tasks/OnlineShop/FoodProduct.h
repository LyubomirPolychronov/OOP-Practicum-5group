#pragma once
#include "Product.h"
class FoodProduct : public Product
{
private:
	int grams;
public:
	FoodProduct(const std::string& name, const std::string& manufacturer, double price, int stockCount, int grams) : Product(name,manufacturer,price, stockCount), grams(grams){}

	void getSize() const override { std::cout << grams << " grams"; }

	std::unique_ptr<Product> clone() const override {
		return std::make_unique<FoodProduct>(*this);
	}

	int getGrams() const { return grams; }
};

