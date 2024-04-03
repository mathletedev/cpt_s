#include "testperson.hpp"

void test_person::test_set_name() {
	set_name("Billy");

	std::cout << "test_set_name(): ";
	if (name_ == "Billy")
		std::cout << "passed";
	else
		std::cout << "failed";
	std::cout << std::endl;
}
