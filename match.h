#ifndef MATCHES_H
#define MATCHES_H

#include <iostream>
#include <string>
#include <vector>
#include "team.h"
#include "player.h"

using namespace std;

class Match{
private:
    string date;
    Team& home_team;
    Team& away_team;
    vector <Player> scorers;
    string hour;
    int goals_home, goals_away;
public:
    Match(string objDate, Team &objHome, Team &objAway, int objHgoals, int objAgoals, vector<Player> objScorers);
    Match(const Match& m);
    Match& operator=(const Match& other);
    void Score();
    friend ostream& operator<<(ostream& os, Match m);
    ~Match();
};
#endif



