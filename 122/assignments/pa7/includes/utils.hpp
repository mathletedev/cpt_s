/*
 * Programming Assignment 7
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-04-05
 * Utility functions
 */

#pragma once

#include "config.hpp"
#include <fstream>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <string>

// used in system(CLEAR)
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

namespace utils {
	void suspend();
	bool read_token(std::ifstream &fstream, std::string &string,
			char delim = ',');
	std::string format_token(std::string const &string, char delim = ',');
	void ignore_line(std::ifstream &fstream);
	std::string get_date();
} // namespace utils
