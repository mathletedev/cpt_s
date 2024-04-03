#pragma once

#include "course.hpp"
#include "person.hpp"
#include <vector>

class student : public person {
	public:
		student(std::string const &name, int const &age,
			char const &gender, double const &height)
		    : person(name, age, gender, height){};

	private:
		std::vector<course> courses_;
		int num_courses_;
		int total_credits_;
};
