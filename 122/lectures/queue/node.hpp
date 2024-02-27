#pragma once

#include <iostream>
#include <string>

template <class T>
class Node {
	public:
		Node(T data);

		T getData() const;

		Node<T> *getNext() const;
		void setNext(Node<T> *const next);

	private:
		T data;
		Node<T> *next;
};
