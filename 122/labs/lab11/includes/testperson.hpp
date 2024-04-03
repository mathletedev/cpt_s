#pragma once

#include "person.hpp"

#include <iostream>

class test_person : public person {
	public:
		test_person(std::string const &name, int const &age,
			    char const &gender, double const &height)
		    : person(name, age, gender, height){};

		void test_set_name();
};
