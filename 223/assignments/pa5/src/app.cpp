#include "app.hpp"
// #include "sorting.hpp"
#include "utils.hpp"
#include <ctime>
#include <fstream>
#include <iostream>

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
		LinkedList<std::string> cols = utils::parse_csv(line);
		std::shared_ptr<Product> p_product =
		    std::make_shared<Product>(cols);
		std::string id = p_product->id();

		// insert into ids_
		ids_[id] = p_product;

		// insert into categories_
		LinkedList<std::string> categories =
		    utils::split(p_product->category(), " | ");
		if (categories.length() > 0) {
			categories.for_each(
			    [this, &id](const std::string &category) {
				    categories_[category].push_back(id);
			    });
		} else {
			// empty category column
			categories_["NA"].push_back(id);
		}
	}
}

void App::quit_() {
	running_ = false;
}

void App::help_() const {
	// TODO: traverse commands_?
	// for now, just hard-code descriptions
	std::cout << "Supported list of commands:" << std::endl;
	std::cout << " 1. find <inventory_id> - Displays inventory details. If "
		     "inventory doesn't exist, prints 'Inventory not found'."
		  << std::endl;
	std::cout << " 2. listInventory <category> <merge?> <desc?> - Lists "
		     "the id and name of "
		     "all inventory belonging to the specified category. If "
		     "category doesn't exist, prints 'Invalid category'."
		  << std::endl;
}

void App::find_(LinkedList<std::string> &args) {
	if (!ids_.contains(args.nth(0))) {
		std::cout << "Inventory not found" << std::endl;
		return;
	}

	ids_[args.nth(0)]->display();
}

void App::list_inventory_(LinkedList<std::string> &args) {
	// join args with spaces (for pa4)
	// std::string category = args.foldr<std::string>(
	//     [](std::string prev, const std::string &curr) {
	// 	    return prev.empty() ? curr : prev + " " + curr;
	//     },
	//     "");

	// now args use quotes (for pa5)
	std::string category = args.pop_front();

	if (!categories_.contains(category)) {
		std::cout << "[ERR] Invalid category" << std::endl;
		return;
	}

	bool asc = !args.elem("desc");
	bool merge = args.elem("merge");

	auto cmp = [this, &asc](const std::string &id_x,
				const std::string &id_y) {
		float x = ids_[id_x]->price();
		float y = ids_[id_y]->price();
		if (x == -1) {
			return false;
		}
		if (y == -1) {
			return true;
		}
		if (asc) {
			return x <= y;
		}
		return x >= y;
	};
	// this uses sorting::msort(), which is sub-optimal
	// auto sort_f =
	//     merge ? sorting::msort<std::string> :
	//     sorting::isort<std::string>;

	LinkedList<std::string> sorted = categories_[category];

	// performance analysis by time
	clock_t start = clock();
	if (merge) {
		sorted.msort(cmp);
	} else {
		sorted.isort(cmp);
	}
	clock_t end = clock();
	double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;

	sorted.for_each([this](const std::string &id) {
		std::shared_ptr<Product> p_product = ids_[id];
		std::cout << p_product->id() << " | " << p_product->name()
			  << " | " << p_product->price_s() << std::endl;
	});

	std::cout << "[INFO] Took " << elapsed_secs << "s" << std::endl;
}

bool App::valid_command_(const std::string &input) const {
	return commands_.find(input) != commands_.end();
}

void App::run_() {
	std::string input;

	std::cout << "> ";
	while (std::getline(std::cin, input)) {
		LinkedList<std::string> args = utils::parse_args(input);
		std::string command_name = args.pop_front();
		if (!valid_command_(command_name)) {
			std::cout << "[ERR] Command not supported. Enter "
				     "\"help\" for "
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

App::App() {
	bootstrap_();
	NEWLINE;

	run_();
}
