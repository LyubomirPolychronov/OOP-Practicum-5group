#pragma once
#include "User.h"
#include "Product.h"
using namespace constants;
class FoodMarket
{
private:
	std::vector<std::unique_ptr<User>> users;
	std::vector<std::unique_ptr<Product>> catalog;

	User* findUser(int userId) {
		for (auto& ptr : users)
		{
			if (ptr->getId() == userId)
			{
				return ptr.get();
			}
		}
		return nullptr;
	}
	Product* findProduct(int productId) {
		for (auto& ptr : catalog)
		{
			if (ptr->getId() == productId)
			{
				return ptr.get();
			}
		}
		return nullptr;
	}
	
public:
	FoodMarket() = default;
	void registerUser(const User& u) { users.push_back(u.clone()); }
	void addProduct(const Product& p) { catalog.push_back(p.clone()); }

	void depositUser(int userId, double amount) {
		User* u = findUser(userId);
		if (u)
		{
			u->addBalance(amount);
			std::cout << "Deposited " << amount << " to " << u->getName() << std::endl;
		}
	}
	void likeProduct(int userId, int ProductId){
		User* u = findUser(userId);
		Product* p = findProduct(ProductId);
		if (u && p)
		{
			u->likeProduct(*p);
			std::cout << u->getName() << " liked " << p->getName() <<  std::endl;
		}
	}
	void buyProduct(int userId, int productId) {
		User* u = findUser(userId);
		Product* p = findProduct(productId);
		if (!u || !p)
		{
			std::cout << "User or Product not found" << std::endl;
			return;
		}
		if (p->getStockCount() <= 0)
		{
			std::cout << "Product " << p->getName() << " is out of stock" << std::endl;
			return;
		}
		
		double price = p->getPrice() * u->getDiscount();
		if (u->getBalance() < price)
		{
			std::cout << "User " << u->getName() << " doesn't have enough money" << std::endl;
			return;
		}
		u->addToBasket(*p);
		u->deductBalance(price);
		p->setStockCount(p->getStockCount() - 1);

		std::cout << u->getName() << " successfully bought " << p->getName()
			<< " for " << price << "eu" << std::endl;

		if (p->getStockCount() < MIN_STOCK) {
			refillStock();
		}
	}
	void refillStock() {
		std::cout << "\n--- Market Stock Refill Triggered ---" << std::endl;
		for (auto& ptr:catalog)
		{
			if (ptr->getStockCount() < MIN_STOCK)
			{
				ptr->setStockCount(REFILL_COUNT);
				std::cout << "Refilled product: " << ptr->getName() << " to " << REFILL_COUNT << " items" << std::endl;
			}
		}
	}
	void printCatalog() const {
		for (auto& ptr : catalog)
		{
			ptr->printInfo();
		}
	}
};

