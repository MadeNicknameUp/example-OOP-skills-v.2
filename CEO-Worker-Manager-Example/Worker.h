#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <cstdlib> // for std::rand

class Worker {
private:
    static short totalAmount; // Total number of workers
    const short id; // Unique ID for each worker
    char taskName; // Task assigned to the worker
    bool busy; // Indicates if the worker is busy

public:
    Worker();
    ~Worker();

    void currentState() const; // Displays the current state of the worker
};

#endif // WORKER_H