/*
 * Programming Assignment 5
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-03-08
 * Grocery store simulation with queues
 */

#pragma once

#include "queue.hpp"
#include <string>

#define ONE_DAY 1440

class simulation {
	public:
		simulation(int n);

		void run();

	private:
		int n_;
		int t_;
		// lanes
		queue express_;
		queue normal_;
		// time until next customer
		int next_express_;
		int next_normal_;
		// running total time
		int time_express_;
		int time_normal_;
		// current service time
		int curr_express_;
		int curr_normal_;
		// current customer number
		int customer_number_;

		void update();

		int random(int low, int high) const;
		std::string curr_time() const;
};
