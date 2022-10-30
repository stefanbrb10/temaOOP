#include "match.h"

using namespace std;

Match::Match(const Match& m){
    date = m.date;
    home_team = m.home_team;
    away_team = m.away_team;
    goals_home = m.goals_home;
    goals_away = m.goals_away;
}

Match::Match(string objDate, string objHome, string objAway, int objHgoals, int objAgoals){
    date = objDate;
    home_team = objHome;
    away_team = objAway;
    goals_home = objHgoals;
    goals_away = objAgoals;
}

Match&Match::operator=(const Match& other){
    date = other.date;
    home_team = other.home_team;
    away_team = other.away_team;
    goals_home = other.goals_home;
    goals_away = other.goals_away;
}

void Match::Score(){
    if(goals_home > goals_away){
    /// voi adauga puncte in clasa Team pt echipa home
    cout << "Castiga " << home_team;
    }
    else if(goals_home < goals_away){
        cout << "Castiga " << away_team;
    }
    else {
       cout <<"Egal";
    }
}

Match::~Match(){}

ostream& operator<<(ostream& os, Match m){
    os << m.home_team << " - " << m.away_team << " " << m.goals_home << "-" << m.goals_away;
    return os;
}

