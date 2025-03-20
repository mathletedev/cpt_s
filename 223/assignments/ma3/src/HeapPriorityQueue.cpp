#include "HeapPriorityQueue.h"
#include <cassert>
#include <iostream>

HeapPriorityQueue::HeapPriorityQueue() {
	size = 0;
}

HeapPriorityQueue::~HeapPriorityQueue() {
	// memory is automatically managed; no work necessary
}

HeapPriorityQueue::HeapPriorityQueue(const HeapPriorityQueue &other) {
	// Copy heap elements and size
	size = other.size;

	for (int i = 0; i < size; ++i) {
		heap[i] = other.heap[i];
	}
}

HeapPriorityQueue &HeapPriorityQueue::operator=(HeapPriorityQueue other) {
	// Assign heap elements and size properly
	// use copy-and-swap
	std::swap(heap, other.heap);
	std::swap(size, other.size);

	return *this;
}

bool HeapPriorityQueue::empty() const {
	return size == 0;
}

void HeapPriorityQueue::enqueue(const string &str, int priority) {
	// Insert new PrinterJob(str, priority) while maintaining heap order
	// using percolateUp
	heap[size] = PrinterJob(str, priority);
	percolateUp(size);
	++size;
}

PrinterJob HeapPriorityQueue::dequeue() {
	assert(!empty());

	PrinterJob res = heap[0];
	percolateDown(0);
	--size;

	return res;
}

void HeapPriorityQueue::printJobs() {
	// Print and remove PrinterJobs from the heap in priority order and
	// using percolateDown as necessary
	if (empty()) {
		std::cout << "No jobs in the queue." << std::endl;
		return;
	}

	while (!empty()) {
		PrinterJob job = dequeue();
		std::cout << job.printString << " (Priority: " << job.priority
			  << ")" << std::endl;
	}
}

void HeapPriorityQueue::percolateUp(int index) {
	// Maintain heap order when inserting a new PrinterJob
	if (index == 0) {
		return;
	}

	int parent = (index - 1) / 2;

	if (heap[index] < heap[parent]) {
		std::swap(heap[parent], heap[index]);
		percolateUp(parent);
	}
}

void HeapPriorityQueue::percolateDown(int index) {
	// Maintain heap order when removing a PrinterJob
	// assume `heap[index]` is a hole
	if (index >= size) {
		return;
	}

	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < size && right < size) {
		int min = heap[left] < heap[right] ? left : right;
		heap[index] = heap[min];
		percolateDown(min);
		return;
	}

	// `left` is the last element, no extra cases necessary

	// fill the hole with the last element
	// otherwise the last element will be lost
	// it can be proven that the last element is larger than the hole
	heap[index] = heap[size - 1];
}
