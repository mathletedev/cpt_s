#include "game_manager.hpp"
#include "tests.hpp"
#include <iostream>

int main(int arc, char **argv) {
	if (arc >= 2 && argv[1] == std::string("--test")) {
		bool passed = test_all();
		std::cout << "tests " << (passed ? "passed" : "failed")
			  << std::endl;
		return !passed;
	}

	GameManager gm;
	gm.run();

	return 0;
}
