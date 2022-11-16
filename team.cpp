#include "team.h"
#include "player.h"
#include <vector>

using namespace std;

Team::Team(const Team&t){
    name = t.name;
    league = t.league;
    wins = t.wins;
    draws = t.draws;
    losses = t.losses;
}

Team::Team(string objName, string objLeague, vector<Player> objSquad){
    name = objName;
    league = objLeague;
    squad = objSquad;
    wins = draws = losses = matches_played = 0;
}

Team&Team::operator=(const Team& other){
    name = other.name;
    league = other.league;
    wins = other.wins;
    draws = other.draws;
    losses = other.losses;
    return *this;
}

int Team::getPoints(){
    return (3*wins + draws);
}

Team::~Team(){

}

ostream& operator<<(ostream& os, Team t){
    os << t.name << " " << t.league << " " << t.getPoints();
    return os;
}
