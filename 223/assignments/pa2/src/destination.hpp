#pragma once

#include <string>

class Destination {
	private:
		int position_;
		std::string name_;

	public:
		Destination(int position, std::string name)
		    : position_(position), name_(name) {}
		// NOTE: destructor not needed

		void print_position() const;
		void print_name() const;
};
