#pragma once
#include "User.h"
class SilverUser : public User
{
public:
	SilverUser(const std::string& name, const std::string& pass, int age, double balance) : User(name, pass, age,balance) {}

	double getDiscount() const override { return 0.9; }

	std::unique_ptr<User> clone() const override {
		return std::make_unique<SilverUser>(*this);
	}
};

