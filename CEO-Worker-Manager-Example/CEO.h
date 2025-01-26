#ifndef CEO_H
#define CEO_H

#include <iostream>
#include <cstdlib> // для std::rand

class CEO {
private:
    const short decision;
    CEO(); // Приватный конструктор

    short getDecision() const;

public:
    static short makeDecision();

    // Удаляем копирование и присваивание
    CEO(const CEO&) = delete;
    CEO& operator=(const CEO&) = delete;
};

#endif // CEO_H