#ifndef TEAM_H
#define TEAM_H

#include "Worker.h"

class Team {
private:
    static int counter;
    const short size;
    Worker* workers;

public:
    Team();
    ~Team();

    short getSize() const;
};

#endif // TEAM_H