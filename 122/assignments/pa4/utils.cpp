#include "utils.hpp"

// https://stackoverflow.com/a/23745035
void utils::flush() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// waits for Enter to be pressed
void utils::suspend() {
	std::cout << "Press Enter to continue...";
	std::cin.get();
}
