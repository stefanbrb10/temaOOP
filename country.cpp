//
// Created by Stefan on 23-Dec-22.
//

#include "country.h"
#include "League.h"
#include <vector>

void country::addLeague(const League &league) {
    L.push_back(league.clone());
}

country::country(const std::vector<std::shared_ptr<League>> &l, int budget) : L(l), budget(budget) {}

country::country(const country &other) {
   budget = other.budget;
   for(const auto &liga: other.L)
       L.push_back(liga->clone());
}

country &country::operator=(const country &other) {
    budget = other.budget;
    for(const auto &liga: other.L)
          L.push_back(liga->clone());
    return *this;
}

int country::budgetEnough() {
    int sum = 0;
    for(const auto &liga: L)
        sum += liga->getBudget();
    return sum <= this->budget;
}
