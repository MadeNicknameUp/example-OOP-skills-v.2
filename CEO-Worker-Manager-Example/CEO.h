#ifndef CEO_H
#define CEO_H

#include <iostream>
#include <cstdlib> // for std::rand

class CEO {
private:
    const short decision; // Decision made by the CEO
    CEO(); // Private constructor

    short getDecision() const; // Returns the decision made by the CEO

public:
    static short makeDecision(); // Static method to get the CEO's decision

    // Delete copy constructor and assignment operator to prevent copying
    CEO(const CEO&) = delete;
    CEO& operator=(const CEO&) = delete;
};

#endif // CEO_H