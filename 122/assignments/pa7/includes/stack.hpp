/*
 * Programming Assignment 7
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-04-05
 * Stack class (using vectors)
 */

#pragma once

#include <fstream>
#include <vector>

template <class T>
class stack {
	public:
		void push(T const &data);
		T pop();
		T peek() const;
		bool is_empty() const;

		void read(std::ifstream &fstream, int const &size);
		void write(std::ofstream &fstream, char delim = ' ') const;

	private:
		std::vector<T> data_;
};

template <class T>
void stack<T>::push(T const &data) {
	data_.push_back(data);
}

// pre-condition: stack is not empty
template <class T>
T stack<T>::pop() {
	T tmp = peek();
	data_.pop_back();

	return tmp;
}

// pre-condition: stack is not empty
template <class T>
T stack<T>::peek() const {
	return data_[data_.size() - 1];
}

template <class T>
bool stack<T>::is_empty() const {
	return data_.size() == 0;
}

// reads a stack from a filestream
template <class T>
void stack<T>::read(std::ifstream &fstream, int const &size) {
	data_.resize(size);
	for (auto &data : data_)
		fstream >> data;
}

// writes a stack to a filestream (separated by delimiter)
template <class T>
void stack<T>::write(std::ofstream &fstream, char delim) const {
	if (data_.size() == 0) return;

	fstream << data_[0];
	for (int i = 1; i < data_.size(); ++i)
		fstream << delim << data_[i];
}
