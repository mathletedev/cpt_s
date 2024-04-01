#pragma once

#include "data.hpp"
#include "list.hpp"
#include "utils.hpp"
#include <fstream>
#include <iostream>
#include <string>

// menu wrapper class
class app {
	public:
		app();

		void import();
		void load();
		void store();
		void mark();
		void edit();
		void generate();

	private:
		list<data> students_;
};
