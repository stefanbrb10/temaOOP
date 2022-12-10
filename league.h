//
// Created by Stefan on 02-Dec-22.
//

#ifndef OOP_LEAGUE_H
#define OOP_LEAGUE_H

#include <string>
#include <ostream>
#include <memory>

class League{
    int nrTeams;
    std::string country;

public:
    League(int nrTeams, const std::string &country);

    virtual void printRules() = 0;

    virtual ~League();

    friend std::ostream &operator<<(std::ostream &os, const League &league);

    virtual std::shared_ptr<League> clone() const = 0;

};

#endif //OOP_LEAGUE_H
