#ifndef LISTPRIORITYQUEUE_H
#define LISTPRIORITYQUEUE_H

#include <list>
#include "PrinterJob.h"

using namespace std;

class ListPriorityQueue {
private:
    list<PrinterJob> jobs;

public:
    ListPriorityQueue(); // Constructor
    ~ListPriorityQueue(); // Destructor

    ListPriorityQueue(const ListPriorityQueue& other); // Copy Constructor
    ListPriorityQueue& operator=(const ListPriorityQueue& other); // Copy Assignment

    void enqueue(const string& str, int priority); // Insert job
    void printJobs(); // Print jobs
};

#endif // LISTPRIORITYQUEUE_H
