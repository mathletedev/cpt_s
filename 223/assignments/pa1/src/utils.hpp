#pragma once

#include <iostream>

#define NEWLINE std::cout << std::endl
#define CLEAR system("clear")
#define PAUSE                                                                  \
	std::cin.ignore();                                                     \
	std::cout << "Press Enter to continue...";                             \
	getchar()
#define PAUSE_NOIGNORE                                                         \
	std::cout << "Press Enter to continue...";                             \
	getchar()
