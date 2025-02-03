#include "tests.hpp"
#include "linked_list.hpp"

// TODO: implement equality comparison for linked list
// TODO: test functional methods

bool test_push() {
	LinkedList<int> l;

	l.push_front(1);
	l.push_front(2);
	l.push_back(3);
	l.push_back(4);

	return l.nth(0) == 2 && l.nth(1) == 1 && l.nth(2) == 3 &&
	       l.nth(3) == 4 && l.length() == 4;
}

bool test_remove() {
	LinkedList<int> l1;

	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);

	l1.remove([](int const &data) { return data == 3; });

	LinkedList<int> l2;

	bool l2_passed = false;
	try {
		l2.remove([](int const &data) { return data == 3; });
	} catch (...) {
		l2_passed = true;
	}

	return l1.nth(0) == 1 && l1.nth(1) == 2 && l1.nth(2) == 4 &&
	       l1.length() == 3 && l2_passed && l2.length() == 0;
}

bool test_all() {
	return test_push() && test_remove();
}
