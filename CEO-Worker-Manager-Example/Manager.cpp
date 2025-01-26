#include "Manager.h"

short Manager::totalAmount = 0;

Manager::Manager() : id(totalAmount + 1), decision(1 + (CEO::makeDecision() + id + std::rand()) % myTeam.getSize()) {
    totalAmount++;
}

Manager::~Manager() {
    totalAmount--;
}

short Manager::getDecision() const {
    return decision;
}