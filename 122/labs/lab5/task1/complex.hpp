#pragma once

#include <iostream>

class Complex {
	public:
		double real;
		double imaginary;

		Complex(double real = 0, double imaginary = 0);

		Complex add(Complex &other);

		void read();
		void print();
};

Complex add(Complex &c1, Complex &c2);
Complex operator+(Complex &c1, Complex &c2);
Complex operator-(Complex &c1, Complex &c2);
std::istream &operator>>(std::istream &stream, Complex &complex);
std::ostream &operator<<(std::ostream &stream, Complex &complex);
