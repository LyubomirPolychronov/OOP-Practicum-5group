#pragma once
#include "GeometricVector.h"
class Matrix
{
private:
	int** matrix;
	int size;
	const int DEFAULT_SIZE = 2;

	void copyFrom(const Matrix& other);
	void free();
	void allocate(int size);

public:
	Matrix();
	Matrix(int size);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	~Matrix();

	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const int scalar);
	Matrix& operator*=(const Matrix& other);
	int* operator[](int index);
	const int* operator[](int index) const;

	bool operator==(const Matrix& other) const;
	Matrix& operator++();

	void resizeToFit(const Matrix& other);
	void printMatrix();
	const int getSize() const;
};

Matrix operator*(const Matrix& lhs, const Matrix& rhs);

GeometricVector operator*(const GeometricVector& vector, const Matrix& matrix);