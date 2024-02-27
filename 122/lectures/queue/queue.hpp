#pragma once

#include "node.hpp"
#include <iostream>
#include <string>

template <class T>
class Queue {
	public:
		Queue();
		bool enqueue(T data);
		T dequeue();
		bool isEmpty() const;

	private:
		Node<T> *head;
		Node<T> *tail;
};

template <class T>
Queue<T>::Queue() {
	this->head = nullptr;
	this->tail = nullptr;
}

template <class T>
bool Queue<T>::enqueue(T data) {
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
	Node<T> *next = head;

	if (head == tail) tail = nullptr;
	head = head->getNext();
	delete head;

	return data;
}

template <class T>
bool Queue<T>::isEmpty() const {
	return head == nullptr;
}
