#include "evaluator.hpp"

evaluator::evaluator() {
	c_ = '\0';
	s_ = stack<int>();
}

int evaluator::evaluate(std::ifstream &fstream) {
	c_ = '\0';
	s_ = stack<int>();

	while (true) {
		if (!(fstream >> c_)) throw;

		if (c_ == '=') {
			if (s_.get_size() != 1) throw;

			int e;
			s_.peek(e);
			return e;
		}

		if (c_ >= '0' && c_ <= '9') {
			s_.push(c_ - '0');
			continue;
		}

		if (s_.get_size() < 2) throw;

		int s1, s2;
		s_.pop(s2);
		s_.pop(s1);
		// std::cout << s_.get_size() << std::endl;

		int v;
		switch (c_) {
		case '+':
			v = s1 + s2;
			break;
		case '-':
			v = s1 - s2;
			break;
		case '*':
			v = s1 * s2;
			break;
		case '/':
			v = s1 / s2;
			break;
		}

		s_.push(v);
	}
}
