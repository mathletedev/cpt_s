#pragma once

#include "linked_list.hpp"
#include <iostream>
#include <string>

#define NEWLINE std::cout << std::endl

namespace utils {
	// splits string by delimiter into linked list
	LinkedList<std::string> split(std::string, std::string);
	// splits string by command-line arg rules into linked list
	LinkedList<std::string> parse_args(const std::string &);
	// splits string by csv rules into linked list
	LinkedList<std::string> parse_csv(const std::string &);
} // namespace utils
