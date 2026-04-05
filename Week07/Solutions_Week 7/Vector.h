#pragma once
#include <iostream>
class Vector
{
private:
	const int INITIAL_SIZE = 3;

	double* arr;
	int size;

	void copyFrom(const Vector& other);
	void moveFrom(Vector&& other) noexcept;
	void free();
	void resizeToFit(const Vector& other);

public:
	Vector();
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);

	Vector(Vector&& other) noexcept;
	Vector& operator=(Vector&& other) noexcept;
	~Vector();

	Vector& operator+=(const Vector& other);
	Vector& operator-=(const Vector& other);
	double operator*=(const Vector& other);
	Vector& operator/=(const Vector& other);
	Vector& operator*=(double scalar);

	Vector& operator++();
	Vector operator++(int dummy);

	double& operator[](int index);
	const double& operator[](int index) const;

	bool operator==(const Vector& other) const;
	bool operator<(const Vector& other) const;
	bool operator>=(const Vector& other) const;
	bool operator<=(const Vector& other) const;
	bool operator>(const Vector& other) const;
	//auto operator<=>(const Vector& other) const = default;

	double findLength() const;
	friend double findCos(const Vector& lhs, const Vector& rhs);
	friend double findSin(const Vector& lhs, const Vector& rhs);

	friend std::ostream& operator<<(std::ostream& os, const Vector& other);
	friend std::istream& operator>>(std::istream& is, Vector& other);

};

Vector operator+(const Vector& lhs,const Vector& rhs);
Vector operator-(const Vector& lhs, const Vector& rhs);
Vector operator/(const Vector& lhs, const Vector& rhs);
double operator*(const Vector& lhs, const Vector& rhs);

Vector operator*(const Vector& lhs,double scalar);
Vector operator*(double scalar,const Vector& lhs);

double operator^(const Vector& lhs, const Vector& rhs);