#pragma once

#include "listnode.hpp"
#include <iostream>

template <class T>
class list {
	public:
		list();

		~list();

		void insert_at_front(T const &data);
		void insert_at_back(T const &data);
		bool remove_from_front(T &data);
		bool remove_from_back(T &data);
		bool is_empty() const;
		void print() const;

	private:
		list_node<T> *p_first_;
		list_node<T> *p_last_;

		void destroy(list_node<T> *const &p_curr);

		list_node<T> *get_new_node(T const &data);
};

template <class T>
list<T>::list() {
	p_first_ = p_last_ = nullptr;
}

template <class T>
list<T>::~list() {
	destroy(p_first_);
}

template <class T>
void list<T>::insert_at_front(T const &data) {
	auto p_node = get_new_node(data);

	if (is_empty()) {
		p_first_ = p_last_ = p_node;
		return;
	}

	p_node->p_next_ = p_first_;
	p_first_ = p_node;
}

template <class T>
void list<T>::insert_at_back(T const &data) {
	auto p_node = get_new_node(data);

	if (is_empty()) {
		p_first_ = p_last_ = p_node;
		return;
	}

	p_last_->p_next_ = p_node;
	p_last_ = p_node;
}

template <class T>
bool list<T>::remove_from_front(T &data) {
	if (is_empty()) return false;

	data = p_first_->data_;

	auto p_tmp = p_first_->p_next_;
	delete p_first_;
	p_first_ = p_tmp;
	if (p_first_ == nullptr) p_last_ = nullptr;

	return true;
}

template <class T>
bool list<T>::remove_from_back(T &data) {
	if (is_empty()) return false;

	data = p_last_->data_;

	if (p_first_ == p_last_) {
		delete p_first_;
		p_first_ = p_last_ = nullptr;
		return true;
	}

	auto p_curr = p_first_;
	for (; p_curr->p_next_ != p_last_; p_curr = p_curr->p_next_)
		;

	delete p_last_;
	p_last_ = p_curr;

	return true;
}

template <class T>
bool list<T>::is_empty() const {
	return p_first_ == nullptr;
}

template <class T>
void list<T>::print() const {
	for (auto p_curr = p_first_; p_curr != nullptr;
	     p_curr = p_curr->p_next_)
		std::cout << p_curr->data_ << " ";
}

template <class T>
void list<T>::destroy(list_node<T> *const &p_curr) {
	if (p_curr == nullptr) return;

	destroy(p_curr->p_next_);
	delete p_curr;
}

template <class T>
list_node<T> *list<T>::get_new_node(T const &data) {
	return new list_node<T>(data);
}
