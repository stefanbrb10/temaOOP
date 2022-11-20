#include <iostream>
#include <string>
#include "match.h"
#include "team.h"
#include "player.h"
#include<vector>
#include <fstream>
#include <sstream>

#define SQUAD_SIZE 26
#define AGE_DIF 22
#define MIN_AGE 16

using namespace std;

vector<string> teams1 = {"FCSB", "FC Rapid", "CFR Cluj", "U Cluj", "Farul Constanta",
                         "Hermannstadt Sibiu", "Petrolul Ploiesti", "Sepsi OSK", "FC Voluntari",
                         "FC Arges Pitesti", "Chindia Targoviste", "FC Botosani", "UTA Arad", "Craiova 1948",
                         "Universitatea Craiova", "FC Mioveni"};

vector<string> teams2 = {"CSA Steaua", "Unirea Slobozia", "Csikszereda Miercurea Ciuc",
                         "Poli Iasi", "Buzau", "Unirea Dej", "Otelul Galati", "Dinamo Bucuresti",
                         "CSM Slatina", "FC Brasov", "Selimbar", "Concordia Chiajna", "CSM Oltenita",
                         "Viitorul Tg Jiu", "Minaur Baia Mare", "Progresul Spartac", "Victoria Chirnogi",
                         "FC Dumbravita", "AFC Unirea Constanta", "Poli Timisoara"};


void Clasa_player(string filepath, vector <Player> &P) {
    string st, t;
    ifstream fin(filepath);
    while (getline(fin, st)) {
        stringstream x(st);
        int i = 0;
        string name, team, position;
        int age = 0;
        while (getline(x, t, '/')) {
            if (i == 0)
                name = t;
            else if (i == 1)
                team = t;
            else if (i == 2) {
                stringstream nr(t);
                nr >> age;
            }
            else if (i == 3) {
                position = t;
            }
            i++;
        }
        Player player(name, team, position, age);
        P.push_back(player);
    }
    fin.close();
}

void Clasa_match(string filepath, vector <Team> T, vector <Match> &M) {
    string st, t;
    ifstream fin(filepath);
    while (getline(fin, st)) {
        stringstream x(st);
        int i = 0;
        string date, home, away;
        int homeGoals = 0, awayGoals = 0;
        while (getline(x, t, '/')) {
            if (i == 0)
                date = t;
            else if (i == 1)
                home = t;
            else if (i==2)
                away = t;
            else if (i == 3) {
                stringstream homeG(t);
                homeG >> homeGoals;
            }
            else if (i == 4) {
                stringstream awayG(t);
                awayG >> awayGoals;
            }
            i++;
        }
        int index_home = 0, index_away = 0;
        for(int k = 0; k < (int)teams1.size();k++) {
            if (T[k].getName() == home)
                index_home = k;
            if (T[k].getName() == away)
                index_away = k;
        }

        Match match(date, homeGoals, awayGoals, T[index_home], T[index_away]);
        M.push_back(match);
    }
    fin.close();
}

void Clasa_team(vector<string> teams, vector <Team> &T, vector <Player> P){
    int nr = 0;
    for(int i = 0; i < (int)teams.size(); i++) {
        vector <Player> squad;
        for (int j = 0; j < SQUAD_SIZE; j++) {
            squad.push_back(P[nr]);
            nr++;
        }
        Team team(teams[i], "SuperLiga", squad);
        T.push_back(team);
    }
}




int main(){
    srand(int(time(0)));
    vector<Player>P;
    Clasa_player("liga1.txt", P);
    Clasa_player("liga2.txt", P);
    vector <int>home;
    vector <int>away;
    for(int i = 0; i < (int)teams1.size() -1; i+=2){
        home.push_back(i);
        away.push_back(i+1);
    }
    vector<Team> T;
    Clasa_team(teams1, T, P);
    vector<Match> M;
    Clasa_match("meciuri.txt", T, M);
    for(int i = 0; i < (int)M.size(); i++, cout << '\n')
        M[i].Score();
    return 0;
}
