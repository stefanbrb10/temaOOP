//
// Created by Stefan on 20-Jan-23.
//

#ifndef OOP_TEMPLATE_H
#define OOP_TEMPLATE_H
#include <iostream>
#include "player.h"

template <typename T> T compara(T x, T y)
{
    return (x > y) ? x : y;
}

#endif //OOP_TEMPLATE_H
