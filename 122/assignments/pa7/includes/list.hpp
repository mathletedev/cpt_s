/*
 * Programming Assignment 7
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-04-05
 * Linked list class
 */

#pragma once

#include "node.hpp"
#include <fstream>

template <class T>
class list {
	public:
		list();

		~list();

		bool push_front(T const &data);
		T pop_front();
		void clear();
		bool is_empty() const;

		void write(std::ofstream &fstream) const;

	private:
		node<T> *p_head_;

		void clear(node<T> *const &p_curr);
};

template <class T>
list<T>::list() {
	p_head_ = nullptr;
}

template <class T>
list<T>::~list() {
	clear();
}

template <class T>
bool list<T>::push_front(T const &data) {
	node<T> *p_node = new node<T>(data);
	if (p_node == nullptr) return false;

	p_node->set_next(p_head_);
	p_head_ = p_node;

	return true;
}

// pre-condition: list is not empty
template <class T>
T list<T>::pop_front() {
	T tmp = p_head_->get_data();

	// essentially turns this linked list into a stack
	node<T> *p_tmp = p_head_;
	p_head_ = p_head_->get_next();
	delete p_tmp;

	return tmp;
}

template <class T>
void list<T>::clear() {
	clear(p_head_);
	p_head_ = nullptr;
}

template <class T>
bool list<T>::is_empty() const {
	return p_head_ == nullptr;
}

// recursively delete linked list nodes
template <class T>
void list<T>::clear(node<T> *const &p_curr) {
	if (p_curr == nullptr) return;

	clear(p_curr->get_next());
	delete p_curr;
}
