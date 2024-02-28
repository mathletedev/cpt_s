#pragma once

#include "node.hpp"
#include <iostream>

template <class T>
class Queue {
	public:
		Queue();

		bool isEmpty() const;

		bool enqueue(const T &data);
		T dequeue();
		void printRecursive() const;

	private:
		Node<T> *head;
		Node<T> *tail;

		void printRecursiveHelper(Node<T> *curr) const;
};

template <class T>
Queue<T>::Queue() {
	head = tail = nullptr;
}

template <class T>
bool Queue<T>::isEmpty() const {
	return head == nullptr;
}

template <class T>
bool Queue<T>::enqueue(const T &data) {
	Node<T> *node = new Node<T>(data);
	if (node == nullptr) return false;

	if (head == nullptr) {
		head = tail = node;
		return true;
	}

	tail->setNext(node);
	tail = node;

	return true;
}

template <class T>
T Queue<T>::dequeue() {
	T data = head->getData();
	Node<T> *tmp = head->getNext();

	if (tail == head) tail = nullptr;
	delete head;
	head = tmp;

	return data;
}

template <class T>
void Queue<T>::printRecursive() const {
	printRecursiveHelper(head);
}

template <class T>
void Queue<T>::printRecursiveHelper(Node<T> *curr) const {
	if (curr == nullptr) {
		std::cout << "nullptr" << std::endl;
		return;
	}

	std::cout << curr->getData() << " -> ";
	printRecursiveHelper(curr->getNext());
}
