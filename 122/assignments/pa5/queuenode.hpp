/*
 * Programming Assignment 5
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-03-08
 * Queue node class
 */

#pragma once

#include "data.hpp"

class queue_node {
	public:
		queue_node(const data &data);

		~queue_node();

		data *get_data() const;
		queue_node *get_next() const;

		void set_next(queue_node *const &p_next);

	private:
		data *p_data_;
		queue_node *p_next_;
};
