/*
 * Programming Assignment 6
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-03-22
 * Binary search tree node
 */

#pragma once

// https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/
template <class T, class U>
class bst_node {
	public:
		bst_node(T const &key, U const &value);

		T get_key() const;
		U get_value() const;
		bst_node<T, U> *get_left() const;
		bst_node<T, U> *get_right() const;

		void set_left(bst_node<T, U> *const &p_node);
		void set_right(bst_node<T, U> *const &p_node);

	private:
		T key_;
		U value_;
		bst_node<T, U> *p_left_;
		bst_node<T, U> *p_right_;
};

template <class T, class U>
bst_node<T, U>::bst_node(T const &key, U const &value) {
	key_ = key;
	value_ = value;
	p_left_ = p_right_ = nullptr;
}

template <class T, class U>
T bst_node<T, U>::get_key() const {
	return key_;
}

template <class T, class U>
U bst_node<T, U>::get_value() const {
	return value_;
}

template <class T, class U>
bst_node<T, U> *bst_node<T, U>::get_left() const {
	return p_left_;
}

template <class T, class U>
bst_node<T, U> *bst_node<T, U>::get_right() const {
	return p_right_;
}

template <class T, class U>
void bst_node<T, U>::set_left(bst_node<T, U> *const &p_node) {
	p_left_ = p_node;
}

template <class T, class U>
void bst_node<T, U>::set_right(bst_node<T, U> *const &p_node) {
	p_right_ = p_node;
}
