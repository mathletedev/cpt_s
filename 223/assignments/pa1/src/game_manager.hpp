#pragma once

#include "data.hpp"
#include "linked_list.hpp"

class GameManager {
	private:
		LinkedList<CommandData> commands_;

		int main_menu_();
		void display_commands_();

	public:
		GameManager();

		void run();
};
