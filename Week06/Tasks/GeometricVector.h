#pragma once
#include <iostream>
class GeometricVector
{
private:
	int size;
	int* array;

	const static int INITIAL_SIZE = 3;
	void copyFrom(const GeometricVector& other);
	void free();
	void resizeToFit(const GeometricVector& other);
public:
	GeometricVector();
	GeometricVector(int size, int* arr);
	GeometricVector(const GeometricVector& other);
	~GeometricVector();

	GeometricVector& operator=(const GeometricVector& other);
	GeometricVector& operator+=(const GeometricVector& rhs);
	GeometricVector& operator-=(const GeometricVector& rhs);
	GeometricVector& operator*=(const int scalar);
	double operator*=(const GeometricVector& rhs);
	int operator[](int index) const;

	double findLength() const;
	const int getSizeOfVector() const;
	void printVector();

	friend double findCos(const GeometricVector& lhs, const GeometricVector& rhs);
	friend double findSin(const GeometricVector& lhs, const GeometricVector& rhs);

	friend std::ostream& operator<<(std::ostream& os, const GeometricVector& v);
	friend std::istream& operator>>(std::istream& is, GeometricVector& v);
};

	double operator*(const GeometricVector& lhs, const GeometricVector& rhs);
	double operator^(const GeometricVector& lhs, const GeometricVector& rhs);
