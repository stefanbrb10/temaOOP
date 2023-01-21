//
// Created by Stefan on 21-Jan-23.
//

#ifndef OOP_APLICATIE_H
#define OOP_APLICATIE_H

#include <vector>
#include <iostream>
#include "player.h"

class Aplicatie {
private:

    std::vector<Player> jucatori;

    Aplicatie() = default;

public:
    Aplicatie(const Aplicatie &) = delete;

    Aplicatie &operator=(const Aplicatie &) = delete;

    static Aplicatie &getAplicatie();

    void printMeniu();

    void addJucator();

    void printJucator();


};

#endif //OOP_APLICATIE_H
