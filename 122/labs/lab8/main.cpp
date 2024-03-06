#include "bst.hpp"
#include <vector>

int main() {
	std::vector<std::string> names = {"Hello", "Coug", "Neal", "Ice cream",
					  "Table"};

	bst bst;
	for (auto name : names)
		bst.insert(name);

	std::vector<std::string> res;
	bst.sort_into(res);

	for (auto x : res)
		std::cout << x << std::endl;

	return 0;
}
