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
		CommandData(const std::string &name,
			    const std::string &description, int value)
		    : name_(name), description_(description), value_(value) {}

		static CommandData from_csv(std::ifstream &file);
		static LinkedList<CommandData>
		from_csv_all(std::ifstream &file);
		void to_csv(std::ofstream &file) const;
		static void to_csv_all(std::ofstream &file,
				       const LinkedList<CommandData> &commands);

		const std::string &name() const {
			return name_;
		}
		const std::string &description() const {
			return description_;
		}
		int value() const {
			return value_;
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
		PlayerData(const std::string &name, int score)
		    : name_(name), score_(score) {}

		static PlayerData from_csv(std::ifstream &file);
		static PlayerData *from_csv_all(std::ifstream &file);
		void to_csv(std::ofstream &file) const;
		static void to_csv_all(std::ofstream &file,
				       const PlayerData *const players, int n);

		const std::string &name() const {
			return name_;
		}
		int score() const {
			return score_;
		}
};
