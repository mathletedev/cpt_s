#include "vector_my_josephus.hpp"
#include <iostream>

void VectorMyJosephus::clear() {
	destinations_.clear();
}

size_t VectorMyJosephus::current_size() const {
	return destinations_.size();
}

bool VectorMyJosephus::is_empty() const {
	return destinations_.empty();
}

Destination VectorMyJosephus::eliminate_destination() {
	if (is_empty()) {
		throw "Vector is empty";
	}

	i_ += M_;
	i_ %= current_size();
	auto it = std::next(destinations_.begin(), i_);

	Destination res = *it;
	destinations_.erase(it);

	return res;
}

void VectorMyJosephus::print_destinations() const {
	for (const auto &d : destinations_) {
		d.print_name();
		std::cout << " ";
	}
}
