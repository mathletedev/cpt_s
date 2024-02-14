#include "complex.hpp"
#include <iostream>

int main() {
	Complex c1(3.5, 2), c2(5.5, 7), c3;

	c3 = c1.add(c2);
	c3 = add(c1, c2);
	c3 = c1 + c2;

	c3 = c1 - c2;

	std::cout << "Enter a complex number in the form a + bi: ";
	c1.read();

	std::cout << "Enter a complex number in the form a + bi: ";
	c2.read();

	std::cout << "Enter two complex numbers in the form a + bi (each "
		     "separated by whitespace): ";
	std::cin >> c1 >> c2;

	c1.print();
	c2.print();
	c3.print();

	std::cout << c1 << " " << c2 << " " << c3 << std::endl;

	return 0;
}
