#include "match.h"
#include "team.h"

using namespace std;

Match::Match(const Match &m, Team &awayTeam, Team &homeTeam) : home_team(homeTeam), away_team(awayTeam) {
    date = m.date;
    goals_home = m.goals_home;
    goals_away = m.goals_away;
}

Match::Match(string objDate, int objHgoals, int objAgoals, vector<Player> &objScorers,
             Team &awayTeam, Team &homeTeam) : home_team(homeTeam), away_team(awayTeam) {
    date = objDate;
    goals_home = objHgoals;
    goals_away = objAgoals;
    scorers = objScorers;
}

Match&Match::operator=(const Match& other){
    date = other.date;
    home_team = other.home_team;
    away_team = other.away_team;
    goals_home = other.goals_home;
    goals_away = other.goals_away;
    return *this;
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
    for(int i = 0; i < goals_home + goals_away; i++) {
        cout << " " << scorers[i].getName();
    }
}

Match::~Match(){

}

ostream& operator<<(ostream& os, Match m){
    os << m.home_team << " - " << m.away_team << " " << m.goals_home << "-" << m.goals_away;
    return os;
}

