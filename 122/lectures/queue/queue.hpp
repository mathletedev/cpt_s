#pragma once

#include "node.hpp"
#include <iostream>
#include <string>

template <class T>
class Queue {
	public:
		Queue();

		bool enqueue(const T &data);
		T dequeue();

		bool isEmpty() const;

		~Queue();

	private:
		Node<T> *head;
		Node<T> *tail;

		void destroyQueue();
};

template <class T>
Queue<T>::Queue() {
	this->head = nullptr;
	this->tail = nullptr;
}

template <class T>
bool Queue<T>::enqueue(const T &data) {
	Node<T> *node = new Node<T>(data);
	if (node == nullptr) return false;

	if (isEmpty()) {
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
	Node<T> *next = head->getNext();

	delete head;
	head = next;
	if (isEmpty()) tail = nullptr;

	return data;
}

template <class T>
bool Queue<T>::isEmpty() const {
	return head == nullptr;
}

template <class T>
Queue<T>::~Queue() {
	destroyQueue();
}

template <class T>
void Queue<T>::destroyQueue() {
	delete head;
}
