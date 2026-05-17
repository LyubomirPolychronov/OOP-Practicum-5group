#pragma once
#include <iostream>
#include <string>
#include <memory>	
#include <vector>
#include "Product.h"
class User
{
protected:
	std::string name;
	std::string password;
	int id;
	inline static int nextId = 1;
	int age;
	double balance;
	std::vector<std::unique_ptr<Product>> basket;
	std::vector<std::unique_ptr<Product>> likedProducts;;

public:
	User(const std::string& name, const std::string& pass, int age, double balance) : name(name), password(pass), age(age),balance(balance), id(nextId++) {};
	User(const User& other) :name(other.name), password(other.password), age(other.age), balance(other.balance), id(other.id) {
		for (auto& ptr : other.basket) {
			if (ptr) {
				this->basket.push_back(ptr->clone());
			}
		}
		for (auto& ptr : likedProducts) {
			if (ptr) {
				this->likedProducts.push_back(ptr->clone());
			}
		}
	}
	virtual ~User()  = default;
	virtual std::unique_ptr<User> clone() const = 0;
	virtual double getDiscount() const = 0;

	void seeBasket() const {
		std::cout << "--- Basket for " << name << " ---" << std::endl;
		double total = 0;

		for (const auto& prod : basket) {
			double discountedPrice = prod->getPrice() * getDiscount();

			std::cout << "- " << prod->getName() << " (Original: " << prod->getPrice()
				<< ", Your Price: " << discountedPrice << ")" << std::endl;
			total += discountedPrice;
		}
		std::cout << "Total Basket Value: " << total << " (Current Balance: " << balance << ")" << std::endl;
	}
	void addToBasket(const Product& p) { basket.push_back(p.clone()); }
	void likeProduct(const Product& p) { likedProducts.push_back(p.clone()); }
	
	double getBalance() const { return balance; }
	void deductBalance(double price) { balance -= price; }
	void addBalance(double amount) { balance += amount; }

	const std::string& getName() const { return name; }
	int getId() const { return id; }
	int getAge() const { return age; }
};

