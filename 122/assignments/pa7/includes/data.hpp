#pragma once

#include "stack.hpp"
#include "utils.hpp"
#include <fstream>
#include <string>

class data {
	public:
		int record_;
		int id_;
		std::string name_;
		std::string email_;
		int units_;
		std::string major_;
		std::string level_;

		// added fields
		int num_absences_;
		stack<std::string> dates_absences_;

		friend std::ifstream &operator>>(std::ifstream &lhs, data &rhs);
};
