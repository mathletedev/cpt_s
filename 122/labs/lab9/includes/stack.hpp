#pragma once

#include <iostream>
#include <string>

#define MAX_SIZE 100

template <class T>
class stack {
	public:
		stack(int size = 0);

		~stack();

		int get_size() const;

		bool push(T const &item);
		bool pop(T &item);
		bool peek(T &item) const;

		bool is_empty() const;

		void clear();

	private:
		int size_;
		int max_size_;
		T *p_top_;
};

template <class T>
stack<T>::stack(int size) {
	size_ = size;
	max_size_ = MAX_SIZE;
	p_top_ = new T[MAX_SIZE];
}

template <class T>
stack<T>::~stack() {
	delete[] p_top_;
}

template <class T>
int stack<T>::get_size() const {
	return size_;
}

template <class T>
bool stack<T>::push(T const &item) {
	if (size_ == max_size_) return false;

	p_top_[size_++] = item;
	return true;
}

template <class T>
bool stack<T>::pop(T &item) {
	if (is_empty()) return false;

	peek(item);
	--size_;
	return true;
}

template <class T>
bool stack<T>::peek(T &item) const {
	if (is_empty()) return false;

	item = p_top_[size_ - 1];
	return true;
}

template <class T>
bool stack<T>::is_empty() const {
	return size_ == 0;
}

template <class T>
void stack<T>::clear() {
	size_ = 0;
}
