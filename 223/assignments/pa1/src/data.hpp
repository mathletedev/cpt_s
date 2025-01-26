#pragma once

#include "linked_list.hpp"
#include <fstream>
#include <string>

/// command data: name, description, value
class CommandData {
	private:
		std::string name_;
		std::string description_;
		int value_;

	public:
		CommandData(std::string const &name,
			    std::string const &description, int value)
		    : name_(name), description_(description), value_(value) {}

		static CommandData from_csv(std::ifstream &file);
		static LinkedList<CommandData>
		from_csv_all(std::ifstream &file);
		void to_csv(std::ofstream &file) const;
		static void to_csv_all(std::ofstream &file,
				       LinkedList<CommandData> const &commands);

		std::string const &name() const {
			return this->name_;
		}
		std::string const &description() const {
			return this->description_;
		}
		int value() const {
			return this->value_;
		}

		friend std::ostream &operator<<(std::ostream &os,
						const CommandData &data) {
			os << data.name_ << ", " << data.description_ << ", "
			   << data.value_;
			return os;
		}
};

/// player data: name, score
class PlayerData {
	private:
		std::string name_;
		int score_;

	public:
		PlayerData(std::string const &name, int score)
		    : name_(name), score_(score) {}

		std::string const &name() const {
			return this->name_;
		}
		int score() const {
			return this->score_;
		}
};
