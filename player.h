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

    Player(string objName, string objTeam, string objPosition, int objAge);

    Player(const Player& p);

    Player& operator=(const Player& other);

    void Goal();

    ~Player();
    friend ostream& operator<<(ostream& os, Player p);
};

#endif
