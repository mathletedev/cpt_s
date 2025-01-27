#pragma once

#include "data.hpp"
#include "linked_list.hpp"
#include <string>

class GameManager {
	private:
		LinkedList<CommandData> commands_;

		int prompt_(const LinkedList<std::string> &choices);
		int main_menu_();
		void display_commands_();

	public:
		GameManager();

		void run();
};
