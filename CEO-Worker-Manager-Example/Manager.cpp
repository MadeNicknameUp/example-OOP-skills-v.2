#include "Manager.h"

short Manager::totalAmount = 0;

Manager::Manager() : id(totalAmount + 1), decision(1 + (CEO::makeDecision() + id + std::rand()) % myTeam.getSize()) {
    totalAmount++; // Increment the total number of managers
}

Manager::~Manager() {
    totalAmount--; // Decrement the total number of managers
}

short Manager::getDecision() const {
    return decision;
}