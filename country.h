//
// Created by Stefan on 23-Dec-22.
//

#ifndef OOP_COUNTRY_H
#define OOP_COUNTRY_H

#include <vector>
#include <memory>
#include "League.h"

class country{
    std::vector<std::shared_ptr<League>> L;
    int budget;
public:
    country(const std::vector<std::shared_ptr<League>> &l, int budget);
    country(const country &other);
    country& operator=(const country &other);
    void addLeague(const League &league);
    int budgetEnough();
};

#endif //OOP_COUNTRY_H
