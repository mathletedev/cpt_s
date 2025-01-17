#include <iostream>
#include <stack>

void print_stack(std::stack<int> &s) {
	std::cout << "State of stack: ";

	while (!s.empty()) {
		std::cout << s.top() << " ";
		s.pop();
	}

	std::cout << std::endl;
}

int sum_of_stack(std::stack<int> &s) {
	if (s.empty()) {
		return 0;
	}

	int top = s.top();
	s.pop();
	return top + sum_of_stack(s);
}
