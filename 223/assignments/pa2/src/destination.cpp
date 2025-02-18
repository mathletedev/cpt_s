#include "destination.hpp"

#include <iostream>

void Destination::print_position() const {
	std::cout << position_;
}

void Destination::print_name() const {
	std::cout << name_;
}
