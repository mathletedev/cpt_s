#ifndef PRINTERJOB_H
#define PRINTERJOB_H

#include <string>

using namespace std;

class PrinterJob {
public:
    string printString;
    int priority;

    PrinterJob();
    PrinterJob(string str, int pri);
    
    bool operator<(const PrinterJob& other) const;
};

#endif // PRINTERJOB_H
