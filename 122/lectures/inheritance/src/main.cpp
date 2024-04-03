#include "employee.hpp"
#include "manager.hpp"
#include <vector>

void print_pay(employee &e);

int main() {
	employee e1;
	manager m1("Chuck", 5000, 5, true);

	employee *p_e2 = new employee("Jeffery", 20.00, 80);
	// manager uses hourly pay calculation (without virtual)
	employee *p_m2 = new manager("Chuck", 5000, 5, true);

	// std::cout << "employee p_e2 pay: " << p_e2->calculate_pay()
	// 	  << std::endl;
	// std::cout << "manager p_m2 pay: " << p_m2->calculate_pay() <<
	// std::endl; std::cout << "manager m1 pay: " << m1.calculate_pay() <<
	// std::endl;

	print_pay(*p_e2);
	print_pay(*p_m2);

	delete p_e2;
	delete p_m2;

	std::cout << "--------" << std::endl;

	std::cout << "Enter number of employees: ";
	int num;
	std::cin >> num;

	std::vector<employee *> employees(num);

	for (int i = 0; i < num; ++i) {
		std::cout << "Enter employee type - 1. Basic, 2. Manager: ";
		int type;
		std::cin >> type;

		if (type == 1) employees[i] = new employee;
		if (type == 2) employees[i] = new manager;
	}

	for (int i = 0; i < num; ++i)
		delete employees[i];

	std::cout << "--------" << std::endl;

	return 0;
}

void print_pay(employee &e) {
	std::cout << e.get_name() << "'s pay: " << e.calculate_pay()
		  << std::endl;
}
