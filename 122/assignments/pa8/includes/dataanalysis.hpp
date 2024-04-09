/*
 * Programming Assignment 8
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-04-12
 * Data analysis wrapper class
 */

#pragma once

#include "bst.hpp"
#include <fstream>
#include <iostream>

enum transaction_type { purchased, sold };

struct data_point {
		int units;
		std::string type;
		enum transaction_type transaction_type;
};

class data_analysis {
	public:
		~data_analysis();

		void run_analysis();

	private:
		bst tree_sold_;
		bst tree_purchased_;
		std::ifstream csv_stream_;

		void open(std::string const &path);
		bool parse_line(data_point &data_point);
		void process();
		void insert(data_point const &data_point);
		void write_trends() const;
};
