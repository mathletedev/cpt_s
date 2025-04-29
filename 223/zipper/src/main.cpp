#include "list.hpp"
#include "zipper.hpp"

void loop(const ListZipper<char> &z) {
	std::cout << "> ";

	std::string input;
	std::getline(std::cin, input);

	char command = input[0];

	switch (command) {
	case 'q':
		return;
	case 'p':
		print(to_list(z));
		return loop(z);
	case 'h':
		return loop(left(z));
	case 'l':
		return loop(right(z));
	case 'i':
		return loop(insert(z, input[2]));
	case 'x':
		return loop(drop(z));
	case 'r':
		return loop(modify(z, input[2]));
	default:
		throw;
	}
}

int main() {
	ListPtr(char) l =
	    cons('H', cons('e', cons('l', cons('l', cons('o', Nil)))));

	loop(ListZipper(l));

	return 0;
}
