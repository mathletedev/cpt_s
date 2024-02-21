#include "list.hpp"

List::List() {
	head = nullptr;
}

List::List(const List &other) {
	*this = other;
}

List::~List() {
	destroyList();
}

List &List::operator=(const List &other) {
	destroyList();

	// copy over head from other
	head = new ListNode(other.getHead()->getData());

	ListNode *tail = head;

	for (ListNode *curr = other.getHead()->getNext(); curr != nullptr;
	     curr = curr->getNext()) {
		// copy over node
		ListNode *node = new ListNode(curr->getData());
		tail->setNext(node);

		tail = tail->getNext();
	}

	return *this;
}

ListNode *List::getHead() const {
	return head;
}

void List::setHead(ListNode *const head) {
	this->head = head;
}

bool List::insertAtFront(const int data) {
	ListNode *node = new ListNode(data);
	if (node == nullptr) return false;

	node->setNext(head);
	head = node;

	return true;
}

bool List::insertInOrder(const int data) {
	bool success = false;

	return success;
}

bool List::insertAtEnd(const int data) {
	bool success = false;

	return success;
}

bool List::isEmpty() const {
	return head == nullptr;
}

int List::deleteAtFront() {
	int data = 0;

	return data;
}

bool List::deleteNode(const int searchValue) {
	bool success = false;

	return success;
}

int List::deleteAtEnd() {
	int data = 0;

	return data;
}

void List::printList() {
	for (ListNode *curr = head; curr != nullptr; curr = curr->getNext())
		std::cout << curr->getData() << std::endl;
}

void List::destroyListHelper(ListNode *const node) {
	if (node == nullptr) return;

	destroyListHelper(node->getNext());
	delete node;
}

void List::destroyList() {
	destroyListHelper(head);

	// reset head to nullptr
	head = nullptr;
}
