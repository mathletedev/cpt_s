#pragma once

#include "destination.hpp"
#include "my_josephus.hpp"
#include <vector>

class VectorMyJosephus : public MyJosephus<std::vector<Destination>> {
	public:
		VectorMyJosephus(int M, int N,
				 std::vector<Destination> destinations);
};
