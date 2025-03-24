#pragma once

#include "avl_map.hpp"
#include "hash_map.hpp"
#include "linked_list.hpp"
#include <functional>
#include <string>

class App {
	private:
		bool running_ = true;
		AvlMap<std::string,
		       std::function<void(LinkedList<std::string> &)>>
		    commands_;
		HashMap<std::string, std::string> ids_;
		HashMap<std::string, LinkedList<std::string>> categories_;

		void quit_();
		void help_() const;
		void find_(LinkedList<std::string> &args);
		void list_inventory_(LinkedList<std::string> &args);

		LinkedList<std::string> split_(const std::string &) const;
		bool valid_command_(const std::string &) const;

		void bootstrap_();
		void run_();

	public:
		App();
};
