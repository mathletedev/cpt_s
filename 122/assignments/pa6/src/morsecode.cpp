#include "morsecode.hpp"

morse_code::morse_code() {
	data_ = "";
	// weight is a number calculated based on the dots and dashes
	// allows us to make comparisons
	weight_ = 0;
}

morse_code::morse_code(std::string const &data) {
	data_ = data;
	update_weight();
}

bool operator<(morse_code const &lhs, morse_code const &rhs) {
	return lhs.weight_ < rhs.weight_;
}

bool operator>(morse_code const &lhs, morse_code const &rhs) {
	return lhs.weight_ > rhs.weight_;
}

bool operator==(morse_code const &lhs, morse_code const &rhs) {
	return lhs.weight_ == rhs.weight_;
}

std::istream &operator>>(std::istream &lhs, morse_code &rhs) {
	lhs >> rhs.data_;
	rhs.update_weight();

	return lhs;
}

std::ostream &operator<<(std::ostream &lhs, morse_code const &rhs) {
	lhs << rhs.data_;

	return lhs;
}

void morse_code::update_weight() {
	weight_ = 0;
	// loop through indices of string
	for (int i = 0; i < std::min((int)data_.length(), 6); ++i) {
		// weight earlier characters more by bitshifting a 1
		int curr_weight = 1 << (MORSE_LENGTH - i - 1);
		// make dots come before dashes
		if (data_[i] == '.') curr_weight *= -1;

		weight_ += curr_weight;
	}
}
