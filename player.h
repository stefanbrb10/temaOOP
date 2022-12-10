#ifndef PLAYERS_H
#define PLAYERS_H

#include <iostream>
#include <string>

using namespace std;

class Player{
private:
    int age;
public:
    int getAge() const;

private:
    string position;
    string name;
    string team;
    int goals_scored = 0;

public:

    Player(string objName, string objTeam, const string &objPosition, int objAge);


    Player(const Player& p);

    Player& operator=(const Player& other);

    void Goal();

    const string &getName() const;

    ~Player();
    friend ostream& operator<<(ostream& os, const Player& p);

    void verifyPlayer();
};

#endif
