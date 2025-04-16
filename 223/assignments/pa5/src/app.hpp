#pragma once

#include "avl_map.hpp"
#include "hash_map.hpp"
#include "linked_list.hpp"
#include "product.hpp"
#include <functional>
#include <memory>
#include <string>

class App {
	private:
		bool running_ = true;
		AvlMap<std::string,
		       std::function<void(LinkedList<std::string> &)>>
		    commands_;
		// store in pointers so hash map isn't too big
		HashMap<std::string, std::shared_ptr<Product>> ids_;
		HashMap<std::string, LinkedList<std::string>> categories_;

		void quit_();
		void help_() const;
		void find_(LinkedList<std::string> &args);
		void list_inventory_(LinkedList<std::string> &args);

		bool valid_command_(const std::string &) const;

		void bootstrap_();
		void run_();

	public:
		App();
};
