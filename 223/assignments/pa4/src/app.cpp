#include "app.hpp"
#include "utils.hpp"
#include <fstream>
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

	// load dataset
	std::ifstream dataset("data/dataset.csv");
	std::string line;
	// skip header
	std::getline(dataset, line);

	while (std::getline(dataset, line)) {
		LinkedList<std::string> args = utils::parse_csv(line);
		std::string id = args.pop_front();
		ids_[id] = args.pop_front();
	}
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

void App::find_(LinkedList<std::string> &args) {
	std::cout << ids_[args.pop_front()] << std::endl;
}

void App::list_inventory_(LinkedList<std::string> &args) {
	std::cout << "YET TO IMPLEMENT!" << std::endl;
}

LinkedList<std::string> App::split_(const std::string &input) const {
	LinkedList<std::string> res;

	std::string curr;
	for (char c : input) {
		if (c == ' ') {
			res.push_back(curr);
			curr.clear();
			continue;
		}

		curr += c;
	}
	res.push_back(curr);

	return res;
}

bool App::valid_command_(const std::string &input) const {
	return commands_.find(input) != commands_.end();
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
		commands_.find(command_name)->second(args);

		if (!running_) {
			break;
		}

		std::cout << "> ";
	}
}
