#pragma once

#include <vector>

template <class T>
class stack {
	public:
		void push(T const &data);
		void pop();
		T peek() const;
		bool is_empty() const;

	private:
		std::vector<T> data_;
};

template <class T>
void stack<T>::push(T const &data) {
	data_.push_back(data);
}

template <class T>
void stack<T>::pop() {
	if (!is_empty()) data_.pop_back();
}

template <class T>
T stack<T>::peek() const {
	if (!is_empty()) return data_[data_.size() - 1];
}

template <class T>
bool stack<T>::is_empty() const {
	return data_.size() == 0;
}
