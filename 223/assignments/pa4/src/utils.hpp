#pragma once

#include "linked_list.hpp"
#include <iostream>

#define NEWLINE std::cout << std::endl

namespace utils {
	LinkedList<std::string> parse_csv(const std::string &);
}
