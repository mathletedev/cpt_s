#include "list_my_josephus.hpp"
#include <iostream>

void ListMyJosephus::clear() {
	destinations_.clear();
}

size_t ListMyJosephus::current_size() const {
	return destinations_.size();
}

bool ListMyJosephus::is_empty() const {
	return destinations_.empty();
}

Destination ListMyJosephus::eliminate_destination() {
	if (is_empty()) {
		throw "list is empty";
	}

	// calculate next destination to eliminate
	i_ += M_;
	i_ %= current_size();
	auto it = std::next(destinations_.begin(), i_);

	// remove while storing destination to return
	Destination res = *it;
	destinations_.erase(it);

	return res;
}

void ListMyJosephus::print_destinations() const {
	for (const auto &d : destinations_) {
		d.print_name();
		std::cout << " ";
	}
}
