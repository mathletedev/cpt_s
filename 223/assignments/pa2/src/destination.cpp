#include "destination.hpp"

#include <iostream>

void Destination::print_position() const {
	std::cout << position_ << std::endl;
}

void Destination::print_name() const {
	std::cout << name_ << std::endl;
}
