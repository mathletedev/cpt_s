/*
 * Programming Assignment 6
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-03-22
 * Binary search tree data structure with template types for key and value
 */

#pragma once

#include "bstnode.hpp"
#include <fstream>
#include <iostream>

template <class T, class U>
class bst {
	public:
		bst(std::ifstream &fstream);

		~bst();

		U search(T const &key) const;
		void print() const;

		void process(std::ifstream &fstream) const;
		void process_char(std::ifstream &fstream) const;

	private:
		bst_node<T, U> *p_root_;

		void destroy(bst_node<T, U> *const &p_curr);
		void insert(T const &key, U const &value);
		void insert(bst_node<T, U> *const &p_curr, T const &key,
			    U const &value);
		U search(bst_node<T, U> const *const &p_curr,
			 T const &key) const;
		void print(bst_node<T, U> const *const &p_curr) const;
};

template <class T, class U>
bst<T, U>::bst(std::ifstream &fstream) {
	p_root_ = nullptr;

	T key;
	U value;
	// while still reading, insert into tree
	while (fstream >> key >> value)
		insert(key, value);
}

template <class T, class U>
bst<T, U>::~bst() {
	destroy(p_root_);
}

// helper function for destroyer
template <class T, class U>
void bst<T, U>::destroy(bst_node<T, U> *const &p_curr) {
	if (p_curr == nullptr) return;

	destroy(p_curr->get_left());
	destroy(p_curr->get_right());
	delete p_curr;
}

template <class T, class U>
U bst<T, U>::search(T const &key) const {
	return search(p_root_, key);
}

template <class T, class U>
void bst<T, U>::print() const {
	print(p_root_);
}

// reads all type T key tokens from file and prints the corresponding values
template <class T, class U>
void bst<T, U>::process(std::ifstream &fstream) const {
	T key;
	while (fstream >> key)
		std::cout << search(key) << " ";
	std::cout << std::endl;
}

// same as process(), but this one converts characters to uppercase before
// processing
template <class T, class U>
void bst<T, U>::process_char(std::ifstream &fstream) const {
	char key;
	while (fstream >> key) {
		if (key >= 'a' && key <= 'z') key += 'A' - 'a';
		std::cout << search(key) << " ";
	}
	std::cout << std::endl;
}

template <class T, class U>
void bst<T, U>::insert(T const &key, U const &value) {
	if (p_root_ == nullptr) {
		p_root_ = new bst_node<T, U>(key, value);
		return;
	}

	insert(p_root_, key, value);
}

template <class T, class U>
void bst<T, U>::insert(bst_node<T, U> *const &p_curr, T const &key,
		       U const &value) {
	// ignore duplicates
	if (key == p_curr->get_key()) return;

	if (key < p_curr->get_key()) {
		if (p_curr->get_left() == nullptr) {
			p_curr->set_left(new bst_node<T, U>(key, value));
			return;
		}

		insert(p_curr->get_left(), key, value);
	} else {
		if (p_curr->get_right() == nullptr) {
			p_curr->set_right(new bst_node<T, U>(key, value));
			return;
		}

		insert(p_curr->get_right(), key, value);
	}
}

template <class T, class U>
U bst<T, U>::search(bst_node<T, U> const *const &p_curr, T const &key) const {
	// failed to find key, return default value
	if (p_curr == nullptr) return U();
	// found key
	if (key == p_curr->get_key()) return p_curr->get_value();

	return search(key < p_curr->get_key() ? p_curr->get_left()
					      : p_curr->get_right(),
		      key);
}

// prints the tree with in-order traversal
template <class T, class U>
void bst<T, U>::print(bst_node<T, U> const *const &p_curr) const {
	if (p_curr == nullptr) return;

	print(p_curr->get_left());
	std::cout << p_curr->get_key() << " " << p_curr->get_value()
		  << std::endl;
	print(p_curr->get_right());
}
