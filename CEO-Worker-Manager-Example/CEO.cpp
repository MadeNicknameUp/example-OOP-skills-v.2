#include "CEO.h"

CEO::CEO() : decision(1 + std::rand() % 10) {}

short CEO::getDecision() const {
    return decision;
}

short CEO::makeDecision() {
    static CEO boss;
    return boss.getDecision();
}