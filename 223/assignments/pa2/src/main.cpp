#include "test_list_my_josephus.hpp"
#include "test_vector_my_josephus.hpp"
#include <string>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		return 1;
	}

	if (std::string(argv[1]) == "list") {
		test_list_my_josephus();
		return 0;
	}

	if (std::string(argv[1]) == "vector") {
		test_vector_my_josephus();
		return 0;
	}

	return 1;
}
