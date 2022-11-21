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
    int wins = 0, draws = 0, losses = 0; // matches_played = 0;
    vector<Player> squad;

public:
    Team(string objName, string objLeague, vector <Player> squad);
    Team(const Team& t);

    Team& operator=(const Team& other);
    int getPoints();
    ~Team();
    friend ostream& operator<<(ostream& os, Team t);

    const string &getName() const;

    const vector<Player> &getSquad() const;
};

#endif

