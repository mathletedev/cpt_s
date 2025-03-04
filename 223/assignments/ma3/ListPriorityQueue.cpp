#include "ListPriorityQueue.h"
#include <iostream>

// Constructor
ListPriorityQueue::ListPriorityQueue() = default;

// Destructor
ListPriorityQueue::~ListPriorityQueue() = default;

// Copy Constructor
ListPriorityQueue::ListPriorityQueue(const ListPriorityQueue& other) : jobs(other.jobs) {}

// Copy Assignment Operator
ListPriorityQueue& ListPriorityQueue::operator=(const ListPriorityQueue& other) {
    if (this != &other) {
        jobs = other.jobs;
    }
    return *this;
}


// Enqueue: Insert job in priority order
void ListPriorityQueue::enqueue(const string& str, int priority) {
    PrinterJob newJob(str, priority);
    auto it = jobs.begin();
    while (it != jobs.end() && it->priority <= priority) {
        ++it;
    }
    jobs.insert(it, newJob);
}

// Print all jobs and clear the queue
void ListPriorityQueue::printJobs() {
    if (jobs.empty()) {
        cout << "No jobs in the queue.\n";
        return;
    }

    cout << "Printing jobs in priority order:\n";
    while (!jobs.empty()) {
        cout << jobs.front().printString << " (Priority: " << jobs.front().priority << ")\n";
        jobs.pop_front();
    }
}
