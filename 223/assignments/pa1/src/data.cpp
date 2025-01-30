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

PlayerData PlayerData::from_csv(std::ifstream &file) {
	std::string active_s, name, score_s;
	bool active;
	int score;

	std::getline(file, active_s, ',');
	std::getline(file, name, ',');
	std::getline(file, score_s, '\n');

	active = active_s == "1";
	name = name.substr(1, name.size() - 2);
	score = std::stoi(score_s);

	return PlayerData(active, name, score);
}

std::unique_ptr<PlayerData[]> PlayerData::from_csv_all(std::ifstream &file,
						       int n) {
	std::unique_ptr<PlayerData[]> res =
	    std::unique_ptr<PlayerData[]>(new PlayerData[n]);

	try {
		for (int i = 0; i < n; ++i) {
			res[i] = PlayerData::from_csv(file);
		}
	} catch (...) {
		throw "error reading player data";
	}

	return res;
}

std::unique_ptr<PlayerData[]> PlayerData::init_csv(std::ofstream &file, int n) {
	std::unique_ptr<PlayerData[]> res =
	    std::unique_ptr<PlayerData[]>(new PlayerData[n]);

	for (int i = 0; i < n; ++i) {
		file << "0,\"\",0\n";
	}

	return res;
}

void PlayerData::to_csv(std::ofstream &file) const {
	throw;
}

void PlayerData::to_csv_all(std::ofstream &file,
			    const PlayerData *const players, int n) {
	throw;
}
