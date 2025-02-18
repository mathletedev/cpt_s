#pragma once

#include "destination.hpp"
#include "my_josephus.hpp"
#include <list>

class ListMyJosephus : public MyJosephus<std::list<Destination>> {
	public:
		ListMyJosephus(int M, int N,
			       std::list<Destination> destinations);
};
