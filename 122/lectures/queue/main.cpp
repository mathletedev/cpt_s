#include "queue.hpp"

template class Queue<int>;

int main() {
	Queue<std::string> printJobs;

	printJobs.enqueue("Print job 1");
	printJobs.enqueue("Print job 2");
	printJobs.enqueue("Print job 3");

	return 0;
}
