#include <iostream>
#include <string>
#include "match.h"
#include "team.h"
#include "player.h"
#include<vector>

using namespace std;

int main(){
    Player p1("Octavian Popescu", "FCSB", "Striker", 19);
    Player p2("Bilel Omrani", "FCSB", "Striker", 29);
    vector <Player> s1 = {p1,p2};
    Player p3("Antonio Sefer", "FC Rapid 1923", "Striker", 22);
    Player p4("Cristian Sapunaru", "FC Rapid 1923", "Defender", 38);
    vector<Player> s2 = {p3, p4};
    Team t1("FCSB", "SuperLiga", s1);
    Team t2("FC Rapid 1923", "SuperLiga", s2);
    vector <Player> goalScorers = {p1, p3};
    Match m("06.11.2022", 1, 1, goalScorers, t1, t2);
    m.Score();
    return 0;
}
