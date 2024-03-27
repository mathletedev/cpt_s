#include "manager.hpp"

manager::~manager() {
	std::cout << "Inside manager destructor!" << std::endl;
}

double manager::calculate_pay() const {
	double pay = get_pay_rate();
	if (is_salaried_) pay = employee::calculate_pay();

	return pay;
}
