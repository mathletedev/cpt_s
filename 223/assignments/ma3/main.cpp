#include "ListPriorityQueue.h"
// #include "HeapPriorityQueue.h" // TODO: Uncomment when implementing HeapPriorityQueue

#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ListPriorityQueue queue; // List-based priority queue TODO: comment when HeapPriorityQueue is ready!
    // HeapPriorityQueue queue; // TODO: Uncomment when HeapPriorityQueue is implemented

    string input;

    cout << "Enter print jobs in format: <string> <priority>. Type 'print' to process jobs. Type 'exit' to exit.\n";

    while (true) {
        cout << "> ";
        getline(cin, input);

        if (input == "exit") break;
        if (input == "print") {
            queue.printJobs();
            continue;
        }

        istringstream iss(input);
        string printString;
        int priority;
        if (iss >> printString >> priority) {
            queue.enqueue(printString, priority);
        } else {
            cout << "Invalid input. Format: <string> <priority>\n";
        }
    }

    return 0;
}
