#include "plan.hpp"

Plan::Plan(int goal, std::string name, std::string date) {
	this->goal = goal;
	this->name = name;
	this->date = date;
}

Plan::Plan(const Plan &other) {
	// reuse copy assignment
	*this = other;
}

Plan::~Plan() {
	// nothing to do
}

Plan &Plan::operator=(const Plan &other) {
	goal = other.goal;
	name = other.name;
	date = other.date;

	return *this;
}

std::string Plan::toString() const {
	return name + ": " + std::to_string(goal) + " (" + date + ")";
}

void Plan::editGoal() {
	std::cout << "Edit goal (" << goal << "): ";
	std::cin >> goal;

	std::cout << *this << std::endl;
}

std::fstream &operator>>(std::fstream &fileStream, Plan &plan) {
	// read over spaces
	std::getline(fileStream, plan.name);
	fileStream >> plan.goal >> plan.date;

	// consume empty line
	std::string s;
	std::getline(fileStream, s);
	std::getline(fileStream, s);

	return fileStream;
}

std::ostream &operator<<(std::ostream &stream, const Plan &plan) {
	stream << plan.toString();

	return stream;
}

std::fstream &operator<<(std::fstream &fileStream, const Plan &plan) {
	fileStream << plan.name << std::endl;
	fileStream << std::to_string(plan.goal) << std::endl;
	fileStream << plan.date << std::endl;

	return fileStream;
}

// polymorphism - override Plan::toString implementation to include units
std::string DietPlan::toString() const {
	return name + ": " + std::to_string(goal) + " calories (" + date + ")";
}

std::string ExercisePlan::toString() const {
	return name + ": " + std::to_string(goal) + " steps (" + date + ")";
}

std::ostream &operator<<(std::ostream &stream, const DietPlan &plan) {
	stream << plan.toString();

	return stream;
}

std::ostream &operator<<(std::ostream &stream, const ExercisePlan &plan) {
	stream << plan.toString();

	return stream;
}
