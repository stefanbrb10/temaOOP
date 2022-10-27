#ifndef PLAYERS_H
#define PLAYERS_H

#include <iostream>
#include <string>

using namespace std;

class Player{
private:
    int age;
    string position;
    int captain;
    string name;
    string team;
    int goals_scored;

public:

    Player(string objName, string objTeam, string objPosition, int objAge){
        name = objName;
        team = objTeam;
        position = objPosition;
        age = objAge;
        goals_scored = 0;
    }

    Player(const Player& p){
        name = p.name;
        team = p.team;
        position = p.position;
        age = p.age;
        goals_scored = p.goals_scored;
    }

    void Goal(){
        goals_scored++;
    }

    ~Player(){}
    friend ostream& operator<<(ostream& os, Player p);
};

ostream& operator<<(ostream& os, Player p){
    os << p.name << " " << p.team << " " << p.age << " " <<
    p.position << " " << p.goals_scored << " goals";
    return os;
}
#endif

int main(){
    return 0;
}
