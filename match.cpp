#include "match.h"
#include "team.h"

using namespace std;

Match::Match(const Match &m, Team &awayTeam, Team &homeTeam) : date(m.date), home_team(awayTeam), away_team(homeTeam), goals_home(m.goals_home), goals_away(m.goals_away) {

}

Match::Match(const string &objDate, int objHgoals, int objAgoals,
             Team &awayTeam, Team &homeTeam) :  date(objDate), home_team(awayTeam), away_team(homeTeam), goals_home(objHgoals), goals_away(objAgoals) {
}

/*Team &Match::getHomeTeam() const {
    return home_team;
}

Team &Match::getAwayTeam() const {
    return away_team;
}*/

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
        cout << "Castiga gazda";
        home_team.victory();
    }
    else if(goals_home < goals_away){
        cout << "Castiga oaspetele";
        away_team.victory();
    }
    else {
        cout <<"Egal";
        home_team.equal();
        away_team.equal();
    }
}

Match::~Match(){

}

ostream& operator<<(ostream& os, Match m){
    os << m.home_team << " - " << m.away_team << " " << m.goals_home << "-" << m.goals_away;
    return os;
}

