#pragma once

#include "config.hpp"
#include "data.hpp"
#include "linked_list.hpp"
#include <memory>
#include <string>

class GameManager {
	private:
		LinkedList<CommandData> commands_;
		std::unique_ptr<PlayerData[]> players_;
		PlayerData *p_player_;

		int prompt_(const LinkedList<std::string> &choices);
		int main_menu_();
		void game_rules_();
		void add_command_();
		void remove_command_();
		void display_commands_();

	public:
		GameManager();

		void run();
};
