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
	LinkedList<int> l;

	l.push(1);
	l.push(2);
	l.push(3);
	l.push(4);

	l.remove([](int const &data) { return data == 3; });

	return l.nth(0) == 4 && l.nth(1) == 2 && l.nth(2) == 1;
}

bool test_all() {
	return test_insert_front() && test_remove();
}
