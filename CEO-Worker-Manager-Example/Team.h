#ifndef TEAM_H
#define TEAM_H

#include "Worker.h"

class Team {
private:
    static int counter; // Total number of teams
    const short size; // Size of the team
    Worker* workers; // Array of workers in the team

public:
    Team();
    ~Team();

    short getSize() const; // Returns the size of the team
};

#endif // TEAM_H