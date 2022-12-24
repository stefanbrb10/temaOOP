//
// Created by Stefan on 02-Dec-22.
//

#ifndef OOP_LEAGUEJUNIOR_H
#define OOP_LEAGUEJUNIOR_H

#include "league.h"
#include <iostream>
#include <memory>


class leagueJunior: public League{

    int maxAge;

public:

    leagueJunior(int nrTeams, const std::string &country, int budget, int maxAge);

    leagueJunior(const League &L, const leagueJunior &other);


    void printRules() override{
        if(maxAge == 19)
            std::cout << "Primele doua echipe din fiecare liga intra in turneul national,\nMeciul se joaca pe teren normal si la 5 faulturi se da un penalty";
        else if(maxAge > 16)
            std::cout << "Pentru jucatorii sub 15 ani se face cerere la federatie\n"
                    "Se iau masuri suplimentare pentru siguranta jucatorilor";
        else if(maxAge > 9)
            std::cout << "Parintii pot veni la meci numai prin cerere scrisa"
                    "Meciul se joaca pe teren la marimi injumatatite";
    }

    std::shared_ptr<League> clone() const override;

    friend std::ostream &operator<<(std::ostream &os, const leagueJunior &junior);
};

#endif //OOP_LEAGUEJUNIOR_H
