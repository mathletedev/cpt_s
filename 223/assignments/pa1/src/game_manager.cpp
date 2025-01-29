#include "game_manager.hpp"

#include "utils.hpp"
#include <iostream>

int GameManager::prompt_(const LinkedList<std::string> &choices) {
	int i = 0;
	choices.for_each([&i](const std::string &choice) {
		std::cout << ++i << ". " << choice << std::endl;
	});
	NEWLINE;
	std::cout << "λ ";

	int choice;
	std::cin >> choice;

	return choice;
}

int GameManager::main_menu_() {
	LinkedList<std::string> choices = {
	    "Game Rules",   "Play New Game",  "Load Previous Game",
	    "Add Command",  "Remove Command", "Display All Commands",
	    "Save and Exit"};
	return prompt_(choices);
}

void GameManager::add_command_() {
	std::string name, description;
	int value;
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

	std::cout << "Description: ";
	std::cin >> description;
	std::cout << "Value: ";
	std::cin >> value;

	commands_.push_back(CommandData(name, description, value));

	NEWLINE;
	PAUSE;
}

void GameManager::remove_command_() {
	std::cout << "Select index of command to remove" << std::endl;
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
	int i = 0;
	commands_.for_each([&i](const CommandData &command) {
		std::cout << ++i << ". " << command.name() << ": "
			  << command.description() << " (" << command.value()
			  << ")" << std::endl;
	});

	NEWLINE;
	PAUSE;
}

GameManager::GameManager() {
	std::ifstream commands_file("target/commands.csv");
	commands_ = CommandData::from_csv_all(commands_file);
	commands_file.close();
}

void GameManager::run() {
	bool running = true;
	while (running) {
		CLEAR;
		int choice = main_menu_();

		CLEAR;
		switch (choice) {
		case 1:
			break;
		case 2:
			break;
		case 3:
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

			running = false;
			break;
		}
	}

	std::cout << "Thanks for playing!" << std::endl;
}
