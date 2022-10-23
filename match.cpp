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
public:
    int goals_home, goals_away;
    Match(string objDate, string objHome, string objAway, int objHgoals, int objAgoals){
        date = objDate;
        home_team = objHome;
        away_team = objAway;
        goals_home = objHgoals;
        goals_away = objAgoals;
    }

    Match(const Match& m){
        date = m.date;
        home_team = m.home_team;
        away_team = m.away_team;
        goals_home = m.goals_home;
        goals_away = m.goals_away;
    }

    void Score(){
        if(goals_home > goals_away){
            /// voi adauga puncte in clasa Team pt echipa home
        }
        else if(goals_home < goals_away){

        }
        else {

        }
    }

    friend ostream& operator<<(ostream& os, Match m);

    ~Match(){}

};

ostream& operator<<(ostream& os, Match m){
    os << m.home_team << " - " << m.away_team << " " << goals_home << "-" << goals_away;
    return os;
}
#endif


