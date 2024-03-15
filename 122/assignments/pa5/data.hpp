/*
 * Programming Assignment 5
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-03-08
 * Data class to store customer data
 */

#pragma once

#include <iostream>

class data {
	public:
		data(const int &customer_number, const int service_time,
		     const int total_time);
		data(const data &other);

		~data();

		int get_customer_number() const;
		int get_service_time() const;
		int get_total_time() const;

		data &operator=(const data &rhs);

		friend bool operator==(const data &lhs, const data &rhs);

	private:
		int customer_number_;
		int service_time_;
		int total_time_;
};
