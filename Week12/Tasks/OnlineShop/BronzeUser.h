#pragma once
#include "User.h"
class BronzeUser : public User
{
public:
	BronzeUser(const std::string& name, const std::string& pass, int age, double balance) : User(name, pass, age, balance) {}

	double getDiscount() const override { return 1.0; }

	std::unique_ptr<User> clone() const override {
		return std::make_unique<BronzeUser>(*this);
	}
};

