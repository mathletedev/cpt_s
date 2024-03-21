/*
 * Programming Assignment 6
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-03-22
 * Morse code class - overloads comparisons
 */

#pragma once

#include <iostream>
#include <string>
#define MORSE_LENGTH 6

class morse_code {
	public:
		morse_code();
		morse_code(std::string const &data);

		friend bool operator<(morse_code const &lhs,
				      morse_code const &rhs);
		friend bool operator>(morse_code const &lhs,
				      morse_code const &rhs);
		friend bool operator==(morse_code const &lhs,
				       morse_code const &rhs);
		friend std::istream &operator>>(std::istream &lhs,
						morse_code &rhs);
		friend std::ostream &operator<<(std::ostream &lhs,
						morse_code const &rhs);

	private:
		std::string data_;
		// weight for binary ordering
		int weight_;

		void update_weight();
};
