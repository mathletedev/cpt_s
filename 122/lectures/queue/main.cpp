#include "queue.hpp"

int main() {
	Queue printJobs;

	printJobs.enqueue("Print job 1");
	printJobs.enqueue("Print job 2");
	printJobs.enqueue("Print job 3");

	return 0;
}
