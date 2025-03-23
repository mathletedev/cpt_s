#include "app.hpp"
#include "utils.hpp"
#include <iostream>

App::App() {
	bootstrap_();
	NEWLINE;

	run_();
}

void App::bootstrap_() {
	std::cout << "Welcome to the Amazon Inventory Query System!"
		  << std::endl;
	std::cout << "Enter \"help\" for commands or \"quit\" to exit."
		  << std::endl;

	// init commands
	commands_.insert("quit", [this](auto args) { quit_(); });
	commands_.insert("help", [this](auto args) { help_(); });
	commands_.insert("find", [this](auto args) { find_(args); });
	commands_.insert("listInventory",
			 [this](auto args) { list_inventory_(args); });
}

void App::quit_() {
	running_ = false;
}

void App::help_() const {
	// TODO: traverse commands_?
	std::cout << "Supported list of commands:" << std::endl;
	std::cout
	    << " 1. find <inventoryid> - Finds if the inventory exists. If "
	       "exists, prints details. If not, prints 'Inventory not found'."
	    << std::endl;
	std::cout
	    << " 2. listInventory <category_string> - Lists just the id and "
	       "name of all inventory belonging to the specified category. If "
	       "the category doesn't exists, prints 'Invalid Category'."
	    << std::endl;
}

void App::find_(const LinkedList<std::string> &args) const {
	std::cout << "YET TO IMPLEMENT!" << std::endl;
}

void App::list_inventory_(const LinkedList<std::string> &args) const {
	std::cout << "YET TO IMPLEMENT!" << std::endl;
}

LinkedList<std::string> App::split_(const std::string &input) const {
	LinkedList<std::string> res;

	std::string curr;
	for (char c : input) {
		if (c == ' ') {
			res.push_back(curr);
			curr = "";
			continue;
		}

		curr += c;
	}
	res.push_back(curr);

	return res;
}

bool App::valid_command_(const std::string &input) const {
	for (auto &[key, value] : commands_) {
		if (key == input) {
			return true;
		}
	}

	return false;
}

void App::run_() {
	std::string input;

	std::cout << "> ";
	while (std::getline(std::cin, input)) {
		LinkedList<std::string> args = split_(input);
		std::string command_name = args.pop_front();
		if (!valid_command_(command_name)) {
			std::cout
			    << "Command not supported. Enter \"help\" for "
			       "list of supported commands."
			    << std::endl;

			std::cout << "> ";
			continue;
		}

		// evaluate the command
		commands_.find(input)->second(args);

		if (!running_) {
			break;
		}

		std::cout << "> ";
	}
}
