#pragma once

#include "destination.hpp"
#include "my_josephus.hpp"
#include <list>

class VectorMyJosephus : public MyJosephus<std::list<Destination>> {
	public:
		VectorMyJosephus(int M, int N,
				 std::list<Destination> destinations)
		    : MyJosephus(M, N, destinations) {};
		// NOTE: destructor not needed

		void clear();
		size_t current_size() const;
		bool is_empty() const;
		Destination eliminate_destination();
		void print_destinations() const;
};
