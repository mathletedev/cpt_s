/*
 * Programming Assignment 8
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-04-12
 * Transaction node class
 */

#pragma once

#include "node.hpp"

class transaction_node : public node {
	public:
		transaction_node(std::string const &data, int const &units);

		~transaction_node();

		int const &get_units() const {
			return units_;
		}

		void set_units(int const &units) {
			units_ = units;
		}

		void print_data() const;

	private:
		int units_;
};
