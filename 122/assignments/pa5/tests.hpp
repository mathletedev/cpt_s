/*
 * Programming Assignment 5
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-03-08
 * Test cases
 */

#pragma once

#include "data.hpp"
#include "queue.hpp"
#include "simulation.hpp"

class tests {
	public:
		void test_all();
		void test_enqueue_empty();
		void test_enqueue_one();
		void test_dequeue_one();
		void test_dequeue_two();
		void test_simulation_day();
};
