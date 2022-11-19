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

vector<string> prenume = {"Stefan", "Octavian", "Cristian", "Moussoufa",
                          "Marius", "Catalin", "Andrei", "Wesley", "Novak", "Filip", "Robert",
                          "John", "Hugo", "Lionel", "Ruben", "Mihai", "Vlad", "Mohammed", "Darius",
                          "Laurentiu", "Dragos", "George", "Patrick", "Ionut", "Marc", "Giani",
                          "Benjamin", "Marco", "Roberto","Costinel", "Marin", "Rocco", "Adelin",
                          "Denis", "Gabriel", "Giovanny", "Raul", "Horea", "Federico", "Rashid",
                          "Vasile", "Cristian", "Sebastian", "Cosmin", "Gelu", "Antonio", "Cezar",
                          "Mason"};

vector<string> nume = {"Barbu", "Popescu", "Martinovic", "Patulea", "Rusu",
                       "Chirica", "Florea", "Vlad", "Vasile", "Messi", "Diaz", "Al Rahman", "Olaru",
                       "Lavric", "Elias", "Anghel", "Mihaila", "Marszolik", "Gaina", "Dumitrache", "Cretu",
                       "Elias", "Toderean", "Iancu", "Cretu", "Velicu", "Ionescu", "Petrov", "Pozniak",
                       "Neagu", "White", "Eftene", "Pisica", "Milescu", "Pitoi","Moraru", "Costea", "Nastase",
                       "Dociu", "Lewandowski", "Sapunaru", "Andronic", "Schlotterbeck", "Valverde", "Dragnoi",
                       "Surdu", "Gidoiu", "Bradu", "Melcu", "Chira", "Gabor", "Rus", "Chitu", "Becali",
                       "Tanase", "Istrate", "Nersidan", "Sandu", "Podocea", "Budeanu", "Cimpeanu"};

vector <string>pos = {"Defender", "Defender", "Defender",
                      "Midfielder", "Midfielder", "Midfielder", "Striker", "Striker"};

vector<string> teams1 = {"FCSB", "FC Rapid", "CFR Cluj", "U Cluj", "Farul Constanta",
                         "Hermannstadt Sibiu", "Petrolul Ploiesti", "Sepsi OSK", "FC Voluntari",
                         "FC Arges Pitesti", "Chindia Targoviste", "FC Botosani", "UTA Arad", "Craiova 1948",
                         "Universitatea Craiova", "FC Mioveni"};

vector<string> teams2 = {"CSA Steaua", "Unirea Slobozia", "Csikszereda Miercurea Ciuc",
                         "Poli Iasi", "Buzau", "Unirea Dej", "Otelul Galati", "Dinamo Bucuresti",
                         "CSM Slatina", "FC Brasov", "Selimbar", "Concordia Chiajna", "CSM Oltenita",
                         "Viitorul Tg Jiu", "Minaur Baia Mare", "Progresul Spartac", "Victoria Chirnogi",
                         "FC Dumbravita", "AFC Unirea Constanta", "Poli Timisoara"};

vector<Match> M;

ofstream fo("meciuri.txt");


void generate_players(vector<string>teams, string filepath) {
    ofstream f(filepath);
    for (int i = 0; i < (int) teams.size(); i++) {
        int captain = rand() % SQUAD_SIZE;
        for (int j = 0; j < SQUAD_SIZE; j++) {
            f << prenume[rand() % prenume.size()] << " " <<
                  nume[rand() % nume.size()];
            if (j == captain)
                f << "(C)";
            f << "/" << teams[i] << "/" << rand() % AGE_DIF + MIN_AGE <<
                  "/";
            if (j == 0 || j == 11)
                f << "Goalkeeper" << endl;
            else f << pos[rand() % pos.size()] << endl;
        }
    }
}

void generate_round(vector<int> home, vector<int> away, vector<string> teams, int nr) {
    int sz = teams.size();
    for (int i = 0; i < sz / 2; i++) {
        for (int j = 0; j < sz / 2; j++) {
            int goalsHome = rand() % 4;
            int goalsAway = rand() % 4;
            fo << i + 1 + nr << '/' << teams[home[j]] << '/' << teams[away[j]]
            << '/' << goalsHome << '/' <<goalsAway << endl;
        }
        int aux = away[0];
        for (int j = 1; j < sz / 2; j++)
            away[j - 1] = away[j];
        away[sz / 2 - 1] = aux;
    }
}

void Clasa_player(string filepath, vector <Player> &P) {
    string st, t;
    ifstream fin(filepath);
    while (getline(fin, st)) {
        stringstream x(st);
        int i = 0;
        string name, team, position;
        int age;
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

void Clasa_match(string filepath, vector <Team> &T) {
    string st, t;
    ifstream fin(filepath);
    while (getline(fin, st)) {
        stringstream x(st);
        int i = 0;
        string date, home, away;
        int homeGoals, awayGoals;
        while (getline(x, t, '/')) {
            if (i == 0)
                date = t;
            else if (i == 1)
                home = t;
            else if (i == 2) {
                stringstream homeG(t);
                homeG >> homeGoals;
            }
            else if (i == 3) {
                stringstream awayG(t);
                awayG >> awayGoals;
            }
            i++;
        }
        Match match(date, homeGoals, awayGoals, T[0], T[1]);
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
    generate_players(teams1, "liga1.txt");
    generate_players(teams2,"liga2.txt");
    vector<Player>P;
    Clasa_player("liga1.txt", P);
    Clasa_player("liga2.txt", P);
    vector <int>home;
    vector <int>away;
    int sz = teams1.size();
    for(int i = 0; i < (int)teams1.size() -1; i+=2){
        home.push_back(i);
        away.push_back(i+1);
    }
    generate_round(home,away,teams1, 0);
    generate_round(away,home,teams1, sz / 2);
    vector<Team> T;
    Clasa_team(teams1, T, P);
    Clasa_match("liga1.txt", T);
    return 0;
}
