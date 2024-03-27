#pragma once

#include "employee.hpp"
#include <iostream>
#include <string>

class manager : public employee {
	public:
		manager(const std::string &name = "",
			const double &pay_rate = 0, const double &hours = 0,
			const bool &is_salaried = false)
		    : employee(name, pay_rate, hours) {
			is_salaried_ = is_salaried;
		}

		~manager();

		double calculate_pay() const;

	private:
		bool is_salaried_;
};
