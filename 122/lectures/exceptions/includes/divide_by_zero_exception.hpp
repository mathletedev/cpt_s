#pragma once

#include <stdexcept>

class divide_by_zero_exception : public std::runtime_error {
	public:
		divide_by_zero_exception()
		    : std::runtime_error("Divide by zero!") {}
};
