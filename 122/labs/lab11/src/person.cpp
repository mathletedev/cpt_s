#include "person.hpp"

person::person(std::string const &name, int const &age, char const &gender,
	       double const &height) {
	name_ = name;
	age_ = age;
	gender_ = gender;
	height_ = height;
}

person::person(person const &other) {
	*this = other;
}

person::~person() {
	// nothing to do
}

person &person::operator=(person const &other) {
	name_ = other.name_;
	age_ = other.age_;
	gender_ = other.gender_;
	height_ = other.height_;

	return *this;
}

std::ostream &operator<<(std::ostream &lhs, person const &rhs) {
	lhs << rhs.name_ << " (" << rhs.gender_ << "): " << rhs.age_ << ", "
	    << rhs.height_ << "cm";

	return lhs;
}

std::istream &operator>>(std::istream &lhs, person &rhs) {
	lhs >> rhs.name_ >> rhs.age_ >> rhs.gender_ >> rhs.height_;

	return lhs;
}
