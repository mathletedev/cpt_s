#include "headers.hpp"
#include <iostream>
#include <stack>

int main() {
	std::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	std::cout << sum_of_stack(s) << std::endl;

	std::cout << fibonacci(10) << std::endl;

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::cout << binary_search(arr, 10, 3) << std::endl;

	return 0;
}
