#pragma once

#include "stack.hpp"
#include <iostream>

template <class T>
class test_stack {
	public:
		test_stack();
		~test_stack();
		void test(T &item1, T &item2);

	private:
		stack<T> stack_;
};

template <class T>
test_stack<T>::test_stack() : stack_(0) {}

template <class T>
test_stack<T>::~test_stack() {}

template <class T>
void test_stack<T>::test(T &item1, T &item2) {
	stack_.push(item1);
	stack_.peek(item2);
	std::cout << "peek: " << item2 << std::endl;
}
