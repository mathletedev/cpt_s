#pragma once

#include "linked_list.hpp"
#include <iostream>
#include <string>

#define NEWLINE std::cout << std::endl

namespace utils {
	LinkedList<std::string> split(std::string, std::string);
	LinkedList<std::string> parse_csv(const std::string &);
} // namespace utils
