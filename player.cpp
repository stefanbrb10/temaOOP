#include "player.h"

#include <utility>
#include "eroare_jucator.h"
using namespace std;

int Player::cnt = 0;

Player::Player(string objName, string objTeam, const string &objPosition, int objAge)
  :age(objAge), position(objPosition), name(std::move(objName)), team(std::move(objTeam)) ,nr_tricou(cnt++) {
        if (objAge < 16)
            throw eroare_varstaJucator();
        if (objPosition != "Striker" && objPosition != "Midfielder" && objPosition != "Defender" &&
            objPosition != "Goalkeeper") {
            throw eroare_pozitieJucator();
        }
}


Player::Player(const Player& p): age(p.age), position(p.position), name(p.name), team(p.team), goals_scored(p.goals_scored), nr_tricou(p.nr_tricou){
}

Player&Player::operator=(const Player& other){
    name = other.name;
    team = other.team;
    position = other.position;
    age = other.age;
    goals_scored = other.goals_scored;
    nr_tricou = other.nr_tricou;
    return *this;
}

 void Player::Goal(){
    goals_scored++;
}

Player::~Player(){}

ostream& operator<<(ostream& os, const Player& p){
    os << p.name << " " << p.team << " " << p.age << " " <<
       p.position << " " << p.goals_scored << " goals";
    return os;
}

void Player::verifyPlayer(){
    if(age < 16)
        throw eroare_varstaJucator();
    if(position != "Striker" && position != "Midfielder" && position != "Defender" &&
       position != "Goalkeeper") {
        throw eroare_pozitieJucator();
    }
}

const string &Player::getName() const {
    return name;
}

//int Player::getAge() const {
 //   return age;
//}