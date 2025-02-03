#pragma once

#include <iostream>
#include <limits>

#define NEWLINE std::cout << std::endl
#define CLEAR system("clear")
#define IGNORE                                                                 \
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')
#define PAUSE                                                                  \
	IGNORE;                                                                \
	std::cout << "Press Enter to continue...";                             \
	IGNORE
#define PAUSE_NOIGNORE                                                         \
	std::cout << "Press Enter to continue...";                             \
	IGNORE
