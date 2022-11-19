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
    //scorers
    Match(string objDate, int objHgoals, int objAgoals,
          Team &awayTeam, Team &homeTeam);
    Match(const Match &m, Team &awayTeam, Team &homeTeam);
    Match& operator=(const Match& other);
    void Score();
    friend ostream& operator<<(ostream& os, Match m);
    ~Match();
};
#endif



