#pragma once

#include "node.hpp"
#include <iostream>

template <class T>
class bst {
	public:
		bst();

		~bst();

		void insert(const T &data);
		void inorder_traversal() const;
		void preorder_traversal() const;
		void postorder_traversal() const;

	private:
		node<T> *p_root_;

		void insert(node<T> *curr, const T &data);
		void inorder_traversal(const node<T> *const curr) const;
		void preorder_traversal(const node<T> *const curr) const;
		void postorder_traversal(const node<T> *const curr) const;
		void destroy(node<T> *const curr);
};

template <class T>
bst<T>::bst() {
	p_root_ = nullptr;
}

template <class T>
bst<T>::~bst() {
	destroy(p_root_);
}

template <class T>
void bst<T>::insert(const T &data) {
	if (p_root_ == nullptr) {
		p_root_ = new node<T>(data);
		return;
	}

	insert(p_root_, data);
}

template <class T>
void bst<T>::inorder_traversal() const {
	inorder_traversal(p_root_);
}

template <class T>
void bst<T>::preorder_traversal() const {
	preorder_traversal(p_root_);
}

template <class T>
void bst<T>::postorder_traversal() const {
	postorder_traversal(p_root_);
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

template <class T>
void bst<T>::inorder_traversal(const node<T> *const curr) const {
	if (curr == nullptr) return;

	inorder_traversal(curr->get_left());
	std::cout << curr->get_data() << std::endl;
	inorder_traversal(curr->get_right());
}

template <class T>
void bst<T>::preorder_traversal(const node<T> *const curr) const {
	if (curr == nullptr) return;

	std::cout << curr->get_data() << std::endl;
	preorder_traversal(curr->get_left());
	preorder_traversal(curr->get_right());
}

template <class T>
void bst<T>::postorder_traversal(const node<T> *const curr) const {
	if (curr == nullptr) return;

	postorder_traversal(curr->get_left());
	postorder_traversal(curr->get_right());
	std::cout << curr->get_data() << std::endl;
}

template <class T>
void bst<T>::destroy(node<T> *const curr) {
	if (curr == nullptr) return;

	destroy(curr->get_left());
	destroy(curr->get_right());
	delete curr;
}
