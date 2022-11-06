#ifndef TEAMS_H
#define TEAMS_H

#include <iostream>
#include <string>
#include <vector>
#include "player.h"


using namespace std;

class Team{
private:
    string logo;
    string name;
    string league;
    int wins, draws, losses, matches_played;
    vector<Player> squad;

public:
    Team(string objName, string objLeague, vector <Player> squad);
    Team(const Team& t);

    Team& operator=(const Team& other);
    int getPoints();
    ~Team();
    friend ostream& operator<<(ostream& os, Team t);
};

#endif

