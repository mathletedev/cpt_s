#pragma once

#include "node.hpp"

template <class T>
class bst {
	public:
		void insert(const T &data);

	private:
		node<T> *p_root_;

		void insert(node<T> *curr, const T &data);
};

template <class T>
void bst<T>::insert(const T &data) {
	if (p_root_ == nullptr) {
		p_root_ = new node<T>(data);
		return;
	}

	insert(p_root_, data);
}

template <class T>
void bst<T>::insert(node<T> *curr, const T &data) {
	if (data == curr->get_data()) return;

	if (data < curr->get_data()) {
		if (curr->get_left() == nullptr) {
			curr->set_left(new node<T>(data));
			return;
		}

		insert(curr->get_left(), data);
	} else {
		if (curr->get_right() == nullptr) {
			curr->set_right(new node<T>(data));
			return;
		}

		insert(curr->get_right(), data);
	}
}
