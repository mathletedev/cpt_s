#pragma once

#include <istream>
#include <ostream>
#include <string>

class person {
	public:
		person(std::string const &name, int const &age,
		       char const &gender, double const &height);
		person(person const &other);

		~person();

		person &operator=(person const &other);

		std::string const &get_name() const {
			return name_;
		}
		int const &get_age() const {
			return age_;
		}
		char const &get_gender() const {
			return gender_;
		}
		double const &get_height() const {
			return height_;
		}

		void set_name(std::string const &name) {
			name_ = name;
		}
		void set_age(int const &age) {
			age_ = age;
		}
		void set_gender(char const &gender) {
			gender_ = gender;
		}
		void set_height(double const &height) {
			height_ = height;
		}

		friend std::ostream &operator<<(std::ostream &lhs,
						person const &rhs);
		friend std::istream &operator>>(std::istream &lhs, person &rhs);

	protected:
		std::string name_;
		int age_;
		char gender_;
		double height_;
};
