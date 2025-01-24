#include "tests.hpp"
#include "linked_list.hpp"

bool test_insert_front() {
	LinkedList<int> l;

	l.push(1);
	l.push(2);
	l.push(3);
	l.push(4);

	return l.nth(0) == 4 && l.nth(1) == 3 && l.nth(2) == 2 && l.nth(3) == 1;
}

bool test_remove() {
	LinkedList<int> l1;

	l1.push(1);
	l1.push(2);
	l1.push(3);
	l1.push(4);

	l1.remove([](int const &data) { return data == 3; });

	LinkedList<int> l2;

	bool l2_passed = false;
	try {
		l2.remove([](int const &data) { return data == 3; });
	} catch (...) {
		l2_passed = true;
	}

	return l1.nth(0) == 4 && l1.nth(1) == 2 && l1.nth(2) == 1 && l2_passed;
}

bool test_all() {
	return test_insert_front() && test_remove();
}
