#pragma once

#include "stack.hpp"
#include <fstream>
#include <map>
#include <string>

class converter {
	public:
		converter();

		std::string convert(std::ifstream &fstream);

	private:
		char c_;
		stack<char> s_;
		std::string r_;
		std::map<char, int> precedence_;

		void append(char &c);
};
