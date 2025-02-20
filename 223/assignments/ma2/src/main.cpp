// Neal Wang | 11870028 | CPT_S 223
// MA2: Binary Search Tree
//
// Conceptual Questions:
// Part A:
// 	1. A **move constructor** is similar to a copy constructor in that both
// constructors create a deep copy of a source object. However, unlike a copy
// constructor, a move constructor may mutate the source object, allowing for
// optimisations. The source object is then unusable.
// 	2. A **move assignment operator** is essentially the same as above with
// respect to the copy assignment operator. The source object may be mutated and
// will be unusable.
// Part B:
// BST::empty() - O(1). No matter the size of the BST, only one comparison is
// required.
// BST::add() - O(N), where `N` is the number of nodes in the BST.
// This occurs when the BST is degenerate.
// BST::makeEmpty() - O(N). All nodes must be processed.
// BST::printLevelOrder() - O(N). All nodes must be processed.
// BST::cloneTree() - O(N). All nodes must be processed.

#include "bst.h"
#include <functional>
#include <iostream>

/// Asserts that `condition` is true
/// Optionally calls `f` if assertion fails
void assert(bool condition, std::string test,
	    std::function<void()> f = nullptr) {
	if (condition) {
		std::cout << test << " passed!" << std::endl;
		return;
	}

	std::cout << test << " failed!" << std::endl;

	if (f != nullptr) {
		f();
	}

	throw;
}

int main() {
	BST<std::string> bst_test(
	    {"C", "p", "t", "s", "2", "3", "B", "S", "T"});

	std::cout << "Number of nodes: " << bst_test.nodesCount() << std::endl;

	// Test1: Test printLevelOrder()
	std::cout << "In-order print:" << std::endl;
	bst_test.printInOrder();
	std::cout << std::endl;
	std::cout << "Level-order print:" << std::endl;
	bst_test.printLevelOrder();
	std::cout << std::endl;
	std::cout << "Post-order print:" << std::endl;
	bst_test.printPostOrder();
	std::cout << std::endl;
	std::cout << "Pre-order print:" << std::endl;
	bst_test.printPreOrder();
	std::cout << std::endl;

	// Test2: Test copy constructor 1
	BST<std::string> bst_copy1(bst_test);
	assert(bst_test.size() == bst_copy1.size(), "Copy constructor test-1");

	// Test3: Test copy constructor 2
	bst_copy1.getNode("B")->setValue("A");
	assert(bst_test.contains("B") && !bst_test.contains("A"),
	       "Copy constructor test-2", [&bst_test]() {
		       bst_test.printLevelOrder();
		       std::cout << std::endl;
	       });

	// Test4: Test copy assignment
	BST<std::string> bst_copy2;
	bst_copy2 = bst_test;
	assert(bst_copy2.size() == bst_test.size() && bst_copy2.contains("B") &&
		   bst_copy2.contains("S") && bst_copy2.contains("T"),
	       "Copy assignment operator test", [&bst_test, &bst_copy2]() {
		       bst_test.printLevelOrder();
		       std::cout << std::endl;
		       bst_copy2.printLevelOrder();
		       std::cout << std::endl;
	       });

	// Test5: Test move constructor
	BST<std::string> bst_move1(std::move(bst_test));
	assert(bst_move1.size() == 9 && bst_move1.contains("B") &&
		   bst_move1.contains("S") && bst_move1.contains("T") &&
		   bst_test.empty(),
	       "Move constructor test", [&bst_move1]() {
		       bst_move1.printLevelOrder();
		       std::cout << std::endl;
	       });

	// Test6: Test move assignment
	BST<std::string> bst_move2;
	bst_move2 = BST<std::string>({"B", "S", "T"});
	assert(bst_move2.size() == 3 && bst_move2.contains("B") &&
		   bst_move2.contains("S") && bst_move2.contains("T"),
	       "Move assignment operator test", [&bst_move2]() {
		       bst_move2.printLevelOrder();
		       std::cout << std::endl;
	       });

	return 0;
}
