#pragma once

#include <iostream>

class Complex {
	public:
		Complex(double real = 0, double imaginary = 0);

		void setReal(double real);
		void setImaginary(double imaginary);
		double getReal();
		double getImaginary();

		Complex add(const Complex &other);
		Complex subtract(const Complex &other);

		void read();
		void print();

	private:
		double real;
		double imaginary;
};

Complex add(const Complex &c1, const Complex &c2);
Complex subtract(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c1, const Complex &c2);
Complex operator-(const Complex &c1, const Complex &c2);
std::istream &operator>>(std::istream &stream, Complex &complex);
std::ostream &operator<<(std::ostream &stream, Complex &complex);
