#include "bst.hpp"

int main() {
	bst<int> tree;

	tree.insert(3);
	tree.insert(6);
	tree.insert(1);
	tree.insert(2);
	tree.insert(7);
	tree.insert(5);

	tree.inorder_traversal();
	std::cout << "----" << std::endl;
	tree.preorder_traversal();
	std::cout << "----" << std::endl;
	tree.postorder_traversal();

	return 0;
}
