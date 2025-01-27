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
			break;
		case 5:
			std::cout << commands_.length() << std::endl;
			PAUSE;
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
