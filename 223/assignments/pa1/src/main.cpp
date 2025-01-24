#include "tests.hpp"
#include <iostream>

int main(int arc, char **argv) {
	if (arc >= 2 && argv[1] == std::string("--test")) {
		bool passed = test_all();
		std::cout << "tests " << (passed ? "passed" : "failed")
			  << std::endl;
		return !passed;
	}

	std::cout << "Hello, world!" << std::endl;

	return 0;
}