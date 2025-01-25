#include "data.hpp"
#include "tests.hpp"
#include <fstream>
#include <iostream>

int main(int arc, char **argv) {
	if (arc >= 2 && argv[1] == std::string("--test")) {
		bool passed = test_all();
		std::cout << "tests " << (passed ? "passed" : "failed")
			  << std::endl;
		return !passed;
	}

	std::ifstream file("data/commands.csv");

	LinkedList<CommandData> commands = CommandData::from_csv_all(file);
	commands.display();

	file.close();

	return 0;
}
