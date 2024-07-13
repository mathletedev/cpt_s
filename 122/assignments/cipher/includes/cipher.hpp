#pragma once

#include <string>

class cipher {
	public:
		virtual std::string encode(std::string const &plain_text) = 0;
		virtual std::string decode(std::string const &encoded_text) = 0;

	private:
};
