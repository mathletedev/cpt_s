#include "testqueue.hpp"

void TestQueue::runTests() {
	testIsEmpty();
	testEnqueue();
	testDequeue();
	testPrintRecursive();
}

void TestQueue::testIsEmpty() {
	Queue<std::string> q;

	bool passed = true;

	passed &= q.isEmpty();
	q.enqueue("Item1");
	passed &= !q.isEmpty();

	std::cout << "testIsEmpty():" << std::endl;
	std::cout << (passed ? "passed" : "failed") << std::endl;
}

void TestQueue::testEnqueue() {
	Queue<std::string> q;

	bool passed = true;

	passed &= q.enqueue("Item1");
	passed &= q.enqueue("Item2");
	passed &= q.enqueue("Item3");
	passed &= q.enqueue("Item4");

	std::cout << "testEnqueue():" << std::endl;
	std::cout << (passed ? "passed" : "failed") << std::endl;
}

void TestQueue::testDequeue() {
	Queue<std::string> q;

	q.enqueue("Item1");
	q.enqueue("Item2");
	q.enqueue("Item3");
	q.enqueue("Item4");

	bool passed = true;

	passed &= (q.dequeue() == "Item1");
	passed &= (q.dequeue() == "Item2");
	passed &= (q.dequeue() == "Item3");
	passed &= (q.dequeue() == "Item4");

	std::cout << "testDequeue():" << std::endl;
	std::cout << (passed ? "passed" : "failed") << std::endl;
}

void TestQueue::testPrintRecursive() {
	Queue<std::string> q;

	q.enqueue("Item1");
	q.enqueue("Item2");
	q.enqueue("Item3");
	q.enqueue("Item4");

	std::cout << "testPrintRecursive():" << std::endl;
	std::cout << "Expected: Item1 -> Item2 -> Item3 -> Item4 -> nullptr"
		  << std::endl;
	std::cout << "Actual:   ";
	q.printRecursive();
}
