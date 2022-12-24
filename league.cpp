//
// Created by Stefan on 02-Dec-22.
//

#include "league.h"

std::ostream &operator<<(std::ostream &os, const League &league) {
    os << "nrTeams: " << league.nrTeams << " country: " << league.country;
    return os;
}

League::League(int nrTeams, const std::string &country, int budget) : nrTeams(nrTeams), country(country), budget(budget) {}

League::~League() {}

int League::getBudget() const {
    return budget;
}
