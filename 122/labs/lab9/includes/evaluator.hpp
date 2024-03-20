#pragma once

#include "stack.hpp"
#include <fstream>
#include <string>

class evaluator {
	public:
		evaluator();

		int evaluate(std::ifstream &fstream);

	private:
		char c_;
		stack<int> s_;
};
