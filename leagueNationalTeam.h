//
// Created by Stefan on 02-Dec-22.
//

#ifndef OOP_LEAGUENATIONALTEAM_H
#define OOP_LEAGUENATIONALTEAM_H

#include "league.h"
#include <string>
#include <iostream>
#include <memory>

class leagueNationalTeam: public League{
    int noOfGroups;
    std::string continent;
    std::string hostCountry;

public:
    void printRules() override{
        std::cout << "Se joaca in tara " << hostCountry <<
        " \nPozitiile 3-4 se decid prin jucarea unei finale mici\nIn timpul grupelor, la egalitate de puncte, urmatorul ca importanta este golaverajul, apoi golurile marcate";
    }

    leagueNationalTeam(int nrTeams, const std::string &country, int noOfGroups, const std::string &continent,
                       const std::string &hostCountry);

    leagueNationalTeam(const League &L, const leagueNationalTeam &other);

    std::shared_ptr<League> clone() const override;


    friend std::ostream &operator<<(std::ostream &os, const leagueNationalTeam &team);
};

#endif //OOP_LEAGUENATIONALTEAM_H
