#include "converter.hpp"

converter::converter() {
	c_ = '\0';
	s_ = stack<char>();
	r_ = "";

	precedence_['+'] = 1;
	precedence_['-'] = 1;
	precedence_['*'] = 2;
	precedence_['/'] = 2;
	precedence_['^'] = 3;
}

std::string converter::convert(std::ifstream &fstream) {
	c_ = '\0';
	s_.clear();
	r_ = "";

	while (fstream >> c_) {
		if (c_ >= '0' && c_ <= '9') {
			append(c_);
			continue;
		}

		char s;
		while (s_.peek(s) && precedence_[s] >= precedence_[c_]) {
			append(s);
			s_.pop(s);
		}

		s_.push(c_);
	}

	char s;
	while (s_.pop(s))
		append(s);

	return r_;
}

void converter::append(char &c) {
	if (r_ != "") r_ += " ";
	r_ += c;
}
