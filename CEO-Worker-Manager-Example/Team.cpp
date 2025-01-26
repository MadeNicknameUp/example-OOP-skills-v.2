#include "Team.h"

int Team::counter = 0;

Team::Team() : size(1 + std::rand() % 10) {
    counter++;
    workers = new Worker[size];
}

Team::~Team() {
    counter--;
    delete[] workers;
}

short Team::getSize() const {
    return size;
}