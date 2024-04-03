/*
 * Programming Assignment 7
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-04-05
 * Menu wrapper class
 */

#pragma once

#include "data.hpp"
#include "list.hpp"
#include "utils.hpp"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

// menu wrapper class
class menu {
	public:
		menu();

		void import();
		void load();
		void store();
		void mark();
		void edit();
		void generate();

	private:
		list<data> students_;
};
