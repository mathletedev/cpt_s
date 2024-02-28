#pragma once

#include <iostream>
#include <string>

template <class T>
class Node {
	public:
		Node(T data);

		~Node();

		T getData() const;

		Node<T> *getNext() const;
		void setNext(Node<T> *const next);

	private:
		T data;
		Node<T> *next;
};

template <class T>
Node<T>::Node(T data) {
	this->data = data;
	this->next = nullptr;
}

template <class T>
Node<T>::~Node() {
	std::cout << "deleting: " << data << std::endl;
	delete next;
}

template <class T>
T Node<T>::getData() const {
	return data;
}

template <class T>
Node<T> *Node<T>::getNext() const {
	return next;
}

template <class T>
void Node<T>::setNext(Node<T> *const next) {
	this->next = next;
}
