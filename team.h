#ifndef TEAMS_H
#define TEAMS_H

#include <iostream>
#include <string>

using namespace std;

class Team{
private:
    string logo;
    string name;
    int league;
    int wins, draws, losses, matches_played;

public:
    Team(string objName, int objLeague);
    Team(const Team& t);

    Team& operator=(const Team& other);
    int getPoints();
    ~Team();
    friend ostream& operator<<(ostream& os, Team t);
};

#endif

