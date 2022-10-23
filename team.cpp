#ifndef TEAMS_H
#define TEAMS_H

#include <iostream>
#include <string>

using namespace std;

class Team{
private:
    string logo;
public:
    string name;
    int league;
    int wins, draws, losses, matches_played;

    Team(string objName, int objLeague){
        name = objName;
        league = objLeague;
        wins = draws = losses = matches_played = 0;
    }

    Team(const Team& t){
        name = t.name;
        league = t.league;
        wins = t.wins;
        draws = t.draws;
        losses = t.losses;
    }

    int getPoints(){
        return (3*wins + losses);
    }
    ~Team(){}
    friend ostream& operator<<(ostream& os, Team t);
};

ostream& operator<<(ostream& os, Team t){
    os << t.name << " " << t.league << " " << t.getPoints();
    return os;
}
#endif
