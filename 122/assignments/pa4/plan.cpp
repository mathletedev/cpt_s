#include "plan.hpp"

std::ifstream &operator>>(std::ifstream &fileStream, Plan &plan) {
	int goal;
	fileStream >> goal;

	return fileStream;
}
