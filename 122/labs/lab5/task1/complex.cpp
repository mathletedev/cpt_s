#include "complex.hpp"

Complex::Complex(double real, double imaginary) {
	this->real = real;
	this->imaginary = imaginary;
}

void Complex::setReal(double real) {
	this->real = real;
}

void Complex::setImaginary(double imaginary) {
	this->imaginary = imaginary;
}

double Complex::getReal() {
	return real;
}

double Complex::getImaginary() {
	return imaginary;
}

Complex Complex::add(const Complex &other) {
	real += other.real;
	imaginary += other.imaginary;

	return *this;
}

Complex Complex::subtract(const Complex &other) {
	real -= other.real;
	imaginary -= other.imaginary;

	return *this;
}

void Complex::read() {
	std::cin >> real;

	char c = '\0';
	while (!(c == '+' || c == '-'))
		std::cin >> c;

	std::cin >> imaginary >> c;
}

void Complex::print() {
	std::cout << real << " + " << imaginary << "i" << std::endl;
}

Complex add(const Complex &c1, const Complex &c2) {
	Complex res = c1;
	return res.add(c2);
}

Complex subtract(const Complex &c1, const Complex &c2) {
	Complex res = c1;
	return res.subtract(c2);
}

Complex operator+(const Complex &c1, const Complex &c2) {
	return add(c1, c2);
}

Complex operator-(const Complex &c1, const Complex &c2) {
	return subtract(c1, c2);
}

std::istream &operator>>(std::istream &stream, Complex &complex) {
	double data;
	stream >> data;
	complex.setReal(data);

	char c = '\0';
	while (!(c == '+' || c == '-'))
		stream >> c;

	stream >> data >> c;
	complex.setImaginary(data);

	return stream;
}

std::ostream &operator<<(std::ostream &stream, Complex &complex) {
	stream << complex.getReal() << " + " << complex.getImaginary() << "i";

	return stream;
}
