/*
 * Programming Assignment 7
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-04-05
 * Data storage class
 */

#pragma once

#include "stack.hpp"
#include "utils.hpp"
#include <fstream>
#include <string>

class data {
	public:
		int const &get_record() const {
			return record_;
		};
		int const &get_id() const {
			return id_;
		}
		std::string const &get_name() const {
			return name_;
		}
		std::string const &get_email() const {
			return email_;
		}
		int const &get_units() const {
			return units_;
		}
		std::string const &get_major() const {
			return major_;
		}
		std::string const &get_level() const {
			return level_;
		}
		int const &get_num_absences() const {
			return num_absences_;
		}
		// not constant to allow for operations on stack
		stack<std::string> &get_dates_absences() {
			return dates_absences_;
		}

		void set_record(int const &record) {
			record_ = record;
		};
		void set_id(int const &id) {
			id_ = id;
		}
		void set_name(std::string const &name) {
			name_ = name;
		}
		void set_email(std::string const &email) {
			email_ = email;
		}
		void set_units(int const &units) {
			units_ = units;
		}
		void set_major(std::string const &major) {
			major_ = major;
		}
		void set_level(std::string const &level) {
			level_ = level;
		}
		void set_num_absences(int const &num_absences) {
			num_absences_ = num_absences;
		}

		bool read(std::ifstream &lhs, bool const &include_dates);
		void write(std::ofstream &lhs) const;

	private:
		int record_;
		int id_;
		std::string name_;
		std::string email_;
		int units_;
		std::string major_;
		std::string level_;

		// added fields
		int num_absences_;
		stack<std::string> dates_absences_;
};
