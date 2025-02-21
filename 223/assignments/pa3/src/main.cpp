#include "avl_map.hpp"
#include <iostream>

int main() {
	AvlMap<int, int> map;
	map.insert(1, 10);
	map.insert(2, 20);
	map.insert(3, 30);
	map.insert(4, 40);
	map.insert(5, 50);
	map.insert(6, 60);

	std::cout << (*map.find(6)).second << std::endl;

	return 0;
}
