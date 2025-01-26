#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <cstdlib> // для std::rand

class Worker {
private:
    static short totalAmount;
    const short id;
    char taskName;
    bool busy;

public:
    Worker();
    ~Worker();

    void currentState() const;
};

#endif // WORKER_H