#include "team.h"

using namespace std;

Team::Team(const Team&t){
    name = t.name;
    league = t.league;
    wins = t.wins;
    draws = t.draws;
    losses = t.losses;
}

Team::Team(string objName, int objLeague){
    name = objName;
    league = objLeague;
    wins = draws = losses = matches_played = 0;
}

Team&Team::operator=(const Team& other){
    name = other.name;
    league = other.league;
    wins = other.wins;
    draws = other.draws;
    losses = other.losses;
}

Team::getPoints(){
    return (3*wins + losses);
}

Team::~Team(){

}

ostream& operator<<(ostream& os, Team t){
    os << t.name << " " << t.league << " " << t.getPoints();
    return os;
}
