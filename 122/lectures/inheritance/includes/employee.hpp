#pragma once

#include <iostream>
#include <string>

class employee {
	public:
		employee(const std::string &name = "",
			 const double &pay_rate = 0, const double &hours = 0);

		virtual ~employee();

		std::string get_name() const;
		double get_pay_rate() const;
		double get_hours() const;

		void set_name(const std::string &name);
		void set_pay_rate(const double &pay_rate);
		void set_hours(const double &hours);

		// allows derived classes to override this function
		virtual double calculate_pay() const;

	protected:
		std::string name_;
		double pay_rate_;
		double hours_;
};
