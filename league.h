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
    int budget;
public:
    League(int nrTeams, const std::string &country, int budget);

    League(const League &other) = default;

     int getBudget() const;

    virtual void printRules() = 0;

    virtual ~League();

    friend std::ostream &operator<<(std::ostream &os, const League &league);
    friend bool operator>(const League& L1, const League& L2);

    virtual std::shared_ptr<League> clone() const = 0;


};

#endif //OOP_LEAGUE_H
