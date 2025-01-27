#include "data.hpp"

CommandData CommandData::from_csv(std::ifstream &file) {
	std::string name, description, value_s;
	int value;

	std::getline(file, name, ',');
	std::getline(file, description, ',');
	std::getline(file, value_s, '\n');

	// trim off quotes
	description = description.substr(1, description.size() - 2);
	value = std::stoi(value_s);

	return CommandData(name, description, value);
}

LinkedList<CommandData> CommandData::from_csv_all(std::ifstream &file) {
	LinkedList<CommandData> res;

	while (true) {
		try {
			res.push_back(CommandData::from_csv(file));
		} catch (...) {
			break;
		}
	}

	return res;
}

void CommandData::to_csv(std::ofstream &file) const {
	file << name_ << ",\"" << description_ << "\"," << value_ << "\n";
}

void CommandData::to_csv_all(std::ofstream &file,
			     const LinkedList<CommandData> &commands) {
	commands.for_each(
	    [&file](const CommandData &command) { command.to_csv(file); });
}
