//
// Created by Stefan on 02-Dec-22.
//

#include "leagueJunior.h"

std::ostream &operator<<(std::ostream &os, const leagueJunior &junior) {
    os << dynamic_cast<const League &>(junior) << " maxAge: " << junior.maxAge;
    return os;
}

leagueJunior::leagueJunior(int nrTeams, const std::string &country, int budget, int maxAge) : League(nrTeams, country, budget),
                                                                                  maxAge(maxAge) {}

std::shared_ptr<League> leagueJunior::clone() const {
    return std::make_shared<leagueJunior>(*this);
}

leagueJunior::leagueJunior(const League &L, const leagueJunior &other) : League(L) {
    maxAge = other.maxAge;
}
