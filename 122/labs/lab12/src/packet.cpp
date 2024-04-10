#include "packet.hpp"

packet::packet(int const &length, std::string const &data) {
	length_ = length;
	data_ = data;
}

packet &packet::operator=(packet const &rhs) {
	length_ = rhs.length_;
	data_ = rhs.data_;

	return *this;
}

int const &packet::get_length() const {
	return length_;
}

std::string const &packet::get_data() const {
	return data_;
}
