#include "plan.hpp"

std::string Plan::toString() const {
	return name + ": " + std::to_string(goal) + " (" + date + ")";
}

void Plan::editGoal() {
	std::cout << "Enter new goal: ";
	std::cin >> goal;

	std::cout << *this << std::endl;
}

std::ifstream &operator>>(std::ifstream &fileStream, Plan &plan) {
	fileStream >> plan.name >> plan.goal >> plan.date;

	return fileStream;
}

std::ostream &operator<<(std::ostream &stream, const Plan &plan) {
	stream << plan.toString();

	return stream;
}

std::ofstream &operator<<(std::ofstream &fileStream, const Plan &plan) {
	fileStream << plan.toString();

	return fileStream;
}
