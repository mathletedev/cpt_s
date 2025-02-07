#pragma once

#include "destination.hpp"
#include <list>

class ListMyJosephus {
	private:
		int M_, N_;
		std::list<Destination> destinations_;

	public:
		ListMyJosephus(int M, int N) : M_(M), N_(N) {}
		// NOTE: destructor not needed

		void clear();
		size_t current_size() const;
		bool is_empty() const;
};
