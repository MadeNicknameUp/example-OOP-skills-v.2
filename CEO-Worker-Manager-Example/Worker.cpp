#include "Worker.h"

short Worker::totalAmount = 0;

Worker::Worker() : id(totalAmount + 1), taskName(101 + std::rand() % 3), busy(false) {
    totalAmount++; // Increment the total number of workers
}

Worker::~Worker() {
    totalAmount--; // Decrement the total number of workers
}

void Worker::currentState() const {
    if (busy) {
        std::cout << "Worker " << id << " performs task " << taskName << std::endl;
    } else {
        std::cout << "Worker " << id << " is free" << std::endl;
    }
}