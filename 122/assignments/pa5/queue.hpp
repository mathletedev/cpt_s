/*
 * Programming Assignment 5
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-03-08
 * Queue data structure
 */

#pragma once

#include "queuenode.hpp"
#include <iostream>

class queue {
	public:
		queue();

		~queue();

		bool is_empty() const;

		bool enqueue(const data &data);
		data dequeue();
		data *peek() const;

		void print();

	private:
		queue_node *p_head_;
		queue_node *p_tail_;
};
