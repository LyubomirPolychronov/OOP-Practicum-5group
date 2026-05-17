#include <iostream>

double square(double num) {
	return num * num;
}

namespace Compelx {

	struct ComplexNumber {
		double realPart;
		double imPart;

		void printNum() {
			if (imPart >= 0)
			{
				std::cout << realPart << " + " << imPart << 'i';
			}
			else
			{
				std::cout << realPart << " - " << -imPart << 'i';
			}
		}
	};
		ComplexNumber sum(ComplexNumber num1, ComplexNumber num2) {
			ComplexNumber sum = { 0,0 };
			sum.realPart += (num1.realPart + num2.realPart);
			sum.imPart += (num1.imPart + num2.imPart);
			sum.printNum();
			return sum;
		}
		ComplexNumber multiply(ComplexNumber num1, ComplexNumber num2) {
			ComplexNumber total = { 0,0 };
			total.realPart += num1.realPart * num2.realPart - num1.imPart * num2.imPart;
			total.imPart += num1.realPart * num2.imPart + num1.imPart * num2.realPart;
			total.printNum();
			return total;
		}
		ComplexNumber divide(ComplexNumber num1, ComplexNumber num2) {
			ComplexNumber quotient = { 0,0 };
			quotient.realPart += (num1.realPart * num2.realPart + num1.imPart * num2.imPart) / (square(num2.realPart) + square(num2.imPart));
			quotient.imPart += (num1.imPart * num2.realPart - num1.realPart * num2.imPart) / (square(num2.realPart) + square(num2.imPart));
			quotient.printNum();
			return quotient;
		}
}

int main()
{
	using namespace Compelx;
	ComplexNumber num1;
	num1.realPart = 3;
	num1.imPart = -5;
	ComplexNumber num2 = { 3.0, -1.0 };
	//num1.printNum();
	//sum(num1, num2);
	//multiply(num1, num2);
	divide(num1, num2);
}
