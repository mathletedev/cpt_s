#pragma once

#include "destination.hpp"
#include <cstddef>

/// base abstract template class for any implementation of josephus
template <typename T>
class MyJosephus {
	public:
		MyJosephus(int M, int N, T destinations)
		    : M_(M), N_(N), i_(0), destinations_(destinations) {};
		/// empties the sequence
		void clear();
		/// returns # of remaining destinations
		size_t current_size() const;
		/// returns `true` if the sequence is empty
		bool is_empty() const;
		/// eliminates a destination based on the rules
		Destination eliminate_destination();
		/// prints all remaining destinations sorted by position
		void print_destinations() const;

	protected:
		// NOTE: N is the "total initial destination", which means it
		// must be immutable
		const int M_, N_;
		/// current destination index
		std::size_t i_;
		T destinations_;
};

template <typename T>
void MyJosephus<T>::clear() {
	destinations_.clear();
}

void MyJosephus::clear() {
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
