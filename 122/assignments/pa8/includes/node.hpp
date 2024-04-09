/*
 * Programming Assignment 8
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-04-12
 * Abstract node class
 */

#pragma once

#include <iostream>
#include <string>

class node {
	public:
		node(std::string const &data);

		virtual ~node();

		std::string const &get_data() const {
			return data_;
		}
		// can't be const because insert needs to assign
		node *&get_left() {
			return p_left_;
		}
		node *&get_right() {
			return p_right_;
		}

		void set_data(std::string const &data) {
			data_ = data;
		}
		void set_left(node *const &p_left) {
			p_left_ = p_left;
		}
		void set_right(node *const &p_right) {
			p_right_ = p_right;
		}

		// pure virtual function
		virtual void print_data() const = 0;

	protected:
		std::string data_;
		node *p_left_;
		node *p_right_;
};
