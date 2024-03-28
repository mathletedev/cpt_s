#pragma once

#pragma once

#include "bstnode.hpp"
#include <iostream>

template <class T>
class bst {
	public:
		bst();

		~bst();

		void insert(T const &data);
		void delete_node(T const &data);
		void inorder_traversal() const;
		void preorder_traversal() const;
		void postorder_traversal() const;

	private:
		bstnode<T> *p_root_;

		void insert(bstnode<T> *curr, T const &data);
		void delete_node_phase1(bstnode<T> *const &curr, T const &data);
		void delete_node_phase2(bstnode<T> *const &curr);
		void inorder_traversal(bstnode<T> const *const &curr) const;
		void preorder_traversal(bstnode<T> const *const &curr) const;
		void postorder_traversal(bstnode<T> const *const &curr) const;
		void destroy(bstnode<T> *const &curr);
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
void bst<T>::insert(T const &data) {
	if (p_root_ == nullptr) {
		p_root_ = new bstnode<T>(data);
		return;
	}

	insert(p_root_, data);
}

template <class T>
void bst<T>::delete_node(T const &data) {
	delete_node_phase1(p_root_, data);
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
void bst<T>::insert(bstnode<T> *curr, T const &data) {
	if (data == curr->get_data()) return;

	if (data < curr->get_data()) {
		if (curr->get_left() == nullptr) {
			curr->set_left(new bstnode<T>(data));
			return;
		}

		insert(curr->get_left(), data);
	} else {
		if (curr->get_right() == nullptr) {
			curr->set_right(new bstnode<T>(data));
			return;
		}

		insert(curr->get_right(), data);
	}
}

template <class T>
void bst<T>::delete_node_phase1(bstnode<T> *const &curr, T const &data) {
	if (data < curr->get_data()) {
		if (curr->get_left() == nullptr) return;

		if (curr->get_left().get_data() != data) {
			delete_node_phase1(curr->get_left(), data);
			return;
		}

		if (curr->get_left()->get_left() == nullptr) {
			curr->set_left(curr->get_left()->get_right());
			return;
		}

		curr->get_left()->set_data(
		    delete_node_phase2(curr->get_left()));
	} else {
		if (curr->get_right() == nullptr) return;

		if (curr->get_right().get_data() != data) {
			delete_node_phase1(curr->get_right(), data);
			return;
		}

		if (curr->get_right()->get_left() == nullptr) {
			curr->set_right(curr->get_right()->get_right());
			return;
		}

		curr->get_right()->set_data(
		    delete_node_phase2(curr->get_right()));
	}
}

template <class T>
void bst<T>::delete_node_phase2(bstnode<T> *const &curr) {
	// TODO
}

template <class T>
void bst<T>::inorder_traversal(bstnode<T> const *const &curr) const {
	if (curr == nullptr) return;

	inorder_traversal(curr->get_left());
	std::cout << curr->get_data() << std::endl;
	inorder_traversal(curr->get_right());
}

template <class T>
void bst<T>::preorder_traversal(bstnode<T> const *const &curr) const {
	if (curr == nullptr) return;

	std::cout << curr->get_data() << std::endl;
	preorder_traversal(curr->get_left());
	preorder_traversal(curr->get_right());
}

template <class T>
void bst<T>::postorder_traversal(bstnode<T> const *const &curr) const {
	if (curr == nullptr) return;

	postorder_traversal(curr->get_left());
	postorder_traversal(curr->get_right());
	std::cout << curr->get_data() << std::endl;
}

template <class T>
void bst<T>::destroy(bstnode<T> *const &curr) {
	if (curr == nullptr) return;

	destroy(curr->get_left());
	destroy(curr->get_right());
	delete curr;
}
