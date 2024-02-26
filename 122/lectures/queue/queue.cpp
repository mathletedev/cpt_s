#include "queue.hpp"

Queue::Queue(Node *head, Node *tail) {
	this->head = head;
	this->tail = tail;
}

bool Queue::enqueue(std::string printJob) {
	Node *node = new Node(printJob);
	if (node == nullptr) return false;

	if (head == nullptr) {
		head = tail = node;
		return true;
	}

	tail->setNext(node);
	tail = node;

	return true;
}

std::string Queue::dequeue() {
	std::string data = head->getPrintJob();
	Node *next = head;

	if (head == tail) tail = nullptr;
	head = head->getNext();
	delete head;

	return data;
}

bool Queue::isEmpty() const {
	return head == nullptr;
}
