#pragma once
class GeometricProgression
{
private:
	double first;
	double quotient;

public:
	GeometricProgression();
	GeometricProgression(double first, double quotient);

	double operator[](int n) ;
	double operator()(int n);
	friend GeometricProgression operator*(const GeometricProgression& lhs, const GeometricProgression& rhs);
	friend GeometricProgression operator+(const GeometricProgression& lhs,const GeometricProgression& rhs);
};

