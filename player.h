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
    const int nr_tricou;
    static int cnt;

public:

    Player(string objName, string objTeam, const string &objPosition, int objAge);


    Player(const Player& p);

    Player& operator=(const Player& other);

    void Goal();

    const string &getName() const;

    ~Player();
    friend ostream& operator<<(ostream& os, const Player& p);
};

class jucator_factory{
public:
    static Player mijlocas(){ return Player("Marius Matei", "FC Rapid", "mijlocas", 21);}
    static Player stelist(){return Player("Tavi Popescu", "FCSB", "atacant", 20);}
};

#endif
