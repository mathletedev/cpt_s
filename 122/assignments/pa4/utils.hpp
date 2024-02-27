/*
 * Programming Assignment 4
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-02-28
 * Various utility functions and definitions
 */

#pragma once

#include <iostream>
#include <limits>

// clear screen
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define NEWLINE std::cout << std::endl

namespace utils {
	void flush();
	void suspend();
} // namespace utils
