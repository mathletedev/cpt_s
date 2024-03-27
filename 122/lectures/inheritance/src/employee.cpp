#include "employee.hpp"

employee::employee(const std::string &name, const double &pay_rate,
		   const double &hours) {
	name_ = name;
	pay_rate_ = pay_rate;
	hours_ = hours;
}

employee::~employee() {
	std::cout << "Inside employee destructor!" << std::endl;
}

std::string employee::get_name() const {
	return name_;
}

double employee::get_pay_rate() const {
	return pay_rate_;
}

double employee::get_hours() const {
	return hours_;
}

void employee::set_name(const std::string &name) {
	name_ = name;
}

void employee::set_pay_rate(const double &pay_rate) {
	pay_rate_ = pay_rate;
}

void employee::set_hours(const double &hours) {
	hours_ = hours;
}

double employee::calculate_pay() const {
	return hours_ * pay_rate_;
}
