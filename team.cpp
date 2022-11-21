#include "team.h"
#include "player.h"
#include <vector>

using namespace std;

Team::Team(const Team&t):name(t.name), league(t.league), wins(t.wins), draws(t.draws), losses(t.losses){

}

Team::Team(const string &objName, const string &objLeague, const vector<Player> &objSquad):name(objName),league(objLeague), squad(objSquad){
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

const string &Team::getName() const {
    return name;
}

const vector<Player> &Team::getSquad() const {
    return squad;
}

Team::~Team(){

}

ostream& operator<<(ostream& os, Team t){
    os << t.name << " " << t.league << " " << t.getPoints();
    return os;
}
