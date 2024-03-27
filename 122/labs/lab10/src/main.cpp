#include "mergesort.cpp"
#include <iostream>
#include <vector>

int main() {
	std::vector<int> list = {4, 6, 7, 2, 3, 9, 8};
	merge_sort(list);

	for (int x : list)
		std::cout << x << " ";
	std::cout << std::endl;

	return 0;
}
