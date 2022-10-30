#ifndef MATCHES_H
#define MATCHES_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Match{
private:
    string date;
    string home_team, away_team;
    vector <int> scorers;
    string hour;
    int goals_home, goals_away;
public:
    Match(string objDate, string objHome, string objAway, int objHgoals, int objAgoals);
    Match(const Match& m);
    Match& operator=(const Match& other);
    void Score();
    friend ostream& operator<<(ostream& os, Match m);
   ~Match();
};
#endif



