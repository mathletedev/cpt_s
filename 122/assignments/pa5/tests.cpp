#include "tests.hpp"

void tests::test_all() {
	test_enqueue_empty();
	test_enqueue_one();
	test_dequeue_one();
	test_dequeue_two();

	std::cout << "Press Enter to run test_simulation_day()...";
	std::cin.ignore();

#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif

	test_simulation_day();
}

void tests::test_enqueue_empty() {
	queue queue;
	data data1 = data(1, 1, 1);

	bool passed = 1;
	passed &= queue.enqueue(data1);
	passed &= queue.peek()->get_customer_number() == 1;

	std::cout << "test_enqueue_empty()" << std::endl;
	std::cout << (passed ? "Passed" : "Failed") << std::endl;
}

void tests::test_enqueue_one() {
	queue queue;
	data data1 = data(1, 1, 1);
	data data2 = data(2, 2, 2);

	queue.enqueue(data1);

	bool passed = 1;
	passed &= queue.enqueue(data2);
	// should insert at back of queue
	passed &= queue.peek()->get_customer_number() == 1;

	std::cout << "test_enqueue_one()" << std::endl;
	std::cout << (passed ? "Passed" : "Failed") << std::endl;
}

void tests::test_dequeue_one() {
	queue queue;
	data data1 = data(1, 1, 1);

	queue.enqueue(data1);

	bool passed = 1;
	passed &= queue.dequeue() == data1;

	std::cout << "test_dequeue_one()" << std::endl;
	std::cout << (passed ? "Passed" : "Failed") << std::endl;
}

void tests::test_dequeue_two() {
	queue queue;
	data data1 = data(1, 1, 1);
	data data2 = data(2, 2, 2);

	queue.enqueue(data1);
	queue.enqueue(data2);

	bool passed = 1;
	// should dequeue first element
	passed &= queue.dequeue() == data1;

	std::cout << "test_dequeue_one()" << std::endl;
	std::cout << (passed ? "Passed" : "Failed") << std::endl;
}

void tests::test_simulation_day() {
	simulation(24 * 60).run();
}
