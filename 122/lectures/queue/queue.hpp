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
