#include "queue.hpp"

template class Queue<int>;

int main() {
	Queue<std::string> printJobs;

	printJobs.enqueue("Print job 1");
	printJobs.enqueue("Print job 2");
	printJobs.enqueue("Print job 3");

	Queue<int> q2;
	q2.enqueue(3);
	q2.enqueue(4);
	q2.enqueue(5);

	return 0;
}
