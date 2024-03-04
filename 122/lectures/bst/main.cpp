#include "bst.hpp"

int main() {
	bst<int> tree;

	tree.insert(3);
	tree.insert(1);
	tree.insert(6);
	tree.insert(2);
	tree.insert(5);

	return 0;
}
