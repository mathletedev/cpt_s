#ifndef HEAPPRIORITYQUEUE_H
#define HEAPPRIORITYQUEUE_H

#include "PrinterJob.h"

using namespace std;

class HeapPriorityQueue {
private:
    static const int MAX_SIZE = 100; // Fixed-size array
    PrinterJob heap[MAX_SIZE]; 
    int size; // Track the number of elements in the heap

    void percolateUp(int index);
    void percolateDown(int index);

public:
    HeapPriorityQueue(); // Constructor
    ~HeapPriorityQueue(); // Destructor

    HeapPriorityQueue(const HeapPriorityQueue& other); // Copy Constructor
    HeapPriorityQueue& operator=(const HeapPriorityQueue& other); // Copy Assignment

    void enqueue(const string& str, int priority); 
    void printJobs();
};

#endif // HEAPPRIORITYQUEUE_H
