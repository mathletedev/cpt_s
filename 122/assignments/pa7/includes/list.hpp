#pragma once

#include "node.hpp"

template <class T>
class list {
	public:
		list();

		~list();

		bool insert(T const &data);
		void clear();

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
bool list<T>::insert(T const &data) {
	node<T> *p_node = new node<T>(data);
	if (p_node == nullptr) return false;

	p_node->set_next(p_head_);
	p_head_ = p_node;

	return true;
}

template <class T>
void list<T>::clear() {
	clear(p_head_);
	p_head_ = nullptr;
}

template <class T>
void list<T>::clear(node<T> *const &p_curr) {
	if (p_curr == nullptr) return;

	clear(p_curr->get_next());
	delete p_curr;
}
