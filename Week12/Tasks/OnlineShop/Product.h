#pragma once
#include <iostream>
#include <memory>
#include <string>

namespace constants {
	const int MIN_STOCK = 2;
	const int REFILL_COUNT = 10;
	const int MAX_STOCK = 50;
}
using namespace constants;
class Product
{
protected:
	std::string name;
	std::string manufacturer;
	double price;
	int id;
	inline static int nextId = 1;
	int stockCount;

public:
	Product(const std::string& name, const std::string& manufacturer, double price, int stockCount) :
		name(name), manufacturer(manufacturer), price(price), stockCount(stockCount), id(nextId++){}
	Product(const Product& other) : name(other.name), manufacturer(other.manufacturer), price(other.price), stockCount(other.stockCount), id(other.id) {}
	virtual ~Product() = default;
	virtual void getSize() const = 0;
	virtual std::unique_ptr<Product> clone() const = 0;

	const std::string& getName()const { return name; }
	const std::string& getManufacturer()const { return manufacturer; }

	double getPrice() const { return price; }
	int getId() const { return id; }
	int getStockCount() const { return stockCount; }
	void printInfo() const {
		std::cout << "Name: " << name << " |Manufacturer: " << manufacturer << " |price: " << price << " |in stock: " << stockCount << "|id: " << id << std::endl;
	}
	void setStockCount(int a) {
		if (a < MIN_STOCK || a > MAX_STOCK)
		{
			return;
		}
		stockCount = a;
	}
};

