/*
 * Programming Assignment 8
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-04-12
 * Binary search tree class
 */

#pragma once

#include "node.hpp"
#include "transactionnode.hpp"

class bst {
	public:
		bst();

		~bst();

		void insert(std::string const &data, int const &units);

		void in_order_traversal() const;

		transaction_node &find_smallest() const;
		transaction_node &find_largest() const;

	private:
		node *p_root_;

		void destroy_tree(node *const &p_curr);

		void insert(node *&p_curr, std::string const &data,
			    int const &units);

		void in_order_traversal(node *const &p_curr) const;
};
