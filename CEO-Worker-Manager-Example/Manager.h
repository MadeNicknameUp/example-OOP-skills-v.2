#ifndef MANAGER_H
#define MANAGER_H

#include "CEO.h"
#include "Team.h"

class Manager {
private:
    static short totalAmount;
    const short id;
    short decision;
    Team myTeam;

public:
    Manager();
    ~Manager();

    short getDecision() const;
};

#endif // MANAGER_H