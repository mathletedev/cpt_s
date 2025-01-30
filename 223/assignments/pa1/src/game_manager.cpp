#include "game_manager.hpp"

#include "utils.hpp"
#include <iostream>

int GameManager::prompt_(const LinkedList<std::string> &choices) {
	int i = 0;
	choices
	    .map<std::string>([&i](const std::string &choice) {
		    return std::to_string(++i) + ". " + choice;
	    })
	    .display();
	NEWLINE;
	std::cout << "λ ";

	int choice;
	std::cin >> choice;

	return choice;
}

int GameManager::main_menu_() {
	std::cout << "Main menu:" << std::endl;
	NEWLINE;

	LinkedList<std::string> choices = {
	    "Game Rules",   "Play New Game",  "Load Previous Game",
	    "Add Command",  "Remove Command", "Display All Commands",
	    "Save and Exit"};
	return prompt_(choices);
}

void GameManager::game_rules_() {
	std::cout << "Game rules:" << std::endl;
	NEWLINE;

	std::cout << "- Match Linux commands with their descriptions"
		  << std::endl;
	std::cout
	    << "- Win or lose points based on correct or incorrect matches"
	    << std::endl;
	std::cout << "- Commands may have different point values" << std::endl;
	std::cout
	    << "- Use utility functions to edit player profiles and commands"
	    << std::endl;
	std::cout << "- Have fun!" << std::endl;

	NEWLINE;
	PAUSE;
}

void GameManager::play_() {
	if (p_player_ != nullptr) {
		std::cout << "Loaded existing game:" << std::endl;
		NEWLINE;

		std::string choice;
		std::cout << "Would you like to create a new profile? (y/n): ";
		std::cin >> choice;

		if (choice == "y" || choice == "Y") {
			p_player_ = nullptr;
		}

		CLEAR;
	}

	if (p_player_ == nullptr) {
		int empty_idx = -1;
		for (int i = 0; i < MAX_PROFILES; ++i) {
			if (!players_[i].active()) {
				empty_idx = i;
				break;
			}
		}

		if (empty_idx == -1) {
			std::cout
			    << "Player data is full! Please remove a player or "
			       "load an existing profile"
			    << std::endl;
			NEWLINE;
			PAUSE;
			return;
		}

		std::cout << "Create new player profile:" << std::endl;
		NEWLINE;

		std::string name;
		std::cout << "Name: ";
		std::getline(std::cin, name);
		std::getline(std::cin, name);

		p_player_ = &players_[empty_idx];
		*p_player_ = PlayerData(true, name, 0);

		CLEAR;

		std::cout << "Now playing as " << name << "!" << std::endl;
		NEWLINE;
		PAUSE_NOIGNORE;
	}
}

void GameManager::load_game_() {
	std::cout << "Load player profile by index:" << std::endl;
	NEWLINE;

	for (int i = 0; i < MAX_PROFILES; ++i) {
		if (!players_[i].active()) {
			std::cout << i + 1 << ". [Empty]" << std::endl;
			continue;
		}

		std::cout << i + 1 << ". " << players_[i].name() << " ("
			  << players_[i].score() << ")" << std::endl;
	}

	NEWLINE;
	std::cout << "λ ";

	int choice;
	std::cin >> choice;

	CLEAR;

	if (choice < 1 || choice > MAX_PROFILES ||
	    !players_[choice - 1].active()) {
		std::cout << "Profile not found!" << std::endl;
		NEWLINE;
		PAUSE;
		return;
	}

	p_player_ = &players_[choice - 1];
	std::cout << "Now playing as " << p_player_->name() << " with "
		  << p_player_->score() << " points!" << std::endl;

	NEWLINE;
	PAUSE;
}

void GameManager::add_command_() {
	std::cout << "Add command:" << std::endl;
	NEWLINE;

	std::string name;
	std::cout << "Name: ";
	std::cin >> name;

	if (commands_.any([&name](const CommandData &command) {
		    return command.name() == name;
	    })) {
		NEWLINE;
		std::cout << "Command already exists!" << std::endl;
		PAUSE;
		return;
	}

	std::string description;
	std::cout << "Description: ";
	// ignore the queued input
	std::getline(std::cin, description);
	std::getline(std::cin, description);

	int value;
	std::cout << "Value: ";
	std::cin >> value;

	commands_.push_back(CommandData(name, description, value));

	NEWLINE;
	PAUSE;
}

void GameManager::remove_command_() {
	std::cout << "Remove command by index:" << std::endl;
	NEWLINE;

	int choice = prompt_(commands_.map<std::string>(
	    [](const CommandData &command) { return command.name(); }));

	CLEAR;

	try {
		int i = 0;
		commands_.remove([&choice, &i](const CommandData &_) {
			return ++i == choice;
		});
	} catch (...) {
		std::cout << "Invalid index!" << std::endl;
		NEWLINE;
		PAUSE;
		return;
	}

	std::cout << "Successfully removed command!" << std::endl;
	NEWLINE;
	PAUSE;
}

void GameManager::display_commands_() {
	std::cout << "All commands:" << std::endl;
	NEWLINE;

	int i = 0;
	commands_
	    .map<std::string>([&i](const CommandData &command) {
		    return std::to_string(++i) + ". " + command.name() + ": " +
			   command.description() + " (" +
			   std::to_string(command.value()) + ")";
	    })
	    .display();

	NEWLINE;
	PAUSE;
}

GameManager::GameManager() {
	std::ifstream commands_file("target/commands.csv");
	commands_ = CommandData::from_csv_all(commands_file);
	commands_file.close();

	try {
		std::ifstream players_file("target/players.csv");
		players_ = PlayerData::from_csv_all(players_file, MAX_PROFILES);
		players_file.close();
	} catch (...) {
		std::ofstream players_file("target/players.csv");
		players_ = PlayerData::init_csv(players_file, MAX_PROFILES);
		players_file.close();
	}

	p_player_ = nullptr;
}

void GameManager::run() {
	bool running = true;
	while (running) {
		CLEAR;
		int choice = main_menu_();

		CLEAR;
		switch (choice) {
		case 1:
			game_rules_();
			break;
		case 2:
			play_();
			break;
		case 3:
			load_game_();
			break;
		case 4:
			add_command_();
			break;
		case 5:
			remove_command_();
			break;
		case 6:
			display_commands_();
			break;
		case 7:
			std::ofstream commands_file("target/commands.csv");
			CommandData::to_csv_all(commands_file, commands_);
			commands_file.close();

			std::ofstream players_file("target/players.csv");
			// cannot pass unique_ptr to to_csv_all, so convert to
			// raw pointer first
			PlayerData::to_csv_all(players_file, players_.get(),
					       MAX_PROFILES);
			players_file.close();

			running = false;
			break;
		}
	}

	std::cout << "Thanks for playing!" << std::endl;
}
