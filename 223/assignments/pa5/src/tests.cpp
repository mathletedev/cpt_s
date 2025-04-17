#include "tests.hpp"
#include "linked_list.hpp"
#include "sorting.hpp"
#include <iostream>

void test_msort_functional() {
	LinkedList<int> xs = {8, 5, 2, 9, 1, 4, 7, 6, 3};
	LinkedList<int> target = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	LinkedList<int> res =
	    sorting::msort<int>(xs, [](int x, int y) { return x < y; });
	assert(res == target);
}

void test_msort_imperative() {
	LinkedList<int> xs = {8, 5, 2, 9, 1, 4, 7, 6, 3};
	LinkedList<int> target = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	xs.msort([](int x, int y) { return x < y; });
	assert(xs == target);
}

void test_isort() {
	LinkedList<int> xs = {8, 5, 2, 9, 1, 4, 7, 6, 3};
	LinkedList<int> target = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	xs.isort([](int x, int y) { return x < y; });
	assert(xs == target);
}

void tests::test_all() {
	test_msort_functional();
	test_msort_imperative();
	test_isort();

	std::cout << "All tests passed!" << std::endl;
}
