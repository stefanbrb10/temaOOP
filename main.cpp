#include <iostream>
#include <string>
#include "match.h"
#include "team.h"
#include "player.h"
#include "eroare_jucator.h"
#include "league.h"
#include "leagueJunior.h"
#include "leagueNationalTeam.h"
#include "country.h"
#include<vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "aplicatie.h"
#include "template.h"

const int SQUAD_SIZE = 26;

using namespace std;

const vector<string> teams1 = {"FCSB", "FC Rapid", "CFR Cluj", "U Cluj", "Farul Constanta",
                         "Hermannstadt Sibiu", "Petrolul Ploiesti", "Sepsi OSK", "FC Voluntari",
                         "FC Arges Pitesti", "Chindia Targoviste", "FC Botosani", "UTA Arad", "Craiova 1948",
                         "Universitatea Craiova", "FC Mioveni"};

const vector<string> teams2 = {"CSA Steaua", "Unirea Slobozia", "Csikszereda Miercurea Ciuc",
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
        try {
            Player player(name, team, position, age);
            P.push_back(player);
        }catch(eroare_jucator &err){
            cout << err.what() << '\n';
        }
    }
    fin.close();
}

void Clasa_match(string filepath, vector <Team> &T, vector <Match> &M) {
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
    try{
        Player corect ("Simon Araujo", "Inter Milan", "Goalkeeper", 33);
        // Player gresit("Robert Stan","Barcelona", "extrema ascunsa", 19);
    }catch(eroare_jucator &err){
        cout << err.what() << '\n';
    }

    vector <int>home;
    vector <int>away;
    int teamsSize = teams1.size();
    for(int i = 0; i < teamsSize -1; i+=2){
        home.push_back(i);
        away.push_back(i+1);
    }
    vector<Team> T;
    Clasa_team(teams1, T, P);
    vector<Match> M;
    Clasa_match("meciuri.txt", T, M);

    int matches_size = M.size();
    for(int i = 0; i < matches_size; i++, cout << '\n')
        M[i].Score();
    P[1].Goal();
    sort(T.begin(), T.end(), Team::cmp);
    cout << "---------------------CLASAMENT------------------------------------\n";
    for(auto i = 0ull; i < teams1.size(); i++)
        cout << i + 1 << ". " << T[i].getName() << " " << T[i].getPoints() << '\n';
    leagueJunior l1 = leagueJunior(8, "Romania", 4000, 19);
    leagueJunior lUnder16 = leagueJunior(10, "Romania", 10000, 16);
    leagueJunior lUnder10 = leagueJunior(16, "Romania", 8000, 10);
    vector<shared_ptr<League>> romanian;
    country Romania = country(romanian, 30000);
    Romania.addLeague(l1);
    Romania.addLeague(lUnder16);
    Romania.addLeague(lUnder10);
    if(Romania.budgetEnough())
        cout << "Tara poate gazdui ligile alocate";
    else cout << "Tara NU poate gazdui ligile alocate";
    leagueNationalTeam l2 =  leagueNationalTeam(32, "World",300, 8, "All", "Qatar");
    auto vec = {l1.clone(), l2.clone()};
    for(shared_ptr<League> l:vec)
        l->printRules();
    League* myLeague = dynamic_cast<League*>(&l2);
    leagueNationalTeam* lnt = dynamic_cast<leagueNationalTeam*>(myLeague);
    int money = lnt->getBudget();
    if(money == 0)
        cout << "Liga nu are buget";
    else cout << money;
    auto& aplicatie = Aplicatie::getAplicatie();
        aplicatie.printMeniu();
            aplicatie.addJucator();
            aplicatie.printJucator();
    Player steaua = jucator_factory::stelist();
    cout << compara(P[4], P[11]) << "\n";
    cout << compara(lUnder10, lUnder16);
    Clasament<string> clasament;
    for(auto i = 0ull; i < teams1.size(); i++){
        clasament.addEchipa(T[i].getName());
        clasament.addPuncte(T[i].getName(),T[i].getPoints());

    }
    clasament.printClasament();
    return 0;
}
