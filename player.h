#ifndef PLAYERS_H
#define PLAYERS_H

#include <iostream>
#include <string>

using namespace std;

class Player{
private:
    int age;
    string position;
    string name;
    string team;
    int goals_scored = 0;

public:

    Player(const string &objName, const string &objTeam, const string &objPosition, int objAge);


    Player(const Player& p);

    Player& operator=(const Player& other);

    void Goal();

    const string &getName() const;

    ~Player();
    friend ostream& operator<<(ostream& os, const Player& p);

    void verifyPlayer();
};

#endif
