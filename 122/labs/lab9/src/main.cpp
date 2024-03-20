#include "evaluator.hpp"
#include <fstream>

int main() {
	std::ifstream input;

	evaluator evaluator;

	input.open("data/input1.txt");
	std::cout << evaluator.evaluate(input) << std::endl;
	input.close();

	input.open("data/input2.txt");
	std::cout << evaluator.evaluate(input) << std::endl;
	input.close();

	input.open("data/input3.txt");
	std::cout << evaluator.evaluate(input) << std::endl;
	input.close();

	return 0;
}
