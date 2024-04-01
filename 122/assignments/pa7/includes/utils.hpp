#pragma once

#include <fstream>
#include <iostream>
#include <limits>
#include <string>

namespace utils {
	void suspend();
	bool read_token(std::ifstream &fstream, std::string &string,
			char delim = ',');
	void ignore_line(std::ifstream &fstream);
	std::string get_date();
} // namespace utils
