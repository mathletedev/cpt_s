#include "listapp.hpp"

int main() {
	List l1;
	l1.insertAtFront(3);
	l1.insertAtFront(4);
	l1.insertAtFront(5);
	List l2 = l1;

	l1.printList();
	l2.printList();

	return 0;
}
