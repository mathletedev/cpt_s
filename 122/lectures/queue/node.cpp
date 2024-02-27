#include "node.hpp"

template <class T>
Node<T>::Node(T data) {
	this->data = data;
	this->next = nullptr;
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
