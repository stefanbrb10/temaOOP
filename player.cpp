#include "PLAYERS_H"
using namespace std;

Player::Player(string objName, string objTeam, string objPosition, int objAge){
    name = objName;
    team = objTeam;
    position = objPosition;
    age = objAge;
    goals_scored = 0;
}

Player::Player(const Player& p){
    name = p.name;
    team = p.team;
    position = p.position;
    age = p.age;
    goals_scored = p.goals_scored;
}

Player&Player::operator=(const Plaayer& other){
    name = other.name;
    team = other.team;
    position = other.position;
    age = other.age;
    goals_scored = other.goals_scored;
}

Player::Goal(){
    goals_scored++;
}

Player::~Player(){}

ostream&Player:: operator<<(ostream& os, Player p){
    os << p.name << " " << p.team << " " << p.age << " " <<
    p.position << " " << p.goals_scored << " goals";
    return os;
}
