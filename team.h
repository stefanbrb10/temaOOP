#ifndef TEAMS_H
#define TEAMS_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "player.h"


using namespace std;

class Team{
private:
    string name;
    string league;
    int wins = 0, draws = 0, losses = 0; // matches_played = 0;
    vector<Player> squad;

public:
    Team(const string &objName, const string &objLeague, const vector <Player> &squad);
    Team(const Team& t);

    Team& operator=(const Team& other);

    int getPoints() const;

    void victory();
    void equal();
    static bool cmp(const Team &team1,const Team &team2);

    ~Team();
    friend ostream& operator<<(ostream& os, Team t);

    const string &getName() const;

    [[nodiscard]] const vector<Player> &getSquad() const;
};

#endif

