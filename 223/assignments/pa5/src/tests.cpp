#include "tests.hpp"
#include "linked_list.hpp"
#include "sorting.hpp"
#include <iostream>

void tests::test_all() {
	test_msort();
	std::cout << "All tests passed!" << std::endl;
}

void tests::test_msort() {
	LinkedList<int> xs = {8, 5, 2, 9, 1, 4, 7, 6, 3};
	LinkedList<int> target = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	LinkedList<int> res =
	    sorting::msort<int>(xs, [](int x, int y) { return x < y; });
	assert(res == target);
}
