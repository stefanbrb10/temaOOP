//
// Created by Stefan on 02-Dec-22.
//

#include "leagueNationalTeam.h"

std::ostream &operator<<(std::ostream &os, const leagueNationalTeam &team) {
    os << dynamic_cast<const League &>(team) << " noOfGroups: " << team.noOfGroups << " continent: "
       << team.continent << " hostCountry: " << team.hostCountry;
    return os;
}

leagueNationalTeam::leagueNationalTeam(int nrTeams, const std::string &country, int noOfGroups,
                                       const std::string &continent, const std::string &hostCountry) : League(nrTeams,
                                                                                                              country),
                                                                                                       noOfGroups(
                                                                                                               noOfGroups),
                                                                                                       continent(
                                                                                                               continent),
                                                                                                       hostCountry(
                                                                                                               hostCountry) {}
std::shared_ptr<League> leagueNationalTeam::clone() const {
    return std::make_shared<leagueNationalTeam>(*this);
}

