#include "complex.hpp"

Complex::Complex(double real, double imaginary) {
	this->real = real;
	this->imaginary = imaginary;
}

Complex Complex::add(Complex &other) {
	real += other.real;
	imaginary += other.imaginary;

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

Complex add(Complex &c1, Complex &c2) {
	return Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

Complex operator+(Complex &c1, Complex &c2) {
	return add(c1, c2);
}

Complex operator-(Complex &c1, Complex &c2) {
	return Complex(c1.real - c2.real, c1.imaginary - c2.imaginary);
}

std::istream &operator>>(std::istream &stream, Complex &complex) {
	stream >> complex.real;

	char c = '\0';
	while (!(c == '+' || c == '-'))
		stream >> c;

	stream >> complex.imaginary >> c;

	return stream;
}

std::ostream &operator<<(std::ostream &stream, Complex &complex) {
	stream << complex.real << " + " << complex.imaginary << "i";

	return stream;
}
