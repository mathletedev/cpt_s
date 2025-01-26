#include "game_manager.hpp"

#include "utils.hpp"
#include <iostream>

int GameManager::main_menu_() {
	std::cout << "1. Game Rules" << std::endl;
	std::cout << "2. Play New Game" << std::endl;
	std::cout << "3. Load Previous Game" << std::endl;
	std::cout << "4. Add Command" << std::endl;
	std::cout << "5. Remove Command" << std::endl;
	std::cout << "6. Display All Commands" << std::endl;
	std::cout << "7. Save and Exit" << std::endl;
	NEWLINE;
	std::cout << "λ ";

	int choice;
	std::cin >> choice;

	return choice;
}

void GameManager::display_commands_() {
	int i = 0;
	this->commands_.for_each([&i](CommandData const &command) {
		std::cout << ++i << ". " << command.name() << ": "
			  << command.description() << " (" << command.value()
			  << ")" << std::endl;
	});

	NEWLINE;
	PAUSE;
}

GameManager::GameManager() {
	std::ifstream commands_file("target/commands.csv");
	this->commands_ = CommandData::from_csv_all(commands_file);
	commands_file.close();
}

void GameManager::run() {
	bool running = true;
	while (running) {
		CLEAR;
		int choice = this->main_menu_();

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
			std::cout << this->commands_.length() << std::endl;
			PAUSE;
			break;
		case 6:
			this->display_commands_();
			break;
		case 7:
			std::ofstream commands_file("target/commands.csv");
			CommandData::to_csv_all(commands_file, this->commands_);
			commands_file.close();

			running = false;
			break;
		}
	}

	std::cout << "Thanks for playing!" << std::endl;
}
