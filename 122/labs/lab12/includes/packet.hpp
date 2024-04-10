#pragma once

#include <string>

class packet {
	public:
		packet(int const &length = 0, std::string const &data = "");

		packet &operator=(packet const &rhs);

		int const &get_length() const;
		std::string const &get_data() const;

	private:
		int length_;
		std::string data_;
};
