#ifndef MANAGER_H
#define MANAGER_H

#include "CEO.h"
#include "Team.h"

class Manager {
private:
    static short totalAmount; // Total number of managers
    const short id; // Unique ID for each manager
    short decision; // Decision made by the manager
    Team myTeam; // Team managed by the manager

public:
    Manager();
    ~Manager();

    short getDecision() const; // Returns the decision made by the manager
};

#endif // MANAGER_H