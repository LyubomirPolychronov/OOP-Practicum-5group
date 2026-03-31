#include "GeometricProgression.h"
#include <cmath>
GeometricProgression::GeometricProgression() :  first(1.0), quotient(1.0)
{
}

GeometricProgression::GeometricProgression(double first, double quotient) : first(first), quotient(quotient)
{
}

double GeometricProgression::operator[](int n) 
{
	return this->first * pow(quotient, n);
}

double GeometricProgression::operator()(int n) {
	if (quotient == 1)
	{
		double sum = n * first;
		return sum;
	}
	double sumOfRow = first * ((1 - pow(quotient, n)) / (1 - quotient));
	return sumOfRow;
}


GeometricProgression operator*(const GeometricProgression& lhs, const GeometricProgression& rhs)
{
	return GeometricProgression(lhs.first * rhs.first, lhs.quotient * rhs.quotient);
}

GeometricProgression operator+(const GeometricProgression& lhs, const GeometricProgression& rhs)
{
	
	GeometricProgression result;
	result.first = lhs.first + rhs.first;
	result.quotient = lhs.quotient + rhs.quotient;
	
	return result;
}
