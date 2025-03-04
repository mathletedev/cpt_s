#include "PrinterJob.h"

// Default Constructor
PrinterJob::PrinterJob() : printString(""), priority(0) {}

// Constructor
PrinterJob::PrinterJob(string str, int pri) : printString(str), priority(pri) {}

// Operator overloading for priority comparison
bool PrinterJob::operator<(const PrinterJob& other) const {
    return priority < other.priority; // Lower number means higher priority
}
