#include "avl_map.hpp"
#include <algorithm>
#include <iostream>

int main() {
	AvlMap<int, int> map;
	map.insert(6, 60);
	map.insert(1, 10);
	map.insert(3, 30);
	map.insert(2, 20);
	map.insert(4, 40);
	map.insert(5, 50);

	map.erase(5);

	std::for_each(map.begin(), map.end(), [](const std::pair<int, int> &x) {
		std::cout << x.first << " " << x.second << std::endl;
	});

	return 0;
}
