#include "Team.h"

int Team::counter = 0;

Team::Team() : size(1 + std::rand() % 10) {
    counter++; // Increment the total number of teams
    workers = new Worker[size]; // Allocate memory for workers
}

Team::~Team() {
    counter--; // Decrement the total number of teams
    delete[] workers; // Free the allocated memory
}

short Team::getSize() const {
    return size;
}