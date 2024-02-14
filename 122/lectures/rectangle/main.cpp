#include "rectangle.hpp"

int main() {
	Rectangle r1(1.2, 3.4);
	Rectangle r2(5.6, 7.8);

	std::cout << r1 + r2 << std::endl;

	return 0;
}
