#include "Matrix.h"
//#include "GeometricVector.h"
#include <iostream>
#pragma warning (disable: 4996)
void Matrix::copyFrom(const Matrix& other)
{
	for (int i = 0; i < other.size; i++)
	{
		for (int j = 0; j < other.size; j++)
		{
			this->matrix[i][j] = other.matrix[i][j];
		}
	}
	this->size = other.size;
}

void Matrix::free()
{
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
		matrix[i] = nullptr;
	}
	delete[] matrix;
	matrix = nullptr;
	size = 0;
}

void Matrix::allocate(int size)
{
	this->size = size;
	matrix = new int* [size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size] {0};
	}
}

Matrix::Matrix() : matrix(nullptr), size(DEFAULT_SIZE)
{
	allocate(DEFAULT_SIZE);
}

Matrix::Matrix(int size) : matrix(nullptr), size(size)
{
	allocate(size);
}

Matrix::Matrix(const Matrix& other)
{
	allocate(other.size);
	copyFrom(other);
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other)
	{
		free();
		allocate(other.size);
		copyFrom(other);
	}
	return *this;
}

Matrix::~Matrix()
{
	free();
}

void Matrix::resizeToFit(const Matrix& other)
{
	if (other.size <= 0 || this->size >= other.size)
	{
		return;
	}
	int** newMatrix = new int* [other.size];
	for (int i = 0; i < other.size; i++)
	{
		newMatrix[i] = new int[other.size] {0};
	}
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			newMatrix[i][j] = this->matrix[i][j];
		}
	}
	free();
	this->matrix = newMatrix;
	this->size = other.size;
}

void Matrix::printMatrix()
{
	std::cout << "This matrix has a size of " << this->size << std::endl;
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			std::cout << this->matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

const int Matrix::getSize() const
{
	return this->size;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	if (other.size > this->size)
	{
		resizeToFit(other);
	}
	for (int i = 0; i < other.size; i++)
	{
		for (int j = 0; j < other.size; j++)
		{
			matrix[i][j] += other.matrix[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	if (other.size > this->size)
	{
		resizeToFit(other);
	}
	for (int i = 0; i < other.size; i++)
	{
		for (int j = 0; j < other.size; j++)
		{
			this->matrix[i][j] -= other.matrix[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator*=(const int scalar)
{
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			matrix[i][j] *= scalar;
		}
	}
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
	if (this->size != other.size)
	{
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				matrix[i][j] = 0;
			}
		}
		return *this;
	}
	Matrix temp(this->size);
	for (int i = 0; i < other.size; i++)
	{
		for (int j = 0; j < other.size; j++)
		{
			temp.matrix[i][j] = 0;
			for (int k = 0; k < other.size; k++)
			{
				temp.matrix[i][j] += this->matrix[i][k] * other.matrix[k][j];
			}
		}
	}
	*this = temp;
	return *this;
}

int* Matrix::operator[](int index)
{
	return matrix[index];
}

const int* Matrix::operator[](int index) const
{
	return matrix[index];
}

bool Matrix::operator==(const Matrix& other) const
{
	if (this->size != other.size)
	{
		return false;
	}
	for (int i = 0; i < other.size; i++)
	{
		for (int j = 0; j < other.size; j++)
		{
			if (matrix[i][j] != other[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

Matrix& Matrix::operator++() {
	
	for (int i = 0; i < this->size; i++)
	{
		matrix[i][i]++;
	}
	return *this;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs)
{
	Matrix result(lhs);
	result *= rhs;
	return result;
}

GeometricVector operator*(const GeometricVector& vector, const Matrix& matrix)
{
	int n = matrix.getSize();
	int m = vector.getSizeOfVector();
	if (n != m)
	{
		return GeometricVector();
	}
	int* resultData = new int[n];
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += matrix[i][j] * vector[j];
		}
		resultData[i] = sum;
	}
	GeometricVector result(n, resultData);
	delete[] resultData;
	return result;
}
