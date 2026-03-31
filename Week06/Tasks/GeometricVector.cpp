#include "GeometricVector.h"
#include "GeometricVector.h"
#include "GeometricVector.h"
#include <cmath>
void GeometricVector::copyFrom(const GeometricVector& other)
{
	if (other.size <= 0 || other.array == nullptr)
	{
		this->array = nullptr;
		this->size = 0;
		return;
	}
	this->size = other.size;
	this->array = new int[other.size];
	for (int i = 0; i < this->size; i++)
	{
		this->array[i] = other.array[i];
	}
}

void GeometricVector::free()
{
	delete[] this->array;
	this->array = nullptr;
	size = 0;
}

void GeometricVector::resizeToFit(const GeometricVector& other)
{
	if (this->size < other.size)
	{
		int* newArr = new int[other.size] {0};
		for (int i = 0; i < size; i++)
		{
			newArr[i] = this->array[i];
		}
		delete[] this->array;
		this->size = other.size;
		this->array = newArr;

	}
}

GeometricVector::GeometricVector() : array(nullptr), size(INITIAL_SIZE)
{
	array = new int[size] {0};
}

GeometricVector::GeometricVector(int size, int* arr) : size(size)
{
	this->array = new int[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->array[i] = arr[i];
	}
}

GeometricVector::GeometricVector(const GeometricVector& other) : array(nullptr), size(0)
{
	copyFrom(other);
}

GeometricVector::~GeometricVector()
{
	free();
}

GeometricVector& GeometricVector::operator=(const GeometricVector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

GeometricVector& GeometricVector::operator+=(const GeometricVector& rhs)
{
	if (this->size < rhs.size)
	{
		resizeToFit(rhs);
	}
	for (int i = 0; i < rhs.size; i++)
	{		
		this->array[i] += rhs.array[i];
	}
	return *this;
}

GeometricVector& GeometricVector::operator-=(const GeometricVector& rhs)
{
	if (this->size < rhs.size)
	{
		resizeToFit(rhs);
	}
	for (int i = 0; i < rhs.size; i++)
	{
		this->array[i] -= rhs.array[i];
	}
	return *this;
}

GeometricVector& GeometricVector::operator*=(const int scalar)
{
	for (int i = 0; i < this->size; i++)
	{
		this->array[i] *= scalar;
	}
	return *this;
}

double GeometricVector::operator*=(const GeometricVector& rhs)
{
	if (this->array == nullptr || rhs.array == nullptr)
	{
		return 0;
	}
	double sum = 0;
	int minSize = (this->size > rhs.size) ? (rhs.size) : (this->size);
	for (int i = 0; i < minSize; i++)
	{
		sum += (double)this->array[i] * rhs.array[i];
	}
	return sum;
}

int GeometricVector::operator[](int index) const {
	return this->array[index];
}

double GeometricVector::findLength() const
{
	double sum = 0;
	for (int i = 0; i < this->size; i++)
	{
		sum += pow(this->array[i], 2);
	}
	return sqrt(sum);
}

const int GeometricVector::getSizeOfVector() const
{
	return this->size;
}

void GeometricVector::printVector()
{
	std::cout << "Your vector is: ( ";
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->array[i] << " ";
		if (i + 1 < this->size)
		{
			std::cout << ", ";
		}
	}
	std::cout << ")\n";
}

double findCos(const GeometricVector& lhs, const GeometricVector& rhs)
{
	double lenOfLhs = lhs.findLength();
	double lenOfRhs = rhs.findLength();
	double result = lhs * rhs;
	if (lenOfLhs == 0 || lenOfRhs == 0)
	{
		return -1;
	}
	return result / (lenOfLhs * lenOfRhs);
}

double findSin(const GeometricVector& lhs, const GeometricVector& rhs)
{
	double cos = findCos(lhs, rhs);
	return sqrt(1 - pow(cos, 2));
}

double operator*(const GeometricVector& lhs, const GeometricVector& rhs)
{
	GeometricVector result(lhs);
	double Scresult = (double)(result *= rhs);
	return Scresult;
}

double operator^(const GeometricVector& lhs, const GeometricVector& rhs)
{
	double sin = abs(findSin(lhs, rhs));
	return sin * lhs.findLength() * rhs.findLength();
}

std::ostream& operator<<(std::ostream& os, const GeometricVector& v) 
{
	os << '(';
	for (int i = 0; i < v.size; i++)
	{
		os << v.array[i];
		if (i + 1 < v.size)
		{
			os << ', ';
		}
	}
	os << ')';
	return os;
}

std::istream& operator>>(std::istream& is, GeometricVector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		is >> v.array[i];
	}
	return is;
}
