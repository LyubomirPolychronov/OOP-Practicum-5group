#include "Vector.h"
#include <cmath>
void Vector::copyFrom(const Vector& other)
{
	if (other.arr == nullptr)
	{
		return;
	}
	this->arr = new double[other.size];
	this->size = other.size;
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = other.arr[i];
	}
}

void Vector::moveFrom(Vector&& other) noexcept
{
	//if (other.arr == nullptr)
	//{
	//	return;
	//}
	this->size = other.size;
	this->arr = other.arr;

	other.arr = nullptr;
	other.size = 0;
}

void Vector::free()
{
	delete[] this->arr;
	this->arr = nullptr;
	this->size = 0;
}

void Vector::resizeToFit(const Vector& other)
{
	if (this->arr == nullptr || other.arr == nullptr)
	{
		return;
	}

	double* newArr = new double[other.size] {0};
	int minSize = this->size < other.size ? this->size : other.size;
	for (int i = 0; i < minSize; i++)
	{
		newArr[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = newArr;
	this->size = other.size;
}

Vector::Vector() : arr(nullptr), size(INITIAL_SIZE)
{
	arr = new double[INITIAL_SIZE] {0};
}

Vector::Vector(const Vector& other)
{
	copyFrom(other);
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Vector::Vector(Vector&& other) noexcept
{
	moveFrom(std::move(other));
}

Vector& Vector::operator=(Vector&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Vector::~Vector()
{
	free();
}

Vector& Vector::operator+=(const Vector& other)
{
	if (this->size < other.size)
	{
		resizeToFit(other);
	}
	for (int i = 0; i < other.size; i++)
	{
		this->arr[i] += other.arr[i];
	}
	return *this;
}

Vector& Vector::operator-=(const Vector& other)
{
	if (this->size < other.size)
	{
		resizeToFit(other);
	}
	for (int i = 0; i < other.size; i++)
	{
		this->arr[i] -= other.arr[i];
	}
	return *this;
}

double Vector::operator*=(const Vector& other)
{
	if (this->size < other.size)
	{
		resizeToFit(other);
	}
	double sum = 0;
	for (int i = 0; i < other.size; i++)
	{
		sum += this->arr[i] * other.arr[i];
	}
	return sum;
}

Vector& Vector::operator/=(const Vector& other)
{
	if (this->size < other.size)
	{
		resizeToFit(other);
	}
	for (int i = 0; i < other.size; i++)
	{
		this->arr[i] /= other.arr[i];
	}
	return *this;
}

Vector& Vector::operator*=(double scalar)
{
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] *= scalar;
	}
	return *this;
}

Vector& Vector::operator++() {
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i]++;
	}
	return *this;
}

Vector Vector::operator++(int dummy) {
	Vector temp(*this);
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i]++;
	}
	return temp;
}

double& Vector::operator[](int index)
{
	/*if (index < 0 || index > this->size)
	{
		std::cout << "Invalid input\n";
		return;
	}*/

	return this->arr[index];
}

const double& Vector::operator[](int index) const
{
	/*if (index < 0 || index > this->size)
	{
		std::cout << "Invalid input\n";
		return;
	}*/
	return this->arr[index];
}

bool Vector::operator==(const Vector& other) const
{
	if (this->size != other.size)
	{
		return false;
	}
	for (int i = 0; i < other.size; i++)
	{
		if (this->arr[i] != other.arr[i]) {
			return false;
		}
	}
	return true;
}

bool Vector::operator<(const Vector& other) const
{
	if (this->size != other.size)
	{
		return false;
	}
	if (this->findLength() >= other.findLength())
	{
		return false;
	}
	for (int i = 0; i < other.size; i++)
	{
		if (this->arr[i] >= other.arr[i]) {
			return false;
		}
	}
	return true;
}

bool Vector::operator>=(const Vector& other) const
{
	return !(*this < other);
}

bool Vector::operator<=(const Vector& other) const
{
	return (*this < other || *this == other);
}

bool Vector::operator>(const Vector& other) const
{
	return !(*this <= other);
}

double Vector::findLength() const
{
	double sum = 0;
	for (int i = 0; i < this->size; i++)
	{
		sum += pow(this->arr[i], 2);
	}
	return sqrt(sum);
}

double findCos(const Vector& lhs, const Vector& rhs)
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

double findSin(const Vector& lhs, const Vector& rhs)
{
	return sqrt(1 - pow(findCos(lhs,rhs), 2));
}

std::ostream& operator<<(std::ostream& os, const Vector& other)
{
	os << "( ";
	for (int i = 0; i < other.size; i++)
	{
		os << other.arr[i];
		if (i + 1 < other.size)
		{
			os << ',';
		}
	}
	os << " )\n";
	return os;
}

std::istream& operator>>(std::istream& is, Vector& other)
{
	int newSize;
	std::cout << "Enter size ";
	is >> newSize;
	if (newSize != other.size)
	{
		double* newArr = new double[newSize];
		delete[] other.arr;
		other.arr = newArr;
		other.size = newSize;
	}
	for (int i = 0; i < other.size; i++)
	{
		is >> other.arr[i];
	}
	return is;
}

Vector operator+(const Vector& lhs, const Vector& rhs)
{
	Vector result(lhs);
	result += rhs;
	return result;
}

Vector operator-(const Vector& lhs, const Vector& rhs)
{
	Vector result(lhs);
	result -= rhs;
	return result;
}

Vector operator/(const Vector& lhs, const Vector& rhs)
{
	Vector result(lhs);
	result /= rhs;
	return result;
}

double operator*(const Vector& lhs, const Vector& rhs)
{
	Vector result(lhs);
	double resultOfMulti = (result *= rhs);
	return resultOfMulti;
}

Vector operator*(const Vector& lhs, double scalar)
{
	Vector result(lhs);
	result *= scalar;
	return result;
}

Vector operator*(double scalar, const Vector& lhs)
{
	Vector result(lhs);
	result *= scalar;
	return result;
}

double operator^(const Vector& lhs, const Vector& rhs)
{
	double sin = findSin(lhs, rhs);
	double lenOfLhs = lhs.findLength();
	double lenOfRhs = rhs.findLength();
	return abs(sin * lenOfLhs * lenOfRhs);
}
